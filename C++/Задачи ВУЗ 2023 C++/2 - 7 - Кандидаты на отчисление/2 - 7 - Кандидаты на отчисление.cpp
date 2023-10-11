#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

struct Course {
    std::string name;
    int semester;
    bool finished;
};

struct Student {
    std::string name;
    std::string group;
    std::vector<Course> courses;
};

#include <sstream>

Student make_student(std::string line) {
    Student student;

    std::vector<std::string> w;
    std::stringstream s(line);


    std::string subline;
    while (getline(s, subline, ';')) {
        w.push_back(subline);
    }

    student.name = w[0]; w.erase(w.begin());
    student.group = w[0]; w.erase(w.begin());

    Course empty;
    std::fill_n(std::back_inserter(student.courses), w.size() / 3, empty);
    for (int i = 0; i < w.size(); i++) {
        switch (i % 3) {
        case 0:
            student.courses[(int)(i / 3)].name = w[i];
            break;
        case 1:
            student.courses[(int)(i / 3)].semester = std::stoi(w[i]);
            break;
        case 2:
            student.courses[(int)(i / 3)].finished = w[i] == "1" ? true : false;
            break;
        }
    }

    return student;
}

bool is_upper(Student x, Student y) {
    if (x.group < y.group) {
        return true;
    }
    else if (x.group == y.group) {
        return x.name < y.name;
    }
    return false;
}

bool is_debtor(Student x, int cur_semester, int max_debt) {
    int debt = 0;
    for (auto& c : x.courses) {
        if ((c.semester < cur_semester) && !c.finished) {
            debt += 1;
        }
    }
    return debt > max_debt;
}

void print(std::vector<Student> students) {
    if (students.size() == 0) {
        std::cout << "Empty list!" << std::endl;
        return;
    }

    std::string prev = "";
    for (auto& s : students) {
        if (s.group != prev) {
            prev = s.group;
            std::cout << s.group << std::endl;
        }
        std::cout << "- " << s.name << std::endl;
    }
}

int main()
{
    int cur_semester, max_debt, stud_count;
    std::cin >> stud_count >> cur_semester >> max_debt;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline

    std::vector<Student> students(stud_count);
    for (auto& student : students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }

    std::vector<Student> expulsion_candidates;
    std::copy_if(students.begin(),
        students.end(),
        std::back_inserter(expulsion_candidates),
        [cur_semester, max_debt](const Student& student) {
            return is_debtor(student, cur_semester, max_debt);
        });

    std::sort(expulsion_candidates.begin(), expulsion_candidates.end(), is_upper);
    print(expulsion_candidates);
}