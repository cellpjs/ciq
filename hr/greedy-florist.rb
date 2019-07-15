#!/bin/ruby

require 'json'
require 'stringio'

# Complete the getMinimumCost function below.
def getMinimumCost(k, c)
  cost = 0
  c.sort!
  multiplier = 1
  while c.size > 0
    cost += c.pop(k).reduce(:+)*multiplier
    multiplier +=1
  end
  return cost
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

nk = gets.rstrip.split

n = nk[0].to_i

k = nk[1].to_i

c = gets.rstrip.split(' ').map(&:to_i)

minimumCost = getMinimumCost k, c

fptr.write minimumCost
fptr.write "\n"

fptr.close()


