/**
 *    author:  HONG-LOU
 *    created: 2023-03-16 14:19:52
**/
#include <bits/stdc++.h>

class Course {
private:
  std::string id;
  std::string name;
  std::string nature;
  double credit_hours;
  double lecture_hours;
  double lab_hours;
  double credits;
  std::string course_term;
public:
  Course(std::string id, std::string name, std::string nature, 
  double credit_hours, double lecture_hours, double lab_hours,
  double credits, std::string course_term):
  id(id), name(name), nature(nature), credit_hours(credit_hours), 
  lecture_hours(lecture_hours), 
  lab_hours(lab_hours), credits(credits), course_term(course_term) {};
  Course():id(), name() {
    id = "none";
    name = "none";
    nature = "";
    credit_hours = 0;
    lecture_hours = 0;
    lab_hours = 0;
    credits = 0;
    course_term = "";
  }
  std::string get_id() {
    return id;
  };
  std::string get_name() {
    return name;
  }
  std::string get_nature() {
    return nature;
  }
  double get_credit_hours() {
    return credit_hours;
  }
  double get_lecture_hours() {
    return lecture_hours;
  }
  double get_lab_hours() {
    return lab_hours;
  }
  double get_credits() {
    return credits;
  }
  std::string get_course_term() {
    return course_term;
  }
  ~Course();
};