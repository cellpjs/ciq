#!/bin/ruby

require 'json'
require 'stringio'

# Complete the findShortest function below.

#
# For the weighted graph, <name>:
#
# 1. The number of nodes is <name>_nodes.
# 2. The number of edges is <name>_edges.
# 3. An edge exists between <name>_from[i] to <name>_to[i].
#
#
def findShortest(graph_nodes, graph_from, graph_to, ids, val)
    return -1 if ids.count(val)<=1 # no two nodes with color val
    dmin = graph_nodes
    num_edges = graph_from.length
    neighbors = {}
    0.upto(num_edges-1) do |i|
      if neighbors[graph_from[i]]
        neighbors[graph_from[i]] << graph_to[i]
      else
        neighbors[graph_from[i]] = [graph_to[i]]
      end
      if neighbors[graph_to[i]]
        neighbors[graph_to[i]] << graph_from[i]
      else
        neighbors[graph_to[i]] = [graph_from[i]]
      end
    end
    p neighbors
    ids.each_with_index do |v,i|
      if v == val
        # zero-base index to one-base index 
        source_node = i+1
        # look for others using bfs (stop looking if distance > dmin)
        queue = []
        visited = []
        backtrace = {}
        queue << source_node
        while !(queue.empty?)
          current_node = queue.shift
          visited << current_node
          if (current_node!=source_node) && (ids[current_node-1]==val)
            puts "we are here!"
            # how did I get here? backtrace
            hops = 0
            trace_node = current_node
            while (trace_node!=source_node)
              trace_node = backtrace[trace_node]
              hops +=1
            end
            if hops < dmin
              dmin = hops
            end
            break
          end
          neighbors[current_node].each do |xnode|
            if !(visited.include?(xnode))
              queue << xnode
              backtrace[xnode] = current_node
            end
          end
        end
        p visited
      end
    end
    if dmin == graph_nodes
      return -1
    else
      return dmin
    end
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

graph_nodes, graph_edges = gets.strip.split(' ').map(&:to_i)

graph_from = Array.new graph_edges
graph_to = Array.new graph_edges

graph_edges.times do |i|
    graph_from[i], graph_to[i] = gets.strip.split(' ').map(&:to_i)
end

ids = gets.rstrip.split(' ').map(&:to_i)

val = gets.to_i

ans = findShortest graph_nodes, graph_from, graph_to, ids, val

fptr.write ans
fptr.write "\n"

fptr.close()


