#include "student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

Student::Student() : name(""), id(0) { }
Student::Student(const std::string& tname, const int tid) : name(tname), id(tid) {}
void Student::setid(const int tid)
{
	this->id = tid;
}

void Student::setname(const std::string& tname)
{
	this->name = tname;
}

void Student::setscore(const std::string& subject, double tscore)
{
	this->scores[subject] = tscore;
}

int Student::getid() const
{
	return this->id;
}

std::string Student::getname() const
{
	return this->name;
}

std::optional<double> Student::getscore(const std::string subject) const
{
	auto it = this->scores.find(subject);
	if (it != this->scores.end()) return it->second;
	else return std::nullopt;
}

double Student::getaverage() const
{
	if (this->scores.empty()) return 0.0;
	double total { 0.0 };
	for (const auto& temp : this->scores) total += temp.second;
	return total / this->scores.size();
}

double Student::getsum() const
{
	double result{ 0 };
	for (const auto& temp : this->scores) result += temp.second;
	return result;
}

const std::map<std::string, double>& Student::getscores() const
{
	return this->scores;
}

bool loadFromFile(const std::string filename, std::vector<Student>& students)
{
	std::ifstream infile(filename);
	if (!infile.is_open())
	{
		std::cerr << "Unable to open the file. Please check the file path." << std::endl;
		return false;
	}
	std::string line;
	while (std::getline(infile, line))
	{
		if (line.empty()) continue;
		std::stringstream ss(line);
		std::string token;
		Student stu;
		try
		{
			ss >> token;
			stu.setname(token);
			ss >> token;
			stu.setid(std::stoi(token));
			while (ss >> token)
			{
				size_t pos = token.find(':');
				if (pos != std::string::npos)
				{
					stu.setscore(token.substr(0, pos), std::stod(token.substr(pos + 1)));
				}
			}
			students.push_back(stu);
		}
		catch (const std::exception& e)
		{
			std::cout << "Format error, skip this student." << std::endl;
			continue;
		}
		
	}
	return true;
}

bool saveToFile(const std::string& filename, const std::vector<Student>& students)
{
	std::ofstream outfile(filename);
	if (!outfile.is_open())
	{
		std::cerr << "Unable to open the file. Please check the file path." << std::endl;
		return false;
	}
	for (const Student& stu : students)
	{
		outfile << stu.getname() << ' ' << stu.getid() << ' ';
		for (auto it : stu.getscores())
		{
			outfile << it.first << ':' << it.second << ' ';
		}
		outfile << std::endl;
	}
	return true;
}