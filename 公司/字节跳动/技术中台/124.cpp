#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
 // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(NULL), right(NULL) {}
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int ret = INT_MIN;
    int maxSum(TreeNode* root) {
        //1. root
        //2. root left
        //3. root right
        //4. left
        //5. right
        //6. root left right
        if(root==NULL)
            return 0;
        int left_max = max(maxSum(root->left),0);
        int right_max = max(maxSum(root->right),0);
        int sum=0;
        sum=root->val+left_max+right_max;
        ret=max(ret,sum);
        sum = max(left_max,right_max)+root->val;
        return sum;
    }
    int maxPathSum(TreeNode* root)
    {
        maxSum(root);
        return ret;
    }
};