class Solution {
public:
    int trap(vector<int>& height) {
        int left_max=0,right_max=0;
        int left = 0,right = height.size()-1;
        int ret = 0;
        while(left<=right)
        {
            if(left_max<right_max)
            {
                ret += max(0,left_max-height[left]);
                left_max = max(left_max,height[left]);
                left++;
            }
            else 
            {
                ret += max(0,right_max-height[right]);
                right_max = max(right_max,height[right]);
                right--;
            }
        }
        return ret;
    }
};