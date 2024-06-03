#include <table.hpp>
#include <iostream>
Table::~Table() {}

<<<<<<< HEAD
bool Table::addupdatejoint(std::string attrname, bool tag)
{
    if (this->attribute_index.find(attrname) == this->attribute_index.end())
    {
        std::cout << "Attribute not found" << std::endl;
        return false;
    }
    this->updatejoint[attrname] = tag;
    return false;
}

bool Table::addDeletejoint(std::string attrname, bool tag)
{
    if (this->attribute_index.find(attrname) == this->attribute_index.end())
    {
        std::cout << "Attribute not found" << std::endl;
        return false;
    }
    this->Deletejoint[attrname] = tag;
    return false;
}

std::map<std::string, bool> Table::getupdatejoint()
{
    if (!this->updatejoint.empty())
    {
        return this->updatejoint;
    }
    return std::map<std::string, bool>();
}

std::map<std::string, bool> Table::getDeletejoint()
{
    if (!this->Deletejoint.empty())
    {
        return this->Deletejoint;
    }
    return std::map<std::string, bool>();
}

std::map<std::string, std::vector<std::pair<std::string, std::string>>> Table::getReferencedBy()
{
    if (!this->referencedBy.empty())
    {
        return this->referencedBy;
    }
    return std::map<std::string, std::vector<std::pair<std::string, std::string>>>();
}

=======
>>>>>>> refs/remotes/origin/main
Table::Table()
{
}

Table::Table(std::string table_name, std::string table_dir)
{
    this->table_name = table_name;
    this->table_dir = table_dir;
    // this->user = user;
}

<<<<<<< HEAD
bool Table::setUpdateJoint(std::map<std::string, bool> updatejoint)
{
    this->updatejoint = updatejoint;
    return true;
}

bool Table::setDeleteJoint(std::map<std::string, bool> Deletejoint)
{
    this->Deletejoint = Deletejoint;
    return true;
}

bool Table::isNULL()
{
    return this->attributes.empty();
    // return false;
}

bool Table::isPrimary(std::string s)
{
    return this->primary_key.find(s) != this->primary_key.end();
}

=======
>>>>>>> refs/remotes/origin/main
void Table::addAttribute(std::string input)
{
    if (this->attribute_index.find(input) == this->attribute_index.end())
    {
        this->attribute_index[input] = ATTCNT;
        ATTCNT++;
        this->attributes.push_back(input);
    }
    else
        std::cout << "Attribute already exists" << std::endl;
}

