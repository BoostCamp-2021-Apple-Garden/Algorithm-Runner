import Foundation

var answer = -1
func makePermutation(from data: [Character], permutation: [Character] = [], visited: [Bool], target: Int) {
    var permutation = permutation
    var visited = visited
    if !permutation.isEmpty && permutation.first! == "0" {
        return
    }
    if permutation.count == data.count {
        let c = Int(String(permutation))!
        guard c < target else { return }
        answer = max(answer, c)
        return
    }
    
    for i in 0..<data.count {
        if !visited[i] {
            visited[i] = true
            permutation.append(data[i])
            makePermutation(from: data, permutation: permutation, visited: visited, target: target)
            permutation.removeLast()
            visited[i] = false
        }
    }
}

func solution() {
    let ab = readLine()!.components(separatedBy: " ")
    let a = Array(ab.first!)
    let b = Int(ab.last!)!
    makePermutation(from: a, visited: Array(repeating: false, count: a.count), target: b)
}

solution()
print(answer)
