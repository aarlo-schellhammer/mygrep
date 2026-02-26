#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;

// Struct for search options
struct SearchOptions
{
    bool showLineNumbers;     // 'l' flag
    bool showOccurrenceCount; // 'o' flag
    bool caseInsensitive;     // 'i' flag
    bool reverseSearch;       // 'r' flag
};

// Prototypes
int Interactive();
int FileSearch(const string &search, const string &filename, SearchOptions options);
void PrintUsage();
SearchOptions ParseOptions(const string &options);

int main(int argc, char **argv)
{
    try
    {
        // No arguments = interactive mode
        if (argc == 1)
        {
            return Interactive();
        }
        // 2 arguments = simple file search
        else if (argc == 3)
        {
            string search = argv[1];
            string filename = argv[2];

            SearchOptions opts{false, false, false, false}; // no options
            return FileSearch(search, filename, opts);
        }
        // 3 arguments = options + file search
        else if (argc == 4)
        {
            string optStr = argv[1];
            string search = argv[2];
            string filename = argv[3];

            // Validate that options starts with "-o"
            if (optStr.size() < 2 || optStr[0] != '-' || optStr[1] != 'o')
            {
                PrintUsage();
                return 1;
            }

            // Parse flags to SearchOption Struct
            SearchOptions opts = ParseOptions(optStr);
            return FileSearch(search, filename, opts);
        }
        else
        {
            // If invalid number of arguments
            PrintUsage();
            return 1;
        }
    }
    catch (const exception &e)
    {
        // Exception handling
        cout << "Exception Nr. -1" << endl;
        cout << e.what() << endl;
        return -1;
    }
    return 0;
}

// Interactive mode (user inputs source and search manually)
int Interactive()
{
    string source, search;

    cout << "Give a string from which to search for: ";
    getline(cin, source);

    cout << "Give search string: ";
    getline(cin, search);

    auto pos = source.find(search);

    // Finds position inside source
    if (pos != string::npos)
    {
        cout << "\"" << search << "\" found in \"" << source
             << "\" in position " << pos << endl;
    }
    else
    {
        cout << "\"" << search << "\" NOT found in \"" << source << "\"" << endl;
    }
    return 0;
}

// Performs file search based on given flags/options
int FileSearch(const string &search, const string &filename, SearchOptions options)
{
    ifstream file(filename);

    // Throw exception if unable to open file
    if (!file)
    {
        throw runtime_error("Could not open the file \"" + filename + "\".");
    }

    string searchToCheck = search;
    // Convert search to lowercase if 'i' flag is used
    if (options.caseInsensitive)
    {
        transform(searchToCheck.begin(), searchToCheck.end(), searchToCheck.begin(),
                  [](unsigned char c)
                  { return static_cast<char>(tolower(c)); });
    }

    string line;
    int lineNumber = 0;
    int count = 0;

    // Read file line by line
    while (getline(file, line))
    {
        lineNumber++;

        string lineToCheck = line;

        // Convert line to lowercase if 'i' flag is used
        if (options.caseInsensitive)
        {
            transform(lineToCheck.begin(), lineToCheck.end(), lineToCheck.begin(),
                      [](unsigned char c)
                      { return static_cast<char>(tolower(c)); });
        }

        // Check if line contains search string
        bool match = (lineToCheck.find(searchToCheck) != string::npos);

        // Reverse result if 'r' flag is used
        if (options.reverseSearch)
        {
            match = !match;
        }

        // If line matches print it
        if (match)
        {
            count++;

            // Print line numbers if 'l' flag is used
            if (options.showLineNumbers)
            {
                cout << lineNumber << ": ";
            }

            cout << line << endl;
        }
    }
    // If no matches found for search string
    if (count == 0 && !options.showOccurrenceCount)
    {
        cout << "No matches found for \"" << search << "\"" << endl;
    }
    // Print total occurrence count if 'o' flag is used
    if (options.showOccurrenceCount)
    {
        // If reverse flag used change print to "NOT containing"
        if (options.reverseSearch)
        {
            cout << "Occurrences of lines NOT containing \"" << search << "\": " << count << endl;
        }
        else
        {
            cout << "Occurrences of lines containing \"" << search << "\": " << count << endl;
        }
    }

    return 0;
}

// Parses option string into SearchOptions struct
SearchOptions ParseOptions(const string &options)
{
    // All options false by default
    SearchOptions opts{false, false, false, false};

    // Starts from index 2 to skip "-o"
    for (size_t i = 2; i < options.length(); i++)
    {
        switch (options[i])
        {
        case 'l':
            opts.showLineNumbers = true;
            break;
        case 'o':
            opts.showOccurrenceCount = true;
            break;
        case 'i':
            opts.caseInsensitive = true;
            break;
        case 'r':
            opts.reverseSearch = true;
            break;
        default:
            // If unknown flag throw exception
            throw runtime_error(string("Option not recognized: '") + options[i] + "'");
        }
    }
    return opts;
}

// Prints instructions if user input is invalid
void PrintUsage()
{
    cout << "Wrong usage, try:\n"
         << "mygrep.exe\n"
         << "mygrep.exe <search> <filename>\n"
         << "mygrep.exe -o<flags> <search> <filename>\n"
         << "flags: l (line numbers), o (count), i (ignore case), r (reverse)\n";
}