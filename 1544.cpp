#include <iostream>
#include <string>
#include <memory>
#include <set>
using namespace std;

void makeCycleWords(string str, set<string>& cycleSet);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    unique_ptr<string []> words(new string[n]);
    set<string> cycleSet;
    
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    
    int count = 0;
    for(int i = 0; i < n; i++){
        if(cycleSet.find(words[i]) == cycleSet.end()){
            makeCycleWords(words[i], cycleSet);
            count++;
        }
    }
    cout << count;
    
    return 0;
}

void makeCycleWords(string str, set<string>& cycleSet){
    
    cycleSet.insert(str);
    for(int i = 1; i < str.length(); i++){
        string newPre(str.begin() + i, str.end());
        string newPos(str.begin(), str.begin() + i);
        cycleSet.insert(newPre+newPos);
    }
    
}
