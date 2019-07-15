#!/bin/ruby

#
# Complete the swapNodes function below.
#
def traverse(root,indexes)
  order = []
  order += traverse(indexes[root-1][0],indexes) if indexes[root-1][0]>0
  order << root
  order += traverse(indexes[root-1][1],indexes) if indexes[root-1][1]>0
  return order
end

def swap(d,root,indexes)
  if d == 1
    puts "#{root} swapping children"
    indexes[root-1][0],indexes[root-1][1] = indexes[root-1][1],indexes[root-1][0]
  else
    swap(d-1,indexes[root-1][0],indexes) if indexes[root-1][0] > 0
    swap(d-1,indexes[root-1][1],indexes) if indexes[root-1][1] > 0
  end
end

def max_depth(root,indexes)
  md = 1
  md += max_depth(indexes[root-1][0],indexes) if indexes[root-1][0] > 0
  md += max_depth(indexes[root-1][1],indexes) if indexes[root-1][1] > 0
  return md
end

def swapNodes(indexes, queries)
    ni = indexes.size
    # number of nodes
    depth = max_depth(1,indexes)
    # just look at examples to understand this exercise
    # indexes[i] = (left child, right child)
    # index[i-1][0] = left child of i
    # index[i-1][1] = right child of i
    # test traverse
    # p traverse(1, indexes)
    result = []
    queries.each do |q|
      nswap = depth/q 
      1.upto(nswap) do |j|
        # puts "current_depth = #{q*j}"
        swap(q*j,1,indexes)
      end
      result << traverse(1,indexes)
    end
    return result
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

indexes = Array.new(n)

n.times do |indexes_row_itr|
    indexes[indexes_row_itr] = gets.rstrip.split(' ').map(&:to_i)
end

queries_count = gets.to_i

queries = Array.new(queries_count)

queries_count.times do |queries_itr|
    queries_item = gets.to_i
    queries[queries_itr] = queries_item
end

result = swapNodes indexes, queries

fptr.write result.map{ |x| x.join " " }.join "\n"
fptr.write "\n"

fptr.close()