<<<<<<< HEAD
void Table::addPrimaryKey(std::string input)
{
    this->primary_key.insert(input);
=======


void Table::addPrimaryKey(std::string input)
{
    if (this->primary_key.find(input) == this->primary_key.end())
        this->primary_key.insert(input);
    else
        std::cout << "Primary key already exists" << std::endl;
>>>>>>> refs/remotes/origin/main
}

void Table::setNull(std::string input, bool tag)
{
    this->attribute_null[input] = tag;
}

<<<<<<< HEAD
void Table::setUnique(std::string input, bool tag)
=======
void Table::setUnique(std::string input,bool tag)
>>>>>>> refs/remotes/origin/main
{
    this->attribute_unique[input] = tag;
}

void Table::setDefault(std::string attr, std::string val)
{
    this->attribute_default[attr] = val;
}

void Table::addForeign(std::string attrname, std::string tablename, std::string otherattr)
{
    // if (checkPermission(this->user, "ALTER") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return;
    // }
<<<<<<< HEAD
    if (tablename.empty())
    {
        std::cout << "Table name is empty" << std::endl;
        return;
    }
    if(tablename=="null")return;
=======
    if(tablename.empty())
    {
        std::cout<<"Table name is empty"<<std::endl;
        return;
    }
>>>>>>> refs/remotes/origin/main
    this->attribute_foreign[attrname].first = tablename;
    this->attribute_foreign[attrname].second = otherattr;
}

void Table::setTableName(std::string input)
{
    this->table_name = input;
}

void Table::setTablePath(std::string input)
{
    this->table_dir = input;
}

<<<<<<< HEAD
void Table::addReferencedBy(std::string attrname, std::pair<std::string, std::string> fkinf)
{
    this->referencedBy[attrname].push_back(fkinf);
}

std::vector<std::pair<std::string, std::string>> Table::getReferencedBy(std::string attrname)
{
    if (this->referencedBy.find(attrname) == this->referencedBy.end())
    {
        std::cout << "No reference found:" << attrname << std::endl;
        return std::vector<std::pair<std::string, std::string>>();
    }
    return this->referencedBy[attrname];
}

bool Table::jointDelete(std::string attrname, std::string val)
{
    if (this->attribute_foreign.find(attrname) == this->attribute_foreign.end())
    {
        std::cout << "No reference found:" << attrname << std::endl;
        return false;
        ;
    }
    if (!this->Deletejoint[attrname])
    {
        std::cout << "restrickted Delete" << std::endl;
        return false;
    }
    for (auto it = this->data.begin(); it != this->data.end();)
    {
        if ((*it)[this->attribute_index[attrname]] == val)
        {
            it = this->data.erase(it);
        }
        else
        {
            it++;
        }
    }
    return true;
}

bool Table::jointUpdate(std::string attrname, std::string oldval, std::string newval)
{
    if (this->referencedBy.find(attrname) == this->referencedBy.end())
    {
        std::cout << "No reference found:" << attrname << std::endl;
        return false;
    }
    if (!this->updatejoint[attrname])
    {
        std::cout << "restrickted Update" << std::endl;
        return false;
    }
    for (auto it = this->data.begin(); it != this->data.end(); it++)
    {
        if ((*it)[this->attribute_index[attrname]] == oldval)
        {
            (*it)[this->attribute_index[attrname]] = newval;
        }
    }
    return true;
}

std::set<std::string> Table::getAttrvals(std::string attrname)
{
    if (this->attribute_index.find(attrname) == this->attribute_index.end())
    {
        std::cout << "Attribute not found:" << attrname << std::endl;
        return std::set<std::string>();
    }
    std::set<std::string> ans;
    for (auto x : this->data)
    {
        ans.insert(x[this->attribute_index[attrname]]);
    }
    return ans;
}

=======
>>>>>>> refs/remotes/origin/main
std::string Table::getTableName()
{
    return this->table_name;
}
std::string Table::getTablePath()
{
    return this->table_dir;
}
std::vector<std::vector<std::string>> Table::getData()
{
    return this->data;
}
std::vector<std::string> Table::getAttributes()
{
    std::vector<std::string> ans;
<<<<<<< HEAD
    for (auto x : attributes)
    {
        if (this->attribute_index.find(x) != this->attribute_index.end())
            ans.push_back(x);
=======
    for(auto x:attribute_index)
    {
        ans.push_back(x.first);
>>>>>>> refs/remotes/origin/main
    }
    return ans;
}
std::set<std::string> Table::getPrimaryKeys()
{
    return this->primary_key;
}
std::map<std::string, std::string> Table::getAttributeType()
{
    return this->attribute_type;
}
std::map<std::string, std::string> Table::getAttributeDefault()
{
    return this->attribute_default;
}

std::map<std::string, std::pair<std::string, std::string>> Table::getForeignKeys()
{
    return this->attribute_foreign;
}

std::map<std::string, bool> Table::getAttributeNull()
{
    return this->attribute_null;
}

std::map<std::string, bool> Table::getAttributeUnique()
{
    return this->attribute_unique;
}

// bool Table::checkPermission(User user, std::string permission)
// {
//     return user.getPermission(this->table_name, permission);
// }

<<<<<<< HEAD
=======



>>>>>>> refs/remotes/origin/main
int Table::getAttributeindex(std::string attr)
{
    if (this->attribute_index.find(attr) == this->attribute_index.end())
    {
<<<<<<< HEAD
        std::cout << "Attribute not found:" << attr << std::endl;
=======
        std::cout << "Attribute not found" << std::endl;
>>>>>>> refs/remotes/origin/main
        return -1;
    }
    return this->attribute_index[attr];
}

<<<<<<< HEAD
// void Table::DeleteallData()
// {
//     // if (checkPermission(this->user, "DELETE") == false)
//     // {
//     //     std::cout << "Permission denied" << std::endl;
//     //     return;
//     // }
//     this->data.clear();
// }
=======

void Table::DeleteallData()
{
    // if (checkPermission(this->user, "DELETE") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return;
    // }
    this->data.clear();
}
>>>>>>> refs/remotes/origin/main

void Table::DeleteDataEq(std::string attr, std::string val)
{
    // if (checkPermission(this->user, "DELETE") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return;
    // }
<<<<<<< HEAD
    int flag = 0;
    for (auto it = this->data.begin(); it != this->data.end();)
    {
        if ((*it)[this->attribute_index[attr]] == val)
            it = this->data.erase(it), flag = 1;
        else
            it++;
    }
    if (flag == 0)
        std::cout << "No user found" << std::endl;
    else
        std::cout << "User Drop sud" << std::endl;
=======
    for (auto it = this->data.begin(); it != this->data.end();)
    {
        if ((*it)[this->attribute_index[attr]] == val)
            it = this->data.erase(it);
        else
            it++;
    }
>>>>>>> refs/remotes/origin/main
}

void Table::DeleteDataLarger(std::string attr, std::string val)
{
    // if (checkPermission(this->user, "DELETE") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return;
    // }
    for (auto it = this->data.begin(); it != this->data.end();)
    {
        if ((*it)[this->attribute_index[attr]] > val)
            it = this->data.erase(it);
        else
            it++;
    }
}

void Table::DeleteDataSmaller(std::string attr, std::string val)
{
    // if (checkPermission(this->user, "DELETE") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return;
    // }
    for (auto it = this->data.begin(); it != this->data.end();)
    {
        if ((*it)[this->attribute_index[attr]] < val)
            it = this->data.erase(it);
        else
            it++;
    }
}

void Table::DeleteDataNoEqual(std::string attr, std::string val)
{
    // if (checkPermission(this->user, "DELETE") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return;
    // }
    for (auto it = this->data.begin(); it != this->data.end();)
    {
        if ((*it)[this->attribute_index[attr]] != val)
            it = this->data.erase(it);
        else
            it++;
    }
}

<<<<<<< HEAD
bool Table::InsertData(std::vector<std::string> argv_atr, std::vector<std::string> argv_val)
=======
std::string Table::InsertData(std::vector<std::string> argv_atr, std::vector<std::string> argv_val)
>>>>>>> refs/remotes/origin/main
{
    // if (checkPermission(this->user, "INSERT") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return "Permission denied";
    // }

<<<<<<< HEAD
    bool flag = 1;
    flag &= this->primaryConstraintCheck(argv_atr, argv_val);
    flag &= this->nullCheck(argv_atr, argv_val);
    flag &= this->unique_check(argv_atr, argv_val);
    if (flag == 0)
    {
        std::cout << "Insert failed" << std::endl;
        return 0;
    }

    if (argv_atr.size() != argv_val.size())
    {
        std::cout << "Attribute and value size mismatch" << std::endl;
        // return "Attribute and value size mismatch";
        return 0;
=======
    if (argv_atr.size() != argv_val.size())
    {
        std::cout << "Attribute and value size mismatch" << std::endl;
        return "Attribute and value size mismatch";
>>>>>>> refs/remotes/origin/main
    }
    for (int i = 0; i < argv_atr.size(); i++)
    {
        if (this->attribute_index.find(argv_atr[i]) == this->attribute_index.end())
        {
<<<<<<< HEAD
            std::cout << "Attribute not found:" << argv_atr[i] << std::endl;
            // return "Attribute not found";
            return 0;
        }
    }
    std::vector<std::string> tmp;
    for (auto attr : this->getAttributes())
=======
            std::cout << "Attribute not found" << std::endl;
            return "Attribute not found";
        }
    }
    std::vector<std::string> tmp;
    for (auto attr : this->data[0])
>>>>>>> refs/remotes/origin/main
    {

        if (std::find(argv_atr.begin(), argv_atr.end(), attr) != argv_atr.end())
        {
            tmp.push_back(argv_val[std::find(argv_atr.begin(), argv_atr.end(), attr) - argv_atr.begin()]);
        }
        else
        {
            if (this->attribute_default.find(attr) != this->attribute_default.end())
                tmp.push_back(this->attribute_default[attr]);
            else
                tmp.push_back("--NULL--");
        }
    }
    this->data.push_back(tmp);
<<<<<<< HEAD
    // return "Data inserted";
    std::cout << "Data inserted" << std::endl;
    return 1;
=======
    return "Data inserted";
>>>>>>> refs/remotes/origin/main
}

// std::string Table::UpdateData(std::vector<std::string> argv_atr, std::vector<std::string> argv_toval)
// {
<<<<<<< HEAD
// if (checkPermission(this->user, "UPDATE") == false)
// {
//     std::cout << "Permission denied" << std::endl;
//     return "Permission denied";
// }
=======
    // if (checkPermission(this->user, "UPDATE") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return "Permission denied";
    // }
>>>>>>> refs/remotes/origin/main

//     if (argv_atr.size() != argv_toval.size())
//     {
//         std::cout << "Attribute and value size mismatch" << std::endl;
//         return "Attribute and value size mismatch";
//     }
//     for (int i = 0; i < argv_atr.size(); i++)
//     {
//         if (this->attribute_index.find(argv_atr[i]) == this->attribute_index.end())
//         {
//             std::cout << "Attribute not found" << std::endl;
//             return "Attribute not found";
//         }
//     }

//     for (auto dt : this->data)
//     {
//         for (int i = 0; i < argv_atr.size(); i++)
//         {
//             dt[this->attribute_index[argv_atr[i]]] = argv_toval[i];
//         }
//     }
//     return "Data updated";
// }

// bool Table::AlterTableAddColumn(std::string column_name,
//                                 std::string column_type,
//                                 bool column_null,
//                                 bool column_unique,
//                                 std::string column_default = std::string())

// {
//     // if (checkPermission(this->user, "ALTER") == false)
//     // {
//     //     std::cout << "Permission denied" << std::endl;
//     //     return false;
//     // }

//     if (this->attribute_index.find(column_name) != this->attribute_index.end())
//     {
//         std::cout << "Attribute already exists" << std::endl;
//         return false;
//     }

//     this->addAttribute(column_name);

//     this->attribute_type[column_name] = column_type;
//     this->attribute_null[column_name] = column_null;
//     this->attribute_unique[column_name] = column_unique;
//     this->attribute_default[column_name] = column_default;
//     return true;
// }

<<<<<<< HEAD
bool Table::AlterTableAddColumn(
    std::vector<std::pair<std::string, std::string>> settings,
    std::pair<std::string, std::string> foreign,
    bool updatejoint,
    bool deletejoint)
{
    Table &ans = *this;
    std::string attrname;
    for(auto x:settings)
    {
        if(x.first=="name")
        {
            attrname=x.second;
            break;
        }
    }
    if (this->attribute_index.find(attrname) != this->attribute_index.end())
    {
        std::cout << "Attribute already exists:" <<attrname<< std::endl;
        return false;
    }
    for (auto p : settings)
    {
        std::string tag = p.first;
        std::string val = p.second;
        if (tag == "null")
        {
            if (val == "0")
            {
                ans.setNull(attrname, 0);
            }
            else
            {
                ans.setNull(attrname, 1);
            }
        }
        else if (tag == "type")
        {
            ans.AlterTableModifyColumnType(attrname, val);
        }
        else if (tag == "primary key")
        {
            if (val == "1")
                ans.addPrimaryKey(attrname);
        }
        else if (tag == "unique")
        {
            if (val == "0")
                ans.setUnique(attrname, 0);
            else
                ans.setUnique(attrname, 1);
        }
        else if (tag == "default")
        {
            ans.setDefault(attrname, val);
        }
        else if (tag == "name")
        {
            ans.addAttribute(val);
            attrname = val;
        }

        else
        {
            std::cout << "Undefined behavior" << std::endl;
        }
    }

    ans.addForeign(attrname, foreign.first, foreign.second);
    if(foreign.first!="null")
    {
        ans.addupdatejoint(attrname,updatejoint);
        ans.addDeletejoint(attrname,deletejoint);
    }
    ans.setConstraintName("FK:" + foreign.second, foreign.second);

    auto defaults=ans.getAttributeDefault();
    auto nulls=ans.getAttributeNull();
    if(nulls[attrname]==1)
    {
        for(auto &x:this->data)
        {
            if(defaults.find(attrname)!=defaults.end())x.push_back(defaults[attrname]);
            else x.push_back("--Novals--");
        }
    }
    else
    {
        for(auto &x:this->data)
        {
            x.push_back(defaults[attrname]);
        }
    }

    return true;
}

bool Table::AlterTableDropColumn(std::string column_name)
{
    // if (checkPermission(this->user, "ALTER") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return false;
    // }

    if (this->attribute_index.find(column_name) == this->attribute_index.end())
    {
        std::cout << "Attribute not found:" << column_name << std::endl;
        return false;
    }

    int index = this->attribute_index[column_name];
    for(auto &x:this->data)
    {
        x.erase(x.begin()+index);
    }

    this->attribute_index.erase(column_name);
    this->attribute_type.erase(column_name);
    this->attribute_default.erase(column_name);
    this->attribute_null.erase(column_name);
    this->attribute_unique.erase(column_name);
    return true;
}
=======
// bool Table::AlterTableDropColumn(std::string column_name)
// {
//     // if (checkPermission(this->user, "ALTER") == false)
//     // {
//     //     std::cout << "Permission denied" << std::endl;
//     //     return false;
//     // }

//     // if (this->attribute_index.find(column_name) == this->attribute_index.end())
//     // {
//     //     std::cout << "Attribute not found" << std::endl;
//     //     return false;
//     // }

//     this->attribute_index.erase(column_name);
//     this->attribute_type.erase(column_name);
//     this->attribute_default.erase(column_name);
//     this->attribute_null.erase(column_name);
//     this->attribute_unique.erase(column_name);
//     return true;
// }
>>>>>>> refs/remotes/origin/main

bool Table::AlterTableAddPrimaryKey(std::vector<std::string> column_name)
{
    // if (checkPermission(this->user, "ALTER") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return false;
    // }

    for (auto col : column_name)
    {
        if (this->attribute_index.find(col) == this->attribute_index.end())
        {
<<<<<<< HEAD
            std::cout << "Attribute not found:" << col << std::endl;
=======
            std::cout << "Attribute not found" << std::endl;
>>>>>>> refs/remotes/origin/main
            return false;
        }
    }

    for (auto col : column_name)
    {
        this->primary_key.insert(col);
    }
    return true;
}

<<<<<<< HEAD
bool Table::LoadAttributeType(std::string attr_name, std::string attr_type)
{
    this->attribute_type[attr_name] = attr_type;
    return true;
}

bool Table::AlterTableDropPrimaryKey()
{

    if (this->primary_key.empty())
    {
        std::cout << "Primary key not found" << std::endl;
        return false;
    }
    this->primary_key.clear();
    return true;
}

bool Table::setConstraintName(std::string constraint_name, std::string attr_name)
{
    if (this->attribute_index.find(attr_name) == this->attribute_index.end())
    {
        std::cout << "Attribute not found:" << attr_name << std::endl;
        return false;
    }
    this->foreign_name[constraint_name] = attr_name;
    return true;
}

std::vector<std::string> Table::getConstraintName()
{
    std::vector<std::string> ans;
    for (auto x : foreign_name)
    {
        ans.push_back(x.second);
    }
    return ans;
}

std::string Table::getConstraintName(std::string attr_name)
{
    for (auto x : foreign_name)
    {
        if (x.second == attr_name)
            return x.first;
    }

    std::cout << "Constraint name not found" << std::endl;
    return "--null--";
}

bool Table::AlterTableAddForeignKey(std::string attrname,
                                    std::string tablename,
                                    std::string otherattr,
                                    std::string constraint_namer)
{

    if (this->attribute_index.find(attrname) == this->attribute_index.end())
    {
        std::cout << "Attribute not found:" << attrname << std::endl;
        return false;
    }
    if (this->attribute_foreign.find(attrname) != this->attribute_foreign.end())
    {
        std::cout << "Foreign key already exists" << std::endl;
=======
bool Table::AlterTableDropPrimaryKey(std::vector<std::string> column_name)
{

    // if (checkPermission(this->user, "ALTER") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return false;
    // }

    if (column_name.size() == 1 && column_name[0] == "*")
    {
        this->primary_key.clear();
        return true;
    }

    for (auto col : column_name)
    {
        if (this->attribute_index.find(col) == this->attribute_index.end())
        {
            std::cout << "Attribute not found" << std::endl;
            return false;
        }
    }

    for (auto col : column_name)
    {
        this->primary_key.erase(col);
    }
    return true;
}

bool Table::AlterTableAddForeignKey(std::string attrname, std::string tablename, std::string otherattr)
{
    // if (checkPermission(this->user, "ALTER") == false)
    // {
    //     std::cout << "Permission denied" << std::endl;
    //     return false;
    // }

    if (this->attribute_index.find(attrname) == this->attribute_index.end())
    {
        std::cout << "Attribute not found" << std::endl;
>>>>>>> refs/remotes/origin/main
        return false;
    }

    this->attribute_foreign[attrname].first = tablename;
    this->attribute_foreign[attrname].second = otherattr;
<<<<<<< HEAD
    this->foreign_name[constraint_namer] = attrname;
=======
>>>>>>> refs/remotes/origin/main

    return false;
}

<<<<<<< HEAD
bool Table::AlterTableDropForeignKey(std::string Fk_name)
{
    if (this->foreign_name.find(Fk_name) == this->foreign_name.end())
    {
        std::cout << "Foreign key not found" << std::endl;
=======
bool Table::AlterTableDropForeignKey(std::string attr)
{
    if (this->attribute_index.find(attr) == this->attribute_index.end())
    {
        std::cout << "Attribute Not exist" << std::endl;
>>>>>>> refs/remotes/origin/main
        return false;
    }
    else
    {
<<<<<<< HEAD
        this->updatejoint.erase(this->updatejoint.find(this->foreign_name[Fk_name]));
        this->Deletejoint.erase(this->Deletejoint.find(this->foreign_name[Fk_name]));
        this->attribute_foreign.erase(this->attribute_foreign.find(this->foreign_name[Fk_name]));
        this->foreign_name.erase(this->foreign_name.find(Fk_name));
        
=======
        this->attribute_foreign[attr] = std::pair<std::string, std::string>();
>>>>>>> refs/remotes/origin/main
    }
    return true;
}

bool Table::AlterTableModifyColumnName(
    std::string old_column_name,
    std::string new_column_name)
{
    if (this->attribute_index.find(old_column_name) == this->attribute_index.end())
    {
        std::cout << "attr not exist" << std::endl;
        return false;
    }

    if (this->attribute_index.find(new_column_name) != this->attribute_index.end())
    {
        std::cout << "new attr already exist" << std::endl;
        return false;
    }

    else
    {
        int idx = attribute_index[old_column_name];
        attribute_index.erase(attribute_index.find(old_column_name));
        attribute_index[new_column_name] = idx;

        std::string type = attribute_type[old_column_name];
        attribute_type.erase(attribute_type.find(old_column_name));
        attribute_type[new_column_name] = type;

        if (attribute_default.find(old_column_name) != attribute_default.end())
        {
            std::string def = attribute_default[old_column_name];
            attribute_default.erase(attribute_default.find(old_column_name));
            attribute_default[new_column_name] = def;
        }

        if (attribute_null.find(old_column_name) != attribute_null.end())
        {
            bool val = attribute_null[old_column_name];
            attribute_null.erase(old_column_name);
            attribute_null[new_column_name] = val;
        }

        if (attribute_unique.find(old_column_name) != attribute_unique.end())
        {
            bool val = attribute_unique[old_column_name];
            attribute_unique.erase(old_column_name);
            attribute_unique[new_column_name] = val;
        }

        if (primary_key.find(old_column_name) != primary_key.end())
        {
            primary_key.erase(primary_key.find(old_column_name));
            primary_key.insert(new_column_name);
        }

        if (attribute_foreign.find(old_column_name) != attribute_foreign.end())
        {
            std::pair<std::string, std::string> ref = attribute_foreign[old_column_name];
            attribute_foreign.erase(attribute_foreign.find(old_column_name));
            attribute_foreign[new_column_name] = ref;
        }

        for (auto &x : attributes)
            if (x == old_column_name)
                x = new_column_name;
    }
    return true;
}

bool Table::AlterTableModifyColumnDefault(
    std::string column_name,
    std::string column_default)
{
    if (attribute_index.find(column_name) == attribute_index.end())
    {
        std::cout << "attr not exist" << std::endl;
        return false;
    }

    attribute_default[column_name] = column_default;
    return true;
}

bool Table::AlterTableModifyColumnNull(
    std::string column_name,
    bool column_null)
{
    if (attribute_index.find(column_name) == attribute_index.end())
    {
        std::cout << "attr not exist" << std::endl;
        return false;
    }
    this->attribute_null[column_name] = column_null;
    return true;
}

bool Table::AlterTableModifyColumnUnique(
    std::string column_name,
    bool column_unique)
{
    if (attribute_index.find(column_name) == attribute_index.end())
    {
        std::cout << "attr not exist" << std::endl;
        return false;
    }

    this->attribute_unique[column_name] = column_unique;
    return true;
}

bool Table::AlterTableModifyColumnType(
    std::string column_name,
    std::string column_type)
{
    if (attribute_index.find(column_name) == attribute_index.end())
    {
        std::cout << "attr not exist" << std::endl;
        return false;
    }

    attribute_type[column_name] = column_type;
    return true;
}

<<<<<<< HEAD
=======

>>>>>>> refs/remotes/origin/main
void Table::LoadData(std::vector<std::string> input)
{
    this->data.push_back(input);
}

<<<<<<< HEAD
=======

>>>>>>> refs/remotes/origin/main
void Table::LoadData(std::vector<std::vector<std::string>> input)
{
    this->data = input;
}

<<<<<<< HEAD
=======



















>>>>>>> refs/remotes/origin/main
// std::vector<std::vector<std::string>> Table::findAttributeEqual(std::string attr, std::string val)
// {
//     if (checkPermission(this->user, "SELECT") == false)
//     {
//         std::cout << "Permission denied" << std::endl;
//         return std::vector<std::vector<std::string>>();
//     }
//     std::vector<std::vector<std::string>> result;
//     if (this->attribute_index.find(attr) == this->attribute_index.end())
//     {
//         std::cout << "Attribute not found" << std::endl;
//         return result;
//     }
//     for (auto data : this->data)
//     {
//         if (data[this->attribute_index[attr]] == val)
//         {
//             result.push_back(data);
//         }
//     }
//     return result;
// }

// std::vector<std::vector<std::string>> Table::findAttributeLarger(std::string attr, std::string val)
// {
//     if (checkPermission(this->user, "SELECT") == false)
//     {
//         std::cout << "Permission denied" << std::endl;
//         return std::vector<std::vector<std::string>>();
//     }

//     std::vector<std::vector<std::string>> result;
//     if (this->attribute_index.find(attr) == this->attribute_index.end())
//     {
//         std::cout << "Attribute not found" << std::endl;
//         return result;
//     }
//     for (auto data : this->data)
//     {
//         if (data[this->attribute_index[attr]] > val)
//         {
//             result.push_back(data);
//         }
//     }
//     return result;
// }

// std::vector<std::vector<std::string>> Table::findAttributeSmaller(std::string attr, std::string val)
// {
//     if (checkPermission(this->user, "SELECT") == false)
//     {
//         std::cout << "Permission denied" << std::endl;
//         return std::vector<std::vector<std::string>>();
//     }

//     std::vector<std::vector<std::string>> result;
//     if (this->attribute_index.find(attr) == this->attribute_index.end())
//     {
//         std::cout << "Attribute not found" << std::endl;
//         return result;
//     }
//     for (auto data : this->data)
//     {
//         if (data[this->attribute_index[attr]] < val)
//         {
//             result.push_back(data);
//         }
//     }
//     return result;
// }

// std::vector<std::vector<std::string>> Table::findAttributeNoEqual(std::string attr, std::string val)
// {
//     if (checkPermission(this->user, "SELECT") == false)
//     {
//         std::cout << "Permission denied" << std::endl;
//         return std::vector<std::vector<std::string>>();
//     }

//     std::vector<std::vector<std::string>> result;
//     if (this->attribute_index.find(attr) == this->attribute_index.end())
//     {
//         std::cout << "Attribute not found" << std::endl;
//         return result;
//     }
//     for (auto data : this->data)
//     {
//         if (data[this->attribute_index[attr]] != val)
//         {
//             result.push_back(data);
//         }
//     }
//     return result;
// }

// std::vector<std::vector<std::string>> Table::selectDataByAttribute(std::set<std::string> attrs)
// {
//     if (checkPermission(this->user, "SELECT") == false)
//     {
//         std::cout << "Permission denied" << std::endl;
//         return std::vector<std::vector<std::string>>();
//     }

//     std::vector<std::vector<std::string>> result;
//     for (auto dt : this->data)
//     {
//         std::vector<std::string> tmp;
//         for (auto attr : attrs)
//         {
//             if (this->attribute_index.find(attr) == this->attribute_index.end())
//             {
//                 std::cout << "Attribute not found" << std::endl;
//                 return std::vector<std::vector<std::string>>();
//             }
//             tmp.push_back(dt[this->attribute_index[attr]]);
//         }
//         result.push_back(tmp);
//     }
//     return result;
// }