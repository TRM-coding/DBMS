#include<tree.hpp>

<<<<<<< HEAD


CaculateTree::CaculateTree(){}

bool CaculateTree:: delim(char c) { return c == ' '; }

bool CaculateTree:: is_op(char c) { return c == '&' || c == '|' || c == '!'; }

bool CaculateTree:: is_unary(char c) { return c == '!'; }

int CaculateTree:: priority(char op)
{
    if (op < 0) // unary operator
        return 3;
    if (op == '|' )
        return 1;
    if (op == '&' )
        return 2;
    return -1;
}

void CaculateTree:: process_op(std::stack<int> &st, char op)
{
    if (op < 0)
    {
        int l = st.top();
        st.pop();
        switch (-op)
        {
        case '!':
            st.push(!l);
            break;
        case '-':
            st.push(-l);
            break;
        }
    }
    else
    { // 取出栈顶元素，注意顺序
        int r = st.top();
        st.pop();
        int l = st.top();
        st.pop();
        switch (op)
        {
        case '&':
            st.push(l && r);
            break;
        case '|':
            st.push(l || r);
            break;
        case '*':
            st.push(l * r);
            break;
        case '/':
            st.push(l / r);
            break;
        }
    }
}

bool CaculateTree:: caculate(std::string s)
{
    std::stack<int> st;
    std::stack<char> op;
    bool may_be_unary = true;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (delim(s[i]))
            continue;

        if (s[i] == '(')
        {
            op.push('('); // 2. 如果遇到左括号，那么将其放在运算符栈上
            may_be_unary = true;
        }
        else if (s[i] == ')')
        { // 3. 如果遇到右括号，执行一对括号内的所有运算符
            while (op.top() != '(')
            {
                process_op(st, op.top());
                op.pop(); // 不断输出栈顶元素，直至遇到左括号
            }
            op.pop(); // 左括号出栈
            may_be_unary = false;
        }
        else if (is_op(s[i]))
        { // 4. 如果遇到其他运算符
            char cur_op = s[i];
            if (may_be_unary && is_unary(cur_op))
                cur_op = -cur_op;
            while (!op.empty() &&
                   ((cur_op >= 0 && priority(op.top()) >= priority(cur_op)) ||
                    (cur_op < 0 && priority(op.top()) > priority(cur_op))))
            {
                process_op(st, op.top());
                op.pop(); // 不断输出所有运算优先级大于等于当前运算符的运算符
            }
            op.push(cur_op); // 新的运算符入运算符栈
            may_be_unary = true;
        }
        else
        { // 1. 如果遇到数字，直接输出该数字
            int number = 0;
            while (i < (int)s.size() && isalnum(s[i]))
                number = number * 10 + s[i++] - '0';
            --i;
            st.push(number);
            may_be_unary = false;
        }
    }

    while (!op.empty())
    {
        process_op(st, op.top());
        op.pop();
    }
    return st.top();
}

=======
CaculateTree::CaculateTree(std::string tokens)
{
    this->tokens=tokens;
}
CaculateTree::CaculateTree(){}

int CaculateTree::priority(char c)
{
    if(c=='+')return 1;
    else if(c=='*'){
        return 2;
    }
    else if(c=='('){
        return 0;
    }
    return -1;
}

bool CaculateTree::isop(char c)
{
    return c=='+'||c=='*'||c=='('||c==')';
}

bool CaculateTree::isnum(char c)
{
    return !isop(c);
}

bool CaculateTree::caculate(std::string RPN)
{
    std::stack<int>num;
    for(auto x:RPN){
        if(isnum(x)){
            num.push(x-'0');
        }
        else if(isop(x)){
            int a=num.top();
            num.pop();
            int b=num.top();
            num.pop();
            if(x=='&'){
                num.push(a&&b);
            }
            else if(x=='|'){
                num.push(a|b);
            }
        }
    }
    return num.top();
}

void CaculateTree::transtoRPN()
{
    RPN.clear();
    for(auto x:tokens){
        if(isnum(x)){
            RPN+=x;
        }
        else if(isop(x)){
            if(op.empty()||x=='('){
                op.push(x);
            }
            else if(x==')'){
                while(op.top()!='('){
                    RPN+=op.top();
                    op.pop();
                }
                op.pop();
            }
            else{
                while(!op.empty()&&priority(op.top())>=priority(x)){
                    RPN+=op.top();
                    op.pop();
                }
                op.push(x);
            }
        }
    }
    while(!op.empty()){
        RPN+=op.top();
        op.pop();
    }
}

bool CaculateTree::getresult()
{
    transtoRPN();
    return caculate(RPN);
}
>>>>>>> refs/remotes/origin/main
