// Problem 3774. Absolute Difference Between Maximum and Minimum K Elements
// https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int largeSum = 0;
        int smallSum = 0;
        for(int i =0;i<k;i++){
            smallSum += nums[i];
            largeSum += nums[n-1-i];
        }

        return abs(largeSum-smallSum);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5, 2, 2, 4};
    int k = 2;

    cout<<sol.absDifference(nums,k)<<endl;

    return 0;
}