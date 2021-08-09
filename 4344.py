T = int(input())

for i in range(T):
    Member = list(map(int, input().split()))
    avr = (sum(Member) - Member[0])/Member[0]
    cnt = 0
    for j in range(1,Member[0]+1):
        if Member[j] > avr:
            cnt += 1

    print("{:.3f}%".format(cnt/Member[0]*100))
