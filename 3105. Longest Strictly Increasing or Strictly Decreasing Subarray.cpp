// Problem 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray?envType=daily-question&envId=2026-11-12

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int inc = 0;
        int dec = 0;
        int maxi = 0;
        while(r<n-1){
            if(nums[r] < nums[r+1]){
                inc++;
                dec = 0;
            }
            else if(nums[r] > nums[r+1]){
                dec++;
                inc = 0;
            }
            else{
                inc = 0;
                dec = 0;
            }
            r++;

            maxi = max(maxi,max(inc,dec));
        }

        return maxi + 1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 4, 3, 3, 2};
    cout<<sol.longestMonotonicSubarray(nums)<<endl;

    return 0;
}