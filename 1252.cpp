    #include <iostream>
    #include <bitset>
    #include <string>
    #define MAX 80

    using namespace std;

    string solution(string longer, string shorter);

    int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        string a, b;
        cin >> a >> b;

        string result;
        if(a.length() >= b.length())
            result = solution(a, b);
        else
            result = solution(b, a);

        if(result.find("1") == string::npos){
            cout << 0 << endl;
        }else{
            int i = 0;
            while(result[i] == '0'){
                i++;
            }
            for(;i < result.length();i++){
                cout << result[i];
            }
        }


        return 0;
    }

    string solution(string longer, string shorter){

        string result = "";
        int carry = 0;

        int llength = longer.length();
        int slength = shorter.length();

        if(llength > slength){
            for(int j = 0; j < llength - slength; j++){
                shorter.insert(shorter.begin(), '0');
            }
        }

        for(int i = longer.length() - 1; i >= 0; i--){

            if(longer[i] == '1' && shorter[i] == '1')
            {
                if(!carry)
                {
                    result.insert(result.begin(), '0');
                    carry  = 1;
                }
                else{
                    result.insert(result.begin(), '1');
                    carry = 1;
                }
            }else if(longer[i] == '1' && shorter[i] == '0'){
                if(!carry)
                    result.insert(result.begin(), '1');
                else{
                    result.insert(result.begin(), '0');
                    carry = 1;
                }
            }else if(longer[i] == '0' && shorter[i] == '1'){
                if(!carry)
                    result.insert(result.begin(), '1');
                else{
                    result.insert(result.begin(), '0');
                    carry = 1;
                }
            }else{
                if(!carry)
                    result.insert(result.begin(), '0');
                else{
                    result.insert(result.begin(), '1');
                    carry = 0;
                }
            }
        }

        if(carry)
            result.insert(result.begin(), '1');

        return result;
    }
