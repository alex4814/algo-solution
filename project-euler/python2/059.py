from itertools import cycle
import string

def parse(x, n):
    pwd = []
    for i in xrange(n):
        pwd.append(x % 26 + ord('a'))
        x /= 26
    return pwd

def password(n):
    for x in xrange(26**n):
        yield parse(x, n)

with open('p059_cipher.txt') as f:
    cipher_text = f.read()
    cipher_text = cipher_text[:-1].split(',')
    cipher_text = [int(c) for c in cipher_text]

printset = set(string.printable)
# Check https://en.wikipedia.org/wiki/Most_common_words_in_English
common_words = [
   'the', 'be', 'to', 'of', 'and', 'a', 'in', 'that', 'have', 'I'
]

for pwd in password(3):
    plain_text = []
    found = True
    for c, p in zip(cipher_text, cycle(pwd)):
        t = chr(c ^ p)
        if t not in printset:
            found = False
            break
        plain_text.append(t)
    if not found:
        continue
    text = ''.join(plain_text)
    n = sum(1 for w in common_words if w in text)
    if n > 8:
        break

print 'Try password', pwd
print text
print 'Sum of ASCII values', sum(ord(c) for c in plain_text)

