// Problem 2342. Max Sum of a Pair With Equal Sum of Digits
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int calDigitSum(int num){
        int sum = 0;
        while(num != 0){
            int rem = num % 10;
            sum += rem;
            num = num / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>map;
        int n = nums.size();
        int ans = -1;

        for(int i = 0;i<n;i++){
            int sum = calDigitSum(nums[i]);
            if(map.find(sum) != map.end()){
                ans = max(ans,nums[i]+map[sum]);
            }

            map[sum] = max(map[sum],nums[i]);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {18,43,36,13,7};

    cout<<sol.maximumSum(nums)<<endl;

    return 0;
}