def all_equal(iterator):
    iterator = iter(iterator)
    try:
        first = next(iterator)
    except StopIteration:
        return True
    return all(first == rest for rest in iterator)

def same_digits(arr):
    digits = [sorted(str(a)) for a in arr]
    return all_equal(digits)

x = 1
while True:
    a = [x*i for i in xrange(1, 7)]
    if same_digits(a):
        break
    x += 1
print a
