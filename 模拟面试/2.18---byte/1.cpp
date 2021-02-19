#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int gcd(int a,int b)
    {
        if(a%b==0)
            return b;
        else ;
        return gcd(b,a%b);
    }
    void min_div(int& father,int& son)
    {
        int t=gcd(father,son);
        father/=t;
        son/=t;
        return;
    }
    vector<int> fraction(vector<int>& cont) {
        vector<int> res;
        if(cont.size()==1)
        {
            res.push_back(cont[0]);
            res.push_back(1);
            return res;
        }
        else if(cont.size()<1)
        {
            return res;
        }
        else
        {
            res.push_back(1);
            res.push_back(cont[cont.size()-1]);
            return fraction_1(cont,cont.size()-2,res);
        }
    }
    vector<int> fraction_1(vector<int>& cont,int i,vector<int>& before)
    {
        int a0=cont[i];
        int a1=before[1];
        int a2=before[0];
        int son=a0*a1+a2;
        int father=a1;
        min_div(father>son?father:son,father>son?son:father);
        before[0]=son;
        before[1]=father;
        if(i==0)
        {
            return before;
        }
        else
        {
            int temp=before[0];
            before[0]=before[1];
            before[1]=temp;
            return fraction_1(cont,i-1,before);
        }
    }
};