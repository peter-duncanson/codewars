def make_readable(seconds):
    t = [0, 0, 0]
    for i in range(seconds):
        t[2] += 1
        if t[2] == 60:
            t[1] += 1
            t[2] -= 60
            if t[1] == 60:
                t[0] += 1
                t[1] -= 60
    t = list(map(str, t))
    t = [i if len(i) != 1 else '0' + i for i in t]
    return f'{t[0]}:{t[1]}:{t[2]}'
