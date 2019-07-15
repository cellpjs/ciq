#!/bin/ruby

require 'json'
require 'stringio'

# Complete the minimumSwaps function below.
def minimumSwaps(arr)
  swaps = 0
  alen = arr.length
  index_lookup = {}
  0.upto(alen-1) do |i|
    index_lookup[arr[i]] = i
  end
  0.upto(alen-1) do |i|
    if arr[i] == i+1
      # puts "nothing to do"
      next
    end
    k = index_lookup[i+1]
    index_lookup[arr[i]] = k
    p [i, k]
    arr[i],arr[k] = arr[k],arr[i]
    swaps +=1
  end
  return swaps
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

arr = gets.rstrip.split(' ').map(&:to_i)

res = minimumSwaps arr

fptr.write res
fptr.write "\n"

fptr.close()


