def tribonacci(signature, n):
    if n == 0:
        return []
    elif n == 1:
        return [signature[0]]
    elif n == 2:
        return signature[0:n]
    elif n != 0:
        while n > 3:
            signature.append(sum(signature[-3:]))
            n -= 1
        return signature
