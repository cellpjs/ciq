#!/bin/ruby

require 'json'
require 'stringio'

# Complete the arrayManipulation function below.
def arrayManipulation(n, queries)
  dq = Array.new(n+1,0)
  queries.each do |q|
    a,b,k = q
    dq[a-1]+=k
    dq[b]-=k
  end
  max_sum = 0
  sum = 0
  dq.each do |x|
    sum += x
    max_sum = [max_sum, sum].max
  end
  return max_sum
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

nm = gets.rstrip.split

n = nm[0].to_i

m = nm[1].to_i

queries = Array.new(m)

m.times do |i|
    queries[i] = gets.rstrip.split(' ').map(&:to_i)
end

result = arrayManipulation n, queries

fptr.write result
fptr.write "\n"

fptr.close()


