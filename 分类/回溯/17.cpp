class Solution {
public:
    string dic[11] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string path;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits.size()==0)
            return res;
        backtracking(digits,0);
        return res;
    }
    void backtracking(string& digits,int index)
    {
        if(index==digits.size())
        {
            res.push_back(path);
            return;
        }
        int dic_num = digits[index]-'0';
        for(int i=0;i<dic[dic_num].size();i++)
        {
            path.push_back(dic[dic_num][i]);
            backtracking(digits,index+1);
            path=path.substr(0,path.size()-1);
        }
        return;
    }
};