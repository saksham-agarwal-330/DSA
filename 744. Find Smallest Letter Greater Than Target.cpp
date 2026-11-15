// Problem 744. Find Smallest Letter Greater Than Target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int st = 0,en = n-1;
        char ans = letters[0];
        while(st <= en){
            int mid = st + (en-st)/2;
            if(letters[mid] <= target){
                st = mid +1;
            }
            else{
                ans = letters[mid];
                en = mid -1 ;
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<char> letters = {'c','f','z'};
    char target = 'a';

    cout<<sol.nextGreatestLetter(letters,target)<<endl;

    return 0;
}