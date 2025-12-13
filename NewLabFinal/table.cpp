#include <iostream>
#include <iomanip>
#include <vector>

#include "table.h"

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
std::vector<TableEntry> searchByUsername(const std::vector<TableEntry>& table, const std::string& username) {
    std::vector<TableEntry> result;

    for (auto& e : table) {
        if (username == e.username) {
            result.push_back(e);
        }
    }

    return result;
}

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
std::vector<TableEntry> searchBySiteURL(const std::vector<TableEntry>& table, const std::string& siteURL) {
    std::vector<TableEntry> result;

    for (auto& e : table) {
        if (siteURL == e.siteURL) {
            result.push_back(e);
        }
    }

    return result;
}

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
void printTable(const std::vector<TableEntry>& table) {
    std::cout << std::left
        << std::setw(8) << "ID"
        << std::setw(30) << "Username"
        << std::setw(30) << "Site URL"
        << std::setw(20) << "Password" << std::endl;

    for (const auto& e : table) {
        std::cout << std::left
                  << std::setw(8) << e.id
                  << std::setw(30) << e.username
                  << std::setw(30) << e.siteURL
                  << std::setw(20) << e.password
                  << std::endl;
    }
}
