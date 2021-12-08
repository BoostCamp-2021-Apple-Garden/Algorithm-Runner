import Foundation

let numOfCars = Int(readLine()!)!
var orderDict = [String: [String]]()

for _ in 0..<numOfCars {
    let car = readLine()!
    for key in orderDict.keys {
        orderDict[key]?.append(car)
    }
    orderDict[car] = []
}

var outSet = Set<String>()
var overSet = Set<String>()

for _ in 0..<numOfCars {
    let car = readLine()!
    outSet.insert(car)
    for priorCar in orderDict[car]! {
        if outSet.contains(priorCar) {
            overSet.insert(priorCar)
        }
    }
}

print(overSet.count)

// 다른 사람의 좋은 풀이
import Foundation

let numOfCars = Int(readLine()!)!
var orderDict = [String: Int]()

for order in 1...numOfCars {
    let car = readLine()!
    orderDict[car, default: 0] = order
}

var answer = 0
var visited = Array(repeating: false, count: numOfCars + 1)
visited[0] = true

for _ in 0..<numOfCars {
    let car = readLine()!
    for i in 0..<orderDict[car]! {
        if !visited[i] {
            answer += 1
            break
        }
    }
    visited[orderDict[car]!] = true
}

print(answer)
