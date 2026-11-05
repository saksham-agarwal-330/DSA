// Problem 648. Replace Words
// https://leetcode.com/problems/replace-words

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>dict;
        for(string root : dictionary){
            dict.insert(root);
        }

        int n = sentence.length();
        string ans = "";
        string temp = "";
        int i = 0;
        while(i<n){ 
            if(sentence[i] == ' '){
                ans += temp + " ";
                temp = "";
            }
            else{
                temp.push_back(sentence[i]);
                if(dict.find(temp) != dict.end()){
                    int j = i;
                    while(j<n-1 && sentence[j+1] != ' '){
                        j++;
                    }
                    i = j;
                }
            }
            i++;
        }

        ans += temp;

        return ans;
    }
};

int main(){
    vector<string>dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    Solution sol;
    string ans = sol.replaceWords(dictionary,sentence);

    cout<<ans<<endl;

    return 0;
}