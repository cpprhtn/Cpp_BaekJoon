n = int(input())

for i in range(n):
    num = n - (i+1)
    for j in range(n):
        if num > 0:
            print(" ",end='')
        else:
            print("*",end='')
        num-=1

    print()
