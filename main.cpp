#include <bits/stdc++.h>
using namespace std;

// Function to trim spaces
string trim(const string &str) {
    int start = 0, end = str.size() - 1;
    while (start <= end && isspace(str[start])) start++;
    while (end >= start && isspace(str[end])) end--;
    return (start > end) ? "" : str.substr(start, end - start + 1);
}

int main() {
    cout << "Enter number of lines of code: ";
    int n;
    cin >> n;
    cin.ignore();

    vector<string> code(n);
    cout << "Enter your C++ code:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, code[i]);
    }

    int currentDepth = 0;
    int maxDepth = 0;

    for (int i = 0; i < n; i++) {
        string line = trim(code[i]);

        // Check for loop keywords
        if (line.find("for") != string::npos || 
            line.find("while") != string::npos) {
            currentDepth++;
            maxDepth = max(maxDepth, currentDepth);
        }

        // Reduce depth when block ends
        if (line.find("}") != string::npos) {
            if (currentDepth > 0)
                currentDepth--;
        }
    }

    cout << "\nEstimated Time Complexity: ";

    if (maxDepth == 0) {
        cout << "O(1) (No loops detected)\n";
    } else if (maxDepth == 1) {
        cout << "O(n)\n";
    } else {
        cout << "O(n^" << maxDepth << ")\n";
    }

    cout << "Max Loop Nesting Depth: " << maxDepth << endl;

    return 0;
}
