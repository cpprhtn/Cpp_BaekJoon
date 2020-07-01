#include <cstdio>
#include <cctype>
#include <algorithm>
int main()
{
	char ch;
	int arr[26]={}, cnt=0;
	while(scanf("%c", &ch)!=EOF)
	{
		if(islower(ch))
			cnt=std::max(cnt, ++arr[ch-'a']);
	}

	for(int i=0; i<26; i++)
	{
		if(arr[i]==cnt)
			printf("%c", i+'a');
	}
}
