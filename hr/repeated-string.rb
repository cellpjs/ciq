#!/bin/ruby

require 'json'
require 'stringio'

# Complete the repeatedString function below.
def repeatedString(s, n)
    num_a = s.count("a")
    if num_a == 0
        return 0
    end
    slen = s.length
    total = num_a*(n/slen)
    total += s[0...n%slen].count("a")
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

s = gets.to_s.rstrip

n = gets.to_i

result = repeatedString s, n

fptr.write result
fptr.write "\n"

fptr.close()


