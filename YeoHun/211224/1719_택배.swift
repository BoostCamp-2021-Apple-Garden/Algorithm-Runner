import Foundation

let nm = readLine()!.components(separatedBy: " ").map({ Int($0)! })
let n = nm[0]
let m = nm[1]

var costs = Array(repeating: Array(repeating: 500000, count: n), count: n)
var paths = Array(repeating: Array(repeating: "-", count: n), count: n)
for _ in 0..<m {
    let input = readLine()!.components(separatedBy: " ").map({ Int($0)! })
    costs[input[0]-1][input[1]-1] = input[2]
    costs[input[1]-1][input[0]-1] = input[2]
    paths[input[0]-1][input[1]-1] = String(input[1])
    paths[input[1]-1][input[0]-1] = String(input[0])
}

for mid in 0..<n {
    for here in 0..<n {
        for there in 0..<n {
            if here == there { costs[here][there] = 0 }
            if costs[here][mid] + costs[mid][there] < costs[here][there] {
                costs[here][there] = costs[here][mid] + costs[mid][there]
                paths[here][there] = paths[here][mid]
            }
            
        }
    }
}
print(paths.map( { $0.joined(separator: " ") } ).joined(separator: "\n"))


