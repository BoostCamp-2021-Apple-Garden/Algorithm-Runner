import Foundation

let t = Int(readLine()!)!

func checkPalindrome(target: [Character], start: Int, end: Int, isDeleted: Bool) -> (isPalineDrome: Bool, isDeleted: Bool) {
    var start = start
    var end = end
    while start <= end {
        guard target[start] != target[end] else {
            start += 1
            end -= 1
            continue
        }
        if !isDeleted {
            return (checkPalindrome(target: target, start: start+1, end: end, isDeleted: true).isPalineDrome
                    || checkPalindrome(target: target, start: start, end: end-1, isDeleted: true).isPalineDrome, true)
        } else {
            return (false, isDeleted)
        }
    }
    return (true, isDeleted)
}

for _ in 0..<t {
    let target = Array(readLine()!)
    let start =  0
    let end = target.endIndex - 1
    
    let isPalindrome = checkPalindrome(target: target, start: start, end: end, isDeleted: false)
    
    switch isPalindrome {
    case (true, true):
        print("1")
    case (true, false):
        print("0")
    case (false, _):
        print("2")
    }
}