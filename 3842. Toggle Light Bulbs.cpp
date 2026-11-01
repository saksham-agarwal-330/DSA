// Problem 3842. Toggle Light Bulbs
// https://leetcode.com/problems/toggle-light-bulbs

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool>bulbStatus(101,false);
        int n = bulbs.size();

        for(int i = 0;i<n;i++){
            bulbStatus[bulbs[i]] = !bulbStatus[bulbs[i]];
        }

        vector<int>ans;

        for(int i = 0;i<101;i++){
            if(bulbStatus[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>bulbs = {10,30,20,10};
    vector<int>ans = sol.toggleLightBulbs(bulbs);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}
