# Enter your code here. Read input from STDIN. Print output to STDOUT
def distance_to_others(n, neighbors, start)
  # Why BFS?
  queue = []
  visited = []
  backtrace = {}
  queue << start
  while !(queue.empty?)
    current = queue.shift
    visited << current
    if neighbors[current] == nil
      neighbors[current] = []
    end
    neighbors[current].each do |x|
      if !(visited.include?(x)) && !(queue.include?(x))
        queue << x
        backtrace[x] = current
      end
    end
  end
  output = []
  1.upto(n) do |i|
    next if i == start
    # backtrace to find distance
    if visited.include?(i)
      tracer = i
      distance = 0
      while (tracer!=start)
        tracer = backtrace[tracer]
        distance +=6
      end
    else
      distance = -1
    end
    output << distance
  end
  puts output.join(" ")
end

q = gets.strip.to_i
q.times do
  n, m = gets.strip.split(' ').map(&:to_i)
  neighbors = {}
  m.times do
    u, v = gets.strip.split(' ').map(&:to_i)
    if neighbors[u] == nil
      neighbors[u] = [v]
    else
      neighbors[u] << v
    end
    if neighbors[v] == nil
      neighbors[v] = [u]
    else
      neighbors[v] << u
    end 
  end
  start = gets.strip.to_i
  distance_to_others(n, neighbors, start)
end


