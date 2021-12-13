import sys
input = sys.stdin.readline

n = int(input())
men = list(map(int, input().split()))
women = list(map(int, input().split()))

p_men = sorted([abs(v) for v in men if v > 0])
m_men = sorted([abs(v) for v in men if v < 0])
p_women = sorted([abs(v) for v in women if v > 0])
m_women = sorted([abs(v) for v in women if v < 0])
c = 0
i, j = len(p_men)-1, len(m_women)-1

while True:
    if i < 0 or j < 0: break
    if p_men[i] < m_women[j]:
        c += 1
        i -= 1
        j -= 1
    else:
        i -= 1

i, j = len(p_women)-1, len(m_men)-1
while True:
    if i < 0 or j < 0: break
    if p_women[i] < m_men[j]:
        c += 1
        i -= 1
        j -= 1
    else:
        i -= 1

print(c)
