func sumOfEvenValuedTermOfFibonacci(notExceed upper: Int) -> Int {
  var a = 1, b = 1, c = 1
  var sum = 0
  while c <= upper {
    if c & 1 == 0 {
      sum += c
    }
    a = b
    b = c
    c = a + b
  }
  return sum
}

print(sumOfEvenValuedTermOfFibonacci(notExceed: 4000000))
