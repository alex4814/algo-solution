from itertools import permutations


def all_equal(iterator):
    iterator = iter(iterator)
    try:
        first = next(iterator)
    except StopIteration:
        return True
    return all(first == rest for rest in iterator)


def numeric_lowest(p):
    return all(p[0] < p[i] for i in xrange(1, len(p)))


nodes = tuple(range(1, 11))
n = len(nodes)
solutions = []
for p in permutations(nodes, n/2):
    if not numeric_lowest(p):
        continue
    d = set(nodes) - set(p)
    for q in permutations(d):
        r = q[1:] + q[:1]
        total = [sum(x) for x in zip(p, q, r)]
        if all_equal(total):
            solutions.append(zip(p, q, r))

cats = []
for s in solutions:
    y = ''.join(''.join(map(str, x)) for x in s)
    print 'solution {}, concatenation {}'.format(s, y)
    cats.append(y)

cats = [c for c in cats if len(c) == 16]
print sorted(cats)

