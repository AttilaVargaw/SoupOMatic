#pragma once
#include "stdafx.h"
#include "ParsedItem.h"

struct ConfigFile {
	std::vector<ParsedItem> soups;
	std::vector<ParsedItem> flavours;
	std::map<std::string, std::string> commandButtonNames;
};

class ConfigLoader
{
	bool error = false;
	ConfigFile buildedConfig;
public:
	ConfigLoader(std::string configFileName);
	~ConfigLoader();

	ConfigFile GetConfig() {
		return buildedConfig;
	}
};

