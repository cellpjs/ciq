#!/bin/ruby

require 'json'
require 'stringio'

# Complete the candies function below.
def candies(n, arr)
  cc = []
  cc[0] = 1
  1.upto(n-1) do |i|
    if arr[i] > arr[i-1]
      cc[i] = cc[i-1] + 1
    else
      cc[i] = 1
    end
  end
  p cc
  (n-2).downto(0) do |i|
    if arr[i] > arr[i+1] && cc[i] <= cc[i+1]
      cc[i] = cc[i+1] + 1
    end
  end
  p cc
  cc.reduce(:+)
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

arr = Array.new(n)

n.times do |i|
    arr_item = gets.to_i
    arr[i] = arr_item
end

result = candies n, arr

fptr.write result
fptr.write "\n"

fptr.close()


