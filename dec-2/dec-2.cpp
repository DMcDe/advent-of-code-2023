#include <iostream>
#include <sstream>
using namespace std;

int main (int argc, char* argv[]) {
    string ln;
    uint32_t sum = 0;

    while (getline(cin, ln)) {
        string junk, color;
        uint32_t id, num;
        stringstream ss(ln);
        ss >> junk >> id >> junk;
        while (ss >> num >> color) {
            if (color.substr(0, color.size() - 1) == "blue" || color == "blue") {
                if (num > 14) id = 0;
            } else if (color.substr(0, color.size() - 1) == "red" || color == "red") {
                if (num > 12) id = 0;
            } else if (color.substr(0, color.size() - 1) == "green" || color == "green") {
                if (num > 13) id = 0;
            }
        }

        sum += id;
    }

    cout << "Part 1 solution: " << sum << "\n";
    return 0;
}