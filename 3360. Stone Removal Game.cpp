// Problem 3360. Stone Removal Game
// https://leetcode.com/problems/stone-removal-game?envType=daily-question&envId=2026-11-26

#include<iostream>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        bool aliceTurn = true;

        while(n >= remove){
            n -= remove;
            remove--;

            aliceTurn = !aliceTurn;
        }

        return !aliceTurn;
    }
};

int main(){
    Solution sol;
    int n = 12;
    cout<<sol.canAliceWin(n)<<endl;

    return 0;
}