#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#pragma once
class Configuration
{
public:
	Configuration( void );
	Configuration( std::string* );
	~Configuration( void );

	bool LoadFile( std::string* );
	void ReadFile( std::string* );

	std::string GetDictionaryValue( std::string* );

private:
	std::map< std::string, std::string > m_dictionary;
	std::ifstream m_file;
	std::string m_stringstream;
	std::istringstream m_istream( std::string );

	void StoreLine( std::string* , std::string* );
};

