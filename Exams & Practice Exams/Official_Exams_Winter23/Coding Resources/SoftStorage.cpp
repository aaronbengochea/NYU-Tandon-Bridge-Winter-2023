#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Software {
private:
    string name;
    string serial_number;
    int num_licenses;
    vector<string> machines;

public:
    Software(const string& name, const string& serial_number, int num_licenses)
        : name(name), serial_number(serial_number), num_licenses(num_licenses) {}

    void operator+=(const string& machine) {
        machines.push_back(machine);
    }

    bool matches(const string& name, const string& serial_number) const {
        return this->name == name && this->serial_number == serial_number;
    }

    bool inCompliance() const {
        return machines.size() <= num_licenses;
    }

    string getName() const {
        return name;
    }

    string getSerialNumber() const {
        return serial_number;
    }

    int getNumLicenses() const {
        return num_licenses;
    }

    vector<string> getMachines() const {
        return machines;
    }
};

void readData(const string& file_name, vector<Software>& software_list) {
    ifstream file(file_name);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string name, serial_number, machine_name;
            if (iss >> name >> serial_number >> machine_name) {
                bool found = false;
                for (Software& software : software_list) {
                    if (software.matches(name, serial_number)) {
                        software += machine_name;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    Software new_software(name, serial_number, 0);
                    new_software += machine_name;
                    software_list.push_back(new_software);
                }
            }
        }
        file.close();
    }
}

int main() {
    vector<Software> software_list;

    readData("file.txt", software_list);

    // Example usage: Print software information and compliance status
    for (const Software& software : software_list) {
        cout << "Product Name: " << software.getName() << "\n";
        cout << "Serial Number: " << software.getSerialNumber() << "\n";
        cout << "Number of Licenses: " << software.getNumLicenses() << "\n";
        cout << "Installed Machines: ";
        for (const string& machine : software.getMachines()) {
            cout << machine << ", ";
        }
        cout << "\nCompliance Status: " << (software.inCompliance() ? "In Compliance" : "Not in Compliance") << "\n\n";
    }

    return 0;
}

