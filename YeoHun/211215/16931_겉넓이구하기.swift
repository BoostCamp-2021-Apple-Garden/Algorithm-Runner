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

extension Int {
    var oppositeSide: Int {
        switch self {
        case 0: return 5
        case 1: return 3
        case 2: return 4
        case 3: return 1
        case 4: return 2
        case 5: return 0
        default: return -1
        }
    }
}

let fio = FastIO()
let n = fio.readInt()
let m = fio.readInt()
var map = Array(repeating: Array(repeating: 0, count: m), count: n)

for row in 0..<n {
    for col in 0..<m {
        map[row][col] = fio.readInt()
    }
}

let rowDir = [0, 0, 1, -1]
let colDir = [1, -1, 0, 0]
var answer = 0
for (rowIndex, row) in map.enumerated() {
    for (colIndex, col) in row.enumerated() {
        // 쌓여있는 블록들의 가능한 최대 겉넓이 구하기
        answer += col * 6 - (col - 1) * 2
        for (nextRowDir, nextColDir) in zip(rowDir, colDir) {
            let nextRowIndex = rowIndex + nextRowDir
            let nextColIndex = colIndex + nextColDir
            // 바깥쪽에 열려있으면 무시
            if (0..<n) ~= nextRowIndex && (0..<m) ~= nextColIndex {
                // 현재보다 높이가 낮은 블록더미가 앞에 있으면 해당 높이만큼 겉넓이를 뺀다
                if map[nextRowIndex][nextColIndex] < col {
                    answer -= map[nextRowIndex][nextColIndex]
                }
                // 현재보다 높이가 높은 블록더미가 앞에 있으면 해당 면은 완전히 사용할 수 없음
                else if map[nextRowIndex][nextColIndex] >= col {
                    answer -= col
                }
            }
        }
    }
}

fio.print("\(answer)")
