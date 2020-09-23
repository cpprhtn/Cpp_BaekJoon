#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ans=0;
	string doc, word;
	getline(cin, doc);
	getline(cin, word);

	int it=0;
	while(it+word.size()<=doc.size())
	{
		if(word==doc.substr(it, word.size()))
			ans++, it+=word.size();

		else
			it++;

	}

	cout<<ans;
}
