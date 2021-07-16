import sys
for i in range(3):
    N = int(sys.stdin.readline())
    arr = []
    for k in range(N):
        arr.append(int(sys.stdin.readline()))
    b = sum(arr)
    if b > 0:
        print("+")
    elif b < 0:
        print("-")
    else:
        print(0)
