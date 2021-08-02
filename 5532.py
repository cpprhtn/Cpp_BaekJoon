L = int(input())
A = int(input())
B = int(input())
C = int(input())
D = int(input())

if A%C == 0:
    front = A//C
else:
    front = A//C+1

if B%D == 0:
    back = B//D
else:
    back = B//D+1

big = max(front, back)

print(L-big)
