#include "stdafx.h"
#include "degree.h"
#include "software_student.h"
#include <vector>
#include <iostream>

Degree SoftwareStudent::get_degree_program()
{
	return SoftwareStudent::degree_program;
}

void SoftwareStudent::print()
{
	std::cout
		<< SoftwareStudent::get_student_id() << " \t First Name: "
		<< SoftwareStudent::get_first_name() << " \t Last Name: "
		<< SoftwareStudent::get_last_name() << " \t  Age: "
		<< SoftwareStudent::get_age() << " \t daysInCourse: "
		<< SoftwareStudent::number_of_days_to_string() << " \t Degree Program: Software."
		<< std::endl;
}
