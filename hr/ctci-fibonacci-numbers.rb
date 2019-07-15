$fib = []
$fib[0]=0
$fib[1]=1
$fib[2]=1
def fibonacci(n)
  return $fib[n] if $fib[n]
  ans = fibonacci(n-1) + fibonacci(n-2)
  # memoize
  $fib[n] = ans
  return ans
end

n = gets.to_i
print(fibonacci(n))


