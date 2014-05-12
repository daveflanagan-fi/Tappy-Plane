//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: SettingsManager.h
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#ifndef __SETTINGS_MANAGER_H__
#define __SETTINGS_MANAGER_H__

#include <boost/property_tree/ptree.hpp>
#include <string>

class SettingsManager
{
private:
	static boost::property_tree::ptree pt;

public:
	static void Load();
	static void Save();

	template <class T>
	static T Get(std::string Name)
	{
		return pt.get<T>(Name);
	}

	template <class T>
	static void Put(std::string Name, T Value)
	{
		pt.put<T>(Name, Value);
	}
};
#endif