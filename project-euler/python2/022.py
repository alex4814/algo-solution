def name_score(name):
    return sum(ord(c) - ord('A') + 1 for c in name)

with open('p022_names.txt') as f:
    names = f.read().split(',')
    names = [name.strip('"') for name in names]
    names.sort()

print sum((i+1) * name_score(name) for i, name in enumerate(names))
