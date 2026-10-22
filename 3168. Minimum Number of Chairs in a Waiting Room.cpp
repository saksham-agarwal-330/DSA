// Problem 3168. Minimum Number of Chairs in a Waiting Room
// https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room

#include<iostream>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int n = s.length();
        int ans = 0;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == 'E'){
                count++;
            }
            else{
                count--;
            }
            ans = max(count,ans);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    string s = "ELELEEL";
    cout<<sol.minimumChairs(s)<<endl;

    return 0;
}