#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <experimental/filesystem>

#ifndef RECORD_HPP
#define RECORD_HPP

namespace fs = std::experimental::filesystem;

class record 
{
    std::string processName;
    int pid;
    fs::directory_entry fileObj; // holds the object file

    public:
        record(fs::directory_entry entry);

        std::string getProcessName ();

        void print () const;

        std::string getLoggingLine ();

};

class recordList 
{
    std::unique_ptr <std::unordered_map<std::string,record>> m_list;

    public:
        recordList();
    
        void add_record (record r);

        void print ();

        void setMapSize(int sz);

        std::unordered_map<std::string,record>* getListPtr () const;
};

#endif