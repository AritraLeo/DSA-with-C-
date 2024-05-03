/*
Initial working approach - 

class Solution {
public:
    int compareVersion(string version1, string version2) {
        // convert each revision to ignored zeros
        // check for each revision > / < return accordingly
        // v1 -> 01.10     |    v2 -> 1.101.001
        int n1 = version1.length();
        int n2 = version2.length();
        int l1 = 0, l2 = 0, r1 = 0, r2 = 0, c = 0;
        bool f1 = false, f2 = false;
        while (c < min(n1, n2)) {
            for (int i = 0; i < n1; i++) {
                if (i == n1 - 1){
                    f1 = true;
                    break;
                }
                if (version1[i] == '.' || i == n1 - 1) {
                    l2 = i;
                    break;
                }
            }

            for (int j = 0; j < n1; j++) {
                if (j == n2 - 1){
                    f2 = true;
                    break;
                }
                if (version1[j] == '.' || j == n2 - 1) {
                    r2 = j;
                    break;
                }
            }

            if (l2 != 0 && r2 != 0) {
                if (compareStrRemovingZeros(version1.substr(l1, l2),
                                            version2.substr(r1, r2)) == 0) {
                    l1 = l2;
                    l2 = 0;
                    r1 = r2;
                    r2 = 0;
                } else
                    return compareStrRemovingZeros(version1.substr(l1, l2),
                                                   version2.substr(r1, r2));
            } else if (f1 || f2) {
                cout << "In else if" << endl;
                if (n1 > n2) {
                    if (compareStrRemovingZeros(version1.substr(l1, l2), "0") ==
                        0) {
                        l1 = l2;
                        l2 = 0;
                cout << "In else if if if" << endl;
                    } else {
                        return compareStrRemovingZeros(version1.substr(l1, l2),
                                                       "0");
                    }
                } else {
                    if (compareStrRemovingZeros("0", version2.substr(r1, r2)) == 0) {
                            r1 = r2;
                            r2 = 0;
                cout << "In else if else if" << endl;

                        }
                    else {
                        return compareStrRemovingZeros("0",
                                                       version2.substr(r1, r2));
                    }
                }
            }
            c++;
        }
        return 0;
    }

public:
    int compareStrRemovingZeros(string v1, string v2) {
        int i = 0;
        while (v1[i] == '0') {
            v1 = v1.substr(1);
            i++;
        }
        int j = 0;
        while (v2[j] == '0') {
            v2 = v2.substr(1);
            j++;
        }
        // if (stoi(v1) == stoi(v2))
        //     return 0;

        // return stoi(v1) < stoi(v2) ? -1 : 1;

        return v1.compare(v2);
    }
};
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        // Initialize two pointers to traverse the versions
        int i = 0, j = 0;

        // Continue until both versions have been traversed
        while (i < version1.size() || j < version2.size()) {
            // Initialize variables to store the version numbers
            unsigned long v1 = 0, v2 = 0;

            // Extract the version number from version1
            while (i < version1.size() && version1[i] != '.') {
                v1 = v1 * 10 + (version1[i] - '0');
                i++;
            }

            // Extract the version number from version2
            while (j < version2.size() && version2[j] != '.') {
                v2 = v2 * 10 + (version2[j] - '0');
                j++;
            }

            // Compare the version numbers
            if (v1 > v2) return 1;
            if (v1 < v2) return -1;

            // Skip the dot character
            i++;
            j++;
        }
        
        // Both versions are equal
        return 0;
    }
};

int main() {
    Solution solution;

    // Test cases
    string version1 = "1.0";
    string version2 = "1.0.0";
    cout << "Test Case 1: " << solution.compareVersion(version1, version2) << endl; // Output: 0

    version1 = "1.2";
    version2 = "1.10";
    cout << "Test Case 2: " << solution.compareVersion(version1, version2) << endl; // Output: -1

    version1 = "7.5.2.4";
    version2 = "7.5.3";
    cout << "Test Case 3: " << solution.compareVersion(version1, version2) << endl; // Output: -1

    return 0;
}
