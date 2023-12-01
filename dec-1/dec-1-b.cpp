#include <iostream>
#include <unordered_map>
using namespace std;

int main (int argc, char* argv[]) {
    unordered_map<string, int> dic;
    dic.insert({"one", 1});
    dic.insert({"two", 2});
    dic.insert({"three", 3});
    dic.insert({"four", 4});
    dic.insert({"five", 5});
    dic.insert({"six", 6});
    dic.insert({"seven", 7});
    dic.insert({"eight", 8});
    dic.insert({"nine", 9});

    string ln;
    uint32_t sum = 0;

    while (getline(cin, ln)) {
        int n1, n2;

        for (size_t i = 0; i < ln.size(); i++) {
            int val = ln[i] - '0';
            if (val < 10 && val > 0) {
                n1 = val;
                break;
            }

            if (i > 1) {
                auto lookup = dic.find(ln.substr(i - 2, 3));
                if (lookup != dic.end()) {
                    n1 = lookup->second;
                    break;
                }
            }

            if (i > 2) {
                auto lookup = dic.find(ln.substr(i - 3, 4));
                if (lookup != dic.end()) {
                    n1 = lookup->second;
                    break;
                }
            } 

            if (i > 3) {
                auto lookup = dic.find(ln.substr(i - 4, 5));
                if (lookup != dic.end()) {
                    n1 = lookup->second;
                    break;
                }
            }
        }

        for (int i = ln.size() - 1; i >= 0; i--) {
            int val = ln[i] - '0';
            if (val < 10 && val > 0) {
                n2 = val;
                break;
            } 

            if (i < ln.size() - 2) {
                auto lookup = dic.find(ln.substr(i, 3));
                if (lookup != dic.end()) {
                    n2 = lookup->second;
                    break;
                }
            }

            if (i < ln.size() - 3) {
                auto lookup = dic.find(ln.substr(i, 4));
                if (lookup != dic.end()) {
                    n2 = lookup->second;
                    break;
                }
            }

            if (i < ln.size() - 4) {
                auto lookup = dic.find(ln.substr(i, 5));
                if (lookup != dic.end()) {
                    n2 = lookup->second;
                    break;
                }
            }
        }

        sum += (n1 * 10 + n2);
    }

    cout << "Part 2: " << sum << "\n";

    return 0;
}