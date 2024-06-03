#ifndef TREE_HPP
#define TREE_HPP
<<<<<<< HEAD
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <vector>
#include <operator.hpp>
class CaculateTree
{

    

public:
    CaculateTree();

    bool delim(char c);

    bool is_op(char c);

    bool is_unary(char c);

    int priority(char op);

    void process_op(std::stack<int> &st, char op);

    bool caculate(std::string s);
};
#endif
=======
#include<iostream>                                             
#include<string>  
#include<stack> 
#include<map>    
#include<algorithm> 
#include<vector>
#include<operator.hpp>
class CaculateTree
{
    private:
    std::string tokens;
    std::string RPN;
    std::stack<char>op;
    
    public:
    CaculateTree();
    CaculateTree(std::string tokens);
    int priority(char c);
    bool isop(char c);
    bool isnum(char c);
    bool caculate(std::string RPN);
    void transtoRPN();
    bool getresult();

    
};
#endif



>>>>>>> refs/remotes/origin/main
