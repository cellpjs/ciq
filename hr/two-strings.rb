#!/bin/ruby

require 'json'
require 'stringio'

# Complete the twoStrings function below.
def twoStrings(s1, s2)
  require 'set'
  set1 = Set.new(s1.chars)
  set2 = Set.new(s2.chars)
  if set1.intersect? set2
    return "YES"
  else
    return "NO"
  end
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

q = gets.to_i

q.times do |q_itr|
    s1 = gets.to_s.rstrip

    s2 = gets.to_s.rstrip

    result = twoStrings s1, s2

    fptr.write result
    fptr.write "\n"
end

fptr.close()


