def off(n):
    switched_off = []
    if n == 1:
        switched_off.append(n)
        return switched_off
    for i in range(1, n):
        if i ** 2 <= n:
            switched_off.append(i * i)
    return switched_off
