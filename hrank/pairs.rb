#!/bin/ruby

require 'json'
require 'stringio'
require 'set'
# Complete the pairs function below.
def pairs(k, arr)
  #p arr
  count = 0
  nset = arr.to_set
  #p nset
  arr.each do |x|
    if nset.include?(x + k)
      #puts "#{x},#{x + k}"
      count+=1
    end
    if nset.include?(x - k)
      #puts "#{x},#{x - k}"
      count+=1
    end
  end
  return count/2
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

nk = gets.rstrip.split

n = nk[0].to_i

k = nk[1].to_i

arr = gets.rstrip.split(' ').map(&:to_i)

result = pairs k, arr

fptr.write result
fptr.write "\n"

fptr.close()


