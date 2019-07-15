#!/bin/ruby

require 'json'
require 'stringio'

# Complete the isBalanced function below.
def isBalanced(s)
  brstack = []
  openers = ["{","[","("]
  closers = ["}","]",")"]
  open_close_map = {
      "{" => "}",
      "[" => "]",
      "(" => ")"
  }
  s.each_char do |x|
    if openers.include?(x)
      brstack << x
    elsif closers.include?(x)
      if x == open_close_map[brstack[-1]]
        brstack.pop()
      else
        return "NO"
      end
    else
      # ignore this one
    end
  end
  if brstack.empty?
    return "YES"
  else
    return "NO"
  end
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

t = gets.to_i

t.times do |t_itr|
    s = gets.to_s.rstrip

    result = isBalanced s

    fptr.write result
    fptr.write "\n"
end

fptr.close()


