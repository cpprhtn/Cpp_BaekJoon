m1,m2,m3,m4 = map(int, input().split())
man1,man2,man3,man4 = map(int, input().split())
S = m1+m2+m3+m4
T = man1+man2+man3+man4
print(max(S,T))
