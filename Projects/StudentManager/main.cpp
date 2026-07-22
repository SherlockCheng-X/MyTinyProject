#include <iostream>
#include <string>
#include <exception>
#include "student.h"

int main()
{
	std::vector<Student> s_list;
	if (loadFromFile("grades.txt", s_list))
	{
		std::cout << "Unable to open the file." << std::endl;
		return 0;
	}
	std::cout << "1.Add a student" << std::endl;
	std::cout << "2.Add/modify the score" << std::endl;
	std::cout << "3.Display the someone's scores list" << std::endl;
	std::cout << "4.Display the class ranking" << std::endl;
	std::cout << "6.Save and exit" << std::endl;
	
	size_t choice = 0;
	std::cin >> choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (choice)
	{
	case 1:
	{
		bool input_status = false;
		int id;
		std::string* str_p = new std::string;
		while (!input_status)
		{
			try
			{
				input_status = true;
				std::cout << "Enter the student's name: ";
				std::getline(std::cin, *str_p);
				id = std::stoi(*str_p);
				for (const Student& single : s_list)
				{
					if (id == single.getid())
					{
						std::cout << "This id is existing, try another one." << std::endl;
						input_status = false;
						break;
					}
				}
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << "Unexpected input, try again" << std::endl;
				input_status = false;
			}
		}
	}
	default:
		break;
	}
	std::cout << "Bye!" << std::endl;
}