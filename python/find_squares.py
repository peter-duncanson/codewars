def find_squares(num):
    x = 3
    for i in range(2, 1000000):
        if i * i + num == x * x:
            return f"{x * x}-{i * i}"
        else:
            x += 1
