#include <iostream>
using namespace std;

int main() {
    string tasks[100];
    bool completed[100];
    int count = 0;
    int choice;

    do {
        cout << "\n--- TO DO LIST ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore();
            cout << "Enter task: ";
            getline(cin, tasks[count]);
            completed[count] = false;
            count++;
            cout << "Task added!\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "No tasks available.\n";
            } else {
                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". " << tasks[i];
                    if (completed[i])
                        cout << " [Completed]\n";
                    else
                        cout << " [Pending]\n";
                }
            }
        }

        else if (choice == 3) {
            int num;
            cout << "Enter task number to mark completed: ";
            cin >> num;

            if (num >= 1 && num <= count) {
                completed[num - 1] = true;
                cout << "Task marked as completed.\n";
            } else {
                cout << "Invalid task number.\n";
            }
        }

        else if (choice == 4) {
            int num;
            cout << "Enter task number to remove: ";
            cin >> num;

            if (num >= 1 && num <= count) {
                for (int i = num - 1; i < count - 1; i++) {
                    tasks[i] = tasks[i + 1];
                    completed[i] = completed[i + 1];
                }
                count--;
                cout << "Task removed.\n";
            } else {
                cout << "Invalid task number.\n";
            }
        }

        else if (choice == 5) {
            cout << "Exiting program.\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
