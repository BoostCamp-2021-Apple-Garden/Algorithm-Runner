var input = readLine()!.split(separator: " ").map { Int(String($0))! }
let n = input[0]
let k = input[1]
let a = readLine()!.split(separator: " ").map { Int(String($0))! }
var d = Array(repeating: false, count: n)
d[0] = true
for i in 0..<n {
    for j in i+1..<n {
        if d[j] == true { continue }
        if d[i] == true && (j - i) * (1 + abs(a[i] - a[j])) <= k {
            d[j] = true
        }
    }
}
d[n-1] ? print("YES") : print("NO")