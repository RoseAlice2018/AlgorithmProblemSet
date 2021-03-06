
int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    unordered_set<int> dic;
    int res_min_positive_interger = 1;
    for(int i=0;i<A.size();i++)
    {
        if(dic.count(A[i]))
            ;
        else 
            dic.insert(A[i]);
        while(dic.count(res_min_positive_interger))
        {
            res_min_positive_interger++;
        }
    }
    return res_min_positive_interger;
}

