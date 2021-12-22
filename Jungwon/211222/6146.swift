var a = Array(repeating: Array(repeating: 0, count: 1001), count: 1001)
var cnt = Array(repeating: Array(repeating: -1, count: 1001), count: 1001)
var start = (500, 500)
let input = readLine()!.split(separator: " ").map { Int(String($0))! }
var end = (input[0] + 500, input[1] + 500)
var n = input[2]
var pools = [(Int, Int)]()
var q = [(Int, Int)]()
var head = 0
var dir = [[-1, 0], [0, 1], [1, 0], [0, -1]]

for _ in 0..<n {
    let input = readLine()!.split(separator: " ").map { Int(String($0))! }
    a[input[0] + 500][input[1] + 500] = 1
}

cnt[start.0][start.1] = 0
q.append(start)
while head < q.count {
    let row = q[head].0
    let col = q[head].1
    head += 1
    if row == end.0 && col == end.1 {
        print(cnt[row][col])
        break
    }
    for i in 0..<4 {
        let newr = row + dir[i][0]
        let newc = col + dir[i][1]
        if newr < 0 || newr >= 1000 || newc < 0 || newc >= 1000 { continue }
        if a[newr][newc] == 1 || cnt[newr][newc] >= 0 { continue }
        cnt[newr][newc] = cnt[row][col] + 1
        q.append((newr, newc))
    }
}