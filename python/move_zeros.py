def move_zeros(array):
    for i in array:
        if i == 0:
            array.remove(i)
            array.append(i)
    return array
