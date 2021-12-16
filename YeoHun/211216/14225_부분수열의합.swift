import Foundation

final class FastIO {
    private let buffer: [UInt8]
    private var index: Int = 0
    private let fhOutput: FileHandle = FileHandle.standardOutput
    
    init(fhInput: FileHandle = FileHandle.standardInput) {
        buffer = Array(try! fhInput.readToEnd()!) + [UInt8(0)]
    }
    
    @inline(__always) private func read() -> UInt8 {
        defer {
            index += 1
        }
        return buffer[index]
    }
    
    @inline(__always) func readInt() -> Int {
        var sum = 0
        var now = read()
        var isPositive = true
        while now == 10 || now == 32 {
            now = read()
        }
        if now == 45 {
            isPositive.toggle(); now = read()
        }
        while now >= 48, now <= 57 {
            sum = sum * 10 + Int(now - 48)
            now = read()
        }
        return sum * (isPositive ? 1 : -1)
    }
    
    @inline(__always) func readString() -> String {
        var now = read()
        while now == 10 || now == 32 {
            now = read()
        }
        let beginIndex = index-1
        while now != 10, now != 32, now != 0 {
            now = read()
        }
        return String(bytes: Array(buffer[beginIndex..<(index-1)]), encoding: .ascii)!
    }
    
    @inline(__always) func readByteSequenceWithoutSpaceAndLineFeed() -> [UInt8] {
        var now = read()
        while now == 10 || now == 32 {
            now = read()
        }
        let beginIndex = index - 1
        while now != 10,
              now != 32,
              now != 0 {
            now = read()
        }
        return Array(buffer[beginIndex..<(index - 1)])
    }
    
    @inline(__always) func print(_ s: String) {
        fhOutput.write(s.data(using: .utf8)!)
    }
}

let fio = FastIO()
let n = fio.readInt()
var numbers = [Int]()
for _ in 0..<n {
    numbers.append(fio.readInt())
}
let permutations = [Int]()
var numberSet = Set<Int>()
var visited = Array(repeating: false, count: n + 1)

func makePermutation(permutation: [Int] = [], index: Int = 0) {
    var permutation = permutation
    numberSet.insert(permutation.reduce(0, +))
    if permutation.count == numbers.count {
        return
    }
    
    for i in index..<numbers.count {
        if visited[i] == false {
            visited[i] = true
            permutation.append(numbers[i])
            makePermutation(permutation: permutation, index: i + 1)
            permutation.removeLast()
            visited[i] = false
        }
    }
}

func solution() {
    makePermutation()
    let sums = numberSet.sorted(by: <)
    for i in 1..<sums.count {
        if sums[i-1] + 1 != sums[i] {
            fio.print("\(sums[i-1] + 1)")
            return
        }
    }
    fio.print("\(sums.last! + 1)")
}

solution()
