#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>

#include "table.h"

/**
 * readCSVFile:
 *   Reads a CSV file and processes it into a computer-friendly format
 * 
 * Arguments:
 *   -> filename: Name of the CSV file we want to read from
 * 
 * Return value:
 *   Returns the CSV file as a list of table entries
 */
std::vector<TableEntry> readCSVFile(const std::string& filename) {
    std::ifstream f(filename);
    std::string line;
    std::vector<TableEntry> table;

    /* Read the file line by line. Each line will be a record. */
    while (std::getline(f, line)) {
        /* Take the line and further divide it at the commas
         * which will let us extract each individual entry.
         */

        size_t a = line.find(',');
        size_t b = line.find(',', a + 1);
        size_t c = line.find(',', b + 1);

        table.push_back(TableEntry {
            std::stoi(line.substr(0, a)),  /* ID */
            line.substr(a + 1, b - a - 1), /* Username */
            line.substr(b + 1, c - b - 1), /* Site URL */
            line.substr(c + 1)             /* Password */
        });
    }

    return table;
}

/**
 * writeCSVFile:
 *   Writes the contents of `table` into `filename` in CSV format
 * 
 * Arguments:
 *   -> filename: The name of the CSV file we want to write to.
 *   -> table: The table that we want to store in CSV format.
 * 
 * Return value:
 *   Returns nothing.
 */
void writeCSVFile(const std::string& filename, const std::vector<TableEntry>& table) {
    std::ofstream f(filename);
    
    for (int i = 0; i < table.size(); i++) {
        f << table[i].id << ','
          << table[i].username << ','
          << table[i].siteURL << ','
          << table[i].password << std::endl;
    }
}


