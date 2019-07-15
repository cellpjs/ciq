#!/bin/ruby

require 'json'
require 'stringio'

# Complete the stepPerms function below.
def recPerms(n,memo)
  return 1 if n==1
  return 2 if n==2
  return 4 if n==3
  return memo[n] if memo[n]
  result = recPerms(n-1,memo)+recPerms(n-2,memo)+recPerms(n-3,memo)
  memo[n] = result
end

def stepPerms(n)
  memo = []
  ans = recPerms(n,memo)
  return ans # % 1000000007
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

s = gets.to_i

s.times do |s_itr|
    n = gets.to_i

    res = stepPerms n

    fptr.write res
    fptr.write "\n"
end

fptr.close()

