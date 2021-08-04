n = int(input())
arr = list(map(int, input().split()))

m = max(arr)

for i in range(n):
    arr[i] = arr[i]/m*100

s = sum(arr)
print(s/n)
