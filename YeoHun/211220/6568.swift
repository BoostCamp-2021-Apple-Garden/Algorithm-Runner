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

enum CommandType: String {
    case sta = "000"
    case lda = "001"
    case beq = "010"
    case nop = "011"
    case dec = "100"
    case inc = "101"
    case jmp = "110"
    case hlt = "111"
}

func printBinary8(x: Int) -> String {
    let numBit = 8
    
    var i = x
    if i < 0 {
        i = 0b1 << numBit + i
    }
    
    var str = String(i, radix: 2)
    if str.count < numBit {
        str = String(repeatElement("0", count: numBit - str.count)) + str
    }
    return str
}

let fio = FastIO()
var answer = ""
fin: while let line = readLine() {
    var memory = [(address: Int, commandType: CommandType, operand: Int)]()
    var adder = 0
    for _ in 0..<32 {
        let command = line
        let addr = (Int(command, radix: 2))!
        let commandType = CommandType(rawValue: String(command.prefix(3)))!
        let operand = addr % 32
        memory.append((addr, commandType, operand))
    }
    var pcCursor = 0
out: while true {
    let command = memory[pcCursor].commandType
    let operand = memory[pcCursor].operand
    pcCursor = (pcCursor + 1) % 32
    
    switch command {
    case .sta:
        memory[operand].address = adder
        memory[operand].commandType = CommandType(rawValue: String(Int(adder/32), radix: 2))!
        memory[operand].operand = adder % 32
    case .lda:
        adder = memory[operand].address
    case .beq:
        if adder == 0 {
            pcCursor = operand
        }
    case .nop:
        continue
    case .dec:
        adder = (adder - 1) % 256
    case .inc:
        adder = (adder + 1) % 256
    case .jmp:
        pcCursor = operand
    case .hlt:
        break out
    }
}
    answer += printBinary8(x: adder) + "\n"
}
fio.print(answer)
