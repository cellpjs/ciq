#!/bin/ruby

require 'json'
require 'stringio'

# Complete the luckBalance function below.
def luckBalance(k, contests)
  balance = 0
  nonimportant = contests.select{|x| x[1] == 0}.map{|y| y[0]}
  if nonimportant.length > 0
    balance += nonimportant.reduce(:+)
  end
  soimportant = contests.select{|x| x[1] == 1}.map{|y| y[0]}.sort{|a,b| b<=>a }
  p soimportant
  soimportant.each_with_index do |v, i|
    if i<k
      balance +=v
    else
      balance -=v
    end
  end
  return balance
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

nk = gets.rstrip.split

n = nk[0].to_i

k = nk[1].to_i

contests = Array.new(n)

n.times do |i|
    contests[i] = gets.rstrip.split(' ').map(&:to_i)
end

result = luckBalance k, contests

fptr.write result
fptr.write "\n"

fptr.close()


