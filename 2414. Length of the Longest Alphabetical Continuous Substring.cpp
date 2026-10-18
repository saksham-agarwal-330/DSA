// Problem 2414. Length of the Longest Alphabetical Continuous Substring
// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring

#include<iostream>
using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        int i=0;

        while(i<n){
            int j = i+1;
            while(j<n && s[j] - s[j-1] == 1){
                j++;
            }

            maxi = max(maxi,j-i);
            i = j;
        }

        return maxi;
    }
};

int main(){
    Solution sol;
    string s = "abdefgh";
    cout<<sol.longestContinuousSubstring(s)<<endl;

    return 0;
}