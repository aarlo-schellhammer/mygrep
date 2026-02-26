#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Prototypes
int Interactive();
int FileSearch(string search, string filename);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        Interactive();
    }
    else if (argc == 3)
    {
        string search = argv[1];
        string filename = argv[2];
        FileSearch(search, filename);
    }
    else
    {
        cout << "Wrong usage, try: \n"
             << "mygrep.exe\n"
             << "mygrep.exe <search> <filename>";
    }
    return 0;
}

int Interactive()
{
    string source, search;

    cout << "Give a string from which to search for: ";
    getline(cin, source);

    cout << "Give a search string: ";
    getline(cin, search);

    auto pos = source.find(search);

    if (pos != string::npos)
    {
        cout << "\"" << search << "\"" << " was found in " << "\"" << source << "\"" << " in position " << pos;
    }
    else
    {
        cout << "\"" << search << "\"" << " was NOT found in " << "\"" << source << "\".";
    }
    return 0;
}

int FileSearch(string search, string filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "Could not open the file\n";
        return 1;
    }
    else
    {
        string line;
        while (getline(file, line))
        {
            if (line.find(search) != string::npos)
            {
                cout << line << endl;
            }
        }
        return 0;
    }
}