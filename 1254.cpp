#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string str, temp;
	int size;
	cin>>str;

	size=str.size();
	temp=str;
	reverse(temp.begin(), temp.end());
	if(!str.compare(temp))
	{
		cout<<str.size()<<endl;
		return 0;
	}

	for(int i=0; i<size; i++)
	{
		string bbb;
		bbb+=str.at(i);
		str.insert(size, bbb);
		temp=str;
		reverse(temp.begin(), temp.end());
		if(!str.compare(temp))
		{
			cout<<str.size()<<endl;
			break;
		}
	}



	return 0;
}
