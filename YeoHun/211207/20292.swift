import Foundation

var sourceSet = Set<String>()
var targetSet = Set<String>()
var readSet = Set<String>()

func clear() {
    sourceSet = Set<String>()
    targetSet = Set<String>()
    readSet = Set<String>()
}

while true {
    let input = readLine()!
    
    let command = input.components(separatedBy: " ").filter({ $0 != " " && $0 != "TO" })
    if command[0] == "WRITE" {
        if readSet.contains(command[2]) {
            print("WAIT")
            clear()
        }
        else if targetSet.contains(command[1]) || sourceSet.contains(command[0]) {
            print("WAIT")
            clear()
        }
        else if targetSet.contains(command[2]) {
            print("WAIT")
            clear()
        }
        else if targetSet.contains(command[1]) && sourceSet.contains(command[2]) {
            print("WAIT")
            clear()
        }
        sourceSet.insert(command[1])
        targetSet.insert(command[2])
    }
    if command[0] == "READ" {
        if targetSet.contains(command[1]) {
            print("WAIT")
            clear()
        }
        readSet.insert(command[1])
    }
    print(input)
    
    if command[0] == "EXIT" {
        break
    }
}
