// Problem 3745. Maximize Expression of Three Elements
// https://leetcode.com/problems/maximize-expression-of-three-elements

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int a = INT_MIN;
        int b = INT_MIN;
        int c = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(a <= nums[i]){
                b = a;
                a = nums[i];
            }
            else if(b < nums[i]){
                b = nums[i];
            }

            if(c > nums[i]){
                c = nums[i];
            }
        }

        return (a+b-c);
    }
};

int main(){
    Solution sol;
    vector<int>nums = {-2,0,5,-2,4};

    cout<<sol.maximizeExpressionOfThree(nums)<<endl;

    return 0;
}