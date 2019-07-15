#!/bin/ruby

require 'json'
require 'stringio'

# Complete the sherlockAndAnagrams function below.
def sherlockAndAnagrams(s)
  count = 0
  n = s.length
  # take string "abcde" of length 5
  # how many substrings of length 1? "a","b","c","d","e" => 5
  # how many substrings of length 2? "ab", "bc", "cd", "de" => 4
  # how many substrings of length 3? "abc", "bcd", "cde" => 3
  # how many substrings of length 4? "abcd", "bcde" => 2
  # how many substrings of length 5? "abcde" => 1 (not strictly a substring)
  # in general for string length n
  # how many substring of length k? n - k + 1
  grams = {}
  1.upto(n-1) do |k|
    0.upto(n-k) do |start|
      ss = s[start..start+k-1].chars.sort.join
      if grams[ss] == nil
        grams[ss]=1
      else
        grams[ss]+=1
      end  
    end
    # # p subs
    # 0.upto(n-k+1) do |i|
    #   (i+1).upto(n-k+1) do |j|
    #     if subs[i].chars.sort.join == subs[j].chars.sort.join
    #       count +=1
    #     end
    #   end
    # end
  end
  # p grams
  grams.each do |k, v|
    # how many unordered pairs can you make from v? (v choose 2) = v(v-1)/2
    count += v*(v-1)/2
  end
  return count
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

q = gets.to_i

q.times do |q_itr|
    s = gets.to_s.rstrip

    result = sherlockAndAnagrams s

    fptr.write result
    fptr.write "\n"
end

fptr.close()


