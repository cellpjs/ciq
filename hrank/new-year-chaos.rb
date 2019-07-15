#!/bin/ruby

require 'json'
require 'stringio'

# Complete the minimumBribes function below.
def minimumBribes(q)
  sum = 0
  q.each_with_index do |v,i|
    if v-(1+i) > 2
      puts "Too chaotic"
      return
    end
    bound = [v-2,0].max
    (bound..i-1).each do |j|
      sum+=1 if q[j] > v
    end
  end
  puts sum
end

t = gets.to_i

t.times do |t_itr|
    n = gets.to_i

    q = gets.rstrip.split(' ').map(&:to_i)

    minimumBribes q
end


