# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
input = int(input())

def isGood(string):
	for i in range(1, len(string)//2 + 1):
		right = string[-i:]
		left = string[-i*2:-i]
		if right == left:
			return False
	return True

answer = "-1"
def makeSequence(current):
	global answer
	
	if not isGood(current):
		return
	if len(current) == input:
		if answer == "-1":
			answer = current
		else:
			answer = min(answer, current)
		return
	
	if current[-1] != "1":
		makeSequence(current + "1")
	if current[-1] != "2":
		makeSequence(current + "2")
	if current[-1] != "3":
		makeSequence(current + "3")

makeSequence("1")
print(answer)