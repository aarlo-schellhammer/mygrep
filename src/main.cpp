#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Struct to hold search options
struct SearchOptions
{
    bool showLineNumbers;
    bool showOccurrenceCount;
};

// Prototypes
int Interactive();
int FileSearch(const string &search, const string &filename, SearchOptions options);
SearchOptions ParseOptions(const string &options);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        return Interactive();
    }
    else if (argc == 3)
    {
        string search = argv[1];
        string filename = argv[2];

        SearchOptions opts{false, false}; // no options
        return FileSearch(search, filename, opts);
    }
    else if (argc == 4)
    {
        string optStr = argv[1];
        string search = argv[2];
        string filename = argv[3];

        SearchOptions opts = ParseOptions(optStr);
        return FileSearch(search, filename, opts);
    }
    else
    {
        cout << "Wrong usage, try:\n"
             << "mygrep.exe\n"
             << "mygrep.exe <search> <filename>\n"
             << "mygrep.exe -o[lo] <search> <filename>\n";
        return 1;
    }
}

int Interactive()
{
    string source, search;

    cout << "Give a string from which to search for: ";
    getline(cin, source);

    cout << "Give search string: ";
    getline(cin, search);

    auto pos = source.find(search);

    if (pos != string::npos)
    {
        cout << "\"" << search << "\" found in \"" << source
             << "\" in position " << pos << endl;
    }
    else
    {
        cout << "\"" << search << "\" not found in \"" << source << "\"" << endl;
    }
    return 0;
}

int FileSearch(const string &search, const string &filename, SearchOptions options)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "Could not open the file \"" << filename << "\"\n";
        return 1;
    }

    string line;
    int lineNumber = 0;
    int count = 0;

    while (getline(file, line))
    {
        lineNumber++;

        if (line.find(search) != string::npos)
        {
            count++;

            if (options.showLineNumbers)
            {
                cout << lineNumber << ": ";
            }

            cout << line << endl;
        }
    }

    if (options.showOccurrenceCount)
    {
        cout << "Occurrences of lines containing \"" << search << "\": " << count << endl;
    }

    return 0;
}

SearchOptions ParseOptions(const string &options)
{
    SearchOptions opts{false, false};

    for (auto i = 2; i < options.length(); i++)
    {
        if (options[i] == 'l')
        {
            opts.showLineNumbers = true;
        }
        else if (options[i] == 'o')
        {
            opts.showOccurrenceCount = true;
        }
    }
    return opts;
}