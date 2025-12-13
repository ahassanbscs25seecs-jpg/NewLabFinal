#pragma once

#include <string>

/* Represents a record in the password table. */
struct TableEntry {
	int id = 0;
	std::string username;
	std::string siteURL;
	std::string password;
};

/**
 * searchByUsername:
 *   Return a table consisting of all the entries with entries having the specified username.
 *
 * Arguments:
 *   -> table: The table we are searching.
 *   -> username: The username to match.
 *
 * Return value:
 *   A table containing records with the username specified.
 */
std::vector<TableEntry> searchByUsername(const std::vector<TableEntry>& table, const std::string& username);

/**
 * searchByUsername:
 *   Return a table consisting of all the entries with entries having the specified site URL.
 *
 * Arguments:
 *   -> table: The table we are searching.
 *   -> username: The site URL to match.
 *
 * Return value:
 *   A table containing records with the site URL specified.
 */
std::vector<TableEntry> searchBySiteURL(const std::vector<TableEntry>& table, const std::string& siteURL);

/**
 * printTable:
 *   Print the password table to the terminal in an easy to read manner.
 *
 * Arguements:
 *   -> table: The table we want to print to the terminal.
 *
 * Return value:
 *   Returns nothing.
 */
void printTable(const std::vector<TableEntry>& table);
