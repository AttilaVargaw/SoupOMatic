#pragma once
#include "stdafx.h"

class ParsedItem {
	std::string name;
	std::string text;
	int slotCode;

public:
	ParsedItem();
	~ParsedItem();
	ParsedItem(std::string name, std::string text, int slotCode);

	std::string GetName();
	std::string GetText();

	int getCode();
};