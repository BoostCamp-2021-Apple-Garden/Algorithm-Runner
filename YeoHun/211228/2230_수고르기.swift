import Foundation

let nm = readLine()!.components(separatedBy: " ").map({ Int($0)! })

var numbers = [Int]()
for _ in 0..<nm[0] {
    numbers.append(Int(readLine()!)!)
}

numbers = numbers.sorted(by: <)
var start = 0
var end = 0

var answer = Int.max
while start <= end && end != numbers.endIndex {
    let diff = numbers[end] - numbers[start]
    if diff >= nm[1] {
        answer = min(answer, diff)
        start += 1
    } else {
        end += 1
    }
}

print(answer)
