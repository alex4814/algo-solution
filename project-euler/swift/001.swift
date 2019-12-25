func sumOfAllMultiplesOfThreeAndFive(below upper: Int) -> Int {
  var sum = 0
  for n in 1..<upper {
    if n % 3 == 0 || n % 5 == 0 {
      sum += n
    }
  }
  return sum
}

print(sumOfAllMultiplesOfThreeAndFive(below: 1000))
