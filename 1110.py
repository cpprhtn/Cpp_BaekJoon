N = int(input())
N_1 = N
cnt = 0

while True:
    a = N//10 + N%10
    b = (N%10)*10 + a%10
    cnt += 1
    N = b
    if N == N_1:
        break

print(cnt)
