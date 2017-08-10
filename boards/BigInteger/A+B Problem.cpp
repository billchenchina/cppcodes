#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
namespace BCC
{
class BigInteger{
private:
    std::string int_str;
public:
    BigInteger(int value)
    {
        std::stringstream ss;
        ss<<value;
        ss>>int_str;
    }
    BigInteger(std::string str)
    {
        int_str=str;
    }
    BigInteger operator+(BigInteger big_integer2)
    {
        std::string str1=int_str;
        reverse(str1.begin(),str1.end());
        std::string str2=big_integer2.int_str;
        reverse(str2.begin(),str2.end());
        if(str1.length()<str2.length()){
            swap(str1,str2);
        }
        int x=0;
        std::string ret_based_str="";
        for(unsigned int i=0;i<str1.length();i++)
        {
            ret_based_str.append(str1.substr(i,1));
            ret_based_str[i]+=x;
            x=0;
            if(i<str2.length())
            {
                ret_based_str[i]+=str2[i]-'0';
            }
            if(ret_based_str[i]>'9')
            {
                ret_based_str[i]-=10;
                x=1;
            }
        }
        if(x==1)
        {
            ret_based_str.append("1");
        }
        reverse(ret_based_str.begin(),ret_based_str.end());
        return BigInteger(ret_based_str);
    }
    std::string getValue()
    {
        return int_str;
    }
};
}



int main()
{
    std::string str1,str2;

    std::cin>>str1>>str2;
    BCC::BigInteger b1(str1),b2(str2);
    b1=b1+b2;
    std::cout<<b1.getValue();
}
