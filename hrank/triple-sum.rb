#!/bin/ruby

require 'json'
require 'stringio'

# Complete the triplets function below.
def triplets(a, b, c)
  count = 0
  ua = a.uniq.sort
  ub = b.uniq.sort
  uc = c.uniq.sort
  la = ua.size
  lc = uc.size
  ia = 0
  ic = 0
  ub.each do |x|
    while ia < la && ua[ia] <= x
      ia+=1
    end
    while ic < lc && uc[ic] <= x
      ic+=1
    end
    count+= ia*ic
  end
  return count
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

lenaLenbLenc = gets.rstrip.split

lena = lenaLenbLenc[0].to_i

lenb = lenaLenbLenc[1].to_i

lenc = lenaLenbLenc[2].to_i

arra = gets.rstrip.split(' ').map(&:to_i)

arrb = gets.rstrip.split(' ').map(&:to_i)

arrc = gets.rstrip.split(' ').map(&:to_i)

ans = triplets arra, arrb, arrc

fptr.write ans
fptr.write "\n"

fptr.close()


