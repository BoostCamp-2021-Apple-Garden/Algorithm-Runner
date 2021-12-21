import Foundation

func bfs(a: Int, b: Int) -> Int {
    var q = [(a, b, 0)]
    while !(q.isEmpty) {
        let current = q.removeFirst()
        let s = current.0
        let t = current.1
        let c = current.2
        
        if s <= t {
            q.append((s*2, t+3, c+1))
            q.append((s+1,t,c+1))
            if s == t{ return c }
        }
    }
    return 0
}

let n = Int(readLine()!)!
for _ in 0..<n {
    let result = readLine()!.split(separator: " ").map { Int(String($0))! }
    let S = result[0]
    let T = result[1]
    print(bfs(a: S, b: T))
}
