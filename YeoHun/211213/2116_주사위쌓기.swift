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
var dices = [[Int]]()

for _ in 0..<n {
    var dice = [Int]()
    for _ in 0..<6 {
        dice.append(fio.readInt())
    }
    dices.append(dice)
}

var answer = 0
for bottom in 0..<6 {
    var nowBottom = bottom
    var nowUpValue = dices[0][nowBottom.oppositeSide]
    var tempDices = dices
    tempDices[0][nowBottom] = -1
    tempDices[0][nowBottom.oppositeSide] = -1
    var sum = tempDices[0].max()!
    for dice in tempDices[1...]{
        nowBottom = dice.firstIndex(where: { $0 == nowUpValue })!
        var tempDice = dice
        
        tempDice[nowBottom] = -1
        nowUpValue = dice[nowBottom.oppositeSide]
        tempDice[nowBottom.oppositeSide] = -1
        sum += tempDice.max()!
    }
    answer = max(answer, sum)
}

fio.print("\(answer)")
