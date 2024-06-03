#include<user.hpp>

<<<<<<< HEAD
User::User()
{
}

=======
>>>>>>> refs/remotes/origin/main
User::User(std::string Username, std::string Password)
{
    this->Username = Username;
    this->Password = Password;
}

<<<<<<< HEAD
User::~User()=default;

=======
>>>>>>> refs/remotes/origin/main
std::string User::getUsername()
{
    return this->Username;
}

std::string User::getPassword()
{
    return this->Password;
}

<<<<<<< HEAD
void User::fixpermissions(std::map<std::string,std::map<std::string,bool> > permissions)
{
    this->Permission=permissions;
}
=======
// void User::fixpermissions(std::vector<std::string> permissions)
// {
//     this->permissionlist=permissions;
// }
>>>>>>> refs/remotes/origin/main

void User::setPermission(std::string table_name,std::map<std::string,bool> permissions)
{
    for(auto i:permissions)
    {
        this->Permission[table_name][i.first]=i.second;
    }
}

bool User::getPermission(std::string table_name,std::string permission)
{
    return this->Permission[table_name][permission];
}