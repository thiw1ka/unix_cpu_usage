#include <iostream>
#include <experimental/filesystem>
#include <string>
#include <fstream>
#include <unordered_map>
#include <chrono>
#include <unistd.h>
#include <algorithm>
#include <iomanip>

#include <record.hpp>

#ifndef LOGGER_HPP
#define LOGGER_HPP

class logger
{
        std::string m_sPath = "", m_sName = "";
        std::ofstream* file;

        std::string getDateTimeString();

    public:
        logger(std::string path);

        ~logger();

        void write (std::string line);

        void listLogging (recordList* rList);
};


#endif