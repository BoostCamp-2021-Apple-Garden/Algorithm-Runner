import Foundation

let nqc = readLine()!.components(separatedBy: " ").map({ Int($0)! })
let operationNum = nqc[1]
let capcity = nqc[2]
let pageSizes = [0] + readLine()!.components(separatedBy: " ").map({ Int($0)! })
var currentPage: Int? {
    didSet {
        guard let oldValue = oldValue else { return }
        cache.cacheSize -= pageSizes[oldValue]
    }
    willSet {
        guard let newValue = newValue else { return }
        cache.cacheSize += pageSizes[newValue]
    }
}

struct Cache {
    var backCache: [Int] = []
    var forwardCache: [Int] = []
    var cacheSize = 0
    var capacity: Int
    
    init(capacity: Int) {
        self.capacity = capacity
    }
    mutating func clearForwardCache() {
        cacheSize -= forwardCache.reduce(0, { $0 + pageSizes[$1] })
        self.forwardCache = []
    }
    mutating func clearBackCache() {
        cacheSize -= backCache.reduce(0, { $0 + pageSizes[$1] })
        self.backCache = []
    }
    mutating func addBackCache(newPage: Int) {
        self.backCache.append(newPage)
        self.cacheSize += pageSizes[newPage]
        while cacheSize > capacity {
            let removed = backCache.removeFirst()
            cacheSize -= pageSizes[removed]
        }
    }
    mutating func addForwardCache(newPage: Int) {
        self.forwardCache.append(newPage)
        self.cacheSize += pageSizes[newPage]
    }
    mutating func removeRecentBackPage() -> Int {
        self.cacheSize -= pageSizes[backCache.last!]
        return backCache.removeLast()
    }
    mutating func removeRecentFrontPage() -> Int {
        self.cacheSize -= pageSizes[forwardCache.first!]
        return forwardCache.removeFirst()
    }
    
    mutating func compress() {
        guard !backCache.isEmpty else { return }
        for i in 1..<self.backCache.count {
            if backCache[i] == backCache[i-1] {
                cacheSize -= pageSizes[backCache[i-1]]
                backCache[i-1] = -1
            }
        }
        backCache = backCache.filter({ $0 != -1 })
    }
}

func back() {
    guard !cache.backCache.isEmpty else { return }
    guard let pageNow = currentPage else { return }
    cache.addForwardCache(newPage: pageNow)
    currentPage = cache.removeRecentBackPage()
}

func front() {
    guard !cache.forwardCache.isEmpty else { return }
    guard let pageNow = currentPage else { return }
    cache.addBackCache(newPage: pageNow)
    currentPage = cache.removeRecentFrontPage()
}

func accessPage(pageNum: Int) {
    if currentPage == nil {
        currentPage = pageNum
        return
    }
    cache.clearForwardCache()
    guard let pageNow = currentPage else { return }
    cache.addBackCache(newPage: pageNow)
    currentPage = pageNum
}

var cache = Cache(capacity: capcity)

for _ in 0..<operationNum {
    let input = readLine()!.components(separatedBy: " ")
    let command = input[0]
    var accessPageNum = 0
    if input.count > 1 {
        accessPageNum = Int(input[1])!
    }
    switch command {
    case "A":
        accessPage(pageNum: accessPageNum)
    case "B":
        back()
    case "F":
        front()
    case "C":
        cache.compress()
    default:
        break
    }
    print(cache.backCache)
    print(currentPage)
    print(cache.forwardCache)
}

print(currentPage!)
cache.backCache.isEmpty
? print(-1)
: print(cache.backCache.reversed().map({ String($0) }).joined(separator: " "))

cache.forwardCache.isEmpty
? print(-1)
: print(cache.forwardCache.map({ String($0) }).joined(separator: " "))
