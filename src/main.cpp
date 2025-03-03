#include "../include/main.hpp"

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

        std::string getDateTimeString() {
            auto now = std::chrono::system_clock::now();
            auto time_t_now = std::chrono::system_clock::to_time_t(now);

            std::stringstream ss;
            ss << std::put_time(std::localtime(&time_t_now), "%m%d%y%H%M");

            return ss.str();
        }

    public:
        logger(std::string path) : m_sPath(path) 
        {
            file = new std::ofstream(path+getDateTimeString()+".txt");
            sleep(0.1);
        };
        ~logger() {
            file->close();
            delete file;
        }

        void write (std::string line)
        {
            *file << "\n";
            *file << line;
        };

        void listLogging (recordList* rList)
        {
            if(!file->is_open()) 
            {
                std::printf("\n[Logger] Error! file is not open");
                return;
            }

            auto rListMapPtr = rList->getListPtr();

            for(auto& i : *rListMapPtr)
            {
                write(i.second.getLoggingLine());
                sleep(0.1);
            }
        }
};

class Readdirectory
{

    public:
        Readdirectory(std::string dirPath) : m_sPath(dirPath)
        {
        };

        void printFileListInsideDir()
        {
            for (const auto& i: m_list)
            {
                std::cout<<i.first<<": "<<i.second.path()<<std::endl;
            }        
        }

        void updateRecordList (recordList* pRecordList)
        {
            int elementCount = 0;

            for (const auto& i: fs::directory_iterator(m_sPath)) ++elementCount;

            pRecordList->setMapSize(elementCount);

            for (const auto& i: fs::directory_iterator(m_sPath))
            {
                pRecordList->add_record(i);
            }
        }

    private:
        std::string m_sPath = "";

        std::unordered_map<std::string,fs::directory_entry> m_list;
};


int main ()
{
    std::printf("Cpu usage log is starting\n");

    logger log("/home/thivanka/github_ws/unix_cpu_usage/");
    log.write("test script\n is it in next line");

    recordList rList;
    
    std::string dirPath = "/proc/";
    Readdirectory dirObj(dirPath);
    // dirObj.printFileListInsideDir();
    dirObj.updateRecordList(&rList);

    rList.print();

    log.listLogging(&rList);



    return 0;
};