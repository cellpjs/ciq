#!/bin/ruby

require 'json'
require 'stringio'

# using disjoint set data structure
# https://en.wikipedia.org/wiki/Disjoint-set_data_structure
def MakeSet(dset, x)
  unless dset[x] 
    # add x to the disjoint-set tree
    dset[x] = {parent: x, size:1}
  end
end

def Find(dset, x)
   if dset[x][:parent] != x
     dset[x][:parent] = Find(dset,dset[x][:parent])
   end
   return dset[x][:parent]
end

def Union(dset, x, y)
  xRoot = Find(dset,x)
  yRoot = Find(dset,y) 
  # x and y are already in the same set
  if xRoot == yRoot
    return dset[xRoot][:size]
  end         
  # x and y are not in same set, so we merge them
  if dset[xRoot][:size] < dset[yRoot][:size]
    xRoot, yRoot = yRoot, xRoot # swap xRoot and yRoot
  end
  # merge yRoot into xRoot
  dset[yRoot][:parent] = xRoot
  dset[xRoot][:size] = dset[xRoot][:size] + dset[yRoot][:size]
  return dset[xRoot][:size]
end

# Complete the maxCircle function below.
def maxCircle(queries)
  current_max = 0
  dset = {}
  max_circle_seq = []
  queries.each do |q|
    #p q
    a = q[0]
    b = q[1]
    MakeSet(dset,a) unless dset[a]
    MakeSet(dset,b) unless dset[b]
    u = Union(dset,a,b)
    current_max = [current_max,u].max
    max_circle_seq << current_max
  end
  return max_circle_seq
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

q = gets.to_i

queries = Array.new(q)

q.times do |i|
    queries[i] = gets.rstrip.split(' ').map(&:to_i)
end

ans = maxCircle queries

fptr.write ans.join "\n"
fptr.write "\n"

fptr.close()

