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
// 첫번째 주사위를 기준으로 6방향 다 돌려본다.
for bottom in 0..<6 {
    var tempDices = dices
    
    // 바닥의 인덱스, 반대편의 주사위 값을 저장
    var nowBottom = bottom
    var nowUpValue = tempDices[0][nowBottom.oppositeSide]
    
    // 바닥과 반대편의 주사위 값을 최소값으로 만든다.
    tempDices[0][nowBottom] = -1
    tempDices[0][nowBottom.oppositeSide] = -1
    
    // 첫 주사위의 옆면의 있는 값들 중 최대 값 뽑기.
    var sum = tempDices[0].max()!
    
    // 두 번째 주사위부터 쌓기 시작
    for dice in tempDices[1...]{
        var dice = dice
        // 바닥면은 이전 주사위의 윗면의 주사위 값과 일치하는 면이어야 함
        nowBottom = dice.firstIndex(where: { $0 == nowUpValue })!
        // 윗면 주사위 값 저장
        nowUpValue = dice[nowBottom.oppositeSide]
        
        // 바닥면과 윗면의 값을 최소값으로 만든다.
        dice[nowBottom] = -1
        dice[nowBottom.oppositeSide] = -1
        
        // 옆면 중 최대 값을 뽑아 더한다.
        sum += dice.max()!
    }
    // 옆면 최대값들의 합으로 정답을 갱신.
    answer = max(answer, sum)
}

fio.print("\(answer)")
