#include <iostream>

#include "appUI.h"
#include "other.h"

int main() {
	clearScreen();
	printTitle();

	int option = 0;
	std::string passFilename;

	std::cout << "Enter the database name: ";
	std::cin >> passFilename;
	passFilename += ".csv";

	while (true) {
		clearScreen();
		printTitle();

		std::cout << "Enter an action\n"
				  << "1) Enter a new password\n"
				  << "2) Search for passwords\n"
				  << "3) Quit" << std::endl;

		do {
			std::cout << "> ";
			std::cin >> option;
			std::cin.ignore(IGNORE_SIZE, '\n');

			if (option == 1) {
				addNewPassword(passFilename);
				break;
			}
			else if (option == 2) {
				searchForPasswords(passFilename);
				break;
			}
			else if (option == 3) {
				return 0;
			}
			else {
				std::cout << "Invalid option!" << std::endl;
			}
		} while (option < 1 || option > 3);
	}
}
