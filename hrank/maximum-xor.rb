#!/bin/ruby

require 'json'
require 'stringio'

class TrieNode
  attr_accessor :left, :right
  def initialize
    @left = nil
    @right = nil
  end
end

# Complete the maxXor function below.
def maxXor(arr, queries)
    # solve here
    # build a trie with each element of arr as leaf
    # binary tree left = "0", right = "1"
    # 30 levels
    trie_root = TrieNode.new
    arr.each do |x|
      p = trie_root
      xb = '%030b' % x
      xb.each_char do |bit|
        if bit == "0"
          # go left
          if p.left
            p = p.left
          else
            nn = TrieNode.new
            p.left = nn
            p = p.left
          end
        else
          # go right
          if p.right
            p = p.right
          else
            nn = TrieNode.new
            p.right = nn
            p = p.right
          end
        end
      end
    end
    ans_seq = []
    queries.each do |q|
      # walk down the trie to leaf
      leaf = ""
      p = trie_root
      qb = '%030b' % q
      qb.each_char do |bit|
        # prefer opposite of bit
        if bit == "0"
          # try go right ("1")
          if p.right
            p = p.right
            leaf << "1"
          else
            p = p.left
            leaf << "0" 
          end
        else
          # try to go left ("0")
          if p.left
            p = p.left
            leaf << "0"
          else
            p = p.right
            leaf << "1"
          end
        end
      end
      a = leaf.to_i(2)
      ans_seq << (a^q)
    end
    return ans_seq
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

arr = gets.rstrip.split(' ').map(&:to_i)

m = gets.to_i

queries = Array.new(m)

m.times do |i|
    queries_item = gets.to_i
    queries[i] = queries_item
end

result = maxXor arr, queries

fptr.write result.join "\n"
fptr.write "\n"

fptr.close()

