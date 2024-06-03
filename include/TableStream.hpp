
#ifndef TABLESTREAM_HPP
#define TABLESTREAM_HPP

#ifndef DBMSROOTDIR
#define DBMSROOTDIR ""
#endif

#include <string>
#include <table.hpp>
#include <vector>
#include <filesystem>
#include<iostream>
#include <fstream>
#include <sstream>

class TableStream
{

private:
    static void ergodicDir(std::string dir_path,std::string tableName, std::vector<std::string> &table_list,int oper = 0);
    
public:
    TableStream();
    ~TableStream();
    static std::string ROOT_DIR;
    static std::vector<std::string> GetTableDir(std::string table_name = "*",int oper = 0);
<<<<<<< HEAD
    static Table LoadTable(std::string table_name, int oper = 0);
    static void SaveTable(Table tableObj,int oper = 0);
    static void RemoveTable(std::string tablename);
    static std::vector<std::string> ShowTable();
=======
    static Table LoadTable(std::string table_name);
    static void SaveTable(Table tableObj);
    static void RemoveTable(std::string tablename);
>>>>>>> refs/remotes/origin/main
};

#endif
