#include <TableStream.hpp>
#include<cstdio>

std::string TableStream::ROOT_DIR=std::string(DBMSROOTDIR);

TableStream::TableStream(){}
TableStream::~TableStream(){}

void TableStream::ergodicDir(std::string dir_path, std::string tableName, std::vector<std::string> &table_list,int oper)
{
<<<<<<< HEAD
=======
    std::cout<<dir_path<<std::endl;
>>>>>>> refs/remotes/origin/main
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


std::vector<std::string> TableStream::GetTableDir(std::string table_name,int oper)
{
    std::vector<std::string> table_list;
<<<<<<< HEAD
    std::string table_dir = ROOT_DIR+ "/SystemTables/";
    std::string table_name_exp=table_name;
    ergodicDir(table_dir, table_name_exp,table_list,oper);
    return table_list;
}

std::vector<std::string> TableStream::ShowTable()
{
    std::vector<std::string> table_list;
    std::string table_dir = ROOT_DIR+ "/SystemTables/data_tables/";
    std::vector<std::string> files;
    for (const auto & entry : std::filesystem::directory_iterator(table_dir)) {
        files.push_back(entry.path().stem().string());
    }
    return files;
}

Table TableStream::LoadTable(std::string table_name, int oper)
{
    // table_name+= ".tb";
    std::string table_path;
    std::vector<std::string> table_list;
    if(!oper)table_list = TableStream::GetTableDir(table_name+".tb");
    else table_list = TableStream::GetTableDir(table_name+".dtb");
=======
    std::string table_dir = ROOT_DIR+ "/SystemTables";
    std::cout<<table_dir<<std::endl;
    ergodicDir(table_dir, table_name,table_list,oper);
    return table_list;
}

Table TableStream::LoadTable(std::string table_name)
{
    std::string table_path;
    std::vector<std::string> table_list = TableStream::GetTableDir(table_name);
>>>>>>> refs/remotes/origin/main
    if(table_list.size()==0)
    {
        std::cout<<"Table not found!"<<std::endl;
        return Table();
    }
    else{
        table_path = table_list[0];
    }

    std:: fstream table_reader(table_path);
    Table tableObj;
    tableObj.setTableName(table_name);
    tableObj.setTablePath(table_path);
    //read attributes
    std::string tmp;
    std::string token;
    getline(table_reader,tmp);
    std::istringstream iss(tmp);
    while(iss>>token)tableObj.addAttribute(token);
<<<<<<< HEAD
    // tableObj.LoadData(tableObj.getAttributes());
=======
    tableObj.LoadData(tableObj.getAttributes());
>>>>>>> refs/remotes/origin/main
    iss.clear();
    
    //read datas
    while(getline(table_reader,tmp))
    {
        if(tmp=="...")break;
        std::vector<std::string> data;
        iss.str(tmp);
        while(iss>>token)data.push_back(token);
        tableObj.LoadData(data);
        iss.clear();
    }
    //read attribute format
    while(getline(table_reader,tmp))
    {
        if(tmp=="...")break;
        std::string attr_name;
        std::string attr_type;
        std::string NOTNULL;
        std::string UNIQUE;
        std::string DEFAULT;
<<<<<<< HEAD
        std::string pimary_key;
        iss.str(tmp);
        iss>>attr_name>>attr_type>>NOTNULL>>UNIQUE>>DEFAULT>>pimary_key;
        if(pimary_key=="1")tableObj.addPrimaryKey(attr_name);

        if(NOTNULL=="1")tableObj.setNull(attr_name,true);
        else tableObj.setNull(attr_name,false);

        if(UNIQUE=="1")tableObj.setUnique(attr_name,true);
        else tableObj.setUnique(attr_name,false);

        tableObj.setDefault(attr_name,DEFAULT);

        tableObj.LoadAttributeType(attr_name,attr_type);
        
=======
        iss.str(tmp);
        iss>>attr_name>>attr_type>>NOTNULL>>UNIQUE>>DEFAULT;
>>>>>>> refs/remotes/origin/main
        iss.clear();
    }
    //read foreign key
    while(getline(table_reader,tmp))
    {
        if(tmp=="...")break;
        std::string attr_name;
        std::string table_name;
        std::string otherattr;
<<<<<<< HEAD
        std::string constraint_name;
        iss.str(tmp);
        iss>>attr_name>>table_name>>otherattr>>constraint_name;
        tableObj.addForeign(attr_name,table_name,otherattr);
        tableObj.setConstraintName(constraint_name,attr_name);
        iss.clear();
    }

    //read referenced by
    while(getline(table_reader,tmp))
    {
        if(tmp=="...")break;
        std::string attr_name;
        std::string table_name;
        std::string otherattr;
        // std::string constraint_name;
        iss.str(tmp);
        iss>>attr_name;
        while(iss>>table_name>>otherattr)
            tableObj.addReferencedBy(attr_name,std::make_pair(table_name,otherattr));
        iss.clear();
    }

    //read updatejoint
    while(getline(table_reader,tmp))
    {
        if(tmp=="...")break;
        std::string attr_name;
        std::string tag;
        iss.str(tmp);
        iss>>attr_name>>tag;
        if(tag=="1")tableObj.addupdatejoint(attr_name,true);
        else tableObj.addupdatejoint(attr_name,false);
        iss.clear();
    }

    //read deletejoint
    while(getline(table_reader,tmp))
    {
        if(tmp=="...")break;
        std::string attr_name;
        std::string tag;
        iss.str(tmp);
        iss>>attr_name>>tag;
        if(tag=="1")tableObj.addDeletejoint(attr_name,true);
        else tableObj.addDeletejoint(attr_name,false);
        iss.clear();
    }
=======
        iss.str(tmp);
        iss>>attr_name>>table_name;
        while(iss>>token)otherattr=token;
        tableObj.addForeign(attr_name,table_name,otherattr);
        iss.clear();
    }

>>>>>>> refs/remotes/origin/main
    table_reader.close();
    return tableObj;
}

