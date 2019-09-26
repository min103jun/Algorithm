import itertools
from sys import stdin
input = stdin.readline

answerarr = set()
N = int(input())
numarr = [int(x) for x in input().strip().split()]
temp = [int(x) for x in input().strip().split()]
oparr = []
for i, op in enumerate (temp) :
    for j in range(op) :
        if i == 0 :
            oparr.append('+')
        elif i == 1 :
            oparr.append('-')
        elif i == 2 :
            oparr.append('*')
        elif i == 3 :
            oparr.append('//')

opop = set(itertools.permutations(oparr))
for opset in opop :
    result = numarr[0]
    for i, op in enumerate(opset) :
        if op == '+' :
            result += numarr[i + 1]
        elif op == '-' :
            result -= numarr[i + 1]
        elif op == '*' :
            result *= numarr[i + 1]
        else :
            if result < 0 :
                result = -1 * (abs(result) // numarr[i + 1])
            else :
                result //= numarr[i + 1]
    answerarr.add(result)

print(max(answerarr), min(answerarr))
