class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int> >& grid) {
        int origin_sum = 0;
        vector<int> top(grid[0].size()+2);
        vector<int> row(grid.size()+2);
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                origin_sum+=grid[i][j];
                if(grid[i][j]>top[j])
                {
                    top[j]=grid[i][j];
                }
                if(grid[i][j]>row[i])
                {
                    row[i]=grid[i][j];
                }
            }
        }
        int ret = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int max_val=min(top[j],row[i]);
                ret+=max_val-grid[i][j];
            }
        }
        return ret;
    }
};