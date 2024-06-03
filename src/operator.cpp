#include<operator.hpp>

bool compareVec(const std::vector<std::string>& v1, const std::vector<std::string>& v2) {
    return v1 < v2;
}


bool Larger(std::string s1,std::string s2)
{
    if(s1.length()<s2.length())
    {
        return 0;
    }
    if(s1.length()>s2.length())
    {
        return 1;
    }
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]>s2[i])
        {
            return 1;
        }
        if(s1[i]<s2[i])
        {
            return 0;
        }
    }
    return 0;

}
bool Smaller(std::string s1,std::string s2)
{
    if(s1.length()<s2.length())
    {
        return 1;
    }
    if(s1.length()>s2.length())
    {
        return 0;
    }
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]>s2[i])
        {
            return 0;
        }
        if(s1[i]<s2[i])
        {
            return 1;
        }
    }
    return 0;

}
bool LargerOrEual(std::string s1,std::string s2)
{
    return !Smaller(s1,s2);
}
bool SmallOrEqual(std::string s1,std::string s2)
{
    return !Larger(s1,s2);
}