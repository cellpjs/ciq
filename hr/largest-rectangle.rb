#!/bin/ruby

require 'json'
require 'stringio'

# Complete the largestRectangle function below.
def largestRectangle(h)
  p h
  max_area = 0
  n = h.length
  # running height streaks with starting index
  running = []
  h.each_with_index do |x,i|
    istart = i
    while running[-1] && x < running[-1][0]
      # running streak ended in previous building
      s = running.pop
      height = s[0]
      length = i - s[1]
      # (i-1) - s[1] + 1
      istart = s[1]
      area = height*length
      max_area = area if area > max_area
    end
    # begin a new streak
    running.push([h[i],istart])
  end
  # running streaks that lasted until the end
  running.each do |s|
    height = s[0]
    length = n - s[1]
    area = height*length
    max_area = area if area > max_area
  end
  return max_area
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

h = gets.rstrip.split(' ').map(&:to_i)

result = largestRectangle h

fptr.write result
fptr.write "\n"

fptr.close()


