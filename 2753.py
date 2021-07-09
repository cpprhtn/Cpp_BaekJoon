a = input()
a = int(a)

if a%4==0 and a%100!=0:
    print(1)

elif a%4==0 and a%400==0:
    print(1)

else:
    print(0)
