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

struct Heap<T: Comparable> {
    private var elements: [T]
    private let sortFunction: (T, T) -> Bool
    
    var isEmpty: Bool {
        return self.elements.isEmpty
    }
    var peek: T? {
        return self.elements.first
    }
    var count: Int {
        return self.elements.count
    }
    
    init(elements: [T] = [], sortFunction: @escaping (T, T) -> Bool) {
        self.elements = elements
        self.sortFunction = sortFunction
        if !elements.isEmpty {
            self.buildHeap()
        }
    }
    
    func leftChild(of index: Int) -> Int {
        return index * 2
    }
    func rightChild(of index: Int) -> Int {
        return index * 2 + 1
    }
    func parent(of index: Int) -> Int {
        return index / 2
    }
    mutating func add(element: T) {
        self.elements.append(element)
    }
    mutating func diveDown(from index: Int) {
        var higherPriority = index
        let leftIndex = self.leftChild(of: index)
        let rightIndex = self.rightChild(of: index)
        
        if leftIndex < self.elements.endIndex && self.sortFunction(self.elements[leftIndex], self.elements[higherPriority]) {
            higherPriority = leftIndex
        }
        if rightIndex < self.elements.endIndex && self.sortFunction(self.elements[rightIndex], self.elements[higherPriority]) {
            higherPriority = rightIndex
        }
        if higherPriority != index {
            self.elements.swapAt(higherPriority, index)
            self.diveDown(from: higherPriority)
        }
    }
    mutating func swimUp(from index: Int) {
        var index = index
        while index >= 0 && self.sortFunction(self.elements[index], self.elements[index/2]) {
            self.elements.swapAt(index/2, index)
            index /= 2
        }
    }
    mutating func buildHeap() {
        for index in (0...(self.elements.count / 2)).reversed() {
            self.diveDown(from: index)
        }
    }
    mutating func insert(node: T) {
        self.elements.append(node)
        self.swimUp(from: self.elements.endIndex - 1)
    }
    mutating func remove() -> T? {
        if self.elements.isEmpty { return nil }
        self.elements.swapAt(0, elements.endIndex - 1)
        let deleted = elements.removeLast()
        self.diveDown(from: 0)
        
        return deleted
    }
}

struct PriorityQueue<T: Comparable> {
    private var heap: Heap<T>
    
    init(_ elements: [T] = [], _ sort: @escaping (T, T) -> Bool) {
        heap = Heap(elements: elements, sortFunction: sort)
    }
    
    var count : Int {
        return heap.count
    }
    var isEmpty : Bool {
        return heap.isEmpty
    }
    
    func top () -> T? {
        return heap.peek
    }
    mutating func clear () {
        while !heap.isEmpty {
            _ = heap.remove()
        }
    }
    mutating func pop() -> T? {
        return heap.remove()
    }
    mutating func push(_ element: T) {
        heap.insert(node: element)
    }
}

var menPositive = PriorityQueue<Int>([], <)
var menNegative = PriorityQueue<Int>([], <)
var womenPositive = PriorityQueue<Int>([], <)
var womenNegative = PriorityQueue<Int>([], <)
let fio = FastIO()
let n = fio.readInt()

for _ in 0..<n {
    let next = fio.readInt()
    next < 0 ? menNegative.push(-next) : menPositive.push(next)
}

for _ in 0..<n {
    let next = fio.readInt()
    next < 0 ? womenNegative.push(-next) : womenPositive.push(next)
}

var answer = 0
while !menNegative.isEmpty && !womenPositive.isEmpty {
    let nowMan = menNegative.pop()
    if nowMan! > womenPositive.top()! {
        answer += 1
        _ = womenPositive.pop()
    }
}
while !menPositive.isEmpty && !womenNegative.isEmpty {
    let nowWoman = womenNegative.pop()
    if nowWoman! > menPositive.top()! {
        answer += 1
        _ = menPositive.pop()
    }
}

fio.print("\(answer)")
