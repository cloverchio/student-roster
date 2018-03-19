#pragma once
#include "degree.h"
#include "student.h"
#include <string>
#include <vector>

class SoftwareStudent : public Student
{
public:
	SoftwareStudent
	(
		std::string student_id,
		std::string first_name,
		std::string last_name,
		std::string email_address,
		int age,
		std::vector<int> number_of_days
	) : Student
	(
		student_id,
		first_name,
		last_name,
		email_address,
		age,
		number_of_days
	) {}

	Degree get_degree_program();
	void print();

private:
	Degree degree_program = SOFTWARE;
};