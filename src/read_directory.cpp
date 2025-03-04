#include "../include/read_directory.hpp"

Readdirectory::Readdirectory(std::string dirPath) : m_sPath(dirPath)
{

};

void Readdirectory::printFileListInsideDir()
{
	// for (const auto& i: m_list)
	// {
	// 	std::cout<<i.first<<": "<<i.second.path()<<std::endl;
	// }        
}

void Readdirectory::updateRecordList (recordList* pRecordList)
{
	int elementCount = 0;

	for (const auto& i: fs::directory_iterator(m_sPath)) ++elementCount;

	pRecordList->setMapSize(elementCount);

	for (const auto& i: fs::directory_iterator(m_sPath))
	{
		pRecordList->add_record(i);
	}
}