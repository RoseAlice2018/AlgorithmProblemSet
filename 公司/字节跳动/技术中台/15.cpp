class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int first,second,third;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            first = i;
            int target = -nums[first];
            second=i+1;
            third=nums.size()-1;
            for(;second+1<nums.size();second++)
            {
                if(second>first+1&&nums[second]==nums[second-1])
                {
                    continue;
                }
                while(second<third&&nums[second]+nums[third]>target)
                {
                    third--;
                }
                if(second==third)
                {
                    break;
                }
                if(nums[second]+nums[third]==target)
                {
                    res.push_back({nums[first],nums[second],nums[third]});
                }
            }
        }
        return res;
    }
};