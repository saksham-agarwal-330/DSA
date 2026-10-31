// Problem 2109. Adding Spaces to a String
// https://leetcode.com/problems/adding-spaces-to-a-string

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = s.length();
        int k = 0;
        for(int i = 0;i<n;i++){
            if(k<spaces.size() && i == spaces[k]){
                ans.push_back(' ');
                k++;
            }
            ans.push_back(s[i]);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    string s = "LeetcodeHelpsMeLearn";
    vector<int>spaces = {8,13,15};

    cout<<sol.addSpaces(s,spaces)<<endl;

    return 0;
}