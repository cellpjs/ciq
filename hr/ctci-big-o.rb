#!/bin/ruby

require 'json'
require 'stringio'

def primality(n)
  # wikipedia algorithm
  if n == 1
    return "Not prime"
  elsif n == 2 || n == 3
    return "Prime"
  elsif n % 2 == 0 || n % 3 == 0
    return "Not prime"
  end
  i = 5
  while i * i <= n
    if n % i == 0 || n % (i + 2) == 0
      return "Not prime"
    end
    i = i + 6
  end
  return "Prime"
end


fptr = File.open(ENV['OUTPUT_PATH'], 'w')

p = gets.to_i

p.times do |p_itr|
    n = gets.to_i

    result = primality n

    fptr.write result
    fptr.write "\n"
end

fptr.close()

