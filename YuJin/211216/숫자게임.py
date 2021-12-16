def solution(A, B):
    answer = 0 
    A.sort(reverse = True)
    B.sort(reverse = True)
    j = 0
    for element in B:
        for j in range(len(A)):
            if element > A[j]:
                answer += 1
                A.pop(j)
                break
    
    return answer
