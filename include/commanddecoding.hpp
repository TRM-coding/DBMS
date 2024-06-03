#ifndef commanddecoding_HPP
#define commanddecoding_HPP

#include<string>
#include<vector>
#include<set>
#include<tablemanager.hpp>
<<<<<<< HEAD
#include<ans.hpp>
// #include<result.hpp>

class CommandDecoding {
private:
    // Result res;

    std::vector<std::string> split(const std::string &str, char delimiter);

    void parseCreate(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager,Ans& ans);

    void parseSelect(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager,Ans& ans);

    void parseDelete(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager,Ans& ans);

    void parseGrant(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager,Ans& ans);

    void parseRevoke(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager,Ans& ans);

    void parseUpdate(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager,Ans& ans);

    void parseInsert(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager,Ans& ans);

    void parseAlter(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager,Ans& ans);

    std::set<std::string> command_set = {"create", "drop", "delete", "insert", "update", "select", "alter", "grant",
                                         "revoke"};
    std::set<std::string> udi_set = {"default", "not", "unique"};
public:
    CommandDecoding(const std::string &sqlstatement,User user,Ans& ans);
    // Result getResult();
=======

class CommandDecoding {
private:
    std::vector<std::string> split(const std::string &str, char delimiter);

    void parseCreate(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager);

    void parseSelect(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager);

    void parseDelete(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager);

    void parseGrant(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager);

    void parseRevoke(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager);

    void parseUpdate(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager);

    void parseInsert(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager);

    void parseAlter(std::vector<std::string>::iterator &token, const std::vector<std::string> &tokens,TableManager &Manager);

    std::set<std::string> command_set = {"create", "drop", "delete", "insert", "update", "select", "alter", "grant",
                                         "revoke"};
    std::set<std::string> type_set = {"int", "char", "date"};
    std::set<std::string> restrict_set = {"null", "primary", "key", "unique", "default", "foreign", "references",
                                          "on", "cascade", "delete", "update"};
public:
    CommandDecoding(const std::string &sqlstatement);
>>>>>>> refs/remotes/origin/main

    ~CommandDecoding();

};

#endif