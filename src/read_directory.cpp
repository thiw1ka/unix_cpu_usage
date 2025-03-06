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
		pRecordList->insertRecord(i);
	}

}

std::vector<std::string> Readdirectory::readFromFile (record* rec)
{
	std::string path = rec->getFilePath();

	if(rec->is_Directory()) //if its directory go inside and read stat file
	{
		path.append("/stat");
	}
	std::ifstream file(path);

	if (!file.is_open())
	{
		throw std::invalid_argument("file cannot be open:" + path);
	}

	std::string tempStr(path + ": ");
	std::vector<std::string> tempVec;
	tempVec.push_back(tempStr);
	while (std::getline(file, tempStr))
	{
		tempVec.push_back(tempStr);
	}

	file.close();

	return std::move(tempVec);
}