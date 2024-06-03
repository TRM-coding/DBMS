#include<usermanage.hpp>

<<<<<<< HEAD
bool UserManager::LoginByUsers(std::string username,std::string password,User& user,Ans& answer)
{
    Table pwdtable=TableStream::LoadTable("userlogin_table",1);
=======
bool UserManager::LoginByUsers(std::string username,std::string password,User& user)
{
    Table pwdtable=TableStream::LoadTable("userlogin_table");
>>>>>>> refs/remotes/origin/main
    for(auto x:pwdtable.getData())
    {
        if(x[0]==username)
        {
            if(x[1]==password)
            {
                user=UserManager::fix(username, password);
<<<<<<< HEAD
                answer.Loadstate("Login success!");
=======
>>>>>>> refs/remotes/origin/main
                return true;
            }
            else
            {
<<<<<<< HEAD
                answer.Loadstate("Login failed!");
=======
>>>>>>> refs/remotes/origin/main
                return false;
            }
        }
    }
<<<<<<< HEAD
    answer.Loadstate("Login failed!");
    return false;
}

UserManager::UserManager()
{
}

UserManager::~UserManager()=default;

User UserManager::fix(std::string username, std::string pwd)
{
    Table user_authority_table=TableStream::LoadTable("user_authority_table",1);
=======
    return false;
}

User UserManager:: fix(std::string username,std::string pwd)
{
    Table user_authority_table=TableStream::LoadTable("user_authority_table");
>>>>>>> refs/remotes/origin/main
    User ans=User(username,pwd);
    std::vector<std::string> permissionslist;
    for(int i=2;i<user_authority_table.getAttributes().size();i++)
    {
        permissionslist.push_back(user_authority_table.getAttributes()[i]);
    }
    // ans.fixpermissions(permissionslist);
    int flag=0;
    std::map<std::string,std::map<std::string,bool> > prs;
<<<<<<< HEAD
    for(int i=0;i<user_authority_table.getData().size();i++)
=======
    for(int i=1;i<user_authority_table.getData().size();i++)
>>>>>>> refs/remotes/origin/main
    {
        std::vector<std::string>datai=user_authority_table.getData()[i];
        std::string tablename=datai[1];
        if(datai[0]!=username)
        {
            continue;
        }
        for(int j=2;j<datai.size();j++)
        {
            std::string pr=datai[j];
            if(pr=="1")
            {
                prs[tablename][user_authority_table.getAttributes()[j]]=true;
            }
            else
            {
                prs[tablename][user_authority_table.getAttributes()[j]]=false;
            }
        }
    }
    ans.fixpermissions(prs);
    return ans;
}

<<<<<<< HEAD
std::string UserManager::CreateUser(std::string username,std::string password,Ans& answer)
{
    Table pwdtable=TableStream::LoadTable("userlogin_table",1);
=======
std::string UserManager::CreateUser(std::string username,std::string password)
{
    Table pwdtable=TableStream::LoadTable("userlogin_table");
>>>>>>> refs/remotes/origin/main
    for(auto x:pwdtable.getData())
    {
        if(x[0]==username)
        {
<<<<<<< HEAD
            answer.Loadstate("User already exists");
=======
>>>>>>> refs/remotes/origin/main
            std::cout<<"User already exists"<<std::endl;
            return "User already exists";
        }
    }
    std::vector<std::string> newdt;
    newdt.push_back(username);
    newdt.push_back(password);
    pwdtable.LoadData(newdt);
<<<<<<< HEAD
    TableStream::SaveTable(pwdtable,1);
    auto tablenames=TableStream::ShowTable();
    auto authori= TableStream::LoadTable("user_authority_table",1);
    
    for(auto p:tablenames)
    {
        std::vector<std::string>newaudt;
        newaudt.push_back(username+" "+p+" 1 0 0 0 0 0");
        authori.LoadData(newaudt);
    }
    TableStream::SaveTable(authori,1);

    std::cout<<"User created successfully"<<std::endl;
    answer.Loadstate("User created successfully");
    return "User created successfully";
}

std::string UserManager::DropUser(std::string username,Ans& answer)
{
    Table pwdtable=TableStream::LoadTable("userlogin_table",1);
    pwdtable.DeleteDataEq("username",username);
    // std::cout<<"User does not exist"<<std::endl;
    TableStream::SaveTable(pwdtable,1);
    answer.Loadstate("User deleted successfully");
    return "true";
=======
    TableStream::SaveTable(pwdtable);
    std::cout<<"User created successfully"<<std::endl;
    return "User created successfully";
}

std::string UserManager::DropUser(std::string username)
{
    Table pwdtable=TableStream::LoadTable("userlogin_table");
    pwdtable.DeleteDataEq("username",username);
    std::cout<<"User does not exist"<<std::endl;
    return "User does not exist";
>>>>>>> refs/remotes/origin/main
}

std::string UserManager::GrantUser(
    std::vector<std::string> username,
    std::vector<std::string> table_name,
<<<<<<< HEAD
    std::vector<std::pair<std::string,bool>> permission,
    Ans& answer)
{
    Table user_authority_table=TableStream::LoadTable("user_authority_table",1);
    std::vector<std::vector<std::string>> newdt;
    bool flag=0;
=======
    std::vector<std::pair<std::string,bool>> permission)
{
    Table user_authority_table=TableStream::LoadTable("user_authority_table");
    std::vector<std::vector<std::string>> newdt;
>>>>>>> refs/remotes/origin/main
    for(auto x:user_authority_table.getData())
    {
        
        if(std::find(username.begin(),username.end(),x[0])!=username.end() && std::find(table_name.begin(),table_name.end(),x[1])!=table_name.end())
        {
<<<<<<< HEAD
            flag=1;
            for(auto p:permission)
            {
                
                if(p.second==true)
                    x[user_authority_table.getAttributeindex(p.first)]="1";
            }
        }
        newdt.push_back(x);
    }

    
    user_authority_table.LoadData(newdt);
    TableStream::SaveTable(user_authority_table,1);
    std::cout<<"Permissions granted successfully"<<std::endl;
    answer.Loadstate("Permissions granted successfully");
    return "Permissions granted successfully";
}

std::string UserManager::NewGrantUser(
    std::vector<std::string> username,
    std::vector<std::string> table_name,
    std::vector<std::pair<std::string,bool>> permission,
    Ans& answer)
{
    Table user_authority_table=TableStream::LoadTable("user_authority_table",1);
    // std::vector<std::vector<std::string>> newdt;
    for(auto x:username)
    {
        for(auto y:table_name)
        {
            std::vector<std::string> newrow;
            newrow.push_back(x);
            newrow.push_back(y);
            for(auto p:permission)
            {
                if(p.second==true)
                    newrow.push_back("1");
                else
                    newrow.push_back("0");
            }
            user_authority_table.LoadData(newrow);
        }
    }
    TableStream::SaveTable(user_authority_table,1);
    std::cout<<"Permissions granted successfully"<<std::endl;
    answer.Loadstate("Permissions granted successfully");
    return "Permissions granted successfully";
}

std::string UserManager::RevokeUser(
    std::vector<std::string> username,
    std::vector<std::string> table_name,
    std::vector<std::pair<std::string,bool>> permission,
    Ans& answer)
{
    Table user_authority_table=TableStream::LoadTable("user_authority_table",1);
    std::vector<std::vector<std::string>> newdt;
    for(auto x:user_authority_table.getData())
    {
        if(std::find(username.begin(),username.end(),x[0])!=username.end() && std::find(table_name.begin(),table_name.end(),x[1])!=table_name.end())
        {
            for(auto p:permission)
            {
                if(p.second==false)
=======
            for(auto p:permission)
            {
                if(p.second==true)
                    x[user_authority_table.getAttributeindex(p.first)]="1";
                else
>>>>>>> refs/remotes/origin/main
                    x[user_authority_table.getAttributeindex(p.first)]="0";
            }
        }
        newdt.push_back(x);
    }
    user_authority_table.LoadData(newdt);
<<<<<<< HEAD
    TableStream::SaveTable(user_authority_table,1);
    answer.Loadstate("Permissions revoked successfully");
=======
    TableStream::SaveTable(user_authority_table);
    std::cout<<"Permissions granted successfully"<<std::endl;
    return "Permissions granted successfully";
}

std::string UserManager::RevokeUser(
    std::vector<std::string> username,
    std::vector<std::string> table_name,
    std::vector<std::pair<std::string,bool>> permission)
{
    Table user_authority_table=TableStream::LoadTable("user_authority_table");
    std::vector<std::vector<std::string>> newdt;
    for(auto x:user_authority_table.getData())
    {
        if(std::find(username.begin(),username.end(),x[0])!=username.end() && std::find(table_name.begin(),table_name.end(),x[1])!=table_name.end())
        {
            for(auto p:permission)
            {
                if(p.second==true)
                    x[user_authority_table.getAttributeindex(p.first)]="0";
                else
                    x[user_authority_table.getAttributeindex(p.first)]="1";
            }
        }
        newdt.push_back(x);
    }
    user_authority_table.LoadData(newdt);
    TableStream::SaveTable(user_authority_table);
>>>>>>> refs/remotes/origin/main
    std::cout<<"Permissions revoked successfully"<<std::endl;
    return "Permissions revoked successfully";
}