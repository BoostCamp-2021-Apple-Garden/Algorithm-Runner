class Node {
   var value: Int?
   var prev: Node?
   var next: Node?
   
   init(value: Int, prev: Node? = nil, next: Node? = nil) {
       self.value = value
       self.prev = prev
       self.next = next
   }
}

struct LinkedList {
   var head: Node? = nil
   var tail: Node? = nil
   var current: Node? = nil
   var bucket: [Node?] = []
   var deletionMarks = [String]()
   
   mutating func add(node: Node) {
       if head == nil {
           head = node
           tail = node
           current = head
           deletionMarks.append("O")
           return
       }
       
       tail?.next = node
       node.prev = tail
       tail = node
       deletionMarks.append("O")
   }
   
   mutating func moveLeft(x: Int) {
       for _ in 0..<x {
           if self.current?.prev == nil {
               return
           }
           self.current = self.current?.prev
       }
   }
   
   mutating func moveRight(x: Int) {
       for _ in 0..<x {
           if self.current?.next == nil {
               return
           }
           self.current = self.current?.next
       }
   }
   
   mutating func delete() {
       self.bucket.append(self.current)
       self.deletionMarks[(self.current?.value)!] = "X"
       if self.current?.next == nil {
           self.current = self.current?.prev
           self.current?.next = nil
           return
       }

       self.current?.next?.prev = self.current?.prev
       self.current?.prev?.next = self.current?.next
       self.current = self.current?.next
   }
   
   mutating func restore() {
       let target = self.bucket.removeLast()
       self.deletionMarks[(target!.value)!] = "O"
       target?.prev?.next = target
       target?.next?.prev = target
   }
   
   var values: [Int?] {
       var arr = [Int?]()
       var start = head
       while start != nil {
           arr.append(start?.value)
           start = start?.next
       }
       return arr
   }
}

func solution(_ n:Int, _ k:Int, _ cmd:[String]) -> String {
   var linkedList = LinkedList()
   
   for i in 0..<n {
       linkedList.add(node: Node(value: i))
   }
   
   linkedList.moveRight(x: k)
   
   for command in cmd {
       let splitCommand = command.components(separatedBy: " ")
       switch splitCommand[0] {
       case "D":
           linkedList.moveRight(x: Int(splitCommand[1])!)
       case "U":
           linkedList.moveLeft(x: Int(splitCommand[1])!)
       case "C":
           linkedList.delete()
       case "Z":
           linkedList.restore()
       default:
           break
       }
   }
   
   return linkedList.deletionMarks.joined()
}

print(solution(8, 2, ["D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"]))
print(solution(8, 2, ["D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"]))

