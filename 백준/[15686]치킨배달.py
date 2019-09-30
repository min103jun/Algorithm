from itertools import combinations

answer = 99999999
house_list = []
chicken_list = []
row, select = map(int, input().strip().split())
for i in range(row) :
    arr = list(map(int, input().strip().split()))
    for j, e in enumerate(arr) :
        if e == 1 :
            house_list.append([i, j])
        elif e == 2 :
            chicken_list.append([i, j])

for comb in combinations(chicken_list, select) :
    temp_sum = 0
    for house in house_list :
        temp_max = 9999
        for tempcomb in comb :
            temp = abs(tempcomb[0] - house[0]) + abs(tempcomb[1] - house[1])
            if temp < temp_max :
                temp_max = temp
        temp_sum += temp_max
    if temp_sum < answer :
        answer = temp_sum
print(answer)
