#!/bin/ruby

require 'json'
require 'stringio'

# Complete the countTriplets function below.
def countTriplets(arr, r)
  triple_count = 0
  # arr is sorted? not necessarily
  # keep two hashes for singles and pairs!!!
  singles = {}
  pairs = {}
  arr.reverse_each do |x|
    # check if this number forms a new triple
    t = [x*r, x*r*r]
    if pairs[t] != nil && pairs[t] > 0
      triple_count += pairs[t]
    end
    # consider new pairs formed by this number
    p = [x, x*r]
    if pairs[p] == nil && singles[x*r] != nil && singles[x*r] > 0
      pairs[p] = singles[x*r]
    elsif pairs[p] != nil && pairs[p] > 0
      pairs[p] += singles[x*r]
    end
    # update singles counter 
    if singles[x] == nil
      singles[x] = 1
    else
      singles[x] +=1
    end
  end    
#    # initial value bucket (*)
#    bucket = {}
#    arr.each do |x|    
#    # factorize: x = vr^k
#      k = 0
#      v = x
#      while v % r == 0
#        v = v/r
#        k +=1
#      end
#      # put k into bucket v
#      if bucket[v] == nil
#        bucket[v] = {}
#        bucket[v][k] = 1
#      elsif bucket[v] && bucket[v][k] == nil
#        bucket[v][k] = 1
#      else
#        bucket[v][k] +=1
#      end
#    end
#    bucket.each_value do |sub|
#      sub.each_key do |i|
#        if sub[i+1] && sub[i+2]
#          triple_count += sub[i]*sub[i+1]*sub[i+2]
#        end
#      end
#    end
  return triple_count
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

nr = gets.rstrip.split

n = nr[0].to_i

r = nr[1].to_i

arr = gets.rstrip.split.map(&:to_i)

ans = countTriplets arr, r

fptr.write ans
fptr.write "\n"

fptr.close()


