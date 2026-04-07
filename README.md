# Simple Code Complexity Checker

## Overview

This project is a basic C++ tool that analyzes source code and estimates its time complexity based on loop detection. It scans the code line by line, identifies loops (`for`, `while`), and determines the maximum nesting depth to approximate complexity.

---

## Features

* Detects `for` and `while` loops
* Calculates loop nesting depth
* Estimates time complexity:

  * No loops → O(1)
  * One loop → O(n)
  * Nested loops → O(n^k)
* Uses simple string parsing techniques

---

## How It Works

1. Takes input: number of lines of code
2. Reads code line by line
3. Trims extra spaces from each line
4. Detects loops using keyword search
5. Tracks nesting using braces `{}`
6. Outputs estimated time complexity

---

## Input Example

```
5
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout << i << j;
    }
}
```

---

## Output Example

```
Estimated Time Complexity: O(n^2)
Max Loop Nesting Depth: 2
```

---

## Compilation and Execution

### Compile

```
g++ complexity_checker.cpp -o checker
```

### Run

```
./checker
```

---

## Limitations

* Does not detect logarithmic complexity (O(log n))
* Does not handle recursion
* Assumes all loops run n times
* Basic estimation, not fully accurate

---

## Future Improvements

* Detect logarithmic patterns
* Add recursion analysis
* Improve parsing (ignore comments/strings)
* Build a graphical or web interface

---

## Use Cases

* Learning time complexity
* Beginner-level code analysis projects

---
