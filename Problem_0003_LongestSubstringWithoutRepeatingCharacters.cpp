#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int LongestSubstringWithoutRepeatingCharacters(string s){
    int maxLen = 0;
    set<char> uniqSet;
    if(!s.length()) 
        return maxLen;
    int n = s.length();
    int i = 0, j = 0;
    while(i < n && j < n){
        if(!uniqSet.count(s[j])){
            uniqSet.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else{
            uniqSet.erase(s[i]);
            i++;
        }
    }
    return maxLen;
}

int main(){
    string s = "pwwkew";
    cout << LongestSubstringWithoutRepeatingCharacters(s) << endl;
}
