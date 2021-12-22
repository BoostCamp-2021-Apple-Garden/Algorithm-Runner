import Foundation

let xyn = readLine()!.components(separatedBy: " ").map({ Int($0)! })
let destinationCol = xyn[0]
let destinationRow = xyn[1]
let n = xyn[2]

var coordSet = Set<[Int]>()
var visited = Set<[Int]>()
for _ in 0..<n {
    let water = readLine()!.components(separatedBy: " ").map({ Int($0)! })
    coordSet.insert([water[1], water[0]])
}

func bfs() {
    var queue = [([0, 0], 0)]
    let rowDir = [0, 0, 1, -1]
    let colDir = [1, -1, 0, 0]
    
    while !queue.isEmpty {
        let now = queue.removeFirst()
        let nowRow = now.0[0]
        let nowCol = now.0[1]
        let depth = now.1
        
        if nowRow == destinationRow && nowCol == destinationCol {
            print(depth)
            return
        }
        
        for (nextRowMove, nextColMove) in zip(rowDir, colDir) {
            let nextRow = nowRow + nextRowMove
            let nextCol = nowCol + nextColMove
            
            if !visited.contains([nextRow, nextCol]) && !coordSet.contains([nextRow, nextCol]) {
                visited.insert([nextRow, nextCol])
                queue.append(([nextRow, nextCol], depth + 1))
            }
        }
    }
}

bfs()
