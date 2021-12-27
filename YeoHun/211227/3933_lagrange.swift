import Foundation

var tests = [Int]()
var maxNum = 0
while true {
    let target = Int(readLine()!)!
    guard target != 0  else { break }
    maxNum = max(maxNum, target)
    tests.append(target)
}

var answers = Array(repeating: 0, count: maxNum + 1)

let maxCandidate = Int(sqrt(Double(maxNum)))
for first in 1...maxCandidate {
    let firstSquare = first * first
    guard firstSquare <= maxNum else { break }
    answers[firstSquare] += 1
    for second in first...maxCandidate {
        let secondSquare = second * second
        guard firstSquare + secondSquare <= maxNum else { break }
        answers[firstSquare + secondSquare] += 1
        for third in second...maxCandidate {
            let thirdSquare = third * third
            guard firstSquare + secondSquare + thirdSquare <= maxNum else { break }
            answers[firstSquare + secondSquare + thirdSquare] += 1
            for fourth in third...maxCandidate {
                let fourthSquare = fourth * fourth
                guard firstSquare + secondSquare + thirdSquare + fourthSquare <= maxNum else { break }
                answers[firstSquare + secondSquare + thirdSquare + fourthSquare] += 1
            }
        }
    }
}

for test in tests {
    print(answers[test])
}

