// Problem 1004. Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int r =0,l=0;
        int maxLen = 0;
        int zeroCount = 0;
        while(r<n){
            if(nums[r] == 0){
                zeroCount++;
            }

            while(zeroCount > k){
                if(nums[l] == 0){
                    zeroCount--;
                }
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout<<sol.longestOnes(nums,k)<<endl;

    return 0;
}