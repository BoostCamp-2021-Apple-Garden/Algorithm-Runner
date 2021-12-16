import Foundation

func solution(_ a:[Int], _ b:[Int]) -> Int {
    var sortedB = b.sorted(by: <)
    let sortedA = a.sorted(by: <)
    
    func binarySearch(target: Int) -> Int {
        var low = 0
        var high = sortedB.count - 1
        while low < high {
            let mid = (low + high) / 2
            if sortedB[mid] > target {
                high = mid
            } else {
                low = mid + 1
            }
        }
        return low
    }
    
    var answer = 0
    for card in sortedA {
        let removed = sortedB.remove(at: binarySearch(target: card))
        if card < removed {
            answer += 1
        }
    }
    
    return answer
}