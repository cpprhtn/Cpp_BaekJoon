T = int(input())
for i in range(T):
    arr = list(input())
    s = 0
    start = 1
    for j in arr:
        if j == 'O':
            s += start
            start+=1
        else:
            start = 1

    print(s)
