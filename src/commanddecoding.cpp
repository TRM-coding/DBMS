<<<<<<< HEAD
#include <commanddecoding.hpp>
=======
#include <commanddecoding.hpp>                                           
>>>>>>> refs/remotes/origin/main
#include <tablemanager.hpp>
#include <usermanage.hpp>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
<<<<<<< HEAD
#include <user.hpp>

// Result CommandDecoding::getResult() {
//     return res;
// }

// 对原始的sql语句按空格切分
std::vector<std::string> CommandDecoding::split(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter))
    {
=======

// 对原始的sql语句按空格切分
std::vector<std::string> CommandDecoding::split(const std::string &str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
>>>>>>> refs/remotes/origin/main
        tokens.push_back(token);
    }
    return tokens;
}

// 解码器
<<<<<<< HEAD
CommandDecoding::CommandDecoding(const std::string &sqlstatement, User user, Ans &ans)
{
    // this->res = Result();
    TableManager Manager(user);
    std::vector<std::string> tokens = split(sqlstatement, ' ');

    auto token = tokens.begin();
    while (token != tokens.end())
    {
        if (command_set.find(*token) != command_set.end())
        {
            if (*token == "create")
            {
                ++token;
                if (token != tokens.end() && *token == "table")
                { // 创建表
                    ++token;
                    parseCreate(token, tokens, Manager, ans);
                }
                else if (token != tokens.end() && *token == "user")
                { // 创建用户
=======
CommandDecoding::CommandDecoding(const std::string &sqlstatement) {
    TableManager Manager;
    std::vector<std::string> tokens = split(sqlstatement, ' ');

    auto token = tokens.begin();
    while (token != tokens.end()) {
        if (command_set.find(*token) != command_set.end()) {
            if (*token == "create") {
                ++token;
                if (token != tokens.end() && *token == "table") {//创建表
                    ++token;
                    parseCreate(token, tokens,Manager);
                } else if (token != tokens.end() && *token == "user") {//创建用户
>>>>>>> refs/remotes/origin/main
                    ++token;
                    std::string username = *token;
                    ++token;
                    ++token;
                    ++token;
                    std::string password = *token;
<<<<<<< HEAD
                    UserManager::CreateUser(username, password, ans);
                }
                else
                {
                    return;
                }
            }
            else if (*token == "drop")
            {
                ++token;
                if (token != tokens.end() && *token == "table")
                { // 删除表
                    ++token;
                    Manager.DropTable(*token, ans);
                }
                else if (token != tokens.end() && *token == "user")
                { // 删除用户
                    ++token;
                    UserManager::DropUser(*token, ans);
                }
                else
                {
                    return;
                }
            }
            else if (*token == "select")
            { // 查询数据
                parseSelect(token, tokens, Manager, ans);
            }
            else if (*token == "delete")
            { // 删除数据
                parseDelete(token, tokens, Manager, ans);
            }
            else if (*token == "update")
            { // 修改数据
                parseUpdate(token, tokens, Manager, ans);
            }
            else if (*token == "insert")
            { // 增加数据
                parseInsert(token, tokens, Manager, ans);
            }
            else if (*token == "grant")
            { // 用户授权
                parseGrant(token, tokens, Manager, ans);
            }
            else if (*token == "revoke")
            { // 用户权限移除
                parseRevoke(token, tokens, Manager, ans);
            }
            else if (*token == "alter")
            { // 更改表
                parseAlter(token, tokens, Manager, ans);
            }
        }
        else
        {
=======
                    UserManager::CreateUser(username, password);
                } else {
                    return;
                }
            } else if (*token == "drop") {
                ++token;
                if (token != tokens.end() && *token == "table") {//删除表
                    ++token;
                    Manager.DropTable(*token);
                } else if (token != tokens.end() && *token == "user") {//删除用户
                    ++token;
                    UserManager::DropUser(*token);
                } else {
                    return;
                }
            } else if (*token == "select") {//查询数据
                parseSelect(token, tokens,Manager);
            } else if (*token == "delete") {//删除数据
                parseDelete(token, tokens,Manager);
            } else if (*token == "update") {//修改数据
                parseUpdate(token, tokens,Manager);
            } else if (*token == "insert") {//增加数据
                parseInsert(token, tokens,Manager);
            } else if (*token == "grant") {//用户授权
                parseGrant(token, tokens,Manager);
            } else if (*token == "revoke") {//用户权限移除
                parseRevoke(token, tokens,Manager);
            } else if (*token == "alter") {//更改表
                parseAlter(token, tokens,Manager);
            }
        } else {
>>>>>>> refs/remotes/origin/main
            return;
        }
    }
}

<<<<<<< HEAD
CommandDecoding::~CommandDecoding() = default;

void CommandDecoding::parseCreate(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,
                                  TableManager &Manager, Ans &ans)
{
    std::string table_name;
    std::vector<std::pair<std::string, std::string>> foreign;
    std::vector<std::vector<std::pair<std::string, std::string>>> settings;
    std::map<std::string, bool> deletejoint;
    std::map<std::string, bool> updatejoint;

    if (token == tokens.end())
        return;
=======

void CommandDecoding::parseCreate(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager) {
    std::string table_name;
    std::vector<std::pair<std::string, std::string>> foreign;
    std::vector<std::vector<std::pair<std::string, std::string>>> settings;

    if (token == tokens.end()) return;
>>>>>>> refs/remotes/origin/main

    // 获取表名
    table_name = *token;
    ++token;

<<<<<<< HEAD
    if (token == tokens.end() || *token != "(")
        return;

    ++token; // 跳过 '('

    while (token != tokens.end() && *token != ")")
    {
        std::vector<std::pair<std::string, std::string>> tmp = {{"name", "0"},
                                                                {"type", "0"},
                                                                {"primary key", "0"},
                                                                {"null", "1"},
                                                                {"unique", "0"},
                                                                {"default", "0"}};
=======
    if (token == tokens.end() || *token != "(") return;

    ++token; // 跳过 '('

    while (token != tokens.end() && *token != ")") {
        std::vector<std::pair<std::string, std::string>> tmp = {{"name",        "0"},
                                                                {"type",        "0"},
                                                                {"primary key", "0"},
                                                                {"null",        "1"},
                                                                {"unique",      "0"},
                                                                {"default",     "0"}};
>>>>>>> refs/remotes/origin/main

        std::string column_name = *token;
        tmp[0].second = column_name; // 设置列名
        ++token;

        std::string column_type = *token;
        tmp[1].second = column_type; // 设置列类型
        ++token;

        bool is_foreign_key = false;
        std::string ref_table, ref_column;
        std::string on_delete_action, on_update_action; // 外键信息

<<<<<<< HEAD
        while (token != tokens.end() && *token != "," && *token != ")")
        {
            if (*token == "primary")
            {
                ++token;
                if (token != tokens.end() && *token == "key")
                {
                    tmp[2].second = "1"; // 设置主键
                    ++token;
                }
            }
            else if (*token == "not")
            {
                ++token;
                if (token != tokens.end() && *token == "null")
                {
                    tmp[3].second = "0"; // 设置非空
                    ++token;
                }
            }
            else if (*token == "unique")
            {
                tmp[4].second = "1"; // 设置唯一
                ++token;
            }
            else if (*token == "default")
            {
                ++token;
                if (token != tokens.end())
                {
                    tmp[5].second = *token; // 设置默认值
                    ++token;
                }
            }
            else if (*token == "foreign")
            {
                ++token;
                if (token != tokens.end() && *token == "key")
                {
                    ++token;
                    if (token != tokens.end() && *token == "references")
                    {
                        ++token;
                        if (token != tokens.end())
                        {
                            ref_table = *token; // 参考的表名
                            ++token;
                            if (token != tokens.end() && *token == "(")
                            {
                                ++token;
                                if (token != tokens.end())
                                {
                                    ref_column = *token; // 参考表中的列名
                                    is_foreign_key = true;
                                    ++token;
                                    if (token != tokens.end() && *token == ")")
                                    {
=======
        while (token != tokens.end() && *token != "," && *token != ")") {
            if (*token == "primary") {
                ++token;
                if (token != tokens.end() && *token == "key") {
                    tmp[2].second = "1"; // 设置主键
                    ++token;
                }
            } else if (*token == "not") {
                ++token;
                if (token != tokens.end() && *token == "null") {
                    tmp[3].second = "0"; // 设置非空
                    ++token;
                }
            } else if (*token == "unique") {
                tmp[4].second = "1"; // 设置唯一
                ++token;
            } else if (*token == "default") {
                ++token;
                if (token != tokens.end()) {
                    tmp[5].second = *token; // 设置默认值
                    ++token;
                }
            } else if (*token == "foreign") {
                ++token;
                if (token != tokens.end() && *token == "key") {
                    ++token;
                    if (token != tokens.end() && *token == "references") {
                        ++token;
                        if (token != tokens.end()) {
                            ref_table = *token; // 参考的表名
                            ++token;
                            if (token != tokens.end() && *token == "(") {
                                ++token;
                                if (token != tokens.end()) {
                                    ref_column = *token; // 参考表中的列名
                                    is_foreign_key = true;
                                    ++token;
                                    if (token != tokens.end() && *token == ")") {
>>>>>>> refs/remotes/origin/main
                                        ++token;
                                    }
                                }
                            }
                        }
                    }
                }
<<<<<<< HEAD
            }
            else if (*token == "on")
            {
                ++token;
                if (token != tokens.end() && *token == "delete")
                {
                    ++token;
                    if (token != tokens.end() && (*token == "cascade" || *token == "restrict"))
                    {
                        on_delete_action = *token;
                        ++token;
                    }
                }
                else if (token != tokens.end() && *token == "update")
                {
                    ++token;
                    if (token != tokens.end() && (*token == "cascade" || *token == "restrict"))
                    {
                        on_update_action = *token;
                        ++token;
                    }
                }
            }
            else
            {
=======
            } else if (*token == "on") {
                ++token;
                if (token != tokens.end() && *token == "delete") {
                    ++token;
                    if (token != tokens.end() && *token == "cascade") {
                        on_delete_action = "cascade";
                        ++token;
                    }
                } else if (token != tokens.end() && *token == "update") {
                    ++token;
                    if (token != tokens.end() && *token == "cascade") {
                        on_update_action = "cascade";
                        ++token;
                    }
                }
            } else {
>>>>>>> refs/remotes/origin/main
                ++token;
            }
        }

        settings.push_back(tmp);

<<<<<<< HEAD
        if (is_foreign_key)
        {
            foreign.emplace_back(ref_table, ref_column);
            deletejoint[ref_column] = (on_delete_action == "cascade");
            updatejoint[ref_column] = (on_update_action == "cascade");
        }
        else
        {
            foreign.emplace_back("", "");
        }

        if (token != tokens.end() && *token == ",")
        {
=======
        if (is_foreign_key) {
            foreign.emplace_back(ref_table + (on_delete_action.empty() ? "" : " on delete " + on_delete_action) +
                                 (on_update_action.empty() ? "" : " on update " + on_update_action), ref_column);
        } else {
            foreign.emplace_back("", "");
        }

        if (token != tokens.end() && *token == ",") {
>>>>>>> refs/remotes/origin/main
            ++token; // 跳过 ','
        }
    }

<<<<<<< HEAD
    Manager.CreateTable(table_name, settings, foreign, deletejoint, updatejoint, ans);
}

void CommandDecoding::parseSelect(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,
                                  TableManager &Manager, Ans &ans)
{
=======
    Manager.CreateTable(table_name, settings, foreign);
}

void CommandDecoding::parseSelect(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager) {
>>>>>>> refs/remotes/origin/main
    ++token; // 跳过 "select"

    std::vector<std::string> attrname;
    std::vector<std::string> tablename;
    std::vector<expr> condition;
    std::vector<std::pair<std::string, bool>> order_by;

    // 解析列名
<<<<<<< HEAD
    while (token != tokens.end() && *token != "from")
    {
        if (*token != ",")
        {
=======
    while (token != tokens.end() && *token != "from") {
        if (*token != ",") {
>>>>>>> refs/remotes/origin/main
            attrname.push_back(*token);
        }
        ++token;
    }

<<<<<<< HEAD
    if (token == tokens.end() || *token != "from")
        return;
    ++token; // 跳过 "from"

    // 解析表名
    while (token != tokens.end() && *token != "join" && *token != "where" && *token != "order")
    {
        if (*token != ",")
        {
=======
    if (token == tokens.end() || *token != "from") return;
    ++token; // 跳过 "from"

    // 解析表名
    while (token != tokens.end() && *token != "join" && *token != "where" && *token != "order") {
        if (*token != ",") {
>>>>>>> refs/remotes/origin/main
            tablename.push_back(*token);
        }
        ++token;
    }

    // 解析 join 语句
<<<<<<< HEAD
    while (token != tokens.end() && *token == "join")
    {
        ++token; // 跳过 "join"
        if (token == tokens.end())
            return;
=======
    while (token != tokens.end() && *token == "join") {
        ++token; // 跳过 "join"
        if (token == tokens.end()) return;
>>>>>>> refs/remotes/origin/main

        std::string join_table = *token;
        tablename.push_back(join_table);
        ++token;

<<<<<<< HEAD
        if (token == tokens.end() || *token != "on")
            return;
        ++token; // 跳过 "on"

        if (token == tokens.end())
            return;

        std::string left_expr = *token;
        ++token;
        if (token == tokens.end() || *token != "=")
            return;
        ++token; // 跳过 "="

        if (token == tokens.end())
            return;

        std::string right_expr = *token;
        condition.emplace_back(expr::_join, expr::equal, left_expr, right_expr);
=======
        if (token == tokens.end() || *token != "on") return;
        ++token; // 跳过 "on"

        if (token == tokens.end()) return;

        std::string left_expr = *token;
        ++token;
        if (token == tokens.end() || *token != "=") return;
        ++token; // 跳过 "="

        if (token == tokens.end()) return;

        std::string right_expr = *token;
        condition.emplace_back(expr::expression, expr::equal, left_expr, right_expr);
>>>>>>> refs/remotes/origin/main
        ++token;
    }

    // 解析 where 语句
<<<<<<< HEAD
    if (token != tokens.end() && *token == "where")
    {
        ++token; // 跳过 "where"
        while (token != tokens.end() && *token != "order")
        {
            if (*token == "not")
            {
                expr::TAG logicTag = expr::_not;
                condition.emplace_back(expr::logic, logicTag, "", "");
                ++token;
            } // 解析非

            std::string left_expr = *token;
            ++token;

            if (token == tokens.end())
                return;
=======
    if (token != tokens.end() && *token == "where") {
        ++token; // 跳过 "where"
        while (token != tokens.end() && *token != "order") {
            std::string left_expr = *token;
            ++token;

            if (token == tokens.end()) return;
>>>>>>> refs/remotes/origin/main

            std::string op = *token;
            expr::TAG tag;

<<<<<<< HEAD
            if (op == "=")
                tag = expr::equal;
            else if (op == "!=")
                tag = expr::noequal;
            else if (op == ">")
                tag = expr::larger;
            else if (op == "<")
                tag = expr::smaller;
            else if (op == ">=")
                tag = expr::largerorequal;
            else if (op == "<=")
                tag = expr::smallerorequal;
            else
                return;

            ++token;

            if (token == tokens.end())
                return;
=======
            if (op == "=") tag = expr::equal;
            else if (op == "!=") tag = expr::noequal;
            else if (op == ">") tag = expr::larger;
            else if (op == "<") tag = expr::smaller;
            else if (op == ">=") tag = expr::largerorequal;
            else if (op == "<=") tag = expr::smallerorequal;
            else return;

            ++token;

            if (token == tokens.end()) return;
>>>>>>> refs/remotes/origin/main

            std::string right_expr = *token;
            condition.emplace_back(expr::expression, tag, left_expr, right_expr);
            ++token;

<<<<<<< HEAD
            if (token != tokens.end())
            {
                if (*token == "and" || *token == "or" || *token == "not")
                {
                    expr::TAG logicTag;
                    if (*token == "and")
                    {
                        logicTag = expr::_and;
                    }
                    else if (*token == "or")
                    {
                        logicTag = expr::_or;
                    }
                    else if (*token == "not")
                    {
=======
            if (token != tokens.end()) {
                if (*token == "and" || *token == "or" || *token == "not") {
                    expr::TAG logicTag;
                    if (*token == "and") {
                        logicTag = expr::_and;
                    } else if (*token == "or") {
                        logicTag = expr::_or;
                    } else if (*token == "not") {
>>>>>>> refs/remotes/origin/main
                        logicTag = expr::_not;
                    }
                    condition.emplace_back(expr::logic, logicTag, "", "");
                    ++token; // 跳过 "and"、"or" 或 "not"
                }
            }
        }
    }

    // 解析 order by 语句
<<<<<<< HEAD
    if (token != tokens.end() && *token == "order")
    {
        ++token; // 跳过 "order"
        if (token != tokens.end() && *token == "by")
        {
            ++token; // 跳过 "by"
            while (token != tokens.end())
            {
=======
    if (token != tokens.end() && *token == "order") {
        ++token; // 跳过 "order"
        if (token != tokens.end() && *token == "by") {
            ++token; // 跳过 "by"
            while (token != tokens.end()) {
>>>>>>> refs/remotes/origin/main
                std::string column = *token;
                ++token;
                bool order = 1; // 默认升序

<<<<<<< HEAD
                if (token != tokens.end() && (*token == "asc" || *token == "desc"))
                {
                    // order = *token;
                    if (*token == "desc")
                        order = 0;

=======
                if (token != tokens.end() && (*token == "asc" || *token == "desc")) {
                    // order = *token;
                    if(*token == "desc") order = 0;
        
>>>>>>> refs/remotes/origin/main
                    ++token;
                }

                order_by.emplace_back(column, order);

<<<<<<< HEAD
                if (token != tokens.end() && *token == ",")
                {
=======
                if (token != tokens.end() && *token == ",") {
>>>>>>> refs/remotes/origin/main
                    ++token; // 跳过 ","
                }
            }
        }
    }
<<<<<<< HEAD
    std::vector<std::vector<std::string>> res;
    res = Manager.Select(tablename, attrname, condition, order_by, ans);
    for (auto x : res)
    {
        for (auto y : x)
        {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }
    return;
}

void CommandDecoding::parseDelete(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,
                                  TableManager &Manager, Ans &ans)
{
=======

    Manager.Select(tablename, attrname, condition, order_by);
}

void CommandDecoding::parseDelete(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager) {
>>>>>>> refs/remotes/origin/main
    ++token; // 跳过 "delete"

    std::string tablename;
    std::vector<expr> condition;

<<<<<<< HEAD
    if (token == tokens.end() || *token != "from")
        return;
=======
    if (token == tokens.end() || *token != "from") return;
>>>>>>> refs/remotes/origin/main
    ++token; // 跳过 "from"

    tablename = *token; // 获取表名
    ++token;

    // 解析 where 语句
<<<<<<< HEAD
    if (token != tokens.end() && *token == "where")
    {
        ++token; // 跳过 "where"
        while (token != tokens.end() && *token != "order")
        {
            std::string left_expr = *token;
            ++token;

            if (token == tokens.end())
                return;
=======
    if (token != tokens.end() && *token == "where") {
        ++token; // 跳过 "where"
        while (token != tokens.end() && *token != "order") {
            std::string left_expr = *token;
            ++token;

            if (token == tokens.end()) return;
>>>>>>> refs/remotes/origin/main

            std::string op = *token;
            expr::TAG tag;

<<<<<<< HEAD
            if (op == "=")
                tag = expr::equal;
            else if (op == "!=")
                tag = expr::noequal;
            else if (op == ">")
                tag = expr::larger;
            else if (op == "<")
                tag = expr::smaller;
            else if (op == ">=")
                tag = expr::largerorequal;
            else if (op == "<=")
                tag = expr::smallerorequal;
            else
                return;

            ++token;

            if (token == tokens.end())
                return;
=======
            if (op == "=") tag = expr::equal;
            else if (op == "!=") tag = expr::noequal;
            else if (op == ">") tag = expr::larger;
            else if (op == "<") tag = expr::smaller;
            else if (op == ">=") tag = expr::largerorequal;
            else if (op == "<=") tag = expr::smallerorequal;
            else return;

            ++token;

            if (token == tokens.end()) return;
>>>>>>> refs/remotes/origin/main

            std::string right_expr = *token;
            condition.emplace_back(expr::expression, tag, left_expr, right_expr);
            ++token;

<<<<<<< HEAD
            if (token != tokens.end())
            {
                if (*token == "and" || *token == "or" || *token == "not")
                {
                    expr::TAG logicTag;
                    if (*token == "and")
                    {
                        logicTag = expr::_and;
                    }
                    else if (*token == "or")
                    {
                        logicTag = expr::_or;
                    }
                    else if (*token == "not")
                    {
=======
            if (token != tokens.end()) {
                if (*token == "and" || *token == "or" || *token == "not") {
                    expr::TAG logicTag;
                    if (*token == "and") {
                        logicTag = expr::_and;
                    } else if (*token == "or") {
                        logicTag = expr::_or;
                    } else if (*token == "not") {
>>>>>>> refs/remotes/origin/main
                        logicTag = expr::_not;
                    }
                    condition.emplace_back(expr::logic, logicTag, "", "");
                    ++token;
                }
            }
        }
    }

<<<<<<< HEAD
    Manager.Delete(tablename, condition, ans);
}

void CommandDecoding::parseGrant(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,
                                 TableManager &Manager, Ans &ans)
{
    std::vector<std::pair<std::string, bool>> permissions = {
        {"drop", false},
        {"select", false},
        {"insert", false},
        {"update", false},
        {"delete", false},
        {"alter", false}};
=======
    Manager.Delete(tablename, condition);
}

void CommandDecoding::parseGrant(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager) {
    std::vector<std::pair<std::string, bool>> permissions = {{"create", false},
                                                             {"drop",   false},
                                                             {"select", false},
                                                             {"insert", false},
                                                             {"update", false},
                                                             {"delete", false},
                                                             {"alter",  false}};
>>>>>>> refs/remotes/origin/main
    std::vector<std::string> username;
    std::vector<std::string> table_name;

    ++token;
<<<<<<< HEAD
    while (token != tokens.end() && *token != "on")
    {
        for (auto &perm : permissions)
        {
            if (*token == perm.first)
            {
                perm.second = true;
                break;
            }
            else if (*token == "all")
            {
                for (auto &p : permissions)
                {
=======
    while (token != tokens.end() && *token != "on") {
        for (auto &perm: permissions) {
            if (*token == perm.first) {
                perm.second = true;
                break;
            } else if (*token == "all") {
                for (auto &p: permissions) {
>>>>>>> refs/remotes/origin/main
                    p.second = true;
                }
                break;
            }
        }
        ++token;
    }

<<<<<<< HEAD
    if (token != tokens.end() && *token == "on")
    {
        ++token;
        table_name.push_back(*token);
        ++token;
        if (token != tokens.end() && *token == "to")
        {
            ++token;
            username.push_back(*token);
            UserManager::GrantUser(username, table_name, permissions, ans);
=======
    if (token != tokens.end() && *token == "on") {
        ++token;
        table_name.push_back(*token);
        ++token;
        if (token != tokens.end() && *token == "to") {
            ++token;
            username.push_back(*token);
            UserManager::GrantUser(username, table_name, permissions);
>>>>>>> refs/remotes/origin/main
        }
    }
}

<<<<<<< HEAD
void CommandDecoding::parseRevoke(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,
                                  TableManager &Manager, Ans &ans)
{
    std::vector<std::pair<std::string, bool>> permissions = {
        {"drop", true},
        {"select", true},
        {"insert", true},
        {"update", true},
        {"delete", true},
        {"alter", true}};
=======
void CommandDecoding::parseRevoke(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager) {
    std::vector<std::pair<std::string, bool>> permissions = {{"create", true},
                                                             {"drop",   true},
                                                             {"select", true},
                                                             {"insert", true},
                                                             {"update", true},
                                                             {"delete", true},
                                                             {"alter",  true}};
>>>>>>> refs/remotes/origin/main
    std::vector<std::string> username;
    std::vector<std::string> table_name;

    ++token;
<<<<<<< HEAD
    while (token != tokens.end() && *token != "on")
    {
        for (auto &perm : permissions)
        {
            if (*token == perm.first)
            {
                perm.second = false;
                break;
            }
            else if (*token == "all")
            {
                for (auto &p : permissions)
                {
=======
    while (token != tokens.end() && *token != "on") {
        for (auto &perm: permissions) {
            if (*token == perm.first) {
                perm.second = false;
                break;
            } else if (*token == "all") {
                for (auto &p: permissions) {
>>>>>>> refs/remotes/origin/main
                    p.second = false;
                }
                break;
            }
        }
        ++token;
    }

<<<<<<< HEAD
    if (token != tokens.end() && *token == "on")
    {
        ++token;
        table_name.push_back(*token);
        ++token;
        if (token != tokens.end() && *token == "from")
        {
            ++token;
            while (token != tokens.end())
            {
                username.push_back(*token);
                ++token;
            }
            UserManager::RevokeUser(username, table_name, permissions, ans);
=======
    if (token != tokens.end() && *token == "on") {
        ++token;
        table_name.push_back(*token);
        ++token;
        if (token != tokens.end() && *token == "from") {
            ++token;
            while (token != tokens.end()) {
                username.push_back(*token);
                ++token;
            }
            UserManager::RevokeUser(username, table_name, permissions);
>>>>>>> refs/remotes/origin/main
        }
    }
}

<<<<<<< HEAD
void CommandDecoding::parseUpdate(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,
                                  TableManager &Manager, Ans &ans)
{
    if (token == tokens.end() || *token != "update")
        return;
    ++token;

    if (token == tokens.end())
        return;
    std::string tablename = *token;
    ++token;

    if (token == tokens.end() || *token != "set")
        return;
=======
void CommandDecoding::parseUpdate(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager) {
    if (token == tokens.end() || *token != "update") return;
    ++token;

    if (token == tokens.end()) return;
    std::string tablename = *token;
    ++token;

    if (token == tokens.end() || *token != "set") return;
>>>>>>> refs/remotes/origin/main
    ++token;

    std::vector<std::string> attrname;
    std::vector<std::string> attrval;
    std::vector<expr> condition;

    // 解析列名和值
<<<<<<< HEAD
    while (token != tokens.end() && *token != "where")
    {
        std::string column = *token;
        ++token;
        if (token == tokens.end() || *token != "=")
            return;
        ++token;
        if (token == tokens.end())
            return;
=======
    while (token != tokens.end() && *token != "where") {
        std::string column = *token;
        ++token;
        if (token == tokens.end() || *token != "=") return;
        ++token;
        if (token == tokens.end()) return;
>>>>>>> refs/remotes/origin/main
        std::string value = *token;
        attrname.push_back(column);
        attrval.push_back(value);
        ++token;
<<<<<<< HEAD
        if (token != tokens.end() && *token == ",")
        {
=======
        if (token != tokens.end() && *token == ",") {
>>>>>>> refs/remotes/origin/main
            ++token;
        }
    }

    // 解析 where 语句
<<<<<<< HEAD
    if (token != tokens.end() && *token == "where")
    {
        ++token;
        while (token != tokens.end())
        {
            std::string left_expr = *token;
            ++token;

            if (token == tokens.end())
                return;
=======
    if (token != tokens.end() && *token == "where") {
        ++token;
        while (token != tokens.end()) {
            std::string left_expr = *token;
            ++token;

            if (token == tokens.end()) return;
>>>>>>> refs/remotes/origin/main

            std::string op = *token;
            expr::TAG tag;

<<<<<<< HEAD
            if (op == "=")
                tag = expr::equal;
            else if (op == "!=")
                tag = expr::noequal;
            else if (op == ">")
                tag = expr::larger;
            else if (op == "<")
                tag = expr::smaller;
            else if (op == ">=")
                tag = expr::largerorequal;
            else if (op == "<=")
                tag = expr::smallerorequal;
            else
                return;

            ++token;

            if (token == tokens.end())
                return;
=======
            if (op == "=") tag = expr::equal;
            else if (op == "!=") tag = expr::noequal;
            else if (op == ">") tag = expr::larger;
            else if (op == "<") tag = expr::smaller;
            else if (op == ">=") tag = expr::largerorequal;
            else if (op == "<=") tag = expr::smallerorequal;
            else return;

            ++token;

            if (token == tokens.end()) return;
>>>>>>> refs/remotes/origin/main

            std::string right_expr = *token;
            condition.emplace_back(expr::expression, tag, left_expr, right_expr);
            ++token;

<<<<<<< HEAD
            if (token != tokens.end())
            {
                if (*token == "and" || *token == "or" || *token == "not")
                {
                    expr::TAG logicTag;
                    if (*token == "and")
                    {
                        logicTag = expr::_and;
                    }
                    else if (*token == "or")
                    {
                        logicTag = expr::_or;
                    }
                    else if (*token == "not")
                    {
=======
            if (token != tokens.end()) {
                if (*token == "and" || *token == "or" || *token == "not") {
                    expr::TAG logicTag;
                    if (*token == "and") {
                        logicTag = expr::_and;
                    } else if (*token == "or") {
                        logicTag = expr::_or;
                    } else if (*token == "not") {
>>>>>>> refs/remotes/origin/main
                        logicTag = expr::_not;
                    }
                    condition.emplace_back(expr::logic, logicTag, "", "");
                    ++token;
                }
            }
        }
    }

<<<<<<< HEAD
    Manager.Update(tablename, attrname, attrval, condition, ans);
}

void CommandDecoding::parseInsert(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,
                                  TableManager &Manager, Ans &ans)
{
    if (token == tokens.end() || *token != "insert")
        return;
    ++token;

    if (token == tokens.end() || *token != "into")
        return;
    ++token;

    if (token == tokens.end())
        return;
    std::string tablename = *token;
    ++token;

    if (token == tokens.end() || *token != "(")
        return;
=======
    Manager.Update(tablename, attrname, attrval, condition);
}

void CommandDecoding::parseInsert(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager) {
    if (token == tokens.end() || *token != "insert") return;
    ++token;

    if (token == tokens.end() || *token != "into") return;
    ++token;

    if (token == tokens.end()) return;
    std::string tablename = *token;
    ++token;

    if (token == tokens.end() || *token != "(") return;
>>>>>>> refs/remotes/origin/main
    ++token;

    std::vector<std::string> attrname;
    std::vector<std::string> attrval;

    // 解析列名
<<<<<<< HEAD
    while (token != tokens.end() && *token != ")")
    {
        if (*token != ",")
        {
=======
    while (token != tokens.end() && *token != ")") {
        if (*token != ",") {
>>>>>>> refs/remotes/origin/main
            attrname.push_back(*token);
        }
        ++token;
    }

<<<<<<< HEAD
    if (token == tokens.end() || *token != ")")
        return;
    ++token;

    if (token == tokens.end() || *token != "values")
        return;
    ++token;

    if (token == tokens.end() || *token != "(")
        return;
    ++token;

    // 解析值
    while (token != tokens.end() && *token != ")")
    {
        if (*token != ",")
        {
=======
    if (token == tokens.end() || *token != ")") return;
    ++token;

    if (token == tokens.end() || *token != "values") return;
    ++token;

    if (token == tokens.end() || *token != "(") return;
    ++token;

    // 解析值
    while (token != tokens.end() && *token != ")") {
        if (*token != ",") {
>>>>>>> refs/remotes/origin/main
            attrval.push_back(*token);
        }
        ++token;
    }

<<<<<<< HEAD
    if (token == tokens.end() || *token != ")")
        return;
    ++token;

    // 检查属性列和属性值数量是否匹配
    if (attrname.size() != attrval.size())
        return;

    Manager.Insert(tablename, attrname, attrval, ans);
}

void CommandDecoding::parseAlter(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,
                                 TableManager &Manager, Ans &ans)
{
    if (token == tokens.end() || *token != "alter")
        return;
    ++token;

    if (token == tokens.end() || *token != "table")
        return;
    ++token;

    if (token == tokens.end())
        return;
    std::string tablename = *token;
    ++token;

    if (token == tokens.end())
        return;

    std::string operation = *token;
    ++token;

    if (operation == "add")
    {
        if (token != tokens.end() && *token == "column")
        {
            std::vector<std::pair<std::string, std::string>> tmp = {{"name", "0"},
                                                                    {"type", "0"},
                                                                    {"primary key", "0"},
                                                                    {"null", "1"},
                                                                    {"unique", "0"},
                                                                    {"default", "0"}};
            std::pair<std::string, std::string> foreign;
            bool updatejoint = false;
            bool deletejoint = false;

            ++token; // 跳过 "column"
            if (token != tokens.end())
            {
                std::string column_name = *token;
                tmp[0].second = column_name;
                ++token; // 跳过列名
                if (token != tokens.end())
                {
                    std::string column_type = *token;
                    tmp[1].second = column_type;
                    ++token; // 跳过类型
                    while (token != tokens.end())
                    {
                        if (*token == "primary")
                        {
                            ++token;
                            if (token != tokens.end() && *token == "key")
                            {
                                tmp[2].second = "1"; // 设置主键
                                ++token;
                            }
                        }
                        else if (*token == "not")
                        {
                            ++token;
                            if (token != tokens.end() && *token == "null")
                            {
                                tmp[3].second = "0"; // 设置非空
                                ++token;
                            }
                        }
                        else if (*token == "unique")
                        {
                            tmp[4].second = "1"; // 设置唯一
                            ++token;
                        }
                        else if (*token == "default")
                        {
                            ++token;
                            if (token != tokens.end())
                            {
                                tmp[5].second = *token; // 设置默认值
                                ++token;
                            }
                        }
                        else if (*token == "foreign")
                        {
                            ++token;
                            if (token != tokens.end() && *token == "key")
                            {
                                ++token;
                                if (token != tokens.end() && *token == "references")
                                {
                                    ++token;
                                    if (token != tokens.end())
                                    {
                                        std::string ref_table = *token; // 参考的表名
                                        foreign.first = ref_table;
                                        ++token;
                                        if (token != tokens.end() && *token == "(")
                                        {
                                            ++token;
                                            if (token != tokens.end())
                                            {
                                                std::string ref_column = *token; // 参考表中的列名
                                                foreign.second = ref_column;
                                                ++token;
                                                if (token != tokens.end() && *token == ")")
                                                {
                                                    ++token;
                                                }
                                            }
                                        }
                                    }
=======
    if (token == tokens.end() || *token != ")") return;
    ++token;

    // 检查属性列和属性值数量是否匹配
    if (attrname.size() != attrval.size()) return;

    Manager.Insert(tablename, attrname, attrval);
}

void CommandDecoding::parseAlter(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager) {
    if (token == tokens.end() || *token != "alter") return;
    ++token;

    if (token == tokens.end() || *token != "table") return;
    ++token;

    if (token == tokens.end()) return;
    std::string tablename = *token;
    ++token;

    if (token == tokens.end()) return;

    // 解析具体的 alter 操作类型
    std::string operation = *token;
    ++token;

    if (operation == "add") {
        if (token != tokens.end() && *token == "primary") {
            ++token;
            if (token != tokens.end() && *token == "key") {
                ++token;
                if (token != tokens.end() && *token == "(") {
                    ++token;
                    std::vector<std::string> column_names;
                    while (token != tokens.end() && *token != ")") {
                        if (*token != ",") {
                            column_names.push_back(*token);
                        }
                        ++token;
                    }
                    if (token != tokens.end() && *token == ")") {
                        ++token;
                        Manager.AlterTableAddPrimaryKey(tablename, column_names);
                        return;
                    }
                }
            }
        } else if (token != tokens.end() && *token == "foreign") {
            ++token; // 跳过 "foreign"
            if (token != tokens.end() && *token == "key") {
                ++token; // 跳过 "key"
                if (token != tokens.end()) {
                    std::string attrname = *token;
                    ++token; // 跳过外键属性名
                    if (token != tokens.end() && *token == "references") {
                        ++token; // 跳过 "references"
                        if (token != tokens.end()) {
                            std::string reftablename = *token;
                            ++token; // 跳过引用表名
                            if (token != tokens.end() && *token == "(") {
                                ++token; // 跳过 "("
                                std::string otherattr;
                                while (token != tokens.end() && *token != ")") {
                                    if (*token != ",") {
                                        otherattr=*token;
                                    }
                                    ++token;
                                }
                                if (token != tokens.end() && *token == ")") {
                                    ++token; // 跳过 ")"
                                    Manager.AlterTableAddForeignKey(tablename, attrname, reftablename, otherattr);
                                    return;
>>>>>>> refs/remotes/origin/main
                                }
                            }
                        }
                    }
                }
            }
<<<<<<< HEAD
            else if (*token == "on")
            {
                ++token;
                if (token != tokens.end() && *token == "delete")
                {
                    ++token;
                    if (token != tokens.end() && (*token == "cascade"))
                    {
                        deletejoint = true;
                        ++token;
                    }
                }
                else if (token != tokens.end() && *token == "update")
                {
                    ++token;
                    if (token != tokens.end() && (*token == "cascade"))
                    {
                        updatejoint = true;
                        ++token;
                    }
                }
            }
            else
            {
                ++token;
            }

            Manager.AlterTableAddColumn(tablename, tmp, foreign, ans, deletejoint, updatejoint);
        }
        else if (token != tokens.end() && *token == "primary")
        {
            ++token; // 跳过 "primary"
            if (token != tokens.end() && *token == "key")
            {
                ++token; // 跳过 "key"
                if (token != tokens.end() && *token == "(")
                {
                    ++token; // 跳过 "("
                    std::vector<std::string> column_names;
                    while (token != tokens.end() && *token != ")")
                    {
                        if (*token != ",")
                        {
                            column_names.push_back(*token);
                        }
                        ++token;
                    }
                    if (token != tokens.end() && *token == ")")
                    {
                        ++token; // 跳过 ")"
                        Manager.AlterTableAddPrimaryKey(tablename, column_names, ans);
=======
        }
    } else if (operation == "drop") {
        if (token != tokens.end() && *token == "primary") {
            ++token; // 跳过 "primary"
            if (token != tokens.end() && *token == "key") {
                ++token; // 跳过 "key"
                Manager.AlterTableDropPrimaryKey(tablename, {});
                return;
            }
        } else if (token != tokens.end() && *token == "foreign") {
            ++token; // 跳过 "foreign"
            if (token != tokens.end() && *token == "key") {
                ++token; // 跳过 "key"
                if (token != tokens.end()) {
                    std::string attrname = *token;
                    ++token; // 跳过外键属性名
                    Manager.AlterTableDropForeignKey(tablename, attrname);
                    return;
                }
            }
        } else if (token != tokens.end() && *token == "column") {
            ++token; // 跳过 "column"
            if (token != tokens.end()) {
                std::string column_name = *token;
                ++token; // 跳过列名
                Manager.AlterTableDropColumn(tablename, column_name);
                return;
            }
        }
    } else if (operation == "rename") {
        if (token != tokens.end() && *token == "column") {
            ++token; // 跳过 "column"
            if (token != tokens.end()) {
                std::string old_column_name = *token;
                ++token; // 跳过旧列名
                if (token != tokens.end() && *token == "to") {
                    ++token; // 跳过 "to"
                    if (token != tokens.end()) {
                        std::string new_column_name = *token;
                        ++token; // 跳过新列名
                        Manager.AlterTableModifyColumnName(tablename, old_column_name, new_column_name);
>>>>>>> refs/remotes/origin/main
                        return;
                    }
                }
            }
        }
<<<<<<< HEAD
        else if (token != tokens.end() && *token == "constraint")
        {
            bool updatejoint = false;
            bool deletejoint = false;
            std::string constraint_name;
            std::string attrname;
            std::string reftablename;
            std::string refcolumn;
            ++token; // 跳过 "constraint"
            if (token != tokens.end())
            {
                constraint_name = *token;
                ++token; // 跳过外键名
                if (token != tokens.end() && *token == "foreign")
                {
                    ++token; // 跳过 "foreign"
                    if (token != tokens.end() && *token == "key")
                    {
                        ++token; // 跳过 "key"
                        if (token != tokens.end() && *token == "(")
                        {
                            ++token; // 跳过 "("
                            attrname = *token;
                            ++token; // 跳过外键属性名
                            if (token != tokens.end() && *token == ")")
                            {
                                ++token; // 跳过 ")"
                                if (token != tokens.end() && *token == "references")
                                {
                                    ++token; // 跳过 "references"
                                    if (token != tokens.end())
                                    {
                                        reftablename = *token;
                                        ++token; // 跳过引用表名
                                        if (token != tokens.end() && *token == "(")
                                        {
                                            ++token; // 跳过 "("
                                            refcolumn = *token;
                                            ++token; // 跳过引用列名
                                            if (token != tokens.end() && *token == ")")
                                            {
                                                ++token; // 跳过 ")"
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else if (*token == "on")
                {
                    ++token;
                    if (token != tokens.end() && *token == "delete")
                    {
                        ++token;
                        if (token != tokens.end() && (*token == "cascade"))
                        {
                            deletejoint = true;
                            ++token;
                        }
                    }
                    else if (token != tokens.end() && *token == "update")
                    {
                        ++token;
                        if (token != tokens.end() && (*token == "cascade"))
                        {
                            updatejoint = true;
                            ++token;
                        }
                    }
                }
                else
                {
                    ++token;
                }
            }
            Manager.AlterTableAddForeignKey(tablename, attrname,
                                            reftablename, refcolumn,
                                            constraint_name, deletejoint, updatejoint, ans);
        }
    }
    else if (operation == "drop")
    {
        if (token != tokens.end() && *token == "column")
        {
            ++token; // 跳过 "column"
            if (token != tokens.end())
            {
                std::string column_name = *token;
                ++token; // 跳过列名
                Manager.AlterTableDropColumn(tablename, column_name, ans);
                return;
            }
        }
        else if (token != tokens.end() && *token == "primary")
        {
            ++token; // 跳过 "primary"
            if (token != tokens.end() && *token == "key")
            {
                ++token; // 跳过 "key"
                Manager.AlterTableDropPrimaryKey(tablename, ans);
                return;
            }
        }
        else if (token != tokens.end() && *token == "foreign")
        {
            ++token; // 跳过 "foreign"
            if (token != tokens.end() && *token == "key")
            {
                ++token; // 跳过 "key"
                if (token != tokens.end())
                {
                    std::string fk_name = *token;
                    ++token; // 跳过外键名称
                    Manager.AlterTableDropForeignKey(tablename, fk_name, ans);
                    return;
                }
            }
        }
    }
    else if (operation == "change")
    {
        if (token != tokens.end() && *token == "column")
        {
            ++token; // 跳过 "column"
            if (token != tokens.end())
            {
                std::string old_column_name = *token;
                ++token; // 跳过旧列名
                if (token != tokens.end())
                {
                    std::string new_column_name = *token;
                    ++token; // 跳过新列名
                    Manager.AlterTableModifyColumnName(tablename, old_column_name, new_column_name, ans);
                    return;
                }
            }
        }
    }
    else if (operation == "modify")
    {
        if (token != tokens.end() && *token == "column")
        {
            ++token; // 跳过 "column"
            if (token != tokens.end())
            {
                std::string column_name = *token;
                ++token; // 跳过列名

                while (token != tokens.end())
                {
                    if (udi_set.find(*token) != udi_set.end())
                    {
                        if (*token == "default")
                        {
                            ++token;
                            if (token != tokens.end())
                            {
                                std::string column_default = *token; // 设置默认值
                                Manager.AlterTableModifyColumnDefault(tablename, column_name, column_default, ans);
                                ++token;
                            }
                        }
                        else if (*token == "not")
                        {
                            ++token;
                            if (token != tokens.end() && *token == "null")
                            {
                                bool column_null = false; // 设置非空
                                Manager.AlterTableModifyColumnNull(tablename, column_name, column_null, ans);
                                ++token;
                            }
                        }
                        else if (*token == "unique")
                        {
                            bool column_unique = true; // 设置唯一
                            Manager.AlterTableModifyColumnUnique(tablename, column_name, column_unique, ans);
                            ++token;
                        }
                    }
                    else
                    {
                        std::string column_type = *token; // 数据类型
                        Manager.AlterTableModifyColumnType(tablename, column_name, column_type, ans);
                        token++;
                    }
                }
            }
        }
    }
}
=======
    } else if (operation == "modify") {
        if (token != tokens.end() && *token == "column") {
            ++token; // 跳过 "column"
            if (token != tokens.end()) {
                std::string column_name = *token;
                ++token; // 跳过列名
                if (token != tokens.end()) {
                    std::string suboperation = *token;
                    ++token;
                    if (suboperation == "type") {
                        if (token != tokens.end()) {
                            std::string column_type = *token;
                            ++token; // 跳过类型名
                            Manager.AlterTableModifyColumnType(tablename, column_name, column_type);
                            return;
                        }
                    } else if (suboperation == "default") {
                        if (token != tokens.end()) {
                            std::string column_default = *token;
                            ++token; // 跳过默认值
                            Manager.AlterTableModifyColumnDefault(tablename, column_name, column_default);
                            return;
                        }
                    } else if (suboperation == "null") {
                        bool column_null = true;
                        if (token != tokens.end() && *token == "not") {
                            ++token; // 跳过 "not"
                            if (token != tokens.end() && *token == "null") {
                                column_null = false;
                                ++token; // 跳过 "null"
                            }
                        }
                        Manager.AlterTableModifyColumnNull(tablename, column_name, column_null);
                        return;
                    } else if (suboperation == "unique") {
                        bool column_unique = true;
                        if (token != tokens.end() && *token == "not") {
                            ++token; // 跳过 "not"
                            if (token != tokens.end() && *token == "unique") {
                                column_unique = false;
                                ++token; // 跳过 "unique"
                            }
                        }
                        Manager.AlterTableModifyColumnUnique(tablename, column_name, column_unique);
                        return;
                    }
                }
            }
        }
    }
}


CommandDecoding::~CommandDecoding() = default;
>>>>>>> refs/remotes/origin/main
