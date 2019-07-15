#!/bin/ruby

require 'json'
require 'stringio'

# Complete the countSwaps function below.
def countSwaps(a)
  # p a
  swaps = 0
  alen = a.length
  (alen-2).downto(0) do |h|
    sorted = true
    0.upto(h) do |i|
      if a[i] > a[i+1]
        a[i],a[i+1]=a[i+1],a[i]
        swaps +=1
        sorted = false
      end
    end
    break if sorted
  end

  puts "Array is sorted in #{swaps} swaps."
  puts "First Element: #{a[0]}"
  puts "Last Element: #{a[-1]}"
end

n = gets.to_i

a = gets.rstrip.split(' ').map(&:to_i)

countSwaps a


