#!/bin/ruby

require 'json'
require 'stringio'

# Complete the countInversions function below.
def countInversions(arr)
  p arr
  # merge sort and count swaps
  # is the number of swaps in merge sort minimal?
  # not necessarily
  # but looks like that's what this problem is looking for
  swap_counter = mergeSort(arr)
  p arr
  return swap_counter
end

def mergeSort(arr)
  n = arr.length
  return 0 if n==1
  left = arr[0..n/2-1]
  right = arr[n/2..n-1]
  counter = mergeSort(left) + mergeSort(right)
  # the merge
  i = j = k = 0
  while (i <= left.length-1 || j <= right.length-1)
    if i > left.length-1
      arr[k] = right[j]
      j+=1
    elsif j > right.length-1
      arr[k] = left[i]
      i+=1
    elsif left[i] <= right[j]
      arr[k] = left[i]
      i+=1
    else
      arr[k] = right[j]
      j+=1
      counter+=(left.length - i)
    end
    k+=1
  end
  return counter
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

t = gets.to_i

t.times do |t_itr|
    n = gets.to_i

    arr = gets.rstrip.split(' ').map(&:to_i)

    result = countInversions arr

    fptr.write result
    fptr.write "\n"
end

fptr.close()


