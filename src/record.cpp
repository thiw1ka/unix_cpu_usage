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
}

void recordList::add_record (record r) 
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
