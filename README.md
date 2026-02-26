# mygrep

**mygrep** is a simplified C++ implementation of the Linux `grep` tool, developed as part of a project for the *Advanced C++ Programming* course.

It allows users to search for text within files using various command-line options such as case-insensitive matching, line numbering, occurrence counting, and reverse search.

---

## Features

- Search for a string inside a file  
- Case-insensitive search (`i`)  
- Show line numbers (`l`)  
- Count matching lines (`o`)  
- Reverse search (show lines NOT containing the string) (`r`)  
- Interactive mode when no arguments are provided  

---

## Usage

### Interactive mode

Run the program without arguments:

```bash
g++ mygrep.cpp -o mygrep
