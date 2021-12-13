from itertools import permutations

def solution(k, dungeons):
    count = 0
    p = list(permutations(dungeons,len(dungeons)))
    for values in p:
        c, temp_k = 0, k
        for element in values:
            if temp_k >= element[0]:
                c += 1
                temp_k -= element[1]
        count = max(c,count)
    return count
