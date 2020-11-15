// Weekly6.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Task2.h"
#include "task3.h"

void task4() 
{
	std::fstream input("gulliver.txt", std::ios::in);
	std::fstream output("output.txt", std::ios::out, std::ios::trunc);
	std::string buffer{ "" };
	std::cout << "Copying...\n";
	while (!input.eof()) {
		std::getline(input, buffer);
		output << buffer << "\n";
	}
	std::cout << "Text from gulliver.txt has been copied to output.txt\n";
}

int main()
{
	int input{ 0 };
	while (true) {
		system("cls");
		std::cout << "What task would you like to view? \nTask [1]: N/A \nTask [2]: Student Exam Results \nTask [3]: Scan for words \nTask [4]: Copy a file info to another \nQuit [5]\n";
		std::cin >> input;
		switch (input) {
		case 1:
			std::cout << "N/A\n";
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 5:
			exit(0);
		default:
			std::cout << "Invalid Input";
			break;
		}
		system("pause");
	}
}

