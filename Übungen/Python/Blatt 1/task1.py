def rek_sum(n):
    """ Recursive sum to n"""
    return (rek_sum(n - 1) + n) if n > 0 else 0


def it_sum(n):
    """ Iterative sum to n"""
    sum_ = 0
    for i in range(n):
        sum_ += n
    return sum_


def rek_product(n):
    """ Recursive product of numbers to n"""
    return (rek_sum(n - 1) * n) if n > 1 else 1


def it_product(n):
    """ Iterative product of numbers to n"""
    prod = 1
    for i in range(n):
        prod += n
    return prod


def rek_fibo(n):
    """ Recursive Fibonacci """
    return rek_fibo(n - 1) + rek_fibo(n - 2) if n > 1 else n


def it_fibo(n):
    """ Iterative Fibonacci """
    a, b = 0, 1
    for i in range(2, n + 1):
        a, b = b, a + b
    return b
