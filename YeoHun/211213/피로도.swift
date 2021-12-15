import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer = 0
    var visited = Array(repeating: false, count: dungeons.count + 1)
    var permutations = [[[Int]]]()
    func makePermutaion(perm: [[Int]]){
        var perm = perm
        if perm.count == dungeons.count {
            permutations.append(perm)
            return
        }
        
        for i in 0..<dungeons.count {
            if !visited[i] {
                visited[i] = true
                perm.append(dungeons[i])
                makePermutaion(perm: perm)
                _ = perm.popLast()
                visited[i] = false
            }
        }
    }
    makePermutaion(perm: [])
    
    for permutation in permutations {
        var currentK = k
        var dungeonCount = 0
        for dungeon in permutation {
            if dungeon[0] <= currentK {
                dungeonCount += 1
                currentK -= dungeon[1]
                if currentK < 0 {
                    break
                }
            }
        }
        answer = max(answer, dungeonCount)
    }
    
    return answer
}

print(solution(80, [[80,20],[50,40],[30,10]]))
