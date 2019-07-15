#!/bin/ruby

require 'json'
require 'stringio'

# Complete the countingValleys function below.
def countingValleys(n, s)
  vcount = 0
  level = 0
  n.times do |i|
    if s[i] == "U"
      level +=1
      vcount +=1 if level == 0
    elsif s[i] == "D"
      level -=1
    end
  end
  return vcount 
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

s = gets.to_s.rstrip

result = countingValleys n, s

fptr.write result
fptr.write "\n"

fptr.close()


