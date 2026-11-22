def digital_root(n):
    while True:
        if n < 10:
            return n
        else:
            n = list(map(int,str(n)))
            n = sum(n)
