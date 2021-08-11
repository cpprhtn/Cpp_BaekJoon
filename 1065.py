def hansu(n) :
    cnt = 0
    for i in range(1, n+1):
        arr = list(map(int,str(i)))
        if i < 100:
            cnt += 1
        elif arr[0]-arr[1] == arr[1]-arr[2]:
            cnt += 1
    return cnt

n = int(input())
print(hansu(n))
