from itertools import permutations


def solution(k, dungeons):
    answer = -1
    candidates = list(permutations(range(len(dungeons))))
    max_cnt = 0
    for candidate in candidates:
        cnt = 0
        cur_k = k
        for dungeon in candidate:
            if cur_k >= dungeons[dungeon][0]:
                cnt += 1
                cur_k -= dungeons[dungeon][1]
            else:
                break
        max_cnt = max(cnt, max_cnt)

    return max_cnt
