import Foundation

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

func alternate(s: String) -> Int {
    let characterSet = Set<Character>(Array(s))
    let uniqueCharacters = Array(characterSet)
    var answer = 0
    
    for (index, firstCharacter) in uniqueCharacters.enumerated() {
        let tempString = s
        outer: for secondCharacter in uniqueCharacters[(index+1)...] {
            let tempArray = Array(tempString.filter({ $0 == firstCharacter || $0 == secondCharacter }))
            for i in 1..<tempArray.count {
                if tempArray[i] == tempArray[i - 1] {
                    continue outer
                }
            }
            answer = max(answer, tempArray.count)
        }
    }
    return answer
}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard let l = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

guard let s = readLine() else { fatalError("Bad input") }

let result = alternate(s: s)

fileHandle.write(String(result).data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)
