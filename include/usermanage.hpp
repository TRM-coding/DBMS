#ifndef usermanage_HPP
#define usermanage_HPP

<<<<<<< HEAD
#include <string>
#include <map>
#include <vector>
#include <user.hpp>
#include <TableStream.hpp>
#include <table.hpp>
#include<ans.hpp>

class UserManager
{
public:
public:
    UserManager();
    ~UserManager();

    static User fix(std::string username, std::string pwd);

    static bool LoginByUsers(std::string username, std::string password, User &user,Ans& answer);

    static std::string CreateUser(std::string username, std::string password,Ans& answer);

    static std::string DropUser(std::string username,Ans& answer);

    static std::string GrantUser(
        std::vector<std::string> username,
        std::vector<std::string> table_name,
        std::vector<std::pair<std::string, bool>> permission,
        Ans& answer);

    static std::string RevokeUser(
        std::vector<std::string> username,
        std::vector<std::string> table_name,
        std::vector<std::pair<std::string, bool>> permission,
        Ans& answer);

    static std::string NewGrantUser(
        std::vector<std::string> username,
        std::vector<std::string> table_name,
        std::vector<std::pair<std::string, bool>> permission,
        Ans& answer);
=======
#include<string>
#include<map>
#include<vector>
#include<user.hpp>
#include<TableStream.hpp>
#include<table.hpp>

class UserManager{
    public:
    

    public:
        UserManager();
        ~UserManager();

        static User fix(std::string username,std::string pwd);

        static bool LoginByUsers(std::string username,std::string password,User& user);

        static std::string CreateUser(std::string username,std::string password);

        static std::string DropUser(std::string username);

        static std::string GrantUser(
            std::vector<std::string> username,
            std::vector<std::string> table_name,
            std::vector<std::pair<std::string,bool>> permission=std::vector<std::pair<std::string,bool>>());
            
        static std::string RevokeUser(
            std::vector<std::string> username,
            std::vector<std::string> table_name,
            std::vector<std::pair<std::string,bool>> permission=std::vector<std::pair<std::string,bool>>());
>>>>>>> refs/remotes/origin/main
};

#endif