class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;
    int sum = 0;
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        backtraking(candidates,target,0,candidates.size());
        return res;
    }
    void backtraking(vector<int>& candidates,int target,int begin,int end)
    {
        if(sum>target)
            return;
        if(sum==target)
        {
            res.push_back(path);
            return;
        }    
        for(int i = begin;i<end;i++)
        {
            sum+=candidates[i];
            path.push_back(candidates[i]);
            backtraking(candidates,target,i,end);
            path.pop_back();
            sum-=candidates[i];
        }
        return;
    }
};