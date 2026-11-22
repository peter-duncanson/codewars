def order(sentence):
    new = sentence.split()
    ordered = ''
    y = 1
    while y < len(new) + 1:
        for i in new:
            for x in i:
                if x == str(y):
                    ordered += i
                    if y != len(new):
                        ordered += ' '
                    y += 1
    return ordered
