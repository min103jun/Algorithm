import itertools

answer = 9999
N = int(input())
all_team = [int(i) for i in range(N)]
score = [[int(x) for x in input().strip().split()] for y in range(N)]

sumA_set = set()
sumB_set = set()
for temp in itertools.combinations(all_team, N//2) :
    teamA = set(temp)
    teamB = set(all_team) - teamA
    sumA = 0
    sumB = 0
    for tempA in itertools.combinations(teamA, 2) :
        sumA += abs(score[tempA[0]][tempA[1]]) + abs(score[tempA[1]][tempA[0]])
    for tempB in itertools.combinations(teamB, 2) :
        sumB += abs(score[tempB[0]][tempB[1]]) + abs(score[tempB[1]][tempB[0]])
    if abs(sumA - sumB) == 0 :
        answer = 0
        break
    if abs(sumA - sumB) < answer :
        answer = abs(sumA - sumB)

print(answer)
