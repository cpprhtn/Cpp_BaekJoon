a = int(input())

if a <= 5:
    print(a)
else:
    a -= 1
    if (a//4)%2 == 0:
        print(a%4+1)
    else:
        print(5-a%4)
