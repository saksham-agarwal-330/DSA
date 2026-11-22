// Problem 2124. Check if All A's Appears Before All B's
// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs?envType=daily-question&envId=2026-11-22

#include<iostream>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        for(int i = 0;i<n-1;i++){
            if(s[i] == 'b' && s[i+1] == 'a'){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s = "abab";
    cout<<sol.checkString(s)<<endl;

    return 0;
}