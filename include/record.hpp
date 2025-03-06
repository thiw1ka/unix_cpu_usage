#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <experimental/filesystem>
#include <stdexcept>

#ifndef RECORD_HPP
#define RECORD_HPP

namespace fs = std::experimental::filesystem;

class record 
{
    std::string processName;
    int pid;
    fs::directory_entry fileObj; // holds the object file
	int isDirectory = false;

	enum Type
	{
		folder = 0,
		file = 1
	};

	enum Attributes
	{

	};

    public:
        record(fs::directory_entry entry);

        std::string getProcessName ();

        void print ();

        std::string getLoggingLine ();

		std::string getObjectPrintableString();

		std::string getFilePath();

		std::string getFormattedString(std::vector<std::string>* strVecPtr);

		bool is_Directory() 
		{
			return bool(isDirectory);
		}

};

class recordList 
{
    std::unique_ptr <std::unordered_map<std::string,record>> m_list;

	/// @brief Selected data to be written in logfile
	std::unique_ptr <std::vector<std::string>> m_selectedList;

    public:
        recordList();
    
        /// @brief Insert record to the container
        /// @param r record
        void insertRecord (record r);

        void print ();

        void setMapSize(int sz);

        std::unordered_map<std::string,record>* getListPtr () const;

		std::string getPath (std::string filename);

		void getListOfTargetsToRecord();

		record* getRecordByName(std::string name);

};

struct cProperties
{
	enum Type
	{
		folder = 0,
		file = 1
	};

	enum Attributes
	{

	};

	Type objType;
	std::vector<Attributes> AttribVector;
};

class cCard : public cProperties
{
	cCard(cProperties);


};


#endif