#pragma once

#include <string>
#include <vector>
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
std::vector<TableEntry> readCSVFile(const std::string& filename);

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
void writeCSVFile(const std::string& filename, const std::vector<TableEntry>& table);
