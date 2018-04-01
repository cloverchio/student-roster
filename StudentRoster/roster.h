#pragma once
#include "degree.h"
#include "student.h"
#include <string>
#include <vector>

class Roster
{
public:
    ~Roster();

    // a map would be better...
    std::vector<Student*> class_roster_array;

    void add
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
    );

    void remove(std::string student_id);
    void print_all();
    void print_days_in_course(std::string student_id);
    void print_invalid_emails();
    void print_by_degree_program(int degree_program);

};
