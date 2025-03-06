#include "../include/record.hpp"

record::record(fs::directory_entry entry) :
		fileObj(entry),
		processName(entry.path().filename().generic_string()),
		isDirectory(fs::is_directory(entry))
		{};

std::string record::getProcessName ()
{
	return processName;
}

void record::print ()
{
	auto lineString = getObjectPrintableString();
	std::cout << lineString;
}

std::string record::getObjectPrintableString()
{
	std::string temp = "[record] Name: " + processName;
	temp.append(" extention: " + fileObj.path().extension().generic_string());
	temp.append(" is a folder: " + std::to_string(isDirectory));
	temp.append("\n");

	return std::move(temp);
}

std::string record::getLoggingLine ()
{
	std::string temp = processName + ", ";
	temp.append(fileObj.path().generic_string() + ", ");
	temp.append(fileObj.path().extension().generic_string());
	return std::move(temp);
}


recordList::recordList()
{
	m_list = std::make_unique <std::unordered_map<std::string,record>> ();
	m_selectedList = std::make_unique <std::vector<std::string>> ();
}

void recordList::insertRecord (record r) 
{
	m_list->emplace(r.getProcessName(), r);
}

void recordList::print ()
{
	for_each (m_list.get()->begin(), m_list.get()->end(), 
						[&](auto i){i.second.print();});
	
}

void recordList::setMapSize(int sz)
{
	m_list->reserve(sz);
}

std::unordered_map<std::string,record>* recordList::getListPtr () const
{
	return m_list.get();
}


std::string recordList::getPath (std::string filename)
{
	return m_list->at(filename).getFilePath();
}

std::string record::getFilePath()
{
	return fileObj.path().generic_string();
}

record* recordList::getRecordByName(std::string name)
{
	return &m_list->at(name);
}


std::string record::getFormattedString(std::vector<std::string>* strVecPtr)
{
	std::string temp ="";
	temp.append(this->processName + ":\n ");
	if (this->processName == "meminfo")
	{
		for (std::string& i : *strVecPtr)
		if(i.find("Mem") != i.npos)
		temp.append(i);
	}
	else if (this->processName == "stat")
	{
		for (std::string& i : *strVecPtr)
		if(i.find("cpu") != i.npos)
		temp.append(i);
	}
	else
	{
		for (std::string& i : *strVecPtr)
		temp.append(i);
	}
	
	return temp;
}
