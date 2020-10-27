#pragma once
std::string word1{ "" };
std::string word2{ "" };
std::string word3{ "" };
std::string buffer{ "" };
std::string tempWord{ "" };
int totalWords{ 0 };
int userWordsFound{ 0 };
int lineNumber{ 0 };

void task3()
{
	system("cls");
	std::cout << "Search through gulliver.txt for a word: \nType a word to search: ";
	std::cin >> word1;

	word3 = word2 = word1;
	word2.at(0) = static_cast<char>(word2.at(0)) - 32;
	for (int i = 0; i < word3.length(); i++)
	{
		word3.at(i) = word3.at(i) - 32;
	}
	std::cout << "\nScanning...\n\n";

	//The Scan
	std::fstream file("gulliver.txt", std::ios::in);
	while (!file.eof())
	{
		std::getline(file, buffer);
		lineNumber++;
		for (int i = 1; i < buffer.length(); i++)		//Check the line
		{
			if (buffer.at(i - 1) == ' ' && buffer.at(i) != ' ')		//Found a word
			{
				tempWord = "";
				totalWords++;
				for (int j = i; j < buffer.size(); j++)			//Save the word
				{
					tempWord += buffer.at(j);

					if (tempWord == word1 || tempWord == word2 || tempWord == word3) {
						userWordsFound++;
						std::cout << "Line: " << lineNumber << "\n";
						//std::cout << tempWord;
					}
					if (buffer.at(j) == ' ')

						j = buffer.size();
				}
			}
		}
	}

	std::cout << "\n\nTotal words scanned: " << totalWords << "\nTotal matching words: " << userWordsFound;
}
