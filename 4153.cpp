#include <cstdio>
#include <algorithm>
int main()
{
	int tri[3];
	while(1)
	{
		scanf("%d %d %d", &tri[0], &tri[1], &tri[2]);
		if(!tri[0] && !tri[1] && !tri[2])
			return 0;

		std::sort(tri, tri+3);
		printf("%s\n", (tri[0]*tri[0]+tri[1]*tri[1]==tri[2]*tri[2]?"right":"wrong"));
	}
}