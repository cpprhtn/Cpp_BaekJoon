x, y = map(int, input().split())
large = max(x,y)
small = min(x,y)
s = (large+small)/2 * (large+1-small)
print(int(s))
