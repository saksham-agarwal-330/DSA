// Problem 2202. Maximize the Topmost Element After K Moves
// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = -1;
        if(n == 1 && k%2 != 0){
            return maxi;
        }
        for(int i =0;i<min(n,k-1);i++){
            maxi = max(nums[i],maxi);
        }
        if(k<n){
            maxi = max(nums[k],maxi);
        }
        return maxi;
    }
};

int main(){
    Solution sol;

    vector<int>nums={5,2,2,4,0,6};
    int k = 4;
    cout<<sol.maximumTop(nums,k)<<endl;

    return 0;
}