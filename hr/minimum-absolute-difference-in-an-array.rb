#!/bin/ruby

require 'json'
require 'stringio'

# Complete the minimumAbsoluteDifference function below.
def minimumAbsoluteDifference(arr)
  alen = arr.length
  dmin = 2*(10**9)

  sarr = arr.sort
                      
  0.upto(alen-2) do |i|
    delta = (sarr[i]-sarr[i+1]).abs
    if delta < dmin
      dmin = delta
    end
  end
  return dmin
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

arr = gets.rstrip.split(' ').map(&:to_i)

result = minimumAbsoluteDifference arr

fptr.write result
fptr.write "\n"

fptr.close()


