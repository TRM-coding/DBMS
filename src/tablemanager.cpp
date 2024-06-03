#include <tablemanager.hpp>
#include <iostream>
#include <TableStream.hpp>
#include <tree.hpp>

TableManager::TableManager()
{
}

TableManager::TableManager(User user)
{
    this->user = user;
}

std::string TableManager::CreateTable(
    std::string table_name,
    std::vector<std::vector<std::pair<std::string, std::string>>> settings,
<<<<<<< HEAD
    std::vector<std::pair<std::string, std::string>> foreign,
    std::map<std::string, bool> updatejoint,
    std::map<std::string, bool> Deletejoint,
    Ans &answer)
=======
    std::vector<std::pair<std::string, std::string>> foreign)
>>>>>>> refs/remotes/origin/main
{
    Table ans;
    ans.setTableName(table_name);

    for (int attrcnt = 0; auto x : settings)
    {
        std::string attrname;
        for (auto p : x)
        {
            std::string tag = p.first;
            std::string val = p.second;
<<<<<<< HEAD
            if (tag == "null")
=======
            if (tag == "NULL")
>>>>>>> refs/remotes/origin/main
            {
                if (val == "0")
                    ans.setNull(attrname, 0);
                else
                    ans.setNull(attrname, 1);
            }
<<<<<<< HEAD
            else if (tag == "type")
            {
                ans.AlterTableModifyColumnType(attrname, val);
            }
            else if (tag == "primary key")
=======
            else if (tag == "TYPE")
            {
                ans.AlterTableModifyColumnType(attrname, val);
            }
            else if (tag == "PRIMARY KEY")
>>>>>>> refs/remotes/origin/main
            {
                if (val == "1")
                    ans.addPrimaryKey(attrname);
            }
<<<<<<< HEAD
            else if (tag == "unique")
=======
            else if (tag == "UNIQUE")
>>>>>>> refs/remotes/origin/main
            {
                if (val == "0")
                    ans.setUnique(attrname, 0);
                else
                    ans.setUnique(attrname, 1);
            }
<<<<<<< HEAD
            else if (tag == "default")
            {
                ans.setDefault(attrname, val);
            }
            else if (tag == "name")
=======
            else if (tag == "DEFAULT")
            {
                ans.setDefault(attrname, val);
            }
            else if (tag == "NAME")
>>>>>>> refs/remotes/origin/main
            {
                ans.addAttribute(val);
                attrname = val;
            }

            else
            {
<<<<<<< HEAD
                answer.Loadstate("Undefined behavior:" + tag);
                std::cout << "Undefined behavior:" << tag << std::endl;
=======
                std::cout << "Undefined behavior" << std::endl;
>>>>>>> refs/remotes/origin/main
            }
        }

        ans.addForeign(attrname, foreign[attrcnt].first, foreign[attrcnt].second);
<<<<<<< HEAD
        ans.setConstraintName("FK:" + foreign[attrcnt].second, foreign[attrcnt].second);
        attrcnt++;
    }
    ans.setUpdateJoint(updatejoint);
    ans.setDeleteJoint(Deletejoint);

    Table users = TableStream::LoadTable("userlogin_table", 1);
    std::vector<std::string> usernames;
    for (auto x : users.getData())
    {
        usernames.push_back(x[0]);
    }

    for (auto us : usernames)
    {
        if (us == "root")
        {
            UserManager::NewGrantUser({us}, {table_name}, {{"select", 1}, {"insert", 1}, {"update", 1}, {"delete", 1}, {"alter", 1}, {"drop", 1}}, answer);
        }
        else
        {
            UserManager::NewGrantUser({us}, {table_name}, {{"select", 1}, {"insert", 0}, {"update", 0}, {"delete", 0}, {"alter", 0}, {"drop", 0}}, answer);
        }
    }

    TableStream::SaveTable(ans);
    answer.Loadstate("Table created successfully");
    return "Table created successfully";
}

std::vector<std::string> TableManager::getConstraintName(std::string tablename, Ans &answer)
{
    Table table = TableStream::LoadTable(tablename);
    std::vector<std::string> ans = table.getConstraintName();
    std::vector<std::vector<std::string>> as;
    as.push_back(ans);
    answer.Loaddata(as);
    return ans;
}

