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
	while (!input.eof()) {
		std::getline(input, buffer);
		output << buffer << "\n";
	}
}

int main()
{
	//task2();
	system("cls");
	//task3();
	task4();
}

