#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n =  bits.size();
        if(bits[n-1]=='1')
            return false;
        else 
        {
            //此时最后一个字符假设为单比特
            //从前遍历
            int index = 0;
            while(index<n-1)
            {
                if(bits[index]=='0')
                {
                    index++;
                }
                else 
                {
                    index+=2;
                }
            }
            if(index==n-1)
                return true;
            else 
                return false;
        }
        return false;
        
    }
};