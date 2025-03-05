#include "../include/logger.hpp"


logger::logger(std::string path) : m_sPath(path) 
{
	///TODO: need to fix this
	// std::experimental::filesystem::directory_entry entry(m_sPath);
	// if (!fs::exists(entry));
	// {
	// 	std::cout << "\nInvalid Path\n";
	// 	throw std::invalid_argument("Invalid File Path: " + entry.path().generic_string());
	// }
	file = new std::ofstream(path+getDateTimeString()+".txt");
	sleep(0.1);
};

logger::~logger() {
	file->close();
	delete file;
}

std::string logger::getDateTimeString() {
	auto now = std::chrono::system_clock::now();
	auto time_t_now = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&time_t_now), "%m%d%y%H%M");

	return ss.str();
}

void logger::write (std::string line)
{
	*file << "\n";
	*file << line;
};

void logger::listLogging (recordList* rList)
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

