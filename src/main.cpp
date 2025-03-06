#include "../include/main.hpp"

int main ()
{
    std::printf("Kernal data log is starting\n");

    logger log("/home/thiva/unix_cpu_usage/logs/");
    log.write("Test script\n");

    recordList rList;

	std::vector<std::string> kernalDataToRecord = {
		"loadavg",
		"meminfo",
		"stat"
	};
    
    std::string dirPath = "/proc/";
    Readdirectory dirObj(dirPath);
    dirObj.updateRecordList(&rList);

	std::string strLineToLog;
	for (int i = 0; i < 2; i++)
	{
		log.write(log.getDateTimeString() + ":\n");
		for (auto kdata : kernalDataToRecord)
		{
			auto getStringVec = dirObj.readFromFile(rList.getRecordByName(kdata));
			strLineToLog = rList.getRecordByName(kdata)->getFormattedString(&getStringVec);
			std::cout<< strLineToLog <<std::endl;
			log.write(strLineToLog);
		}
		for (auto kdata : *rList.getListPtr())
		{
			try
			{
				if (!kdata.second.is_Directory()) continue;
				auto getStringVec = dirObj.readFromFile(rList.getRecordByName(kdata.first));
				strLineToLog = rList.getRecordByName(kdata.first)->getFormattedString(&getStringVec);
				std::cout<< strLineToLog <<std::endl;
				log.write(strLineToLog);
			}
			catch(const std::exception& e)
			{
				//we know some will fail here.
				std::cerr << e.what() << '\n';
				continue;
			}
			


		}
		log.write("\n\n");

		sleep(1);
	}

    return 0;
};