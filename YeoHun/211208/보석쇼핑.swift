import Foundation

func solution(_ gems:[String]) -> [Int] {
    let uniqueGems:Set<String> = Set(gems)
    var currentGems:[String:Int] = [:]
    
    var start = 0
    var end = 0
    var answer:(start:Int, end:Int) = (start, end)
    var minDist = 987654321
    currentGems.updateValue((currentGems[gems[start]] ?? 0) + 1, forKey: gems[start])
    while end < gems.count {
        if currentGems.count == uniqueGems.count {
            if minDist > end-start {
                answer = (start, end)
                minDist = end - start
            }
            currentGems[gems[start]]! -= 1
            if currentGems[gems[start]]! == 0 {
                currentGems.removeValue(forKey: gems[start])
            }
            start += 1
        } else {
            end += 1
            if end == gems.count { break }
            currentGems.updateValue((currentGems[gems[end]] ?? 0) + 1, forKey: gems[end])
        }
    }
    
    return [answer.start + 1, answer.end + 1]
}
