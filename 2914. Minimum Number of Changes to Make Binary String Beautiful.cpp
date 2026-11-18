// Problem 2914. Minimum Number of Changes to Make Binary String Beautiful
// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful?envType=daily-question&envId=2026-11-18

#include<iostream>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int count=0;
        int n = s.length();

        for(int i = 0;i<n;i+=2){
            if(s[i] != s[i+1]){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    string s = "1001";

    cout<<sol.minChanges(s)<<endl;

    return 0;
}