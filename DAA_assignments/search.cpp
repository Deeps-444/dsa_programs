#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student
{
    int prn;
    string name;
    string class_name;
    string phNo;
    int marks;
};

// parsing the line
Student parseLine(const string &line)
{
    Student s;
    stringstream ss(line);
    string temp;
    getline(ss, temp, ',');
    s.prn = stoi(temp);
    getline(ss, s.name, ',');
    getline(ss, s.class_name, ',');
    getline(ss, s.phNo, ',');
    getline(ss, temp, ',');
    s.marks = stoi(temp);
    return s;
}

// loading the data from file
vector<Student> loadData(const string &filename)
{
    ifstream file(filename);
    vector<Student> data;
    string line;
    while (getline(file, line))
    {
        if (!line.empty())
        {
            data.push_back(parseLine(line));
        }
    }
    return data;
}
void displayData(const vector<Student> &students)
{
    cout << "\n--- Displaying Student Records ---\n";
    for (const auto &s : students)
    {
        cout << "PRN: " << s.prn
             << ", Name: " << s.name
             << ", Class: " << s.class_name
             << ", Phone: " << s.phNo
             << ", Marks: " << s.marks << endl;
    }
}

int main()
{
    string filename = "class_data.txt"; // make sure your file exists in the same folder

    vector<Student> students = loadData(filename);

    if (students.empty())
        cout << "No data found or file not loaded properly.\n";
    else
        displayData(students);

    return 0;
}