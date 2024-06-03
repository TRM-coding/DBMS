#ifndef OPERATOR_HPP
#define OPERATOR_HPP
#include <vector>                                                                               
#include <string>

<<<<<<< HEAD

bool compareVec(const std::vector<std::string>& v1, const std::vector<std::string>& v2);


=======
>>>>>>> refs/remotes/origin/main
struct expr
{
    enum TYPE
    {
        expression,
        logic,
<<<<<<< HEAD
        _join,
=======
>>>>>>> refs/remotes/origin/main
    }type;   
    enum TAG
    {
        equal,
        noequal,
        larger,
        smaller,
        largerorequal,
        smallerorequal,
        _and,
        _or,
        _not,
<<<<<<< HEAD
        
    }tag;
    std::string val;
    std::string key;
    expr(TYPE type, TAG tag, const std::string &key, const std::string &val)
            : type(type), tag(tag), key(key), val(val) {}
};

// bool operator==(std::vector<std::string> data1,std::vector<std::string> data2);//equal


bool Larger(std::string s1,std::string s2);

bool Smaller(std::string s1,std::string s2);

bool LargerOrEual(std::string s1,std::string s2);
bool SmallOrEqual(std::string s1,std::string s2);
=======
    }tag;
    std::string val;
    std::string key;
};

bool operator==(std::vector<std::string> data1,std::vector<std::string> data2)//equal
{
    bool ans=1;
    if(data1.size()!=data2.size())
    {
        return 0;
    }
    for(int i=0;i<data1.size();i++)
    {
        if(data1[i]!=data2[i])
        {
            ans=0;
            break;
        }
    }
    return ans;
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
>>>>>>> refs/remotes/origin/main
#endif