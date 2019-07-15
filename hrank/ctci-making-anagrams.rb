#!/bin/ruby

require 'json'
require 'stringio'

# Complete the makeAnagram function below.
def makeAnagram(a, b)
  delta = 0
  a_map = Hash.new(0)
  b_map = Hash.new(0)
  a.each_char do |c|
    a_map[c] +=1
  end
  b.each_char do |c|
    b_map[c] +=1
  end
  "a".upto("z") do |x|
    delta += (a_map[x]-b_map[x]).abs
  end
  return delta
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

a = gets.to_s.rstrip

b = gets.to_s.rstrip

res = makeAnagram a, b

fptr.write res
fptr.write "\n"

fptr.close()


