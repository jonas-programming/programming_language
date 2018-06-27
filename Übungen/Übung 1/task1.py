def rek_sum(n):
    """ Recursive sum to n """
    return (rek_sum(n - 1) + n) if n > 1 else 0 if n<=0 or not isinstance(n, int) else 1


def it_sum(n):
    """ Iterative sum to n """
    if not isinstance(n, int):
        return 0
    sum_ = 0
    for i in range(n+1):
        sum_ += i
    return sum_

    """ Same would be:
        sum(range(n+1)) """


def rek_product(n):
    """ Recursive product of numbers to n """
    return (rek_product(n - 1) * n) if n > 1 else 0 if n <= 0 or not isinstance(n, int) else 1


def it_product(n):
    """ Iterative product of numbers to n """
    if not isinstance(n, int):
        return 0
    prod = 0 if n <= 0 else 1
    for i in range(2, n+1):
        prod *= i
    return prod


def rek_fibo(n):
    """ Recursive Fibonacci """
    if not isinstance(n, int) or n < 0:
        return 0
    return rek_fibo(n - 1) + rek_fibo(n - 2) if n > 1 else n


def it_fibo(n):
    """ Iterative Fibonacci """
    if not isinstance(n, int):
        return 0
    a, b = 0, 1
    for i in range(2, n + 1):
        a, b = b, a + b
    return b if n>0 else 0

print(it_sum(10))
print(rek_sum(10))
print(it_product(10))
print(rek_product(10))
print(it_fibo(10))
print(rek_fibo(10))
