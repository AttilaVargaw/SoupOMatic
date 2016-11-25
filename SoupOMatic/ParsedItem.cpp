#include "stdafx.h"
#include "ParsedItem.h"

ParsedItem::ParsedItem() {
}

ParsedItem::ParsedItem(std::string name, std::string text, int slotCode) : name(name), text(text), slotCode(slotCode) {
}

std::string ParsedItem::GetName() {
	return name;
}

std::string ParsedItem::GetText() {
	return text;
}

int ParsedItem::getCode() {
	return slotCode;
}

ParsedItem::~ParsedItem()
{
}
