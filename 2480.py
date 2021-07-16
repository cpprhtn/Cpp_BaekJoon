x, y, z = map(int, input().split())
if x==y and y==z:
    print(10000+(1000*x))
elif x==y:
    print(1000+(100*x))
elif y==z:
    print(1000+(100*y))
elif z==x:
    print(1000+(100*z))
else:
    print(max(x,y,z)*100)
