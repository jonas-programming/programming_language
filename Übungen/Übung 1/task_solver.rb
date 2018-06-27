def it_sum (n)
  sum = 0
  (1..n).each do |i|
    sum += i
  end
  sum
end

def rek_sum (n)
  if n <= 0
    return 0
  end
  if n == 1
    return 1
  end
  n + rek_sum(n - 1)
end

def it_product (n)
  product = n <= 0 ? 0 : 1
  (2..n).each do |i|
    product *= i
  end
  product
end

def rek_product (n)
  if n <= 0
    return 0
  end
  if n <= 2
    return 2
  end
  n * rek_product(n - 1)
end

def it_fibo (n)
  a, b = 0, 1
  (2..n).each do |i|
    a, b = b, a + b
  end
  (n <= 0) ? 0 : b
end

def rek_fibo(n)
  if n < 0
    return 0
  end
  if n < 2
    return n
  end
  rek_fibo(n - 1) + rek_fibo(n - 2)
end

puts it_sum 10
puts rek_sum 10

puts it_product 10
puts rek_product 10

puts it_fibo 10
puts rek_fibo 10