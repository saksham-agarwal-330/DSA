// Problem 3974. Maximum Total Sum of K Selected Elements
// https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(),nums.rend());
        long long sum = 0;
        for(int i =0;i<k;i++){
            long long val = nums[i];
            if(mul>0){
                val = val*mul;
                mul--;
            }
            sum+=val;
        }

        return sum;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {6,1,2,9};
    int k = 3, mul = 2;

    cout<<sol.maxSum(nums,k,mul)<<endl;

    return 0;
}