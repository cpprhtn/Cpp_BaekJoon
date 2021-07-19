m = int(input())
d = int(input())

special_date = [2, 18]

if m > special_date[0]:
    print("After")

elif m < special_date[0]:
    print("Before")

else:
    if d > special_date[1]:
        print("After")
    elif d < special_date[1]:
        print("Before")
    else:
        print("Special")
