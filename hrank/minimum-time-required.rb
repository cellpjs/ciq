#!/bin/ruby

require 'json'
require 'stringio'

# Complete the minTime function below.
def minTime(machines, goal)
  # p goal
  # p machines
  # number produced on day t by machine k = t/machines[k]
  # number produced on day t by all machines = sum_k (t/machines[k])
  # find smallest t such that sum_k (t/machines[k]) >= goal
  # continous estimation for days ~ goal / (sum_k (1.0/machines[k]))
  # this is a lower bound since it assumes partially done item can be used
  # start from this lower bound and check each day
  # upper bound? pessimistic
  # fastest machine working by itself
  # produces 1 item every machines.min days
  # upper bound = machines.min * goal
  lower_bound = (goal/machines.map{|x| 1.0/x}.reduce(:+)).floor
  upper_bound = machines.min * goal
  while (upper_bound - lower_bound > 1)
    days = (upper_bound + lower_bound)/2
    produced = machines.map{ |x| days/x }.reduce(:+)
    puts "#{goal - produced} more needed"
    if produced < goal
      lower_bound = days
    else
      upper_bound = days
    end
  end
  if produced = machines.map{ |x| lower_bound/x }.reduce(:+) >= goal
    return lower_bound
  else
    return upper_bound
  end
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

nGoal = gets.rstrip.split

n = nGoal[0].to_i

goal = nGoal[1].to_i

machines = gets.rstrip.split(' ').map(&:to_i)

ans = minTime machines, goal

fptr.write ans
fptr.write "\n"

fptr.close()

