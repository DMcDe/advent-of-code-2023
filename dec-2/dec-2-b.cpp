#include <iostream>
#include <sstream>
using namespace std;

int main (int argc, char* argv[]) {
    string ln;
    uint32_t sum = 0;

    while (getline(cin, ln)) {
        string junk, color;
        int32_t id, num;
        stringstream ss(ln);
        int32_t min_red = -1;
        int32_t min_blue = -1;
        int32_t min_green = -1;
        ss >> junk >> id >> junk;
        while (ss >> num >> color) {
            if (color.substr(0, color.size() - 1) == "blue" || color == "blue") {
                if (num > min_blue) min_blue = num;
            } else if (color.substr(0, color.size() - 1) == "red" || color == "red") {
                if (num > min_red) min_red = num;
            } else if (color.substr(0, color.size() - 1) == "green" || color == "green") {
                if (num > min_green) min_green = num;
            }
        }

        sum += (min_blue * min_green * min_red);
    }

    cout << "Part 2 solution: " << sum << "\n";

    return 0;
}