def is_valid_walk(walk):
    minutes = 0
    xy = [0, 0]
    for i in walk:
        minutes += 1
        if i == 'n':
            xy[1] += 1
        elif i == 's':
            xy[1] -= 1
        elif i == 'e':
            xy[0] += 1
        elif i == 'w':
            xy[0] -= 1
    if minutes != 10:
        return False
    if xy == [0,0]:
        return True
    else:
        return False
