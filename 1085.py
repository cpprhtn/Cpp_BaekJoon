x,y,w,h = map(int, input().split())
a = w-x
b = h-y

print(min(x,y,a,b))
