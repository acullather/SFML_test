#include "Configuration.h"

#pragma region Constructor & Destructor

Configuration::Configuration( void )
{
}

Configuration::Configuration( std::string* filename )
{
	Configuration::Configuration();
	ReadFile( filename );
}

Configuration::~Configuration(void)
{
}

#pragma endregion

#pragma region Public Methods

void Configuration::ReadFile( std::string* filename )
{
	if ( filename->empty() )
	{
		return;
	}
	try 
	{
		m_file.open( filename->c_str() );
		while ( std::getline( m_file, m_stringstream ))
		{
			std::istringstream iss( m_stringstream );
			std::string key;
			if ( std::getline( iss, key, '=' ))
			{
				std::string value;
				if ( std::getline( iss, value ))
				{
					StoreLine( &key, &value );
				}
			}
		}
		m_file.close();
	}
	catch( std::ifstream::failure e )
	{
		std::cout << "Exception opening/reading file '" << filename << "'" << std::endl;
	}
}

std::string Configuration::GetDictionaryValue( std::string* key )
{
	return m_dictionary[ *key ];
}

#pragma endregion

#pragma region Private Methods

void Configuration::StoreLine( std::string* key, std::string* value )
{
	m_dictionary[ *key ] = *value;
}

#pragma endregion