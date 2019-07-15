#!/bin/ruby

require 'json'
require 'stringio'

# Complete the sockMerchant function below.
def sockMerchant(n, ar)
    color_bin = {}
    ar.each do |x|
        if color_bin[x] == nil
            color_bin[x] = 1
        else
            color_bin[x]+=1
        end
    end
    pairs = 0
    color_bin.each do |k,v|
        pairs += v/2
    end
    return pairs
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

ar = gets.rstrip.split(' ').map(&:to_i)

result = sockMerchant n, ar

fptr.write result
fptr.write "\n"

fptr.close()

