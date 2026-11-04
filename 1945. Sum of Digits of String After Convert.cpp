// Problem 1945. Sum of Digits of String After Convert
// https://leetcode.com/problems/sum-of-digits-of-string-after-convert

#include<iostream>
using namespace std;

class Solution {
public:
    int sumOfDigits(int num){
        int sum = 0;
        while(num != 0){
            sum += num %10;
            num = num /10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int n = s.length();
        int sum = 0;
        for(int i = 0;i<n;i++){
            int num = s[i] - 'a' + 1;
            sum += sumOfDigits(num);
        }
        k--;

        while(k > 0){
            sum = sumOfDigits(sum);
            k--; 
        }
        return sum;
    }
};

int main(){
    Solution sol;

    string s = "leetcode";
    int k = 2;
    cout<<sol.getLucky(s,k)<<endl;

    return 0;
}