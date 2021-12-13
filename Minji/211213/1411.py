import sys

n = int(sys.stdin.readline().strip())
words = [sys.stdin.readline().strip() for i in range(n)]
answer = 0

for i in range(len(words)):
    for j in range(i + 1, len(words)):
        char_dict = dict()
        is_shom = True
        for k in range(len(words[i])):
            if char_dict.get(words[i][k]) == None and words[j][k] in char_dict.values():
                is_shom = False
                break
            elif char_dict.get(words[i][k]) == None and words[j][k] not in char_dict.values():
                char_dict[words[i][k]] = words[j][k]
            elif char_dict.get(words[i][k]) != None and char_dict.get(words[i][k]) != words[j][k]:
                is_shom = False
                break
        if is_shom: answer += 1

print(answer)

