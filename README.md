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

## Program Structure

The program consists of the following main components:

- **Main function**: Handles command-line arguments and execution flow  
- **Option parsing**: Processes flags given with `-o`  
- **File handling**: Opens and reads the file line by line  
- **Search logic**: Compares each line to the search string  
- **Output handling**: Formats output based on selected flags  

### Processing steps

```
Start
 ↓
Read command-line arguments
 ↓
Parse options (-o flags)
 ↓
IF file given:
    Open file
    FOR each line:
        Check match
        Apply options (i, l, o, r)
        Print result
ELSE:
    Run interactive mode
 ↓
End
```

---

## Build

Compile the program:

```
g++ main.cpp -o mygrep
```

The program compiles without errors or warnings.

---

## Usage

### Interactive mode

Run without arguments:

```
./mygrep
```

---

### File search

```
./mygrep <search> <filename>
```

Example:

```
./mygrep hello example.txt
```

---

### Using options

```
./mygrep -o<flags> <search> <filename>
```

### Available flags

- l → Show line numbers  
- o → Show total occurrence count  
- i → Case-insensitive search  
- r → Reverse search  

---

### Examples

```
./mygrep -ol hello example.txt
./mygrep -oi hello example.txt
./mygrep -or hello example.txt
./mygrep -oli hello example.txt
```

---

## Testing

The program was tested using the included `example.txt` file.

Example test:

```
./mygrep -oi hello example.txt
```

Output:

```
1: Hello world
4: hello again
6: HELLO uppercase
8: Another hello here
10: 123 hello 456

Occurrences of lines containing "hello": 5
```

The results match the expected output, confirming correct functionality.

---

## Learning

During this project, I learned how to handle command-line arguments in C++, process text files line by line, and implement flexible program behavior using flags. I also improved my understanding of string handling and debugging.

---

## Increments

Implemented increments:
- Increment 1  
- Increment 2  
- Increment 3  
- Increment 4  

Target grade: **5 points**

---

## AI Usage

AI tools were used to support understanding of certain concepts, assist with debugging, and improve the documentation. The program itself is implemented independently, and all code is written and understood by the author.
