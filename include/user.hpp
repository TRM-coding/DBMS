#ifndef USER_HPP
#define USER_HPP
#include<string>
#include<map>
#include<vector>

class User
{
    private:
    std::string Username;
    std::string Password;
    std::map<std::string,std::map<std::string,bool> >Permission;
    // std::vector<std::string> permissionlist;
    public:
    User();
    User(std::string Username,std::string Password);
    ~User();
    std::string getUsername();
    std::string getPassword();
    void fixpermissions(std::map<std::string,std::map<std::string,bool> > permissions);
    void setPermission(std::string table_name,std::map<std::string,bool> permisionts);
    bool getPermission(std::string table_name,std::string permission);

};
#endif