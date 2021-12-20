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
let numOfCases = fio.readInt()

func bfs(startS: Int, startT: Int) -> Int {
    var queue = [(startS, startT, 0)]
    let visited = Array(repeating: false, count: 600)
    
    while !queue.isEmpty {
        let now = queue.removeFirst()
        let nowS = now.0
        let nowT = now.1
        let nowDepth = now.2
        
        if nowS * 2 == nowT + 3 || nowS + 1 == nowT {
            return nowDepth + 1
        }
        
        if nowS < nowT && !visited[nowS] {
            queue.append((nowS * 2, nowT + 3, nowDepth + 1))
            queue.append((nowS + 1, nowT, nowDepth + 1))
        }
    }
    return 0
}

for _ in 0..<numOfCases {
    let s = fio.readInt()
    let t = fio.readInt()
    fio.print("\(bfs(startS: s, startT: t))\n")
}
