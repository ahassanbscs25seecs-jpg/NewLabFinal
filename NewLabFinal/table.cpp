#include <iostream>
#include <iomanip>
#include <vector>

#include "table.h"

/**
 *
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
 *
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
        << std::setw(15) << "Username"
        << std::setw(25) << "Site URL"
        << std::setw(20) << "Password"
        << "\n-------------------------------------------------------------" << std::endl;

    for (const auto& e : table) {
        std::cout << std::left
                  << std::setw(8) << e.id
                  << std::setw(15) << e.username
                  << std::setw(25) << e.siteURL
                  << std::setw(20) << e.password
                  << std::endl;
    }
}
