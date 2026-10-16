// Problem 2962. Count Subarrays Where Max Element Appears at Least K Times
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxElement(vector<int> nums){
        int maxi = INT_MIN;
        for(auto num : nums){
            if(maxi < num){
                maxi = num;
            }
        }
        return maxi;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0, r=0;
        int maxi = maxElement(nums);
        long long ans = 0;
        int count = 0;
        while(r<n){
            if(nums[r] == maxi){
                count++;
            }

            while(count >= k){
                if(nums[l] == maxi){
                    count--;
                }
                l++;
            }
            ans += l;
            r++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums={1,3,2,3,3};
    int k =2;
    
    cout<<sol.countSubarrays(nums,k)<<endl;

    return 0;

}