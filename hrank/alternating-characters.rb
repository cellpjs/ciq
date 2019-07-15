#!/bin/ruby

require 'json'
require 'stringio'

# Complete the alternatingCharacters function below.
def alternatingCharacters(s)
  del_count = 0
  s.chars.each_with_index do |v, i|
    next if i == 0
    if v == s[i-1]
      del_count+=1
    end
  end
  return del_count
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

q = gets.to_i

q.times do |q_itr|
    s = gets.to_s.rstrip

    result = alternatingCharacters s

    fptr.write result
    fptr.write "\n"
end

fptr.close()


