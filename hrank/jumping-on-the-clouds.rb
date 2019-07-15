#!/bin/ruby

require 'json'
require 'stringio'

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c)
 segs = c.join.split("1")
 jumps = segs.count - 1
 segs.each do |x|
     jumps += x.length/2
 end
 return jumps
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

c = gets.rstrip.split(' ').map(&:to_i)

result = jumpingOnClouds c

fptr.write result
fptr.write "\n"

fptr.close()


