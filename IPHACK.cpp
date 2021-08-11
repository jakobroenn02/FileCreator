#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <ShlObj.h>
using namespace std;
wstring GetUserDesktopPath()
{
    PWSTR path = NULL;
    HRESULT result = SHGetKnownFolderPath(FOLDERID_Desktop, 0, NULL, &path);
    if (SUCCEEDED(result)) {
        wprintf_s(L"Path:  %ls\n", path);
    }
    
    
    
    return path;
}
int main()
{   
    wstring currentDesktop = GetUserDesktopPath();
    Sleep(4000);
    ofstream myfile(currentDesktop);
    if (myfile.is_open() == false) {
        cout << "File creation failed";
        return 0;
    }
    myfile << "I like cake";
    myfile.close();


    return 0;
   
}