import Foundation

let abbreviatedAddress = readLine()!.components(separatedBy: ":")

var groups = [String]()
for group in abbreviatedAddress {
    guard !group.isEmpty else {
        groups.append("")
        continue
    }
    var group = group
    while group.count != 4 {
        group = "0" + group
    }
    groups.append(group)
}

let ommitedCount = 8 - (groups.filter({ !$0.isEmpty }).count)
let ommitedZeros = ":" + Array(repeating: "0000", count: ommitedCount).joined(separator: ":") + ":"
var answer = groups.joined(separator: ":").replacingOccurrences(of: "::", with: ommitedZeros)

while answer.last == ":" {
    answer.removeLast()
}
while answer.first == ":" {
    answer.removeFirst()
}

print(answer)
