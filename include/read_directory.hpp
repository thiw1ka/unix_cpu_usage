#include <iostream>
#include <string>
#include <experimental/filesystem>
#include <memory>

#include "record.hpp"

#ifndef READ_DIRECTORY_HPP
#define READ_DIRECTORY_HPP

namespace fs = std::experimental::filesystem;

class Readdirectory
{

    public:
        Readdirectory(std::string dirPath);

        void printFileListInsideDir();

        void updateRecordList (recordList* pRecordList);

    private:
        std::string m_sPath = "";

        // std::unordered_map<std::string,fs::directory_entry> m_list;
};

#endif