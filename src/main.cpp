#include "../include/main.hpp"

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