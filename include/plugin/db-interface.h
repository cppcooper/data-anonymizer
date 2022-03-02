#pragma once
#include <pqxx/pqxx>

// todo: name better?
class DBInterface { // not an 'interface'
private:
    pqxx::connection con;
    DBInterface() = default;
    void disconnect();
public:
    ~DBInterface() {
        disconnect();
    }
    static DBInterface& GetInstance(){
        static DBInterface instance;
        return instance;
    }
    void Connect(std::string database, std::string host, std::string port, std::string username, std::string password);
    bool IsOpen();
    
    //static void UpdateChecksum(std::string uuid, int64_t size, char *hash);
    void CreateTables();
    void UpdateChecksum(std::string uuid, int64_t size, const char *hash);
};