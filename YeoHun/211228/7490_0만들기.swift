import Foundation

let testNum = Int(readLine()!)!
let operators: [String] = ["+", "-", " "]

func calculate(expression: String) -> Int {
    var expression = expression.replacingOccurrences(of: " ", with: "")
    var stack = [String]()
    while !expression.isEmpty {
        let now = expression.removeFirst()
        if operators.contains(String(now)) {
            let lhs = stack.removeLast()
            var rhs = ""
            
            while !expression.isEmpty && expression.first!.isNumber {
                rhs += String(expression.removeFirst())
            }
            if now == "+" {
                stack.append(String(Int(lhs)! + Int(rhs)!))
            } else {
                stack.append(String(Int(lhs)! - Int(rhs)!))
            }
        } else {
            if !stack.isEmpty {
                stack[stack.endIndex - 1].append(now)
            } else {
                stack.append(String(now))
            }
        }
    }
    return Int(stack.first!)!
}

var allAnswers = [String]()
for _ in 0..<testNum {
    let target = Int(readLine()!)!
    let numbers = (1...target).map({ $0 })
    var answers = [String]()
    func dfs(now: String, index: Int = 0) {
        if now.count == target * 2 - 1 {
            if calculate(expression: now) == 0 {
                answers.append("\(now)")
            }
            return
        }
        if index == numbers.count - 1 {
            dfs(now: now + String(numbers[index]), index: index + 1)
        } else {
            dfs(now: now + String(numbers[index]) + "+", index: index + 1)
            dfs(now: now + String(numbers[index]) + "-", index: index + 1)
            dfs(now: now + String(numbers[index]) + " ", index: index + 1)
        }
    }
    dfs(now: "")
    allAnswers.append(answers.sorted(by: <).joined(separator: "\n"))
}

print(allAnswers.joined(separator: "\n\n"))
