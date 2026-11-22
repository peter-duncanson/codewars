def tower_builder(n_floors):
    array = []
    x = 1
    y = (n_floors - 1)
    for i in range(n_floors):
        array.append(y * ' ' + x * '*' + y * ' ')
        y -= 1
        x += 2
        n_floors -= 1
    return array

