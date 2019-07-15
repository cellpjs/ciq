#!/bin/ruby

require 'json'
require 'stringio'

# Complete the maximumToys function below.
def maximumToys(prices, k)
  s = prices.sort
  spent = 0
  score = 0
  s.each do |x|
    if spent + x < k
      spent +=x
      score +=1
    else
      break
    end
  end
  return score
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

nk = gets.rstrip.split

n = nk[0].to_i

k = nk[1].to_i

prices = gets.rstrip.split(' ').map(&:to_i)

result = maximumToys prices, k

fptr.write result
fptr.write "\n"

fptr.close()


