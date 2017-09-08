def triangle_numbers_less_than(n):
    x = 1
    s = 2
    while x < n:
        yield x
        x += s
        s += 1


def word_value(word):
    base = ord('A')
    return sum(ord(c)-base+1 for c in word)


with open('p042_words.txt') as f:
    content = f.readline()

words = content.split(',')
words = [word[1:-1] for word in words]

max_word_length = max(len(w) for w in words)
max_triangle_number = 26 * max_word_length

g = triangle_numbers_less_than(max_triangle_number + 1)
subset = set(g)

triangle_words = [word for word in words if word_value(word) in subset]
print len(triangle_words)
