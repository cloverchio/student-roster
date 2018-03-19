#pragma once
#include "degree.h"
#include <string>
#include <vector>

class Student
{
private:
	std::string _student_id;
	std::string _first_name;
	std::string _last_name;
	std::string _email_address;
	int _age;
	std::vector<int> _number_of_days;

public:
	Student
	(
		std::string student_id,
		std::string first_name,
		std::string last_name,
		std::string email_address,
		int age,
		std::vector<int> number_of_days
	);

	virtual ~Student();

	std::string get_student_id();
	void set_student_id(std::string student_id);
	std::string get_first_name();
	void set_first_name(std::string first_name);
	std::string get_last_name();
	void set_last_name(std::string last_name);
	std::string get_email_address();
	void set_email_address(std::string email_address);
	int get_age();
	void set_age(int age);
	std::vector<int> get_number_of_days();
	void set_number_of_days(std::vector<int> number_of_days);

	virtual void print() = 0;
	virtual Degree get_degree_program() = 0;

protected:
	std::string number_of_days_to_string();
};