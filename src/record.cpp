#include "../include/record.hpp"

record::record(fs::directory_entry entry) :
		fileObj(entry),
		processName(entry.path().filename().generic_string())
		{};

std::string record::getProcessName ()
{
	return processName;
}

void record::print () const
{
	std::printf("\n[record] Name:%s, Path:%s", processName.c_str(), fileObj.path().c_str());
}

std::string record::getLoggingLine ()
{
	std::string temp = processName + ", ";
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