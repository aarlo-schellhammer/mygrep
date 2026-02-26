#include <iostream>
#include <string>

using namespace std;

int main()
{
    string source;
    string search;

    cout << "Give string from which to search for: ";
    getline(cin, source);

    cout << "Give search string: ";
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