#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std; 

string Add(string &arr1, string &str2) 
{
	string result(max(arr1.size(), str2.size()), '0'); 
	bool carry = false; 
	for (int i = 0; i < result.size(); i++) 
	{ 
		int temp = carry; 
		carry = false; 
		if (i < arr1.size()) 
			temp += arr1[arr1.size() - i - 1] - '0'; 
		
		if (i < str2.size()) 
			temp += str2[str2.size() - i - 1] - '0'; 
		
		if (temp >= 10) 
		{ 
			carry = true;
			temp -= 10; 
		} 
		
		result[result.size() - i - 1] = temp + '0';
	} 
	
	if (carry) 
		result.insert(result.begin(), '1'); 
	
	return result; 
} 

int main() 
{ 
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	
	string A, B; 
	
	cin >> A >> B; 
	string result = Add(A, B);
	cout << result << "\n"; 
	return 0; 
}
