def Y_S(a):
    if a == 0:
        return 0
    ys = (a//30)*10 + 10
    return ys

def M_S(b):
    if b == 0:
        return 0
    ms = (b//60)*15 + 15
    return ms

N = int(input())
ys_add = 0
ms_add = 0
arr = list(map(int,input().split()))

for i in arr:
    Y = Y_S(i)
    M = M_S(i)
    ys_add += Y
    ms_add += M

if ys_add < ms_add:
    print('Y',ys_add)

elif ys_add > ms_add:
    print('M', ms_add)

else:
    print('Y M', ys_add)
