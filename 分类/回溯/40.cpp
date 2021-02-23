class Solution {
public:
    int sum = 0;
    vector<int> path;
    vector<vector<int> > res;
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        sort(candidates.begin(),candidates.end());
        backtarcking(candidates,target,0);
        return res;

    }
    void backtarcking(vector<int>& candidates, int target,int begin)
    {
        if(sum>target)
        {
            return;
        }
        if(sum==target)
        {
            res.push_back(path);
            return;
        }
        for(int i=begin;i<candidates.size();i++)
        {
            int t=candidates[i];
            sum+=t;
            path.push_back(t);
            backtarcking(candidates,target,i+1);
            sum-=t;
            path.pop_back();
            int next = i+1;
            if(next>=candidates.size())
                return;
            while(candidates[next]==t)
            {
                next++;
                if(next>=candidates.size())
                    return;
            }
            i=next-1;
        }
        return;
    }
};