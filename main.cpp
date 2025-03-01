#include <iostream>
#include <experimental/filesystem>
#include <string>
#include <fstream>
#include <unordered_map>
#include <chrono>
#include <unistd.h>

namespace fs = std::experimental::filesystem;


class process_base 
{
    virtual void update_val ();
    virtual double get_value ();     
};

class process : public process_base
{
    public:

        process (int pName) {

        }

        void update_val () override
        {

        }

        double get_value () override
        {
            return 0;
        }
};

class logger
{
        std::string m_sPath = "", m_sName = "";
        std::ofstream* file;
    public:
        logger(std::string path) : m_sPath(path) 
        {
            file = new std::ofstream(path);
            sleep(1);
        };
        ~logger() {
            file->close();
            delete file;
        }

        void write (std::string line)
        {
            *file << line;
        };
};

class Readdirectory
{

    public:
        Readdirectory(std::string dirPath) : m_sPath(dirPath)
        {
            update_list();
        };

        void printFileListInsideDir()
        {
            for (const auto& i: m_list)
            {
                std::cout<<i.first<<": "<<i.second.path()<<std::endl;
            }        
        }
    private:
        std::string m_sPath = "";

        std::unordered_map<std::string,fs::directory_entry> m_list;
 
        void update_list() {
            for (const auto& i: fs::directory_iterator(m_sPath))
            {
                m_list[i.path().filename().generic_string()] = i;
            }
        }
};


int main ()
{
    std::printf("Cpu usage log is starting\n");

    logger log("/home/thivanka/github_ws/log_cpu_usage/test.txt");
    log.write("test script\n is it in next line");
    log.~logger();
    
    std::string dirPath = "/proc/";
    Readdirectory dirObj(dirPath);
    dirObj.printFileListInsideDir();

    return 0;
};