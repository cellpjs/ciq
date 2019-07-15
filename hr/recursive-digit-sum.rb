#!/bin/ruby

require 'json'
require 'stringio'

def recSD(m)
  return m if m < 10
  digit_sum = m.to_s.chars.map(&:to_i).reduce(&:+)
  return recSD(digit_sum)
end

# Complete the superDigit function below.
def superDigit(n, k)
  digit_sum = n.chars.map(&:to_i).reduce(&:+)
  digit_sum = digit_sum*k
  return recSD(digit_sum)
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

nk = gets.rstrip.split

n = nk[0].to_s.rstrip

k = nk[1].to_i

result = superDigit n, k

fptr.write result
fptr.write "\n"

fptr.close()

