class Solution {
public:
    vector<int> path;
    vector<vector<int> >res;
    vector<vector<int> > subsets(vector<int>& nums) {
        path.clear();
        res.clear();
        backtracking(nums,0);
        return res;
    }
    void backtracking(vector<int>& nums,int index)
    {
        if(index>=nums.size())
        {
            res.push_back(path);
            return;
        }
        //choose
        path.push_back(nums[index]);
        backtracking(nums,index+1);
        path.pop_back();
        //not 
        backtracking(nums,index+1);
        return;
    }
};