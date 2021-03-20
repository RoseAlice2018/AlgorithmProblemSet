#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int> > dp(s.size()+1,vector<int>(s.size()+2));
        int len = 0;
        string ret;
        for(len=0;len<s.size();len++)
        {
            for(int i = 0;i+len<s.size();i++)
            {
                int j=i+len;
                if(j==i+1)
                {
                    dp[i][j]=(s[i]==s[j])?1:0;
                }
                else if(len==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    if(dp[i+1][j-1])
                    {
                        dp[i][j]=(s[i]==s[j])?1:0;
                    }
                }
                 if(dp[i][j]&&len+1>ret.size())
                            ret = s.substr(i,len+1);
            }
        }
        return ret;
    }
};