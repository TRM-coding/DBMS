#ifndef TABLE_HPP
#define TABLE_HPP

#include <string>
#include <vector>
#include <map>
#include <set>
#include <tuple>
// #include <user.hpp>
<<<<<<< HEAD
#include<iostream>
#include <algorithm>
// data_table format:
=======
#include <algorithm>
//data_table format:
>>>>>>> refs/remotes/origin/main
/*
attr1 attr2 attr3 attr4
sdfs 123 2019-12-12 2019-12-12
sdfs 123 2019-12-12 2019-12-12
sdfs 123 2019-12-12 2019-12-12
sdfs 123 NULL 2019-12-12
...
attr1 type [primarykey=1] [not null=1] [unique=1] [default=xxx/.]
attr2 type [primarykey=0] [not null=0] [unique=1] [default=xxx/.]
attr3 type [primarykey=1] [not null=1] [unique=1] [default=xxx/.]
attr3 type [primarykey=1] [not null=1] [unique=1] [default=xxx/.]
...
attr1 table2 otherattr1
attr2 table3 otherattr2
attr3 table4 otherattr3 otherattr4
...

*/

<<<<<<< HEAD
// userlogin_table format:
=======
//userlogin_table format:
>>>>>>> refs/remotes/origin/main
/*
username password
sdfs 123
sdfz 133
...
...
...
*/

