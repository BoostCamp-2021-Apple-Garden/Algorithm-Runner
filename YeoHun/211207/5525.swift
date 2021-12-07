import Foundation

let N = readLine()!.components(separatedBy: " ").map{ Int($0)!}.first!
let M = readLine()!.components(separatedBy: " ").map{ Int($0)!}.first!
let S = readLine()!

let targetString = Array(S)
var answer = 0
var n = 0
var contFlag = false

for i in 0..<S.count - 3 {
    if contFlag == true {
        contFlag = false
        continue
    }
    let subString = String(targetString[i..<i+3])
    if subString == "IOI" {
        n += 1
        if n == N {
            answer += 1
            n -= 1
        }
        contFlag = true
    } else {
        n = 0
    }
}

print(answer)
