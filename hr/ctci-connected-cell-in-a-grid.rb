#!/bin/ruby

require 'json'
require 'stringio'

# Complete the maxRegion function below.
def visitor(i,j,n,m,grid,visited)
  if (i<0 || i>n-1 || j<0 || j>m-1 || grid[i][j]==0 || visited[i][j])
    return 0
  else visited[i][j] = true
    score = 1
    score += visitor(i-1,j-1,n,m,grid,visited)
    score += visitor(i-1,j,n,m,grid,visited)
    score += visitor(i-1,j+1,n,m,grid,visited)
    score += visitor(i,j-1,n,m,grid,visited)
    score += visitor(i,j+1,n,m,grid,visited)
    score += visitor(i+1,j-1,n,m,grid,visited)
    score += visitor(i+1,j,n,m,grid,visited)
    score += visitor(i+1,j+1,n,m,grid,visited)
    return score
  end
end

def maxRegion(grid)
  # p grid
  mxr = 0
  n = grid.length
  m = grid[0].length
  # puts "#{n} x #{m}"
  visited = []
  0.upto(n-1) do |i|
    visited[i] = []
    0.upto(m-1) do |j|
      visited[i][j] = false
    end
  end
  # p visited
  0.upto(n-1) do |i|
    0.upto(m-1) do |j|
      r = visitor(i,j,n,m,grid,visited)
      mxr = r if r > mxr
    end
  end
  return mxr
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

m = gets.to_i

grid = Array.new(n)

n.times do |i|
    grid[i] = gets.rstrip.split(' ').map(&:to_i)
end

res = maxRegion grid

fptr.write res
fptr.write "\n"

fptr.close()


