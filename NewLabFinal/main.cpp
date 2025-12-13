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

			/* Rejects input that aren't integers */
			if (!(std::cin >> option)) {
				std::cout << "Invalid input!" << std::endl;
				std::cin.clear();
				std::cin.ignore(IGNORE_SIZE, '\n');
				continue;
			}

			std::cin.ignore(IGNORE_SIZE, '\n'); /* You will see this line a lot because cin leaves a newline
												 * in the input buffer which can mess with a getline call afterwards.
												 * So we have to call cin.ignore() to discard it.
												 */

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
