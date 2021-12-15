#!/bin/python3

import math
import os
import random
import re
import sys
import itertools

#
# Complete the 'alternate' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def alternate(s):
    max_len = 0
    c = list(set(s))

    if len(c) == 1: return 0
    else:
        remove_c = list(itertools.combinations(c,len(c)-2))
        for v in remove_c:
            f = True
            temp_s = list(s)
            temp_s = [i for i in temp_s if i not in set(v)]
            for i in range(len(temp_s)):
                if i == 0 : continue
                if temp_s[i] == temp_s[i-1]:
                    f = False
                    break
            if f:
                max_len = max(max_len, len(temp_s))
        return max_len
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    l = int(input().strip())

    s = input()

    result = alternate(s)

    fptr.write(str(result) + '\n')

    fptr.close()
