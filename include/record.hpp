#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <algorithm>

namespace fs = std::experimental::filesystem;

class record 
{
    std::string processName;
    int pid;
    fs::directory_entry fileObj; // holds the object file

    public:
        record(fs::directory_entry entry) :
            fileObj(entry),
            processName(entry.path().filename().generic_string())
            {};

        std::string getProcessName ()
        {
            return processName;
        }

        void print () const
        {
            std::printf("\n[record] Name:%s, Path:%s", processName.c_str(), fileObj.path().c_str());
        }

        std::string getLoggingLine ()
        {
            std::string temp = processName + ", ";
            return std::move(temp);
        }

};

class recordList 
{
    std::unique_ptr <std::unordered_map<std::string,record>> m_list;

    public:
        recordList()
        {
            m_list = std::make_unique <std::unordered_map<std::string,record>> ();
        }
    
        void add_record (record r) 
        {
            m_list->emplace(r.getProcessName(), r);
        }

        void print ()
        {
            for_each (m_list.get()->begin(), m_list.get()->end(), 
                                [&](auto i){i.second.print();});
            
        }

        void setMapSize(int sz)
        {
            m_list->reserve(sz);
        }

        std::unordered_map<std::string,record>* getListPtr () const
        {
            return m_list.get();
        }
};