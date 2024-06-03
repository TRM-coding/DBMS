#include<iostream>
#include<filesystem>
#include<string>
#include<vector>

#ifndef DBMSROOTDIR
#define DBMSROOTDIR ""
#endif

std::string ROOT_DIR=DBMSROOTDIR;

void ergodicDir(std::string dir_path, std::string tableName, std::vector<std::string> &table_list,int oper)
{
    for(const auto& iter: std::filesystem::directory_iterator(dir_path))
    {
        if(iter.is_directory())
        {
            ergodicDir(iter.path().string(),tableName,table_list,oper);
        }
        else
        {
            std::string file_path = iter.path().string();
            if(tableName == "*")
            {
                int pos = file_path.find(ROOT_DIR+"/SystemTables/");
                if(oper)file_path = file_path.substr(pos+ROOT_DIR.length()+14);
                table_list.push_back(file_path);
                continue;
            }
            if(file_path.find(tableName) != std::string::npos)
            {
                int pos = file_path.find(ROOT_DIR+"/SystemTables/");
                if(oper)file_path = file_path.substr(pos+ROOT_DIR.length()+14);
                table_list.push_back(file_path);
            }
        }
    }
    return;
}


std::vector<std::string> GetTableDir(std::string table_name = "*",int oper=0)
{
    std::vector<std::string> table_list;
    std::string table_dir = ROOT_DIR + "/SystemTables";
    ergodicDir(table_dir, table_name,table_list,oper);
    return table_list;
}

using namespace std;
int main(){
    std::vector<std::string> table_list = GetTableDir("*");
    for(auto table: table_list)
    {
        std::cout<<table<<std::endl;
    }
    std::cout<<ROOT_DIR<<std::endl;
    return 0;
}



// #include<iostream>



// using namespace std;
// int main(){
//     cout<<ROOT_DIR<<endl;
//     return 0;
// }