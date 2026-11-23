// Problem 1784. Check if Binary String Has at Most One Segment of Ones
// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones


#include<iostream>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length()-1;
        for(int i = 0;i<n;i++){
            if(s[i] == '0' && s[i+1] == '1'){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s = "1001";
    cout<<sol.checkOnesSegment(s)<<endl;

    return 0;
}