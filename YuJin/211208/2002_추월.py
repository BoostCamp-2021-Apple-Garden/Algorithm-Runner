import sys
input = sys.stdin.readline

n = int(input())
inCar = list(str(input()).strip() for _ in range(n))
outCar = list(str(input()).strip() for _ in range(n))
c = 0

for i in range(len(inCar)-1):
    for j in range(i+1,len(inCar)):
        if inCar.index(outCar[i]) > inCar.index(outCar[j]):
            c += 1
            break
print(c)
