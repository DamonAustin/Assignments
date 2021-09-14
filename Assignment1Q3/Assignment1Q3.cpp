// Assignment1Q3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <iterator>
#include <string>
using namespace std;

struct dueDate {
    int month, day, year;
    // override the == operator
    friend bool operator==(dueDate a, dueDate b) {
        if (a.month = b.month && a.day == b.day && a.year == b.year) {
            return true;
        }
        else {
            return false;
        }
    }
    friend bool operator<(dueDate a, dueDate b) {
        if (a.year < b.year) {
            return true;
        }
        else if (a.month < b.month && a.year == b.year) {
            return true;
        }
        else if (a.day < b.month && a.month == b.month && a.year == b.year) {
            return true;
        }
        else {
            return false;
        }
    }
    
    string dateFormat() {
        return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    }
};

class Assignment {
    friend bool operator==(Assignment a1, Assignment a2) {
        if (a1.name == a2.name && a1.ddate == a2.ddate) {
            return true;
        }
        else {
            return false;
        }
    }
public:
    Assignment(string nm, dueDate dd) : name(nm), ddate(dd){}
    void set_assignment(string nm, dueDate dd) {
        name = nm;
        ddate = dd;
    }

    string get_name() {
        return name;
    }

    dueDate get_dueDate() {
        return ddate;
    }

private:
    /*Assignment Name*/
    string name;
    /*Assignment Due Date*/
    dueDate ddate;
};

class Assignments {
    public:
        /*Adds an assginment to the list*/
        void add_assignment(Assignment AA1) {
            listOfAssignments.push_back(AA1);
        }

        /*Removes an assignment to the list*/
        void remove_assignment(Assignment AA1) {
            for (auto it = listOfAssignments.begin(); it != listOfAssignments.end(); it++) {
                if ((*it) == AA1) {
                    listOfAssignments.remove(*it);
                    break;
                }
            }
        }

        /*Print assignments based on when they were assigned*/
        void print_assignments() {
            for (auto it = listOfAssignments.begin(); it != listOfAssignments.end(); it++) {
                cout << (*it).get_name() << "; Due on: " << (*it).get_dueDate().dateFormat() << endl;
            }
        }

        /*Finds the assignment with the closest due date and returns it*/
        Assignment closeDueDate() {
            Assignment nearDue("Test", dueDate{ 99,99,9999 });
            for (auto it = listOfAssignments.begin(); it != listOfAssignments.end(); it++) {
                if ((*it).get_dueDate() < nearDue.get_dueDate()) {
                    nearDue = (*it);
                }
            }
            return nearDue;

        }
    private:
        list <Assignment> listOfAssignments;
};

int main()
{
    Assignments AAS;
    Assignment A1("303 Quiz 3", dueDate{ 9,13,2021 }), 
        A2("291 Homework 1", dueDate{ 9,14,2021 }), 
        A3("281R PartA 2.3", dueDate{ 9,14,2021 }), 
        A4("281R Homework 3", dueDate{ 9,16,2021 }), 
        A5("281R Quiz 3", dueDate{ 9,16,2021 });
    AAS.add_assignment(A1), AAS.add_assignment(A2), AAS.add_assignment(A3), AAS.add_assignment(A4), AAS.add_assignment(A5);
    AAS.print_assignments();
    
    Assignment nearstDueDate = AAS.closeDueDate();
    cout << " This closest assignment due is " << nearstDueDate.get_name() << " due on " << nearstDueDate.get_dueDate().dateFormat();
    AAS.remove_assignment(nearstDueDate);
    nearstDueDate = AAS.closeDueDate();
    cout << " This closest assignment due is " << nearstDueDate.get_name() << " due on " << nearstDueDate.get_dueDate().dateFormat();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
