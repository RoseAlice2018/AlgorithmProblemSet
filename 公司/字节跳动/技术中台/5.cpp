#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int> > dp(n,vector<int>(n));
        string ret;
        for(int l = 0 ;l<n;l++)
        {
            for(int i = 0;i+l < n;i++)
            {
                int j = i+l;
                if(l==0)
                    dp[i][i]=1;
                else if(l==1)
                {
                    dp[i][i+1]=(s[i]==s[i+1]);
                }
                else
                {
                    dp[i][j]=((dp[i+1][j-1])&&(s[i]==s[j]));
                    if(dp[i][j]&&l+1>ret.size())
                    {
                        ret=s.substr(i,l+1);
                    }
                }
            }
        }
        return ret;
    }
};