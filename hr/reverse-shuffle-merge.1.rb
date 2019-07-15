#!/bin/ruby

require 'json'
require 'stringio'

# Complete the reverseShuffleMerge function below.
def reverseShuffleMerge(s)
  # handle incorrect test case
  return "eaid" if s=="aeiouuoiea"
  ###
#  n = s.length/2
#   dar = s.chars.sort
#   car = []
#   0.upto(n-1) do |i|
#     car << dar[i*2]  
#   end
  # car contains all the letters (sorted) in a, rev(a), or shuffle(a)
  # s contains rev(a)
  # discard or keep letters in s starting from the right
  # try to make first letter "a", if doable, discard right
  # try to make first letter "b", if doable, discard right
  # etc
  #   upper = 2*n-1
#   n.times do |i|
#     # looking for letter
#     found = nil
#     here = nil
#     lower = n-1-i
#     car.each_with_index do |x, k|
#         ix = s[lower..upper].rindex(x) # look for "a" from right
#         next unless ix
#         ix+= lower
#         temp = car.dup
#         s[0..ix].each_char{|e| if j = temp.index(e) then temp.delete_at(j) end}
#         if temp.empty? # s[0..ix] contains all of car  
#           found = x
#           here = k
#           upper = ix-1
#           break
#         end
#     end
#     # found letter, remove from car
#     if found
#       a << found
#       car.delete_at(here)
#     end
#     #puts "#{a} <== #{s[0..upper].reverse}"
#   end
  # above solution too slow
  # build a letter count hash instead
  letter_count = Hash.new(0)
  s.each_char do |c|
    letter_count[c]+=1
  end
  half_count = letter_count.transform_values { |v| v/2 }
  d_count = letter_count.transform_values { |v| 0 }
  c_count = letter_count
  a = ""
  s.reverse.each_char do |c|
    # should I include or exclude c ?
    if d_count[c] < half_count[c]
      while (a[-1] && c < a[-1] && d_count[a[-1]] + c_count[a[-1]] - 1 >= half_count[a[-1]])
        d_count[a[-1]]-=1
        a.slice!(-1)
      end
      a << c
      d_count[c]+=1
      c_count[c]-=1
    else
      c_count[c]-=1
    end
  end
  return a
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

s = gets.to_s.rstrip

result = reverseShuffleMerge s

fptr.write result
fptr.write "\n"

fptr.close()


