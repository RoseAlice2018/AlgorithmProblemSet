class Solution {
public:
    bool isvalid(string s,int begin,int end)
    {
        int temp=0;
        if(s[begin]=='0'&&begin<end)
            return false;
        for(int i = end;i>=begin;i--)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                temp+=(s[i]-'0')*pow(10,end-i);
            }
            else
            {
                return false;
            }
        }
        if(temp>=0&&temp<=255)
            return true;
        return false;
    }
    vector<string> res;
    vector<string> path;
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        backtracking(s,0);
        return res;
    }
    void backtracking(string s,int begin)
    {
        if(begin>=s.size()&&path.size()==4)
        {
            //res.push_back(path);
            string temp="";
            for(int i=0;i<path.size()-1;i++)
            {
                temp+=path[i];
                temp.push_back('.');  
            }
            temp+=path[3];
            res.push_back(temp);

            return;
        }
        if(path.size()>4)
            return;
        for(int i=begin;i<s.size();i++)
        {
            //
            if(i-begin>=3)
                return;
            if(isvalid(s,begin,i))
            {
              string t = s.substr(begin,i-begin+1);
              path.push_back(t);
              //path.push_back('.');    
            }
            else 
                continue;
            backtracking(s,i+1);
            path.pop_back();
        }
        return;
    }
};