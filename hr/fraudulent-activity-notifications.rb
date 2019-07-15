#!/bin/ruby

require 'json'
require 'stringio'

# Complete the activityNotifications function below.
def activityNotifications(expenditure, d)
  notify_count = 0
  n = expenditure.length
  window = expenditure[0..d-1].sort
  d.upto(n-1) do |i|
    if d%2 == 1
      med = window[d/2]
    else
      med = (window[d/2]+window[(d/2)-1])/2.0
    end
    current = expenditure[i]
    if current >= 2*med
      notify_count +=1
    end
    # remove item from d days ago
    togo = expenditure[i-d]
    # using binary search
    lower = 0
    upper = d-1
    while (upper > lower) do
      if window[(upper+lower)/2] > togo
        upper = (upper+lower)/2
      elsif window[(upper+lower)/2] < togo
        lower = (upper+lower)/2
      else
        found = (upper+lower)/2
        break
      end
    end
    window.delete_at(found)
    # insert current item
    # using binary search
    lower = 0
    upper = d-2
    while (upper - lower > 1) do
      if window[(upper+lower)/2] > current
        upper = (upper+lower)/2
      else
        lower = (upper+lower)/2
      end
    end
    if current >= window[lower] && current < window[upper]
       window.insert(lower,current)
    elsif current == window[upper]
       window.insert(upper,current)
    else
       window << current
    end
  end
  return notify_count
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

nd = gets.rstrip.split

n = nd[0].to_i

d = nd[1].to_i

expenditure = gets.rstrip.split(' ').map(&:to_i)

result = activityNotifications expenditure, d

fptr.write result
fptr.write "\n"

fptr.close()


