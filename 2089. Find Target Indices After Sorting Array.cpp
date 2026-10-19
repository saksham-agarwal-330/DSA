// Problem 2089. Find Target Indices After Sorting Array
// https://leetcode.com/problems/find-target-indices-after-sorting-array?envType=daily-question&envId=2026-10-19

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>nums,int target){
        int n = nums.size();
        int st = 0,en = n-1;
        int ans = -1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(nums[mid] == target){
                ans = mid;
                en = mid-1;
            }
            else if(nums[mid] > target){
                en = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }
    int upperBound(vector<int>nums,int target){
        int n = nums.size();
        int st = 0,en = n-1;
        int ans = -1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(nums[mid] == target){
                ans = mid;
                st = mid+1;
            }
            else if(nums[mid] > target){
                en = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int st = lowerBound(nums,target);
        int en = upperBound(nums,target);
        vector<int>ans;
        if(st == -1 || en == -1){
            return ans;
        }
        for(int i=st;i<=en;i++){
            ans.push_back(i);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums={1,2,5,2,3};
    int target = 2;

    vector<int>ans = sol.targetIndices(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;
}
