num = list(range(1,10001))
is_not = []
for i in num:
    for j in str(i):
        i += int(j)

    if i <= 10000:
        is_not.append(i)

for rm in set(is_not):
    num.remove(rm)

for t in num:
    print(t)
