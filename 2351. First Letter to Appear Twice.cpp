// Problem 2351. First Letter to Appear Twice
// https://leetcode.com/problems/first-letter-to-appear-twice

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool>seen(26,false);
        int n = s.length();

        for(int i = 0;i<n;i++){
            int idx = s[i] - 'a';
            if(seen[idx]){
                return s[i];
            }
            else{
                seen[idx] = true;
            }
        }
        return s[0];
    }
};

int main(){
    Solution sol;
    string s = "abcdecd";
    cout<<sol.repeatedCharacter(s)<<endl;

    return 0;
}