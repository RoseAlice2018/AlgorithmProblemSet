#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s){
        set<char> dic;
        int n = s.size();

        int right = -1, ans = 0;
        for(int i = 0;i<n;++i)
        {
            if(i!=0)
            {
                dic.erase(s[i-1]);
            }
            while((right+1<n&&!dic.count(s[right+1])))
            {
                dic.insert(s[right+1]);
                ++right;
            }
            ans = max(ans,right-i+1);
        }   
        return ans;
    }
};