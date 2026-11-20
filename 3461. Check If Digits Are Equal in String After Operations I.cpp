// Problem 3461. Check If Digits Are Equal in String After Operations I
// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i

#include<iostream>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() > 2){
            string temp = "";
            for(int i = 0;i<s.length()-1;i++){
                int d1 = s[i] - '0';
                int d2 = s[i+1] - '0';
                int sum = (d1 + d2)%10;
                temp.push_back(sum + '0');
            }
            s = temp;
        }

        return s[0] == s[1];
    }
};

int main(){
    Solution sol;
    string s = "3902";

    cout<<sol.hasSameDigits(s)<<endl;

    return 0;
}