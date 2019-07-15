#!/bin/ruby

require 'json'
require 'stringio'

# Complete the maxMin function below.
def maxMin(k, arr)
  arr.sort!
  mm = 10**9
  (0..arr.length-k).each do |i|
    diff = arr[i+k-1]-arr[i]
    mm = [mm,diff].min
  end
  return mm
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

k = gets.to_i

arr = Array.new(n)

n.times do |i|
    arr_item = gets.to_i
    arr[i] = arr_item
end

result = maxMin k, arr

fptr.write result
fptr.write "\n"

fptr.close()


