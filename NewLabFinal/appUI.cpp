#include <vector>
#include <iostream>
#include <string>

#include "appUI.h"

#include "fileIO.h"
#include "strengthChecking.h"
#include "passGen.h"
#include "table.h"
#include "other.h"

void clearScreen() {
	std::cout << "\033[H\033[2J";
}

void printTitle() {
	std::cout << "-----------\n"
		      << "-PassGuard-\n"
		      << "-----------\n" << std::endl;
}

void searchForPasswords(const std::string& filename) {
	clearScreen();
	printTitle();

	std::vector<TableEntry> table = readCSVFile(filename);
	std::vector<TableEntry> searchResults;
	int option = 0;

	std::cout << "What do you want to search with?\n"
		<< "1) Username\n"
		<< "2) Site URL" << std::endl;

	do {
		std::cout << "> ";

		if (!(std::cin >> option)) {
			std::cout << "Invalid input!" << std::endl;
			std::cin.clear();
			std::cin.ignore(IGNORE_SIZE, '\n');
			continue;
		}

		std::cin.ignore(IGNORE_SIZE, '\n');

		if (option != 1 && option != 2) {
			std::cout << "Wrong option!" << std::endl;
		}
	} while (option != 1 && option != 2);

	switch (option) {
	case 1: {
		std::string username;

		std::cout << "\nEnter the username" << std::endl;
		do {
			std::cout << "> ";
			std::getline(std::cin, username);

			if (username.length() == 0) {
				std::cout << "Username can't be empty!" << std::endl;
			}
		} while (username.length() == 0);

		searchResults = searchByUsername(table, username);
		break;
	}

	case 2: {
		std::string siteURL;

		std::cout << "Enter the site URL" << std::endl;
		do {
			std::cout << "> ";
			std::getline(std::cin, siteURL);

			if (siteURL.length() == 0) {
				std::cout << "Site URL can't be empty!" << std::endl;
			}
			else if (!isSiteURLValid(siteURL)) {
				std::cout << "Site URL can't contain whitespace!" << std::endl;
			}
		} while (siteURL.length() == 0 || !isSiteURLValid(siteURL));

		searchResults = searchBySiteURL(table, siteURL);

		break;
	}
	}

	std::cout << std::endl;
	printTable(searchResults);

	std::cout << "\nPress any key to continue..." << std::endl;
	(void)std::getchar();
}

