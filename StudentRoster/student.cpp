#include "stdafx.h"
#include "degree.h"
#include "student.h"
#include <string>
#include <vector>

Student::Student
(
    std::string student_id,
    std::string first_name,
    std::string last_name,
    std::string email_address,
    int age,
    std::vector<int> number_of_days
) :
    _student_id(student_id),
    _first_name(first_name),
    _last_name(last_name),
    _email_address(email_address),
    _age(age),
    _number_of_days(number_of_days) {}

Student::~Student() {}

std::string Student::get_student_id()
{
    return _student_id;
}

void Student::set_student_id(std::string student_id)
{
    _student_id = student_id;
}

std::string Student::get_first_name()
{
    return _first_name;
}

void Student::set_first_name(std::string first_name)
{
    _first_name = first_name;
}

std::string Student::get_last_name()
{
    return _last_name;
}

void Student::set_last_name(std::string last_name)
{
    _last_name = last_name;
}

std::string Student::get_email_address()
{
    return _email_address;
}

void Student::set_email_address(std::string email_address)
{
    _email_address = email_address;
}

int Student::get_age()
{
    return _age;
}

void Student::set_age(int age)
{
    _age = age;
}

std::vector<int> Student::get_number_of_days()
{
    return _number_of_days;
}

void Student::set_number_of_days(std::vector<int> number_of_days)
{
    _number_of_days = number_of_days;
}

std::string Student::number_of_days_to_string()
{
    std::string days_in_course = "{ ";
    for (int i = 0; i < _number_of_days.size(); i++)
    {
        days_in_course.append(std::to_string(_number_of_days[i]) + " ");
    }
    days_in_course.append("}");
    return days_in_course;
}