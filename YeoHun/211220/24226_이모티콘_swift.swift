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
let S = fio.readInt()

func bfs() -> Int {
    var queue = [(screen: 1, clipBoard: 0, depth: 0)]
    var memo = Array(repeating: Array(repeating: false, count: 10000), count: 10000)
    memo[1][0] = true
    while !queue.isEmpty {
        let now = queue.removeFirst()
        let nowScreen = now.0
        let nowClipBoard = now.1
        let nowDepth = now.2
        
        if nowScreen == S {
            return nowDepth
        }
                
        if !memo[nowScreen][nowScreen] {
            memo[nowScreen][nowScreen] = true
            queue.append((nowScreen, nowScreen, nowDepth + 1))
        }
        if nowClipBoard > 0 && !memo[nowScreen + nowClipBoard][nowClipBoard] {
            memo[nowScreen + nowClipBoard][nowClipBoard] = true
            queue.append((nowScreen + nowClipBoard, nowClipBoard, nowDepth + 1))
        }
        if nowScreen > 0 && !memo[nowScreen - 1][nowClipBoard] {
            memo[nowScreen - 1][nowClipBoard] = true
            queue.append((nowScreen - 1, nowClipBoard, nowDepth + 1))
        }
    }
    return 0
}

print(bfs())
// 화 -> 클
// 클 -> 화
// 화 - 1
