#10000번째 피보나치수는 너무 크다. c로 풀려면 string으로 연산을 해야한다.
fib = []
fib.append(0)
fib.append(1)
n = int(input())

for i in range(2, n + 1) :
    fib.append(fib[i - 1] + fib[i - 2])

print(fib[n])
