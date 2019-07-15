#!/bin/ruby

require 'json'
require 'stringio'

# Complete the substrCount function below.
def substrCount(n, s)
  spa_counter = 0
  run_seq = []
  run_char = nil
  run_count = 0
  s.each_char do |c|
    if c != run_char
      run_char = c
      run_seq << [c,1]
    else
       run_seq[-1][1] +=1
    end
  end     
  p run_seq
  # all same case
  run_seq.each do |x|
    spa_counter += x[1]*(x[1]+1)/2
  end
  # one in middle case
  slen = run_seq.length
  1.upto(slen-2) do |i|
    if run_seq[i][1] == 1 && run_seq[i-1][0] == run_seq[i+1][0]
      spa_counter += [run_seq[i-1][1],run_seq[i+1][1]].min
    end
  end
  return spa_counter
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

s = gets.to_s.rstrip

result = substrCount n, s

fptr.write result
fptr.write "\n"

fptr.close()


