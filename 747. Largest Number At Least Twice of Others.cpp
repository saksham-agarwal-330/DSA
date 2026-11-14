// Problem 747. Largest Number At Least Twice of Others
// https://leetcode.com/problems/largest-number-at-least-twice-of-others

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int maxIdx = -1;
        for(int i =0;i<n;i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxIdx = i;
            }
        }

        for(int i = 0;i<n;i++){
            if(maxIdx != i && (maxi < 2*nums[i])){
                return -1;
            }
        }

        return maxIdx;
    }
};

int main(){
    Solution sol;

    vector<int>nums= {3,6,1,0};
    cout<<sol.dominantIndex(nums)<<endl;

    return 0;
}