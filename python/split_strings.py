def solution(s):
    if len(s) % 2 != 0:
        s += '_'
    x = int((len(s) / 2))
    y = 0
    n = 2
    ls = []
    for i in range(0, x):
        ls.append(s[y:n])
        y += 2
        n += 2
    return ls
