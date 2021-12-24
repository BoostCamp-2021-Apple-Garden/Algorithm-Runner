import Foundation

let n = Int(readLine()!)!
var usedAlphabet = Set<String>()

for _ in 0..<n {
    let words = readLine()!.components(separatedBy: " ")
    
    var line = [String]()
    var flag = false
    for word in words {
        if flag == false && !usedAlphabet.contains(word.first!.uppercased()) {
            usedAlphabet.insert(word.first!.uppercased())
            line.append("[\(word.first!)]\(String(word.suffix(word.count - 1)))")
            flag = true
        } else {
            line.append(word)
        }
    }
    if !flag {
        var newLine = ""
        let chars = line.joined(separator: " ")
        for (index, char) in chars.enumerated() {
            if char != " " && !usedAlphabet.contains(String(char).uppercased()) {
                usedAlphabet.insert(String(char).uppercased())
                newLine.append("[\(char)]\(String(Array(chars)[(index+1)...]))")
                break
            } else {
                newLine.append(char)
            }
        }
        print(newLine)
    } else {
        print(line.joined(separator: " "))
    }
}
