#include <iostream>
#include <string>

class StudentManager {
private:
    std::string students[100]; // Fixed size array
    int count;

public:
    StudentManager() {
        count = 0;
    }

    void addStudent(std::string name) {
        if (count < 100) {
            students[count] = name;
            count++;
        }
    }

    bool deleteStudent(std::string name) {
        for (int i = 0; i < count; i++) {
            if (students[i] == name) {
                // Shift remaining students left
                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }
                count--;
                return true;
            }
        }
        return false;
    }

    void displayStudents() {
        std::cout << "Student List:\n";
        for (int i = 0; i < count; i++) {
            std::cout << "- " << students[i] << "\n";
        }
    }

    int getCount() {
        return count;
    }

    std::string getStudent(int index) {
        if (index >= 0 && index < count)
            return students[index];
        else
            return "";
    }

    void clear() {
        count = 0;
    }
};
int main() {
    StudentManager manager;

    manager.addStudent("Alice");
    manager.addStudent("Bob");
    manager.addStudent("Charlie");

    std::cout << "Before deletion:\n";
    manager.displayStudents();

    manager.deleteStudent("Bob");

    std::cout << "\nAfter deleting 'Bob':\n";
    manager.displayStudents();

    return 0;
}

