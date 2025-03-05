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

    logger log("/home/thiva/unix_cpu_usage/logs/");
    log.write("test script\n is it in next line");

    recordList rList;
    
    std::string dirPath = "/proc/";
    Readdirectory dirObj(dirPath);
    // dirObj.printFileListInsideDir();
    dirObj.updateRecordList(&rList);

	auto fromFile = dirObj.readFromFile(rList.getPath("loadavg"));

	std::cout<<"from File: \n";
	for (auto& i : fromFile)
		std::cout<<i<<std::endl;

    // rList.print();
	// char username[FILENAME_MAX];
    // if (getlogin_r(username, FILENAME_MAX));
	// std::cout << username <<std::endl;

    log.listLogging(&rList);



    return 0;
};