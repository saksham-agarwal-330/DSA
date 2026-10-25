// 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

#include<iostream>
#include<vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<ListNode*,ListNode*> getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast -> next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return {slow,prev};
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        if(head -> next == NULL){
            return new TreeNode(head -> val);
        }

        pair<ListNode*,ListNode*>middleAndItsPrev  = getMiddle(head);
        ListNode* middle = middleAndItsPrev.first;
        ListNode* middlePrev = middleAndItsPrev.second;
        middlePrev -> next = NULL;
        
        TreeNode* root = new TreeNode(middle->val);
        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(middle-> next);

        return root;
    }
};

void buildSLL(ListNode* &head,ListNode* &tail,int data){
    ListNode* newNode = new ListNode(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> next = newNode;
        tail = newNode;
    }
}

void inoderTreeTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }

    inoderTreeTraversal(root -> left);
    cout<<root -> val<<" ";
    inoderTreeTraversal(root -> right);
}

int main(){
    Solution sol;
    vector<int>nums = {-10,-3,0,5,9};
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for(auto num:nums){
        buildSLL(head,tail,num);
    }

    TreeNode* root = sol.sortedListToBST(head);
    inoderTreeTraversal(root);

    return 0;
}