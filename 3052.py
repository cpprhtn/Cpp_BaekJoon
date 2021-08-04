arr = []
for i in range(10):
    arr.append(int(input()))

for j in range(10):          
    arr[j] = arr[j]%42

arr = set(arr)

print(len(arr))
