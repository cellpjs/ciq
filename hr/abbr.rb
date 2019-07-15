#!/bin/ruby

require 'json'
require 'stringio'

# Complete the abbreviation function below.
def rec_abr(a,b,memo)
  if memo[[a,b]] != nil
    #print "r"
    return memo[[a,b]]
  end
  # base case
  if a.length < b.length
    return false
  elsif b.empty? && a.empty?
    return true
  elsif b.empty? && a.length > 0
    if (a.chars - ("a".."z").to_a).empty?
      return true
    else 
      return false
    end
  else
    # a and b both not empty
    if a[-1] == b[-1] # B/B
      result = rec_abr(a[0..-2],b[0..-2],memo)
    elsif a[-1] == b[-1].downcase # b/B
      # right (convert) <= left (delete) : dependency order matters
      result = rec_abr(a[0..-2],b[0..-1],memo) || rec_abr(a[0..-2],b[0..-2],memo)
    elsif a[-1] == a[-1].downcase # c/B
      result = rec_abr(a[0..-2],b[0..-1],memo)
    else # C/B
      return false
    end
  end
  #print "w"
  memo[[a,b]] = result
  return result 
end

def abbreviation(a, b)
  #puts a
  #puts b
  memo = {}
  result = rec_abr(a,b,memo)
  return result ? "YES" : "NO"
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

q = gets.to_i

q.times do |q_itr|
    a = gets.to_s.rstrip

    b = gets.to_s.rstrip

    result = abbreviation a, b

    fptr.write result
    fptr.write "\n"
end

fptr.close()

