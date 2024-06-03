#ifndef tablemanager_HPP
#define tablemanager_HPP

#ifndef DBMSROOTDIR
#define DBMSROOTDIR std::string()
#endif

#include <string>
#include <table.hpp>
#include <operator.hpp>
#include <user.hpp>
<<<<<<< HEAD
#include <usermanage.hpp>
#include <ans.hpp>
=======
>>>>>>> refs/remotes/origin/main

class TableManager
{
private:
    User user;

public:
    TableManager();
    TableManager(User user);

    std::string CreateTable(
        std::string table_name,
        std::vector<std::vector<std::pair<std::string, std::string>>> settings,
<<<<<<< HEAD
        std::vector<std::pair<std::string, std::string>> foreign,
        std::map<std::string, bool> updatejoint,
        std::map<std::string, bool> Deletejoint,
        Ans&ans);

    std::string DropTable(std::string table_name,Ans&ans);
=======
        std::vector<std::pair<std::string, std::string>> foreign);

    std::string DropTable(std::string table_name);
>>>>>>> refs/remotes/origin/main

    std::vector<std::vector<std::string>> cartesian_product(
        std::vector<std::vector<std::string>> table1,
        std::vector<std::vector<std::string>> table2);

    std::vector<std::vector<std::string>> Select(
        std::vector<std::string> tablename,
        std::vector<std::string> attrname,
        std::vector<expr> condition,
<<<<<<< HEAD
        std::vector<std::pair<std::string, bool>> order,
        Ans&ans);

    bool Delete(
        std::string tablename,
        std::vector<expr> condition,
        Ans&ans);

    static void Sort(
        std::vector<std::pair<std::string, bool>> order,
        std::vector<std::vector<std::string>> &table);

    bool AlterTableAddColumn(
        std::string tablename,
        std::vector<std::pair<std::string, std::string>> settings,
        std::pair<std::string, std::string> foreign,
        Ans&ans,
        bool updatejoint,
        bool deletejoint);

    bool AlterTableDropColumn(std::string tablename, std::string column_name,Ans&ans);

    bool AlterTableAddPrimaryKey(std::string tablename, std::vector<std::string> column_name,Ans&ans);

    bool AlterTableDropPrimaryKey(std::string tablename,Ans&ans);

    bool AlterTableAddForeignKey(std::string tablename, std::string attrname, std::string reftablename, std::string otherattr, std::string constraint_name,bool updatejoint,bool deletejoint, Ans&ans);

    bool AlterTableDropForeignKey(std::string tablename, std::string attr,Ans&ans);
=======
        std::vector<std::pair<std::string,bool> > order);

    
    bool Delete(
        std::string tablename,
        std::vector<expr> condition);
    
    static void Sort(
        std::vector<std::pair<std::string,bool> > order,
        std::vector<std::vector<std::string>> &table);


    bool AlterTableDropColumn(std::string tablename,std::string column_name);

    bool AlterTableAddPrimaryKey(std::string tablename,std::vector<std::string> column_name);

    bool AlterTableDropPrimaryKey(std::string tablename,std::vector<std::string> column_name);

    bool AlterTableAddForeignKey(std::string tablename,std::string attrname, std::string reftablename, std::string otherattr);

    bool AlterTableDropForeignKey(std::string tablename,std::string attr);
>>>>>>> refs/remotes/origin/main

    bool AlterTableModifyColumnName(
        std::string tablename,
        std::string old_column_name,
<<<<<<< HEAD
        std::string new_column_name,
        Ans&ans);
=======
        std::string new_column_name);
>>>>>>> refs/remotes/origin/main

    bool AlterTableModifyColumnDefault(
        std::string tablename,
        std::string column_name,
<<<<<<< HEAD
        std::string column_default,
        Ans&ans);
=======
        std::string column_default);
>>>>>>> refs/remotes/origin/main

    bool AlterTableModifyColumnNull(
        std::string tablename,
        std::string column_name,
<<<<<<< HEAD
        bool column_null,
        Ans&ans); // column_null=0 ref not null,1 ref null
=======
        bool column_null);//column_null=0 ref not null,1 ref null
>>>>>>> refs/remotes/origin/main

    bool AlterTableModifyColumnUnique(
        std::string tablename,
        std::string column_name,
<<<<<<< HEAD
        bool column_unique,
        Ans&ans);
    // column_unique=1 ref unique,0 ref not unique
=======
        bool column_unique);
        //column_unique=1 ref unique,0 ref not unique
>>>>>>> refs/remotes/origin/main

    bool AlterTableModifyColumnType(
        std::string tablename,
        std::string column_name,
<<<<<<< HEAD
        std::string column_type,
        Ans&ans);

    bool Insert(
        std::string tablename,
        std::vector<std::string> argv_atr,
        std::vector<std::string> argv_val,
        Ans&ans);

    bool Update(
        std::string tablename,
        std::vector<std::string> attrname,
        std::vector<std::string> attrval,
        std::vector<expr> condition,
        Ans&ans);

    std::vector<std::string> getConstraintName(std::string tablename,Ans&ans);
=======
        std::string column_type);
    
    bool Insert(
        std::string tablename,
        std::vector<std::string> argv_atr,
        std::vector<std::string> argv_val);

    bool Update(
    std::string tablename,
    std::vector<std::string> attrname,
    std::vector<std::string> attrval,
    std::vector<expr> condition);

>>>>>>> refs/remotes/origin/main
};

#endif
