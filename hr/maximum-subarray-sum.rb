#!/bin/ruby

require 'json'
require 'stringio'

# Complete the maximumSum function below.
def maximumSum(a, m)
  # contiguous subarrays i..j
  # using prefix array 0..k
  # keep array sorted 
  n = a.size 
  sorted_prefix = [m]
  sum_so_far = 0
  maxmod = 0
  a.each_with_index do |x|
    sum_so_far+=x
    pmod = sum_so_far % m
    if pmod > maxmod
      maxmod = pmod
    end
    j = sorted_prefix.bsearch_index{ |r| r > pmod }
    sorted_prefix.insert(j,pmod)
    if sorted_prefix[j+1]<m
       # only consider new prefix and next higher valued prefix
       # which has been seen previously (shorter prefix)
      candidate = (sorted_prefix[j]-sorted_prefix[j+1]+m)%m
      if candidate > maxmod
        maxmod = candidate
      end
    end
  end
  return maxmod
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

q = gets.to_i

q.times do |q_itr|
    nm = gets.rstrip.split

    n = nm[0].to_i

    m = nm[1].to_i

    a = gets.rstrip.split(' ').map(&:to_i)

    result = maximumSum a, m
    
    fptr.write result
    fptr.write "\n"
end

fptr.close()

