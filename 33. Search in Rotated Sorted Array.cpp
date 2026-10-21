// Problem 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0,en = n-1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[st] <= nums[mid]){
                if(nums[st] <= target && target < nums[mid]){
                    en = mid-1;
                }
                else{
                    st = mid+1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[en]){
                    st = mid+1;
                }
                else{
                    en = mid-1;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout<<sol.search(nums,target)<<endl;

    return 0;
}