std::string TableManager::DropTable(std::string table_name, Ans &answer)
{
    if (this->user.getPermission(table_name, "drop") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return "Permission denied";
    }
    TableStream::RemoveTable(table_name);
    answer.Loadstate("Table dropped successfully");
    return "Table dropped successfully";
}

bool TableManager::AlterTableAddColumn(
    std::string tablename,
    std::vector<std::pair<std::string, std::string>> settings,
    std::pair<std::string, std::string> foreign,
    Ans &answer,
    bool updatejoint,
    bool deletejoint)
{
    if (this->user.getPermission(tablename, "alter") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }

    Table table = TableStream::LoadTable(tablename);
    if (table.AlterTableAddColumn(settings, foreign, updatejoint, deletejoint))
    {
        TableStream::SaveTable(table);
        auto reftablename = foreign.first;
        auto otherattr = foreign.second;
        std::string attrname;
        for (auto P : settings)
        {
            if (P.first == "name")
                attrname = P.second;
        }
        Table reftable = TableStream::LoadTable(reftablename);
        reftable.addReferencedBy(otherattr, make_pair(tablename, attrname));
        TableStream::SaveTable(reftable);
    }
    answer.Loadstate("Column added successfully");
    return true;
}

=======
        attrcnt++;
    }

    TableStream::SaveTable(ans);
    return "Table created successfully";
}

std::string TableManager::DropTable(std::string table_name)
{
    TableStream::RemoveTable(table_name);
    return "Table dropped successfully";
}

>>>>>>> refs/remotes/origin/main
std::vector<std::vector<std::string>> TableManager::cartesian_product(
    std::vector<std::vector<std::string>> table1,
    std::vector<std::vector<std::string>> table2)
{
    std::vector<std::vector<std::string>> ans;
    if (table1.empty())
        return table2;
    if (table2.empty())
        return table1;
    for (auto x : table1)
    {
        for (auto y : table2)
        {
            std::vector<std::string> temp;
            for (auto z : x)
                temp.push_back(z);
            for (auto z : y)
                temp.push_back(z);
            ans.push_back(temp);
        }
    }
    return ans;
}

