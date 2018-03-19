#include "stdafx.h"
#include "degree.h"
#include "network_student.h"
#include <vector>
#include <iostream>

Degree NetworkStudent::get_degree_program() 
{
	return NetworkStudent::degree_program;
}

void NetworkStudent::print()
{
	std::cout
		<< NetworkStudent::get_student_id() << " \t First Name: "
		<< NetworkStudent::get_first_name() << " \t Last Name: "
		<< NetworkStudent::get_last_name() << " \t  Age: "
		<< NetworkStudent::get_age() << " \t daysInCourse: "
		<< NetworkStudent::number_of_days_to_string() << " \t Degree Program: Security."
		<< std::endl;
}