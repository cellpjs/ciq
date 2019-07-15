#!/bin/ruby

require 'json'
require 'stringio'

# Complete the hourglassSum function below.
def hourglassSum(arr)
  max_sum = -9*7
  (1..4).each do |row|
    (1..4).each do |col|
      sum = arr[row][col] 
      sum += arr[row-1][col-1..col+1].reduce(:+)
      sum += arr[row+1][col-1..col+1].reduce(:+)
      max_sum = [max_sum,sum].max
    end
  end
  return max_sum
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

arr = Array.new(6)

6.times do |i|
    arr[i] = gets.rstrip.split(' ').map(&:to_i)
end

result = hourglassSum arr

fptr.write result
fptr.write "\n"

fptr.close()


