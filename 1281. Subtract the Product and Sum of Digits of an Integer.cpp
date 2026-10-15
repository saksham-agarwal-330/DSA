// Problem 1281. Subtract the Product and Sum of Digits of an Integer

#include<iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while(n!=0){
            int digit = n%10;
            product *= digit;
            sum += digit;
            n /= 10;
        }

        return product - sum;
    }
};

int main(){
    Solution sol;

    cout<<sol.subtractProductAndSum(235)<<endl;

    return 0;
}