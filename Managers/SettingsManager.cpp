//========= Copyright © 2014, DeadPixel, All rights reserved. =========//
// File: SettingsManager.cpp
// Version: 1.0
// Author: Dave Flanagan
//=====================================================================//

#include "SettingsManager.h"
#include <boost/property_tree/xml_parser.hpp>

boost::property_tree::ptree SettingsManager::pt;

void SettingsManager::Load()
{
	std::ifstream ifile("Content/settings.xml");
	if (ifile)
		read_xml(ifile, pt, boost::property_tree::xml_parser::trim_whitespace);
	else
	{
		pt.put("Graphics.Resolution.Width", 854);
		pt.put("Graphics.Resolution.Height", 480);
		pt.put("Graphics.Resolution.Fullscreen", false);
		pt.put("Graphics.Virtual.Width", 854);
		pt.put("Graphics.Virtual.Height", 480);
		pt.put("Graphics.ShowCollisons", false);
		pt.put("Graphics.ShowLog", false);

		pt.put("Audio.Music.Volume", 128);
		pt.put("Audio.Effects.Volume", 128);
		pt.put("Audio.Rate", 44100);
		pt.put("Audio.Channels", 2);
		pt.put("Audio.Buffers", 4096);

		Save();
	}
}
void SettingsManager::Save()
{
	boost::property_tree::xml_writer_settings<char> settings('\t', 1);
	write_xml("Content/settings.xml", pt, std::locale(), settings);
}