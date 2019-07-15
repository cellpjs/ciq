#!/bin/ruby

require 'json'
require 'stringio'

# Complete the isValid function below.
def isValid(s)
  count = Hash.new(0)
  s.each_char do |c|
    count[c] +=1
  end
  p count
  cv = count.values
  p cv
  if cv.uniq.size > 2
    return "NO" 
  elsif cv.uniq.size == 1
    return "YES" 
  else
    # cv.uniq.size == 2
    type1,type2 = cv.uniq
    return "YES" if type1 == 1 && cv.count(type1) == 1
    return "YES" if type2 == 1 && cv.count(type2) == 1
    return "YES" if type1 == type2+1 && cv.count(type1)==1
    return "YES" if type2 == type1+1 && cv.count(type2)==1
    return "NO"
  end
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

s = gets.to_s.rstrip

result = isValid s

fptr.write result
fptr.write "\n"

fptr.close()


