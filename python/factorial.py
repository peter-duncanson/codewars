def factorial(n):
    if n < 0 or n > 12:
        raise ValueError
    f = 1
    for i in range(0, n):
        f += f * i
    return f
