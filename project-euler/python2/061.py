from operator import mul
from itertools import permutations

def triangle(n):
   return n * (n+1) / 2

def square(n):
   return n * n

def pentagonal(n):
   return n * (3*n - 1) / 2

def hexagonal(n):
   return n * (2*n - 1)

def heptagonal(n):
   return n * (5*n - 3) / 2

def octagonal(n):
   return n * (3*n - 2)

def polygonal(formula, low, high):
   if low >= high:
      return
   n = 1
   while True:
      x = formula(n)
      if x >= high:
         break
      if x >= low:
         yield x
      n += 1

low = 1000
high = 10000
fmls = [triangle, square, pentagonal, hexagonal, heptagonal, octagonal]
nums = [list(polygonal(fml, low, high)) for fml in fmls]

def search(cycles, curr, nums):
    if curr == len(fmls):
        if str(cycles[-1])[-2:] == str(cycles[0])[:2]:
            print cycles, sum(cycles)
        return
    for n in nums[curr]:
        if cycles:
            m = cycles[-1]
            if str(m)[-2:] == str(n)[:2]:
                cycles.append(n)
                search(cycles, curr+1, nums)
                cycles.pop()
        else:
            cycles.append(n)
            search(cycles, curr+1, nums)
            cycles.pop()

for nums_ in permutations(nums):
    search([], 0, nums_)
