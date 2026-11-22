def sqInRect(l, w):
    ans = []
    t = l * w
    if l == w:
        return None
    if w > l:
        saver = w
        w = l
        l = saver
    while t > 0:
        try:
            for i in range(int(l/w)):
                ans.append(w)
                l -= w
                t -= w**2
            for i in range(int(w/l)):
                ans.append(l)
                w -= l
                t -= l**2
        except: ZeroDivisionError
    return ans
