from operator import mul

numerators = []
denominators = []

def simplify(n, d):
    joint = set(str(n)) & set(str(d))
    if len(joint) == 2:
        return 0, 0, 0
    elif len(joint) == 1:
        for digit in joint:
            nontrivial = 0
            sn = int(str(n).replace(digit, '', 1))
            sd = int(str(d).replace(digit, '', 1))
            if str(n).index(digit) != str(d).index(digit):
                nontrivial = 1
        return sn, sd, nontrivial
    else:
        return n, d, 0
            
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b / gcd(a, b)
        
for n in xrange(10, 100):
    for d in xrange(n+1, 100):
        sn, sd, nt = simplify(n, d)
        if nt and n * sd == d * sn:
            print '{}/{}, {}/{}'.format(n, d, sn, sd)
            numerators.append(n)
            denominators.append(d)

rn = reduce(mul, numerators)
rd = reduce(mul, denominators)
g = gcd(rn, rd)
print rd / g
