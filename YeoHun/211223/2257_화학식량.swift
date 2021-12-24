import Foundation

let expression = readLine()!
var stack = [String]()
let dict = ["H": 1, "C": 12, "O": 16]

for now in expression {
    guard !stack.isEmpty else {
        if now == "(" {
            stack.append(String(now))
        } else {
            stack.append(String(dict[String(now)]!))
        }
        continue
    }
    if now == ")" {
        var sum = 0
        while !stack.isEmpty && stack.last! != "(" {
            sum += Int(stack.removeLast())!
        }
        stack.removeLast()
        stack.append(String(sum))
    } else if now.isNumber && Int(stack.last!) != nil {
        let num = Int(stack.removeLast())!
        stack.append(String(num * Int(String(now))!))
    } else {
        if now == "(" {
            stack.append(String(now))
        } else {
            stack.append(String(dict[String(now)]!))
        }
    }
}

print(stack.reduce(0, { $0 + Int($1)! }))