<<<<<<< HEAD
void TableStream::SaveTable(Table tableObj,int oper)
{
    std::string table_path;
    if(!oper)table_path=ROOT_DIR+"/SystemTables/data_tables/"+tableObj.getTableName()+".tb";
    else table_path=ROOT_DIR+"/SystemTables/data_dictionary/"+tableObj.getTableName()+".dtb";
    // std::vector<std::string> table_list = TableStream::GetTableDir(tableObj.getTableName());
    // if(table_list.size()==0)
    // {
    //     std::cout<<"The table has not been created yet!"<<std::endl;
    //     // return;
    // }
    // else{
    //     table_path = table_list[0];
    // }
    std:: fstream table_writer(table_path,std::ios::out);
=======
void TableStream::SaveTable(Table tableObj)
{
    std::string table_path;
    std::vector<std::string> table_list = TableStream::GetTableDir(tableObj.getTableName());
    if(table_list.size()==0)
    {
        std::cout<<"The table has not been created yet!"<<std::endl;
        return;
    }
    else{
        table_path = table_list[0];
    }
    std:: fstream table_writer(table_path);
>>>>>>> refs/remotes/origin/main
    //write attributes
    for(auto attr: tableObj.getAttributes())
    {
        table_writer<<attr<<" ";
    }
    table_writer<<std::endl;
    //write datas
<<<<<<< HEAD
    // std::vector<std::vector<std::string >>datas = tableObj.getData();
    for(int i=0;i<tableObj.getData().size();i++)
    {
        std::vector<std::string> datai=tableObj.getData()[i];
        for(auto d: datai)
=======
    for(int i=1;i<tableObj.getData().size();i++)
    {
        for(auto d: tableObj.getData()[i])
>>>>>>> refs/remotes/origin/main
        {
            table_writer<<d<<" ";
        }
        table_writer<<std::endl;
    }
    table_writer<<"..."<<std::endl;
    //write attribute format
<<<<<<< HEAD
    if(oper)return;
=======
>>>>>>> refs/remotes/origin/main
    for(auto attr: tableObj.getAttributes())
    {
        table_writer<<attr<<" "
                    <<tableObj.getAttributeType()[attr]<<" "
                    <<tableObj.getAttributeNull()[attr]<<" "
                    <<tableObj.getAttributeUnique()[attr]<<" "
                    <<tableObj.getAttributeDefault()[attr]<<" "
<<<<<<< HEAD
                    <<tableObj.isPrimary(attr)
=======
>>>>>>> refs/remotes/origin/main
                    <<std::endl;
    }
    table_writer<<"..."<<std::endl;
    //write foreign key
    for(auto foreign: tableObj.getForeignKeys())
    {
<<<<<<< HEAD
        table_writer<<foreign.first<<" "
                    <<foreign.second.first<<" "
                    <<foreign.second.second<<" "
                    <<tableObj.getConstraintName(foreign.first)
                    <<std::endl;
    }
    table_writer<<"..."<<std::endl;
    //write referenced by
    auto refby = tableObj.getReferencedBy();
    for(auto ref: refby)
    {
        table_writer<<ref.first<<" ";
        for(auto refi: ref.second)
        {
            table_writer<<refi.first<<" "<<refi.second<<" ";
=======
        table_writer<<foreign.second.first<<" ";
        for(auto attr: foreign.second.second)
        {
            table_writer<<attr<<" ";
>>>>>>> refs/remotes/origin/main
        }
        table_writer<<std::endl;
    }
    table_writer<<"..."<<std::endl;

<<<<<<< HEAD
    //write updatejoint
    auto uj = tableObj.getupdatejoint();
    for(auto uji: uj)
    {
        table_writer<<uji.first<<" "<<uji.second<<std::endl;
    }
    table_writer<<"..."<<std::endl;

    //write deletejoint
    auto dj = tableObj.getDeletejoint();
    for(auto dji: dj)
    {
        table_writer<<dji.first<<" "<<dji.second<<std::endl;
    }
    table_writer<<"..."<<std::endl;

    table_writer.close();
    std::cout<<"Table saved successfully!"<<std::endl;
    return;
=======

>>>>>>> refs/remotes/origin/main
}

void TableStream::RemoveTable(std::string tablename)
{
    std::string table_path;
    std::vector<std::string> table_list = TableStream::GetTableDir(tablename);
    if(table_list.size()==0)
    {
        std::cout<<"Table not found!"<<std::endl;
        return ;
    }
    else{
        table_path = table_list[0];
    }
    //remove the table by this path
    char *p=(char*)table_path.c_str();
    int result = remove(p);
    if(result!=0){
        std::cout<<"Delete failed"<<std::endl;
    }
    else{
        std::cout<<"successfully deleted"<<std::endl;
    }
    return ;
}
