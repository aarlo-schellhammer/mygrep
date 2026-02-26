# mygrep

**mygrep** is a simplified C++ implementation of the Linux grep tool, developed as part of a project for the *Advanced C++ Programming* course.

It allows users to search for text within files using various command-line options such as case-insensitive matching, line numbering, occurrence counting, and reverse search.

---

## Features

- Search for a string inside a file  
- Case-insensitive search (i)  
- Show line numbers (l)  
- Count matching lines (o)  
- Reverse search (show lines NOT containing the string) (r)  
- Interactive mode when no arguments are provided  

---

## Build

Compile the program:

    g++ mygrep.cpp -o mygrep

---

## Usage

### Interactive mode

Run without arguments:

    ./mygrep

You will be prompted to enter:
- Source string  
- Search string  

---

### File search

Search for a string inside a file:

    ./mygrep <search> <filename>

Example:

    ./mygrep hello example.txt

---

### Using options

All options must start with -o followed by one or more flags:

    ./mygrep -o<flags> <search> <filename>

### Available flags

- l → Show line numbers  
- o → Show total occurrence count  
- i → Case-insensitive search  
- r → Reverse search (lines NOT containing the string)  

---

### Examples

    ./mygrep -ol hello example.txt
    ./mygrep -oi hello example.txt
    ./mygrep -or hello example.txt
    ./mygrep -oli hello example.txt

---

## Test File

An example file (`example.txt`) is included in the repository for quick testing.

Try:

    ./mygrep -oi hello example.txt

---

## Example Output

    1: Hello world
    4: hello again
    6: HELLO uppercase
    8: Another hello here
    10: 123 hello 456

    Occurrences of lines containing "hello": 5

---

## AI Usage

AI tools were used to improve documentation and assist with debugging. The program itself is implemented independently, and all code is written and understood by me :O
