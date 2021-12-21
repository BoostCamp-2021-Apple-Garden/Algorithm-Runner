var memory = [String]()
var adder: UInt8 = 0
var pc = 0

extension String {
    func substr(from: Int, to: Int) -> String {
        guard from < count, to >= 0, to - from >= 0 else {
            return ""
        }

        let startIndex = index(self.startIndex, offsetBy: from)
        let endIndex = index(self.startIndex, offsetBy: to + 1)
        return String(self[startIndex ..< endIndex])
    }

    func toInt() -> Int {
        var result = 0
        for c in self {
            if c == "1" { result = result * 2 + 1 }
            else { result = result * 2 }
        }
        return result
    }
}

extension UInt8 {
    func toString() -> String {
        var result = ""
        var num = self
        for _ in 0..<8 {
            let r = num % 2
            result = (r == 0 ? "0" : "1") + result
            num = num / 2
        }
        return result
    }
}

func f() {
    while true {
        let command = memory[pc]
        pc = (pc + 1) % 32
        if command.substr(from: 0, to: 2) == "111" { break }
        switch command.substr(from: 0, to: 2) {
        case "000":
            let address = command.substr(from: 3, to: 7).toInt()
            memory[address] = adder.toString()
        case "001":
            let address = command.substr(from: 3, to: 7).toInt()
            adder = UInt8(memory[address].toInt())
        case "010":
            if adder == 0 { pc = command.substr(from: 3, to: 7).toInt() }
        case "100":
            if adder == 0 { adder = 255 }
            else { adder -= 1 }
        case "101":
            if adder == 255 { adder = 0 }
            else { adder += 1 }
        case "110":
            pc = command.substr(from: 3, to: 7).toInt()
        default:
            break
        }
    }
}

while let command = readLine() {
    memory.append(command)
    if memory.count == 32 {
        f()
        memory.removeAll()
        print(adder.toString())
        adder = 0
        pc = 0
    }
}