#include <iostream>
#include <vector>
#include <algorithm>
void addTask(std::vector<std::string>& tasks) {
    std::string task;
    std::cout << "Enter task: ";
    std::getline(std::cin, task);
    tasks.push_back(task);
}

void viewTasks(const std::vector<std::string>& tasks) {
    std::cout << "Task List:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << (i + 1) << ". " << tasks[i] << std::endl;
    }
}

void markTaskAsCompleted(std::vector<std::string>& tasks) {
    int taskIndex;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> taskIndex;
    std::cin.ignore();

    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
    } else {
        std::cout << "Invalid task number" << std::endl;
    }
}

void removeTask(std::vector<std::string>& tasks) {
    int taskIndex;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskIndex;
    std::cin.ignore();

    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
    } else {
        std::cout << "Invalid task number" << std::endl;
    }
}

int main() {
    std::vector<std::string> tasks;
    char choice;

    do {
        std::cout << "\n1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case '1':
                addTask(tasks);
                break;
            case '2':
                viewTasks(tasks);
                break;
            case '3':
                markTaskAsCompleted(tasks);
                break;
            case '4':
                removeTask(tasks);
                break;
            case '5':
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != '5');

    return 0;
}