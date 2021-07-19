n = int(input())
arr = "%.250f"% (1/(2**n))
length = len(arr)
for i in range(length-1,0,-1):
    if arr[i] != '0':
        length = i
        break
print(arr[:length+1])
