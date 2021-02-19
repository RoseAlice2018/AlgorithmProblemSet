#include<vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        vector<int> dic(len+5,0);
        for(int i=0;i<len;i++)
        {
            int t =citations[i];
            for(int j=0;j<=min(t,len);j++)
                dic[j]++;
        }
        for(int i=len;i>=0;i--)
        {
            if(dic[i]>=i)
                return i;
        }
        return 0;
    }
};