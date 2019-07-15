#!/bin/ruby

require 'json'
require 'stringio'

# Complete the checkMagazine function below.
def checkMagazine(magazine, note)
  mdict = {}
  magazine.each do |w|
    if mdict[w] == nil
      mdict[w] = 1
    else
      mdict[w] +=1
    end
  end
  note.each do |x|
    if mdict[x] && mdict[x]>0
      mdict[x]-=1
    else
      puts "No"
      return
    end
  end
  puts "Yes"
end

mn = gets.rstrip.split

m = mn[0].to_i

n = mn[1].to_i

magazine = gets.rstrip.split(' ').map(&:to_s)

note = gets.rstrip.split(' ').map(&:to_s)

checkMagazine magazine, note


