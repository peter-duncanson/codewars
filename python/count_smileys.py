def count_smileys(arr):
    x = 0
    valid = [':', ';', '-', '~', ')', 'D']
    for i in arr:
        if i[0] in valid[0:2]:
            if i[1] in valid[2:]:
                if len(i) == 2:
                    x += 1
                else:
                    if i[2] in valid[4:]:
                        x += 1
    return x
