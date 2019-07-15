#!/bin/ruby

require 'json'
require 'stringio'

# Complete the whatFlavors function below.
def whatFlavors(cost, money)
  sorted = cost.sort
  ia = 0
  ib = sorted.length - 1
  while (ia<ib) do
    sum = sorted[ia]+sorted[ib] 
    if sum == money
    break;
    elsif sum > money
    ib-=1
    else
    ia+=1
    end
  end
  c1 = sorted[ia]
  c2 = sorted[ib]
  f1 = 1+cost.index(c1)
  f2 = 1+cost.index(c2)
  if f2==f1
    f2 = 1+cost.rindex(c2)
  end
  ff = [f1, f2].sort
  puts "#{ff[0]} #{ff[1]}"
end

t = gets.to_i

t.times do |t_itr|
    money = gets.to_i

    n = gets.to_i

    cost = gets.rstrip.split(' ').map(&:to_i)

    whatFlavors cost, money
end


