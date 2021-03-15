class Solution {
public:
    vector<int> res;
    vector<int> spiralOrder(vector<vector<int> >& matrix) 
    {
        if(matrix.size()==0)
            return res;
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        int all = matrix[0].size()*matrix.size();
        while(res.size()<all)
        {
            //转圈遍历
            //一行
            for(int i = left ; i<= right&&res.size()<all;i++)
            {
                res.push_back(matrix[top][i]);
            }
            //top++;
            //一列
            for(int i = top+1;i<=bottom&&res.size()<all;i++)
            {
                res.push_back(matrix[i][right]);
            }
            //right--;
            //一行
            for(int i = right-1;i>=left&&res.size()<all;i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            //bottom--;
            for(int i = bottom-1;i>top&&res.size()<all;i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
            right--;
            top++;
            bottom--;
        }

        return res;
    }
};