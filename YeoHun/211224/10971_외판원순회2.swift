import Foundation

let n = Int(readLine()!)!
var costs = [[Int]]()
var visited = Array(repeating: false, count: n + 1)
var answer = Int.max
for _ in 0..<n {
    costs.append(readLine()!.components(separatedBy: " ").map({ Int($0)! }))
}

func makePath(now: Int = 0, prev: Int = 0, path: [Int] = [0]) {
    var path = path
    if path.count == n {
        guard costs[now][0] != 0 else { return }
        var sum = 0
        var prevForCost = 0
        for path in path {
            sum += costs[prevForCost][path]
            prevForCost = path
        }
        answer = min(answer, sum + costs[now][0])
        return
    }
    
    for next in 1..<n {
        if !visited[next] && costs[now][next] != 0 {
            visited[next] = true
            path.append(next)
            makePath(now: next, prev: now, path: path)
            path.removeLast()
            visited[next] = false
        }
    }
}

visited[0] = true
makePath()
print(answer)

