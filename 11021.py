n = int(input())

for i in range(n):
    a, b = map(int, input().split())
    print("Case #",i+1,': ', a+b, sep='')