void addNewPassword(std::string filename) {
	clearScreen();
	printTitle();

	TableEntry entry;

	std::cout << "Enter your username" << std::endl;
	do {
		std::cout << "> ";
		std::getline(std::cin, entry.username);

		if (entry.username.size() == 0) {
			std::cout << "Username can't be empty" << std::endl;
		}
	} while (entry.username.size() == 0);

	std::cout << "Enter the site URL" << std::endl;
	do {
		std::cout << "> ";
		std::getline(std::cin, entry.siteURL);

		if (entry.siteURL.length() == 0) {
			std::cout << "Site URL can't be empty!" << std::endl;
		}
		else if (!isSiteURLValid(entry.siteURL)) {
			std::cout << "Site URL can't contain whitespace!" << std::endl;
		}
	} while (entry.siteURL.length() == 0 || !isSiteURLValid(entry.siteURL));

	char option;
	std::cout << "Do you want to generate a password (y/n)" << std::endl;
	do {
		std::cout << "> ";
		std::cin >> option;
		std::cin.ignore(IGNORE_SIZE, '\n');
		option = std::tolower(option);

		if (option != 'y' && option != 'n') {
			std::cout << "Incorrect option!" << std::endl;
		}
	} while (option != 'y' && option != 'n');

	switch (option) {
	case 'n': {
		std::string label;

		do {
			entry.password = getPasswordInput();
			int score = calculateStrengthScore(entry.password);
			label = strengthLabel(score);
			std::cout << "Strength : " << label << std::endl;

			if (label == "Strong" || label == "Very Strong") {
				break;
			}

			char option;

			std::cout << "Do you want to enter the password again?" << std::endl;
			do {
				std::cout << "> ";
				std::cin >> option;
				std::cin.ignore(IGNORE_SIZE, '\n');
				option = std::tolower(option);

				if (option != 'y' && option != 'n') {
					std::cout << "Incorrect option!" << std::endl;
				}
			} while (option != 'y' && option != 'n');

			if (option == 'n') {
				break;
			}
		} while (true);
		break;
	}

	case 'y': {
		int passwordLen;

		std::string rand_str;
		unsigned long int seed = 0;

		bool options[4] = {};
		int n_options = 0;
		bool allow_repeating = true;

		std::cout << "Enter a random string of at least 50 characters long" << std::endl;

		do {
			std::cout << "> ";
			std::getline(std::cin, rand_str);

			if (rand_str.length() < 50) {
				std::cout << "\nNot long enough\n" << std::endl;
				rand_str.clear();
			}
		} while (rand_str.length() < 50);

		seed = genSeed(rand_str);

		std::cout << "Enter the password length (8-20)" << std::endl;
		do {
			std::cout << "> ";
			std::cin >> passwordLen;

			if (passwordLen < 8 || passwordLen > 20) {
				std::cout << "Out of range!" << std::endl;
			}
		} while (passwordLen < 8 || passwordLen > 20);

		std::cout << "Allow repetition (y/n)?" << std::endl;
		char option;
		do {
			std::cout << "> ";
			std::cin >> option;
			option = std::tolower(option);
			std::cin.ignore(IGNORE_SIZE, '\n');

			if (option != 'y' && option != 'n') {
				std::cout << "Wrong option!" << std::endl;
			}
		} while (option != 'y' && option != 'n');

		if (option == 'y') {
			allow_repeating = true;
		}
		else {
			allow_repeating = false;
		}

		std::cout << "Enter the number of character types you want to choose (2-4)" << std::endl;
		do {
			std::cout << "> ";
			std::cin >> n_options;

			if (n_options < 2 || n_options > 4) {
				std::cout << "Out of range";
			}
		} while (n_options < 2 || n_options > 4);

		if (n_options == 4) {
			options[0] = options[1] = options[2] = options[3] = true;
		}
		else {
			int option = 0;
			std::cout << "1) Digits\n2) Special\n3) Upper\n4) Lower" << std::endl;
			std::cout << "Enter any " << n_options << " options" << std::endl;

			for (int i = 0; i < n_options; i++) {
				do {
					std::cout << "> ";
					std::cin >> option;

					if (option < 1 || option > 4) {
						std::cout << "Invalid option" << std::endl;
					}
					else if (options[option - 1]) {
						std::cout << "Option already selected." << std::endl;
					}
				} while (option < 1 || option > 4 || options[option - 1]);
				options[option - 1] = true;
			}
		}

		do {
			entry.password = genNewPassword(passwordLen, options, allow_repeating);
			std::cout << "Password: " << entry.password << std::endl;
			std::cout << "Do you want to regenerate the password (y/n)?" << std::endl;

			char option;
			do {
				std::cout << "> ";
				std::cin >> option;
				option = std::tolower(option);
				std::cin.ignore(IGNORE_SIZE, '\n');

				if (option != 'y' && option != 'n') {
					std::cout << "Wrong option!" << std::endl;
				}
			} while (option != 'y' && option != 'n');

			if (option == 'n') {
				break;
			}
		} while (true);
		break;
	}
	}

	std::vector<TableEntry> table = readCSVFile(filename);

	if (table.size() == 0) {
		entry.id = 1;
	}
	else {
		TableEntry& lastEntry = table.back();
		entry.id = lastEntry.id + 1;
	}

	table.push_back(entry);

	writeCSVFile(filename, table);

	std::cout << "Done. Press any key to continue..." << std::endl;
	(void)std::getchar();
}
