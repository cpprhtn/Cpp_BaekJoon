A = int(input())
B = int(input())
C = int(input())

multi = A * B * C

for i in range(10):
    print(list(str(multi)).count(str(i)))
