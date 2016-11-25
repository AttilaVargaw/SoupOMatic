#include "stdafx.h"
#include "ConfigLoader.h"

ConfigLoader::~ConfigLoader() {
}

ConfigLoader::ConfigLoader(std::string configFileName) {
	std::string data, err, buffer;

	std::ifstream input;
	input.open(configFileName);

	while (input >> buffer) {
		data += buffer;
	}

	auto jsonData = json11::Json::parse(data, err);
	auto object = jsonData.object_items();

	auto flavours = object["flavours"].array_items();
	auto soups = object["soups"].array_items();
	auto commandButtons = object["commandButtons"].object_items();

	for (auto jt : commandButtons) {
		commandButtons.emplace(jt);
	}

	for (auto jt : soups) {
		auto item = jt.object_items();
		buildedConfig.soups.push_back(
			ParsedItem(item.at("name").string_value(),
				item.at("text").string_value(),
				item.at("slot").number_value()));
	}

	for (auto jt : flavours) {
		auto item = jt.object_items();
		buildedConfig.flavours.push_back(
			ParsedItem(item.at("name").string_value(),
				item.at("text").string_value(),
				item.at("slot").number_value()));
	}
}