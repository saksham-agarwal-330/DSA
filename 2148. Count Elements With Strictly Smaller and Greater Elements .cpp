// Problem 2148. Count Elements With Strictly Smaller and Greater Elements 
// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int num : nums){
            mini = min(mini,num);
            maxi = max(maxi,num);
        }
        
        int ans = 0;
        for(int num : nums){
            if(mini < num && num < maxi){
                ans++;
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {11,7,2,15};
    cout<<sol.countElements(nums)<<endl;

    return 0;
}