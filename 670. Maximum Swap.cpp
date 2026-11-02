// Problem 670. Maximum Swap
// https://leetcode.com/problems/maximum-swap

#include<iostream>
using namespace std;

class Solution {
public:
    string convertToString(int num){
        string revNumStr = "";
        while(num != 0){
            int rem = num%10;
            revNumStr.push_back(rem + '0');
            num = num/10;
        }
        return revNumStr;
    }
    int convertToNum(string numStr){
        int num = 0;
        int n = numStr.size();
        for(int i =n-1;i>=0;i--){
            num = num*10 + (numStr[i]-'0');
        }
        return num;
    }
    int maximumSwap(int num) {
        if(num <= 9){
            return num;
        }
        
        string revNumStr = convertToString(num);
        // 6372
        int maxIdx = -1, swap1 = -1,swap2 = -1;

        for(int i = 0;i<revNumStr.size();i++){
            if(maxIdx == -1 || revNumStr[i] > revNumStr[maxIdx]){
                maxIdx = i;
            }
            else if(revNumStr[i] < revNumStr[maxIdx]){
                swap1 = i;
                swap2 = maxIdx;
            }
        }

        if(swap1 == -1){
            return num;
        }

        swap(revNumStr[swap1],revNumStr[swap2]);

        return convertToNum(revNumStr);
    }
};

int main(){
    Solution sol;
    int num = 2736;
    int ans = sol.maximumSwap(num);
    cout<<ans<<endl;

    return 0;
}