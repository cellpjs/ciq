#!/bin/ruby

require 'json'
require 'stringio'

# Complete the maxSubsetSum function below.
def maxSubsetSum(arr)
  n = arr.length
  result = []
  result[0] = [arr[0], 0].max
  result[1] = [arr[0], arr[1], 0].max
  2.upto(n-1) do |i|
    result[i] = [result[i-2]+arr[i], result[i-1]].max
  end
  return result[n-1]
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

arr = gets.rstrip.split(' ').map(&:to_i)

res = maxSubsetSum arr

fptr.write res
fptr.write "\n"

fptr.close()


