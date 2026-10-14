// Problem 3223. Minimum Length of String After Operations
// https://leetcode.com/problems/minimum-length-of-string-after-operations

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        unordered_map<char,int>freq;
        for(int i =0;i<n;i++){
            freq[s[i]]++;
            if(freq[s[i]] == 3){
                freq[s[i]] = 1;
            }
        }
        int ans = 0;

        for(auto p : freq){
            ans += p.second;
        }

        return ans;
    }
};

int main(){
    string str = "abaacbcbb";
    Solution sol;
    cout<<sol.minimumLength(str)<<endl;

    return 0;
}