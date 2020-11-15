#pragma once
std::string correctAns{ "ABDCAB" };
std::string temp{ "" };
int fileSize{ 0 };

struct students
{
	std::string name{};
	std::string answer{};
	int score{ 0 };
};

float calcAverageScore(std::vector<students> students) {

	float score{ 0 };
	for (int i = 0; i < students.size(); i++)
	{
		score += students.at(i).score;
	}

	return (score / static_cast<float>(students.size()));
}

int calcHighScore(std::vector<students> students) {
	int highscore{ 0 };
	for (int i = 0; i < students.size(); i++)
	{
		if (students.at(i).score > highscore)
			highscore = students.at(i).score;
	}
	return highscore;
}

int calcLowScore(std::vector<students> students) {
	int lowscore{ 99 };
	for (int i = 0; i < students.size(); i++)
	{
		if (students.at(i).score < lowscore)
			lowscore = students.at(i).score;
	}
	return lowscore;
}

int scoreCalc(std::string studentAns)
{
	int score{ 0 };
	for (int i = 0; i < correctAns.size(); i++)
	{
		if (correctAns.at(i) == studentAns.at(i))
			score++;
	}
	return score;
}

void task2() 
{
	std::fstream file("Task2.txt", std::ios::in);
	while (!file.eof())
	{
		file >> temp;
		fileSize++;
		//std::cout << fileSize << std::endl;
	}
	file.close();
	std::vector<students> students(fileSize / 2);		//divide by 2 because of the format inside the file, each student has 2 lines, one for name and one for results

	std::fstream file2("Task2.txt", std::ios::in);

	for (int i = 0; i < students.size(); i++)		//assign name and answer for each student
	{
		std::getline(file2, students.at(i).name);
		//std::cout << students.at(i).name << std::endl;
		std::getline(file2, students.at(i).answer);
		//std::cout << students.at(i).answer << std::endl;
	}

	for (int i = 0; i < students.size(); i++)		//assign each student a score
	{
		students.at(i).score = scoreCalc(students.at(i).answer);
	}

	//Final Print:
	std::cout << "Student Name: \t\tScore:\n";
	for (int i = 0; i < students.size(); i++)
	{
		std::cout << students.at(i).name << "\t\t\t" << students.at(i).score << std::endl;
	}
	std::cout << "\nNumber of students: " << students.size() << std::endl;
	std::cout << "Average grade: " << calcAverageScore(students) << std::endl;
	std::cout << "Highest grade: " << calcHighScore(students) << std::endl;
	std::cout << "Lowest grade: " << calcLowScore(students) << std::endl;
}