#!/bin/ruby

require 'json'
require 'stringio'

# Complete the freqQuery function below.
def freqQuery(queries)
  ans = []
  my_hash = Hash.new(0)
  freq_hash = Hash.new(0)
  queries.each do |q|
    cmd = q[0]
    arg = q[1]
    case cmd
    when 1     
      my_hash[arg] +=1
      freq_hash[my_hash[arg]] +=1
      freq_hash[my_hash[arg]-1] -=1
    when 2
      if my_hash[arg]>0
        my_hash[arg] -=1
        freq_hash[my_hash[arg]] +=1
        freq_hash[my_hash[arg]+1] -=1
      end
    when 3
      if freq_hash[arg] > 0
        ans << 1
      else
        ans << 0
      end
    end
  end
  return ans
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

q = gets.strip.to_i

queries = Array.new(q)

q.times do |i|
    queries[i] = gets.rstrip.split.map(&:to_i)
end

ans = freqQuery queries

fptr.write ans.join "\n"
fptr.write "\n"

fptr.close()