std::vector<std::vector<std::string>> TableManager::Select(
    std::vector<std::string> tablename,
    std::vector<std::string> attrname,
    std::vector<expr> condition,
<<<<<<< HEAD
    std::vector<std::pair<std::string, bool>> order,
    Ans &answer)
{
    for (auto x : tablename)
    {
        if (this->user.getPermission(x, "select") == false)
        {
            std::cout << "Permission denied" << std::endl;
            return std::vector<std::vector<std::string>>();
        }
    }
=======
    std::vector<std::pair<std::string, bool>> order)
{
>>>>>>> refs/remotes/origin/main
    std::vector<Table> tables;
    for (auto x : tablename)
    {
        tables.push_back(TableStream::LoadTable(x));
    }
<<<<<<< HEAD
    for (auto x : tables)
    {
        if (x.isNULL())
            return std::vector<std::vector<std::string>>();
    }
=======
>>>>>>> refs/remotes/origin/main
    std::vector<std::vector<std::string>> dikar;
    for (auto x : tables)
    {
        dikar = cartesian_product(dikar, x.getData());
    }
<<<<<<< HEAD
    std::vector<std::string> dikar_attr;
    std::vector<std::string> join_attr;
    for (auto x : tables)
    {
        std::vector<std::string> x_attr = x.getAttributes();
        for (auto p : x_attr)
        {
            join_attr.push_back(x.getTableName() + "." + p);
        }
        dikar_attr.insert(dikar_attr.end(), x_attr.begin(), x_attr.end());
    }
    dikar.insert(dikar.begin(), dikar_attr);

    std::map<std::string, int> checkctt;
    for (auto x : attrname)
    {
        for (auto p : dikar_attr)
        {
            if (x == p)
                checkctt[x]++;
        }
    }
    for (auto x : checkctt)
    {
        if (x.second > 1)
        {
            answer.Loadstate("attr not named with table" + x.first);
            std::cout << "attr not named with table:" << x.first << std::endl;
            return std::vector<std::vector<std::string>>();
        }
    }

    // if (!order.empty())
    // {
    //     Sort(order, dikar);
    // }

=======
>>>>>>> refs/remotes/origin/main
    std::vector<std::string> attrs = dikar[0];
    std::vector<std::vector<std::string>> ans;
    for (int i = 1; i < dikar.size(); i++)
    {
        std::vector<std::string> datai = dikar[i];
        std::string checkstring;
<<<<<<< HEAD
        for (int autocnt = 0; auto x : condition)
=======
        for (auto x : condition)
>>>>>>> refs/remotes/origin/main
        {
            if (x.type == expr::expression)
            {
                if (x.tag == expr::largerorequal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
<<<<<<< HEAD
                        if (attrs[j] == x.key||join_attr[j]==x.key)
=======
                        if (attrs[j] == x.key)
>>>>>>> refs/remotes/origin/main
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (LargerOrEual(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::smallerorequal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
<<<<<<< HEAD
                        if (attrs[j] == x.key||join_attr[j]==x.key)
=======
                        if (attrs[j] == x.key)
>>>>>>> refs/remotes/origin/main
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (SmallOrEqual(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::smaller)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
<<<<<<< HEAD
                        if (attrs[j] == x.key||join_attr[j]==x.key)
=======
                        if (attrs[j] == x.key)
>>>>>>> refs/remotes/origin/main
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (Smaller(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::larger)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
<<<<<<< HEAD
                        if (attrs[j] == x.key||join_attr[j]==x.key)
=======
                        if (attrs[j] == x.key)
>>>>>>> refs/remotes/origin/main
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (Larger(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::equal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
<<<<<<< HEAD
                        if (attrs[j] == x.key||join_attr[j]==x.key)
=======
                        if (attrs[j] == x.key)
>>>>>>> refs/remotes/origin/main
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (datai[attrindex] == x.val)
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::noequal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (!(datai[attrindex] == x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
            }
            else if (x.type == expr::logic)
            {
                if (x.tag == expr::_and)
                {
                    checkstring.push_back('&');
                }
                else if (x.tag == expr::_or)
                {
                    checkstring.push_back('|');
                }
<<<<<<< HEAD
                else if (x.tag == expr::_not)
                {
                    checkstring.push_back('!');
                }
            }
            else if (x.type == expr::_join)
            {
                if (
                    std::find(join_attr.begin(), join_attr.end(), x.key) == join_attr.end() ||
                    std::find(join_attr.begin(), join_attr.end(), x.val) == join_attr.end())
                {
                    std::cout << "attr not definite" << std::endl;
                    return std::vector<std::vector<std::string>>();
                }
                int keyindex = std::find(join_attr.begin(), join_attr.end(), x.key) - join_attr.begin();
                int valindex = std::find(join_attr.begin(), join_attr.end(), x.val) - join_attr.begin();
                if (datai[keyindex] != datai[valindex])
                {
                    checkstring.push_back('0');
                }
                else
                {
                    checkstring.push_back('1');
                }
                if (autocnt != condition.size() - 1)
                    checkstring.push_back('&');
=======
>>>>>>> refs/remotes/origin/main
            }
            else
            {
                std::cout << "Undefined behavior" << std::endl;
                return std::vector<std::vector<std::string>>();
            }
<<<<<<< HEAD
            autocnt++;
        }
        CaculateTree checker;
        if (condition.empty() || (!condition.empty() && checker.caculate(checkstring)))
        {
            std::vector<std::string> tmp;
            if (attrname[0] == "*")
            {
                tmp = datai;
            }
            else
            {

                for (auto x : attrname)
                {

                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x || join_attr[j] == x)
                        {
                            tmp.push_back(datai[j]);
                            break;
                        }
=======
        }
        CaculateTree checker(checkstring);
        if (checker.caculate(checkstring))
        {
            std::vector<std::string> tmp;
            for (auto x : attrname)
            {
                for (int j = 0; j < attrs.size(); j++)
                {
                    if (attrs[j] == x)
                    {
                        tmp.push_back(datai[j]);
>>>>>>> refs/remotes/origin/main
                    }
                }
            }
            ans.push_back(tmp);
        }
    }
<<<<<<< HEAD
    // ans.insert(ans.begin(), dikar_attr);

    // std::set<std::vector<std::string> >unique;
    // for (int i = 1; i < ans.size(); i++)
    // {
    //     unique.insert(ans[i]);
    // }
    // ans.clear();
    // for (auto x : unique)
    //     ans.push_back(x);

    std::sort(ans.begin(), ans.end(), compareVec);
    auto iter = std::unique(ans.begin(), ans.end());
    ans.erase(iter, ans.end());


    std::vector<std::string> ans_attr;
    if (attrname[0] != "*")
    {
        ans_attr = attrname;
    }
    else
    {
        ans_attr = dikar_attr;
    }

    ans.insert(ans.begin(), ans_attr);
    if (!order.empty())
    {
        Sort(order, ans);
    }
    answer.Loadstate("Select successfully");
    answer.Loaddata(ans);
    return ans;
}

bool TableManager::Delete(std::string tablename, std::vector<expr> condition, Ans &answer)
{
    if (this->user.getPermission(tablename, "delete") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }
    Table table = TableStream::LoadTable(tablename);
    if (table.isNULL())
        return 0;
    std::vector<std::vector<std::string>> data = table.getData();
    std::vector<std::string> attrs = table.getAttributes();
    std::vector<std::vector<std::string>> ans;
    // ans.push_back(attrs);
    bool joinflag = 0;
    for (int i = 0; i < data.size(); i++)
=======
    if(!order.empty())
    {
        Sort(order,ans);
    }
    return ans;
}

bool TableManager::Delete(std::string tablename, std::vector<expr> condition)
{
    Table table = TableStream::LoadTable(tablename);
    std::vector<std::vector<std::string>> data = table.getData();
    std::vector<std::string> attrs = table.getAttributes();
    std::vector<std::vector<std::string>> ans;
    ans.push_back(attrs);
    for (int i = 1; i < data.size(); i++)
>>>>>>> refs/remotes/origin/main
    {
        std::vector<std::string> datai = data[i];
        std::string checkstring;
        for (auto x : condition)
        {
            if (x.type == expr::expression)
            {
                if (x.tag == expr::largerorequal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (LargerOrEual(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::smallerorequal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (SmallOrEqual(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::smaller)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (Smaller(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::larger)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (Larger(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::equal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (datai[attrindex] == x.val)
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::noequal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (!(datai[attrindex] == x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
            }
            else if (x.type == expr::logic)
            {
                if (x.tag == expr::_and)
                {
                    checkstring.push_back('&');
                }
                else if (x.tag == expr::_or)
                {
                    checkstring.push_back('|');
                }
<<<<<<< HEAD
                else if (x.tag == expr::_not)
=======
                else if(x.tag==expr::_not)
>>>>>>> refs/remotes/origin/main
                {
                    checkstring.push_back('!');
                }
            }
            else
            {
                std::cout << "Undefined behavior" << std::endl;
                return false;
            }
        }
<<<<<<< HEAD
        CaculateTree checker;
=======
        CaculateTree checker(checkstring);
>>>>>>> refs/remotes/origin/main
        if (!checker.caculate(checkstring))
        {
            ans.push_back(datai);
        }
<<<<<<< HEAD
        else
        {
            for (auto x : attrs)
            {

                auto referencedBy = table.getReferencedBy(x);
                for (auto p : referencedBy)
                {
                    auto pp = p;
                    auto inpuar = p.first;
                    Table reftable = TableStream::LoadTable(inpuar);
                    joinflag = reftable.jointDelete(p.second, datai[table.getAttributeindex(x)]);
                    TableStream::SaveTable(reftable);
                }
            }
        }
    }
    if (joinflag)
        table.LoadData(ans);
    TableStream::SaveTable(table);
    answer.Loadstate("Delete successfully");
=======
    }
    table.LoadData(ans);
    TableStream::SaveTable(table);
>>>>>>> refs/remotes/origin/main
    return true;
}

void TableManager::Sort(
    std::vector<std::pair<std::string, bool>> order,
    std::vector<std::vector<std::string>> &result)
{
    // if (checkPermission(this->user, "SELECT") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return;
    // }
    std::map<std::string, int> attrindex;
    for (int i = 0; i < result[0].size(); i++)
    {
        attrindex[result[0][i]] = i;
    }

<<<<<<< HEAD
    std::sort(result.begin() + 1, result.end(),
=======
    std::sort(result.begin(), result.end(),
>>>>>>> refs/remotes/origin/main
              [&](std::vector<std::string> a, std::vector<std::string> b)
              {
                  for (auto ord : order)
                  {
<<<<<<< HEAD
                      if (a[attrindex[ord.first]] == "NULL")
                          return false;
                      if (b[attrindex[ord.first]] == "NULL")
                          return true;
                      if (a[attrindex[ord.first]] == b[attrindex[ord.first]])
                          continue;
=======

>>>>>>> refs/remotes/origin/main
                      if (ord.second) // 1 for ascending

                          return a[attrindex[ord.first]] < b[attrindex[ord.first]];
                      else
                          return a[attrindex[ord.first]] > b[attrindex[ord.first]];
                  }
                  return false;
              });
    return;
}

<<<<<<< HEAD
bool TableManager::AlterTableDropColumn(std::string tablename, std::string column_name, Ans &answer)
{
    if (this->user.getPermission(tablename, "alter") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }
    Table table = TableStream::LoadTable(tablename);
    std::vector<std::string> tmpc;
    tmpc.push_back(column_name);
    if (!table.inputattrsCheck(tmpc))
    {
        answer.Loadstate("Input attribute error");
        std::cout << "Input attribute error" << std::endl;
        return false;
    }
    table.AlterTableDropColumn(column_name);
    TableStream::SaveTable(table);
    answer.Loadstate("Column dropped successfully");
    return true;
}

bool TableManager::AlterTableAddPrimaryKey(std::string tablename, std::vector<std::string> column_name, Ans &answer)
{
    if (this->user.getPermission(tablename, "alter") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }
    Table table = TableStream::LoadTable(tablename);
    if (!table.inputattrsCheck(column_name))
    {
        answer.Loadstate("Input attribute error");
        std::cout << "Input attribute error" << std::endl;
        return false;
    }
    table.AlterTableAddPrimaryKey(column_name);
    TableStream::SaveTable(table);
    answer.Loadstate("Primary key added successfully");
    return true;
}

bool TableManager::AlterTableDropPrimaryKey(std::string tablename, Ans &answer)
{
    if (this->user.getPermission(tablename, "alter") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableDropPrimaryKey();
    TableStream::SaveTable(table);
    answer.Loadstate("Primary key dropped successfully");
    return true;
}

bool TableManager::AlterTableAddForeignKey(
    std::string tablename,
    std::string attrname,
    std::string reftablename,
    std::string otherattr,
    std::string constraint_name,
    bool updatejoint,
    bool deletejoint,
    Ans &answer)
{
    if (this->user.getPermission(tablename, "alter") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableAddForeignKey(attrname, reftablename, otherattr, constraint_name);
    std::vector<std::string> tmpc;
    tmpc.push_back(attrname);
    if (!table.inputattrsCheck(tmpc))
    {
        answer.Loadstate("Input attribute error");
        std::cout << "Input attribute error" << std::endl;
        return false;
    }
    if (updatejoint)
        table.addupdatejoint(attrname, true);
    else
        table.addupdatejoint(attrname, false);
    if (deletejoint)
        table.addDeletejoint(attrname, true);
    else
        table.addDeletejoint(attrname, false);
    TableStream::SaveTable(table);
    Table reftable = TableStream::LoadTable(reftablename);
    reftable.addReferencedBy(otherattr, make_pair(tablename, attrname));
    TableStream::SaveTable(reftable);
    answer.Loadstate("Foreign key added successfully");
    return true;
}

bool TableManager::AlterTableDropForeignKey(std::string tablename, std::string FK_name, Ans &answer)
{
    if (this->user.getPermission(tablename, "alter") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }
    Table table = TableStream::LoadTable(tablename);
    auto fr = table.getForeignKeys(FK_name);
    if (fr.first == "NULL")
    {
        answer.Loadstate("Foreign key not exist");
        std::cout << "Foreign key not exist" << std::endl;
        return false;
    }
    auto reftable = TableStream::LoadTable(fr.second.first);
    auto reftableattrname = fr.second.second;
    auto FK_attrname = fr.first;
    reftable.removerefby(reftableattrname, make_pair(tablename, FK_attrname));
    table.AlterTableDropForeignKey(FK_name);
    TableStream::SaveTable(reftable);
    TableStream::SaveTable(table);
    answer.Loadstate("Foreign key dropped successfully");
    return true;
}

bool TableManager::AlterTableModifyColumnName(
    std::string tablename,
    std::string old_column_name,
    std::string new_column_name,
    Ans &answer)
{
    if (this->user.getPermission(tablename, "alter") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }
    Table table = TableStream::LoadTable(tablename);
    std::vector<std::string> tmpc;
    tmpc.push_back(old_column_name);
    if (!table.inputattrsCheck(tmpc))
    {
        answer.Loadstate("Input attribute error");
        std::cout << "Input attribute error" << std::endl;
        return false;
    }
    table.AlterTableModifyColumnName(old_column_name, new_column_name);
    TableStream::SaveTable(table);
    return true;
}

bool TableManager::AlterTableModifyColumnDefault(
    std::string tablename,
    std::string column_name,
    std::string column_default,
    Ans &answer)
{
    if (this->user.getPermission(tablename, "alter") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }
    Table table = TableStream::LoadTable(tablename);

    std::vector<std::string> tmpc;
    tmpc.push_back(column_name);
    if (!table.inputattrsCheck(tmpc))
    {
        answer.Loadstate("Input attribute error");
        std::cout << "Input attribute error" << std::endl;
        return false;
    }

    table.AlterTableModifyColumnDefault(column_name, column_default);
    TableStream::SaveTable(table);
    answer.Loadstate("Default value modified successfully");

    return true;
}

bool TableManager::AlterTableModifyColumnNull(
    std::string tablename,
    std::string column_name,
    bool column_null,
    Ans &answer)
{
    if (this->user.getPermission(tablename, "alter") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }
    Table table = TableStream::LoadTable(tablename);

    std::vector<std::string> tmpc;
    tmpc.push_back(column_name);
    if (!table.inputattrsCheck(tmpc))
    {
        answer.Loadstate("Input attribute error");
        std::cout << "Input attribute error" << std::endl;
        return false;
    }

    table.AlterTableModifyColumnNull(column_name, column_null);
    TableStream::SaveTable(table);
    answer.Loadstate("Null value modified successfully");
    return true;
}

bool TableManager::AlterTableModifyColumnUnique(
    std::string tablename,
    std::string column_name,
    bool column_unique,
    Ans &answer)
{
    if (this->user.getPermission(tablename, "alter") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }

    Table table = TableStream::LoadTable(tablename);

    std::vector<std::string> tmpc;
    tmpc.push_back(column_name);
    if (!table.inputattrsCheck(tmpc))
    {
        answer.Loadstate("Input attribute error");
        std::cout << "Input attribute error" << std::endl;
        return false;
    }

    table.AlterTableModifyColumnUnique(column_name, column_unique);
    TableStream::SaveTable(table);
    answer.Loadstate("Unique value modified successfully");
    return true;
}

bool TableManager::AlterTableModifyColumnType(
    std::string tablename,
    std::string column_name,
    std::string column_type,
    Ans &answer)
{
    if (this->user.getPermission(tablename, "alter") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }

    Table table = TableStream::LoadTable(tablename);

    std::vector<std::string> tmpc;
    tmpc.push_back(column_name);
    if (!table.inputattrsCheck(tmpc))
    {
        answer.Loadstate("Input attribute error");
        std::cout << "Input attribute error" << std::endl;
        return false;
    }

    table.AlterTableModifyColumnType(column_name, column_type);
    TableStream::SaveTable(table);
    answer.Loadstate("Column type modified successfully");
    return true;
}

bool TableManager::Insert(
    std::string tablename,
    std::vector<std::string> argv_atr,
    std::vector<std::string> argv_val,
    Ans &answer)
{
    if (this->user.getPermission(tablename, "insert") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }
    Table table = TableStream::LoadTable(tablename);

    if (!table.inputattrsCheck(argv_atr))
    {
        answer.Loadstate("Input attribute error");
        std::cout << "Input attribute error" << std::endl;
        return false;
    }

    // foreign key check
    auto foreigns = table.getForeignKeys();
    for (auto x : argv_atr)
    {
        if (foreigns.find(x) == foreigns.end())
        {
            continue;
        }
        auto ref = foreigns[x];
        auto reftable = TableStream::LoadTable(ref.first);
        auto refattrvals = reftable.getAttrvals(ref.second);
        auto index = table.getAttributeindex(x);
        if (index < 0)
        {
            answer.Loadstate("Attribute not exist: " + x);
            std::cout << "Attribute not exist: " << x << std::endl;
            return 0;
        }
        auto arv = argv_val[index];
        if (refattrvals.find(arv) == refattrvals.end())
        {
            answer.Loadstate("foreign key constraint failed");
            std::cout << "foreign key constraint failed" << std::endl;
            return false;
        }
    }

    table.InsertData(argv_atr, argv_val);
    // std::cout<<"Inserted data"<<std::endl;
    TableStream::SaveTable(table);
    answer.Loadstate("Insert successfully");
    return true;
}

bool TableManager::Update(
    std::string tablename,
    std::vector<std::string> attrname,
    std::vector<std::string> attrval,
    std::vector<expr> condition,
    Ans &answer)
{
    if (this->user.getPermission(tablename, "update") == false)
    {
        answer.Loadstate("Permission denied");
        std::cout << "Permission denied" << std::endl;
        return false;
    }
    Table table = TableStream::LoadTable(tablename);
    if (!table.inputattrsCheck(attrname))
    {
        answer.Loadstate("Input attribute error");
        std::cout << "Input attribute error" << std::endl;
        return false;
    }

    bool ckflag = 1;
    ckflag &= table.primaryConstraintCheck(attrname, attrval);
    // ckflag&=table.nullCheck(attrname,attrval);
    ckflag &= table.unique_check(attrname, attrval);
    if (ckflag == 0)
    {
        answer.Loadstate("Update Failed");
        std::cout << "Update Failed" << std::endl;
        return false;
    }

    std::vector<std::vector<std::string>> data = table.getData();
    std::vector<std::string> attrs = table.getAttributes();
    std::vector<std::vector<std::string>> ans;
    // ans.push_back(attrs);
    for (int i = 0; i < data.size(); i++)
=======
bool TableManager::AlterTableDropColumn(std::string tablename, std::string column_name)
{
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableDropColumn(column_name);
    return true;
}

bool TableManager::AlterTableAddPrimaryKey(std::string tablename, std::vector<std::string> column_name)
{
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableAddPrimaryKey(column_name);
    return true;
}

bool TableManager::AlterTableDropPrimaryKey(std::string tablename, std::vector<std::string> column_name)
{
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableDropPrimaryKey(column_name);
    return true;
}

bool TableManager::AlterTableAddForeignKey(std::string tablename, std::string attrname, std::string reftablename, std::string otherattr)
{
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableAddForeignKey(attrname, reftablename, otherattr);
    return true;
}

bool TableManager::AlterTableDropForeignKey(std::string tablename, std::string attr)
{
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableDropForeignKey(attr);
    return true;
}

bool TableManager::AlterTableModifyColumnName(std::string tablename, std::string old_column_name, std::string new_column_name)
{
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableModifyColumnName(old_column_name, new_column_name);
    return true;
}

bool TableManager::AlterTableModifyColumnDefault(std::string tablename, std::string column_name, std::string column_default)
{
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableModifyColumnDefault(column_name, column_default);
    return true;
}

bool TableManager::AlterTableModifyColumnNull(std::string tablename, std::string column_name, bool column_null)
{
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableModifyColumnNull(column_name, column_null);
    return true;
}

bool TableManager::AlterTableModifyColumnUnique(std::string tablename, std::string column_name, bool column_unique)
{
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableModifyColumnUnique(column_name, column_unique);
    return true;
}

bool TableManager::AlterTableModifyColumnType(std::string tablename, std::string column_name, std::string column_type)
{
    Table table = TableStream::LoadTable(tablename);
    table.AlterTableModifyColumnType(column_name, column_type);
    return true;
}

bool TableManager::Insert(std::string tablename, std::vector<std::string> argv_atr, std::vector<std::string> argv_val)
{
    Table table = TableStream::LoadTable(tablename);
    table.InsertData(argv_atr, argv_val);
    return true;
}

bool TableManager:: Update(
    std::string tablename,
    std::vector<std::string> attrname,
    std::vector<std::string> attrval,
    std::vector<expr> condition)
{
    Table table = TableStream::LoadTable(tablename);
    std::vector<std::vector<std::string>> data = table.getData();
    std::vector<std::string> attrs = table.getAttributes();
    std::vector<std::vector<std::string>> ans;
    ans.push_back(attrs);
    for (int i = 1; i < data.size(); i++)
>>>>>>> refs/remotes/origin/main
    {
        std::vector<std::string> datai = data[i];
        std::string checkstring;
        for (auto x : condition)
        {
            if (x.type == expr::expression)
            {
                if (x.tag == expr::largerorequal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (LargerOrEual(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::smallerorequal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (SmallOrEqual(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::smaller)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (Smaller(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::larger)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (Larger(datai[attrindex], x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::equal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (datai[attrindex] == x.val)
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
                else if (x.tag == expr::noequal)
                {
                    int attrindex;
                    for (int j = 0; j < attrs.size(); j++)
                    {
                        if (attrs[j] == x.key)
                        {
                            attrindex = j;
                            break;
                        }
                    }
                    if (!(datai[attrindex] == x.val))
                    {
<<<<<<< HEAD
                        checkstring += "1 ";
                    }
                    else
                    {
                        checkstring += "0 ";
=======
                        checkstring+="1 ";
                    }
                    else
                    {
                        checkstring+="0 ";
>>>>>>> refs/remotes/origin/main
                    }
                }
            }
            else if (x.type == expr::logic)
            {
                if (x.tag == expr::_and)
                {
                    checkstring.push_back('&');
                }
                else if (x.tag == expr::_or)
                {
                    checkstring.push_back('|');
                }
<<<<<<< HEAD
                else if (x.tag == expr::_not)
                {
                    checkstring.push_back('!');
                }
=======
                else if(x.tag==expr::_not)
                {
                    checkstring.push_back('!');
                }

>>>>>>> refs/remotes/origin/main
            }
            else
            {
                std::cout << "Undefined behavior" << std::endl;
                return false;
            }
        }
<<<<<<< HEAD
        CaculateTree checker;
=======
        CaculateTree checker(checkstring);
>>>>>>> refs/remotes/origin/main
        if (checker.caculate(checkstring))
        {
            for (int j = 0; j < attrs.size(); j++)
            {
                for (int k = 0; k < attrname.size(); k++)
                {
                    if (attrs[j] == attrname[k])
                    {
                        datai[j] = attrval[k];
                    }
                }
            }
<<<<<<< HEAD
            for (auto x : attrname)
            {
                auto referencedBy = table.getReferencedBy(x);
                for (auto p : referencedBy)
                {
                    Table reftable = TableStream::LoadTable(p.first);
                    reftable.jointUpdate(p.second, datai[table.getAttributeindex(x)], attrval[table.getAttributeindex(x)]);
                    TableStream::SaveTable(reftable);
                }
            }
=======
>>>>>>> refs/remotes/origin/main
        }
        ans.push_back(datai);
    }
    table.LoadData(ans);
    TableStream::SaveTable(table);
<<<<<<< HEAD
    answer.Loadstate("Update successfully");
    return true;
}
=======
    return true;
}

>>>>>>> refs/remotes/origin/main
