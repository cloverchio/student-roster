#include "stdafx.h"
#include "degree.h"
#include "security_student.h"
#include <vector>
#include <iostream>

Degree SecurityStudent::get_degree_program()
{
	return SecurityStudent::degree_program;
}

void SecurityStudent::print()
{
	std::cout
		<< SecurityStudent::get_student_id() << " \t First Name: "
		<< SecurityStudent::get_first_name() << " \t Last Name: "
		<< SecurityStudent::get_last_name() << " \t  Age: "
		<< SecurityStudent::get_age() << " \t daysInCourse: "
		<< SecurityStudent::number_of_days_to_string() << " \t Degree Program: Security."
		<< std::endl;
}