# CS2021 
# lab03.py
# Q1
def skip_add(n):
    """ Takes a number x and returns x + x-2 + x-4 + x-6 + ... + 0.

    >>> skip_add(5)  # 5 + 3 + 1 + 0
    9
    >>> skip_add(10) # 10 + 8 + 6 + 4 + 2 + 0
    30
    """
    if n <= 0:
        return 0
    return n + skip_add(n - 2)


# Q6
def gcd(a, b):
    """Returns the greatest common divisor of a and b.
    Should be implemented using recursion.

    >>> gcd(34, 19)
    1
    >>> gcd(39, 91)
    13
    >>> gcd(20, 30)
    10
    >>> gcd(40, 40)
    40
    """
    if a % b == 0:
        return min(a, b)
    else:
        return gcd(min(a, b), max(a, b) % min(a, b))
        


# Q7
def hailstone(n):
    """Print out the hailstone sequence starting at n, and return the
    number of elements in the sequence.

    >>> a = hailstone(10)
    10
    5
    16
    8
    4
    2
    1
    >>> a
    7
    """
    print(n)
    if n == 1:
        return 1
    elif n % 2 == 0:
        return 1 + hailstone(n // 2)
    else:
        return 1 + hailstone(n * 3 + 1)


# Q8
def fibonacci(n):
    """Return the nth fibonacci number.

    >>> fibonacci(11)
    89
    >>> fibonacci(5)
    5
    >>> fibonacci(0)
    0
    >>> fibonacci(1)
    1
    """
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)


# Q9
def paths(m, n):
    """Return the number of paths from one corner of an
    M by N grid to the opposite corner.

    >>> paths(2, 2)
    2
    >>> paths(5, 7)
    210
    >>> paths(117, 1)
    1
    >>> paths(1, 157)
    1"""
    
    def factcombo(a):
        if a == 0:
            return 1
        else:
            return a * factcombo(a-1)
    if n <= 1 or m <= 1:
        return 1
    else:
        return factcombo((m-1) + (n-1)) // factcombo(m-1) // factcombo(n-1)


# Q10
def count_vals(nlst):
    """Returns the number of values in the nested list.

    >>> count_vals([1, 2, 3])     # normal list
    3
    >>> x = [1, [2, 3], 4]      # nested list
    >>> count_vals(x)
    4
    >>> x = [[1, [1, 1]], 1, [1, 1]] 
    >>> count_vals(x)
    6
    """
    if type(nlst) is not list:
        return 1
    num = 0
    for i in nlst:
        num += count_vals(i)
    return num


# Q11
def flatten(lst):
    """Returns a flattened version of lst.

    >>> flatten([1, 2, 3]) 
    [1, 2, 3]
    >>> x = [1, [2, 3], 4]      
    >>> flatten(x)
    [1, 2, 3, 4]
    >>> x = [[1, [1, 1]], 1, [1, 1]] 
    >>> flatten(x)
    [1, 1, 1, 1, 1, 1]
    """
    if type(lst) is not list:
        return [lst]
    ret = []
    for i in lst:
        ret += flatten(i)
    return ret


