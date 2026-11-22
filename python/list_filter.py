def filter_list(l):
    newlist = []
    for i in l:
        if i in range(0, 10000):
            newlist.append(i)
    return newlist