<<<<<<< HEAD
// user_authority_table format:
/*
username,table_name,select,insert,delete,update,references
sdfs table1 1 1 1 1 1
=======
//user_authority_table format:
/*
username,table_name,select,insert,delete,update,references
sdfs table1 1 1 1 1 1 
>>>>>>> refs/remotes/origin/main
...
...
...
*/
class Table
{
private:
<<<<<<< HEAD
    // datatypes:int,float,char,date
=======
// datatypes:int,float,char,date
>>>>>>> refs/remotes/origin/main
    int ATTCNT = 0;
    std::string table_name;
    std::string table_path;
    // User user;
<<<<<<< HEAD
    struct date
    {
        int year;
        int month;
        int day;
        bool operator<(const date &rhs) const
        {
            if (year != rhs.year)
                return year < rhs.year;
            if (month != rhs.month)
                return month < rhs.month;
            return day < rhs.day;
=======
    struct date{
        int year;
        int month;
        int day;
        bool operator <(const date &rhs) const{
            if(year!=rhs.year)return year<rhs.year;
            if(month!=rhs.month)return month<rhs.month;
            return day<rhs.day;
>>>>>>> refs/remotes/origin/main
        }
    };
    std::string table_dir = std::string();
    std::map<std::string, std::string> attribute_type;
    std::map<std::string, std::string> attribute_default;
<<<<<<< HEAD
    std::map<std::string, bool> attribute_null;
    std::map<std::string, bool> attribute_unique;
    std::set<std::string> primary_key;
    std::map<std::string, std::string> foreign_name;
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> referencedBy;
    // constraint_name,attribuite_name,
    std::map<std::string, std::pair<std::string, std::string>> attribute_foreign;
    // attribuite_name,table_name,attribute_name
    std::vector<std::vector<std::string>> data;
    std::map<std::string, int> attribute_index;
    std::vector<std::string> attributes;

    std::map<std::string, bool> updatejoint;
    std::map<std::string, bool> Deletejoint;

public:
=======
    std::map<std::string,bool> attribute_null;
    std::map<std::string,bool> attribute_unique;
    std::set<std::string> primary_key;
    std::map<std::string,std::pair<std::string,std::string> > attribute_foreign;
    std::vector<std::vector<std::string> > data;
    std::map<std::string,int>attribute_index;
    std::vector<std::string> attributes;

public:
    
>>>>>>> refs/remotes/origin/main
    Table();
    Table(std::string table_name, std::string table_path);
    ~Table();

<<<<<<< HEAD
    bool addupdatejoint(std::string attrname, bool tag);
    bool addDeletejoint(std::string attrname, bool tag);
    std::map<std::string, bool> getupdatejoint();
    std::map<std::string, bool> getDeletejoint();

    bool removerefby(std::string attrname, std::pair<std::string, std::string> fkinf)
    {
        if (this->referencedBy.find(attrname) == this->referencedBy.end())
            return 0;
        auto &refby = this->referencedBy[attrname];
        for (auto it = refby.begin(); it != refby.end();)
        {
            if (it->first == fkinf.first && it->second == fkinf.second)
            {
                it=refby.erase(it);
            }
            else{
                it++;
            }
        }
        if(refby.size()==0)
        {
            this->referencedBy.erase(attrname);
        }
        return 0;
    }


    std::map<std::string, std::vector<std::pair<std::string, std::string>>> getReferencedBy();

    bool inputattrsCheck(std::vector<std::string> argvs)
    {
        for (auto x : argvs)
        {
            if (this->attribute_index.find(x) == this->attribute_index.end())
            {
                std::cout << "Attribute not exist:" << x << std::endl;
                return 0;
            }
        }
        return 1;
    }

    bool primaryConstraintCheck(std::vector<std::string> argv_atr, std::vector<std::string> argv_val)
    {
        bool flag = 1;
        int i=0;
        for (auto x : argv_atr)
        {
            if(this->primary_key.find(x)==this->primary_key.end())continue;
            auto x_val=this->getAttrvals(x);
            if(x_val.find(argv_val[i])!=x_val.end())
            {
                flag=0;
                break;
            }
            i++;
        }
        if (flag == 0)
        {
            std::cout << "primary key constraint failed" << std::endl;
            return false;
        }
        return true;
    }

    bool nullCheck(std::vector<std::string> argv_atr, std::vector<std::string> argv_val)
    {
        auto attrs = this->getAttributes();
        for(auto x:attrs)
        {
            if(std::find(argv_atr.begin(),argv_atr.end(),x)==argv_atr.end())
            {
                auto nullmap=this->getAttributeNull();
                if(nullmap[x]==0)
                {
                    std::cout<<"null constraint failed:"<<x<<std::endl;
                    return 0;
                }
            }
        }
        return 1;
    }

    bool unique_check(std::vector<std::string> argv_atr, std::vector<std::string> argv_val)
    {
        int i=0;
        for (auto x : argv_atr)
        {
            auto uniques = this->getAttributeUnique();
            
            if(!uniques[x])continue;
            auto attrvals = this->getAttrvals(x);
            if (attrvals.find(argv_val[i]) != attrvals.end())
            {
                std::cout << "unique constraint failed:" << x <<":"<<argv_val[i] << std::endl;
                return 0;
            }
            i++;
        }
        return 1;
    }

    bool isNULL();
    bool LoadAttributeType(std::string attr_name, std::string attr_type);
    bool isPrimary(std::string);
=======
>>>>>>> refs/remotes/origin/main
    void addAttribute(std::string input);
    void LoadData(std::vector<std::string> input);
    void LoadData(std::vector<std::vector<std::string>> input);
    void addPrimaryKey(std::string input);
<<<<<<< HEAD
    void setNull(std::string input, bool tag);
    void setUnique(std::string input, bool tag);
    void setDefault(std::string input, std::string val);
    void addForeign(std::string attrname, std::string tablename, std::string otherattr);
    void setTableName(std::string input);
    void setTablePath(std::string input);

    bool setUpdateJoint(std::map<std::string, bool> updatejoint);
    bool setDeleteJoint(std::map<std::string, bool> Deletejoint);

    void addReferencedBy(std::string attrname, std::pair<std::string, std::string> fkinf);
    std::vector<std::pair<std::string, std::string>> getReferencedBy(std::string attrname);
    bool jointDelete(std::string attrname, std::string val);
    bool jointUpdate(std::string attrname, std::string oldval, std::string newval);

    std::set<std::string> getAttrvals(std::string attrname);

    std::string getTableName();
    std::string getTablePath();

=======
    void setNull(std::string input,bool tag);
    void setUnique(std::string input,bool tag);
    void setDefault(std::string input,std::string val);
    void addForeign(std::string attrname, std::string tablename, std::string otherattr);
    void setTableName(std::string input);
    void setTablePath(std::string input);
    std::string getTableName();
    std::string getTablePath();
    
>>>>>>> refs/remotes/origin/main
    std::vector<std::string> getAttributes();
    std::set<std::string> getPrimaryKeys();
    std::map<std::string, std::string> getAttributeType();
    std::map<std::string, std::string> getAttributeDefault();
<<<<<<< HEAD
    std::map<std::string, std::pair<std::string, std::string>> getForeignKeys();
    std::pair<std::string,std::pair<std::string,std::string>> getForeignKeys(std::string Fkname)
    {
        if(this->foreign_name.find(Fkname)==this->foreign_name.end())
        {
            std::cout<<"Foreign key not exist:"<<Fkname<<std::endl;
            return std::make_pair("NULL",std::make_pair("NULL","NULL"));
        }
        auto attr=this->foreign_name[Fkname];
        auto table=this->attribute_foreign[attr];
        return std::make_pair(attr,table);
    }
    std::map<std::string, bool> getAttributeNull();
    std::map<std::string, bool> getAttributeUnique();
    int getAttributeindex(std::string attr);
    std::vector<std::vector<std::string>> getData();

    bool setConstraintName(std::string constraint_name, std::string attr_name);

    std::vector<std::string> getConstraintName();
    std::string getConstraintName(std::string attr_name);

    // bool checkPermission(User user,std::string permission);
=======
    std::map<std::string,std::pair<std::string,std::string > > getForeignKeys();
    std::map<std::string,bool>getAttributeNull();
    std::map<std::string,bool> getAttributeUnique();
    int getAttributeindex(std::string attr);
    std::vector<std::vector<std::string> > getData();

    // bool checkPermission(User user,std::string permission);
    


>>>>>>> refs/remotes/origin/main

    // Table findDataByCondition(
    //     std::vector<std::string> argv_atr = std::vector<std::string>(),
    //     std::vector<std::string> argv_val = std::vector<std::string>());

    // std::vector<std::vector<std::string>> findAttributeEqual(std::string attr, std::string val);
    // std::vector<std::vector<std::string>> findAttributeLarger(std::string attr, std::string val);
    // std::vector<std::vector<std::string>> findAttributeSmaller(std::string attr, std::string val);
    // std::vector<std::vector<std::string>> findAttributeNoEqual(std::string attr, std::string val);
    // std::vector<std::vector<std::string>> selectDataByAttribute(std::set<std::string>attrs);

<<<<<<< HEAD
=======
    


>>>>>>> refs/remotes/origin/main
    // std::string DeleteDataByAttribute(
    //     std::vector<std::string> argv_atr = std::vector<std::string>(),
    //     std::vector<std::string> argv_val = std::vector<std::string>());

<<<<<<< HEAD
    // void DeleteallData();
=======
    void DeleteallData();
>>>>>>> refs/remotes/origin/main

    void DeleteDataEq(
        std::string attr,
        std::string val);

    void DeleteDataLarger(
        std::string attr,
        std::string val);

    void DeleteDataSmaller(
        std::string attr,
        std::string val);
<<<<<<< HEAD

    void DeleteDataNoEqual(
        std::string attr,
        std::string val);

    bool InsertData(
=======
    
    void DeleteDataNoEqual(
        std::string attr,
        std::string val);
    

    std::string InsertData(
>>>>>>> refs/remotes/origin/main
        std::vector<std::string> argv_atr,
        std::vector<std::string> argv_val);

    // std::string UpdateData(
    //     std::vector<std::string> argv_atr,
    //     std::vector<std::string> argv_toval);

    std::string integrityCheck();

    bool AlterTableAddColumn(
<<<<<<< HEAD
        std::vector<std::pair<std::string, std::string>> settings,
        std::pair<std::string, std::string> foreign,
        bool updatejoint,
        bool deletejoint);
=======
        std::string column_name,
        std::string column_type,
        bool column_null,
        bool column_unique,
        std::string column_default = std::string());
>>>>>>> refs/remotes/origin/main

    bool AlterTableDropColumn(std::string column_name);

    bool AlterTableAddPrimaryKey(std::vector<std::string> column_name);

<<<<<<< HEAD
    bool AlterTableDropPrimaryKey();

    bool AlterTableAddForeignKey(
        std::string attrname,
        std::string tablename,
        std::string otherattr,
        std::string constraint_name);
=======
    bool AlterTableDropPrimaryKey(std::vector<std::string> column_name);

    bool AlterTableAddForeignKey(std::string attrname, std::string tablename, std::string otherattr);
>>>>>>> refs/remotes/origin/main

    bool AlterTableDropForeignKey(std::string attr);

    bool AlterTableModifyColumnName(
        std::string old_column_name,
        std::string new_column_name);

    bool AlterTableModifyColumnDefault(
        std::string column_name,
        std::string column_default);

    bool AlterTableModifyColumnNull(
        std::string column_name,
<<<<<<< HEAD
        bool column_null); // column_null=0 ref not null,1 ref null
=======
        bool column_null);//column_null=0 ref not null,1 ref null
>>>>>>> refs/remotes/origin/main

    bool AlterTableModifyColumnUnique(
        std::string column_name,
        bool column_unique);
<<<<<<< HEAD
    // column_unique=1 ref unique,0 ref not unique
=======
        //column_unique=1 ref unique,0 ref not unique
>>>>>>> refs/remotes/origin/main

    bool AlterTableModifyColumnType(
        std::string column_name,
        std::string column_type);
};

#endif