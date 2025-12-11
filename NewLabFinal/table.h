#pragma once

#include <string>

struct TableEntry {
	int id = 0;
	std::string username;
	std::string siteURL;
	std::string password;
};

/**
 *
 */
std::vector<TableEntry> searchByUsername(const std::vector<TableEntry>& table, const std::string& username);

/**
 *
 */
std::vector<TableEntry> searchBySiteURL(const std::vector<TableEntry>& table, const std::string& siteURL);

void printTable(const std::vector<TableEntry>& table);
