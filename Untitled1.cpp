#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

#ifdef _WIN32
// For Windows platform
void listRunningTasks() {
    system("tasklist");
}

void closeTask(int pid) {
    string command = "taskkill /PID " + to_string(pid);
    system(command.c_str());
}

#elif __linux__ || __APPLE__
// For Unix-like systems
void listRunningTasks() {
    system("ps -e");
}

void closeTask(int pid) {
    string command = "kill " + to_string(pid);
    system(command.c_str());
}

#endif

int main() {
    while (true) {
        cout << "\n=== Running Processes ===\n";
        listRunningTasks();

        int pid;
        cout << "Enter the PID of the process to terminate (or -1 to exit): ";
        cin >> pid;

        if (pid == -1) {
            cout << "Exiting program." << endl;
            break;
        }

        closeTask(pid);
        cout << "Process with PID " << pid << " has been terminated." << endl;
    }

    return 0;
}

