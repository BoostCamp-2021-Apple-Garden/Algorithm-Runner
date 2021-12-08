def find(gems, g):
    b, c = [], {}
    start, end = 1, 0
    
    for i in range(len(gems)): #end구하기
        if len(list(set(b))) == g: break
        end += 1
        b.append(gems[i])
        c.setdefault(gems[i], []).append(1)
    
    for i in range(len(gems)): #start구하기
        if len(c[gems[i]]) == 1: break
        else:
            c[gems[i]].pop(0)
            start += 1
    return [start, end]

def solution(gems):
    result = []
    min_result = []
    match = list(reversed(list(range(len(gems)))))
    g = len(list(set(gems)))
    min = float('inf')
    if g == 1 : return [1,1]
    
    result.append(find(gems, g))
    r = find(list(reversed(gems)), g)
    r = [match[r[1]-1]+1, match[r[0]-1]+1]
    result.append(r)

    for v in result:
        value = v[1]-v[0]
        if value < min:
            min = value
            min_result = [v[0],v[1]]
    
    return min_result 
