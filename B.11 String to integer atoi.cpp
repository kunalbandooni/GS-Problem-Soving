// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str){
        if(str.empty())
            return 0;
        int len=str.length(),i=0,sign=1;
        while(i<len and str[i]==' ')
            i++;
        if(i==len)
            return 0;
        if(str[i]=='-'){
            sign=0;
            i++;
        }
        else if(str[i]=='+')
            i++;
        
        long long out=0;
        while(str[i]>='0' and str[i]<='9'){
            out=out*10;
            if(out<=INT_MIN || out>=INT_MAX)
                break;
            out+=(str[i]-'0');
            i++;
        }
        if(sign==0)
            out=-1*out;
        if(out<=INT_MIN)
            return INT_MIN;
        if(out>=INT_MAX)
            return INT_MAX;
        return (int)out;
    }
};
