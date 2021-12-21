var q = [(Int, Int, Int)]()
var head = 0
var visited = Array(repeating: Array(repeating: false, count: 1050), count: 1050)
let s = Int(readLine()!)!

q.append((1, 0, 0))
while head < q.count {
    let num = q[head].0
    let time = q[head].1
    let clipBoard = q[head].2
    head += 1
    if num == s {
        print(time)
        break
    }
    if visited[num][num] == false {
        visited[num][num] = true
        q.append((num, time + 1, num))
    }
    var newNum = num + clipBoard
    if clipBoard > 0 && newNum <= s + 1 && visited[newNum][clipBoard] == false {
        visited[newNum][clipBoard] = true
        q.append((newNum, time + 1, clipBoard))
    }
    newNum = num - 1
    if newNum > 0 && visited[newNum][clipBoard] == false {
        visited[newNum][clipBoard] = true
        q.append((newNum, time + 1, clipBoard))
    }
}