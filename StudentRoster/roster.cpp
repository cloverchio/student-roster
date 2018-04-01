#include "stdafx.h"
#include "roster.h"
#include "degree.h"
#include "software_student.h"
#include "security_student.h"
#include "network_student.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

Roster::~Roster()
{
    for (Student *student : Roster::class_roster_array)
    {
        delete student;
    }
    Roster::class_roster_array.clear();
}


void Roster::add
(
    std::string student_id,
    std::string first_name,
    std::string last_name,
    std::string email_address,
    int age,
    int days_in_course1,
    int days_in_course2,
    int days_in_course3,
    Degree degree_program
)
{
    int days[] = { days_in_course1, days_in_course2, days_in_course3 };
    std::vector<int> days_in_course(days, days + sizeof(days) / sizeof(days[0]));

    if (degree_program == NETWORKING)
    {
        Student *student = new NetworkStudent
        (
            student_id,
            first_name,
            last_name,
            email_address,
            age,
            days_in_course
        );
        Roster::class_roster_array.push_back(student);
    }
    else if (degree_program == SECURITY)
    {
        Student *student = new SecurityStudent
        (
            student_id,
            first_name,
            last_name,
            email_address,
            age,
            days_in_course
        );
        Roster::class_roster_array.push_back(student);
    }
    else
    {
        Student *student = new SoftwareStudent
        (
            student_id,
            first_name,
            last_name,
            email_address,
            age,
            days_in_course
        );
        Roster::class_roster_array.push_back(student);
    }
}

void Roster::remove(std::string student_id)
{
    std::vector<Student*>::iterator it;
    for (it = Roster::class_roster_array.begin(); it != Roster::class_roster_array.end(); it++)
    {
        if ((*it)->get_student_id() == student_id)
        {
            delete *it;
            Roster::class_roster_array.erase(it);
            return;
        }
    }
    std::cout << "Student: " << student_id << " was not found." << std::endl;
}

void Roster::print_all()
{
    for (size_t i = 0; i < Roster::class_roster_array.size(); i++)
    {
        Roster::class_roster_array[i]->print();
    }
}

void Roster::print_days_in_course(std::string student_id)
{
    std::vector<Student*>::iterator it;
    for (it = Roster::class_roster_array.begin(); it != Roster::class_roster_array.end(); it++)
    {
        if ((*it)->get_student_id() == student_id)
        {
            int sum = 0;
            std::vector<int> days_in_course = (*it)->get_number_of_days();
            for (size_t i = 0; i < days_in_course.size(); i++)
            {
                sum += days_in_course[i];
            }
            std::cout << "Average number of days in the three courses: " << sum / days_in_course.size() << std::endl;
            break;
        }
    }
}

void Roster::print_invalid_emails()
{
    std::vector<Student*>::iterator it;
    for (it = Roster::class_roster_array.begin(); it != Roster::class_roster_array.end(); it++)
    {
        const std::string email = (*it)->get_email_address();

        bool contains_at_sign = (email.find("@") != std::string::npos);
        bool contains_period = (email.find(".") != std::string::npos);
        bool contains_space = (email.find(" ") != std::string::npos);

        if (!contains_at_sign || !contains_period || contains_space)
        {
            std::cout << email << std::endl;
        }
    }
}

void Roster::print_by_degree_program(int degree_program)
{
    std::vector<Student*>::iterator it;
    for (it = Roster::class_roster_array.begin(); it != Roster::class_roster_array.end(); it++)
    {
        if ((*it)->get_degree_program() == degree_program)
        {
            (*it)->print();
        }
    }
}

static std::vector<std::string> split_string(std::string str)
{
    std::vector<std::string> split_strs;
    std::stringstream ss(str);

    while (std::getline(ss, str, ','))
    {
        split_strs.push_back(str);
    }
    return split_strs;
}