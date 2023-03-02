//
// Created by ahmed-kashkoush on 2/25/23.
//
#include "macros.h"
class CommunityMemmber{};
class Employee{};
class Faculty: public Employee{};
class Adminstrator:public Faculty{};
class Teacher:public Faculty{};
class AdminstratorTeacher:public Adminstrator, public Teacher{};
class Staff:public Employee{};
class Student:public CommunityMemmber{};
class Alumns:public CommunityMemmber{};
int main(){
    judge();
    return 0;
}