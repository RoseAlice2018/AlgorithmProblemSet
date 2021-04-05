#include<iostream>
#include<vector>
#include<set>
using namespace std;
//* Definition for a binary tree node.
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n -1;
        int index_1 = m-1;
        int index_2 = n-1;
        while(index_1>=0&&index_2>=0)
        {
            if(nums1[index_1]>nums2[index_2])
            {
                nums1[index]=nums1[index_1];
                index--;
                index_1--;
            }
            else if(nums1[index_1]<=nums2[index_2])
            {
                nums1[index]=nums2[index_2];
                index--;
                index_2--;
            }
        }
        while (index_1>=0)
        {
            nums1[index--]=nums1[index_1--];
        }
        while(index_2>=0)
        {
            nums1[index--]=nums2[index_2--];
        }      
    }
};