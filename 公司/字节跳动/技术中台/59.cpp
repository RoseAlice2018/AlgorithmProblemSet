class Solution {
public:
    
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n,vector<int>(n));
        if(n==0)
            return res;
        int left = 0;
        int right  = n-1;
        int top = 0;
        int bottom = n-1;
        int value = 1;
        int count = 0;
        while(count<n*n)
        {
            for(int i = left ;i <= right&& count<n*n ;i++)
            {
                res[top][i]=value;
                value++;
                count++;
            }
            for(int i = top+1;i<=bottom&&count<n*n;i++)
            {
                res[i][right]=value;
                value++;
                count++;
            }
            for(int i = right-1;i>=left&&count<n*n;i--)
            {
                res[bottom][i]=value;
                value++;
                count++;
            }
            for(int i = bottom-1;i>top&&count<n*n;i--)
            {
                res[i][left]=value;
                value++;
                count++;
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};