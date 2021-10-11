n = int(input())

def binary(n):
    if n == 1:
        print(n, end = "")
    else:
        binary(n//2)
        print(n % 2, end = "")

binary(n)