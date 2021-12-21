import Foundation

func f(_ s: Int, _ t: Int) -> Int {
    var q = [(Int, Int, Int)]()
    var head = 0
    q.append((s, t, 0))
    while head < q.count {
        let a = q[head].0
        let b = q[head].1
        let cnt = q[head].2
        head += 1
        if a != 2 && a > b { continue }
        if a == b { return cnt }
        q.append((2 * a, b + 3, cnt + 1))
        q.append((a + 1, b, cnt + 1))
    }
    return 0
}

let c = Int(readLine()!)!
(0..<c).forEach { _ in
    let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
    let s = input[0]
    let t = input[1]
    let result = f(s, t)
    print(result)
}