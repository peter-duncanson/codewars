def pig_it(text):
    split = text.split()
    latin = ''
    punctuation = False
    for i in split:
        latin += i[1:] + i[0] + 'ay' + ' '
        if i == '?':
            punctuation = True
        elif i == '!':
            punctuation = True
    if not punctuation:
        return latin[0:-1]
    else:
        return latin[0:-3]
