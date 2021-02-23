class Solution {
public:
    int sum=0;
    vector<int> path;
    vector<vector<int> > res;
    vector<vector<int> > combinationSum3(int k, int n) {
        path.clear();
        res.clear();
        backtracking(1,n,k);
        return res;
    }
    void backtracking(int begin,int target,int k)
    {
        if(target == sum && path.size()==k)
        {
            res.push_back(path);
            return;
        }
        else if(sum>target||path.size()>k||target==sum)
        {
            return;
        }
        for(int i=begin;i<=9;i++)
        {
            sum+=i;
            path.push_back(i);
            backtracking(i+1,target,k);
            sum-=i;
            path.pop_back();
        }
        return;
    }
};