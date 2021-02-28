class Solution {
public:
    vector<int> path;
    vector<vector<int> > res;
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        path.clear();
        res.clear();
        sort(nums.begin(),nums.end());
        backtracking(nums,0);
        return res;   
    }
    void backtracking(vector<int>& nums,int begin)
    {
        res.push_back(path);
        for(int i= begin;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
            int next = i+1;
            if(next>=nums.size())
                return;
            while(nums[next]==nums[i])
            {
                next++;
                if(next>=nums.size())
                {
                    res.push_back(path);
                    return;
                }
            }
            i = next-1;
        }
        return;
    }
};