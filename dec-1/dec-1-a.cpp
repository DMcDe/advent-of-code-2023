#include <iostream>
#include <unordered_map>
using namespace std;

int main (int argc, char* argv[]) {
    string temp;
    int sum = 0;
    int j1 = -1;
    int j2 = -1;

    while (getline(cin, temp)) {
        bool found1 = false;
        for (auto ch : temp) {
            if (ch - '0' < 10 && ch - '0' > 0) {
                !found1 ? j1 = (ch - '0') : j2 = (ch = '0');
                found1 = true;
            }
        }
        if (j2 = -1) j2 = j1;
        int res = j1 * 10 + j2;
        sum += res;
    }

    cout << "Part 1: " << sum << "\n";

    return 0;
}