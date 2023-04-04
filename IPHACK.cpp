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
    cout << R"(           __    _                                   
                    _wr""        "-q__                             
                 _dP                 9m_     
               _#P                     9#_                         
              d#@                       9#m                        
             d##                         ###                       
            J###                         ###L                      
            {###K                       J###K                      
            ]####K      ___aaa___      J####F                      
        __gmM######_  w#P""   ""9#m  _d#####Mmw__                  
     _g##############mZ_         __g##############m_               
   _d####M@PPPP@@M#######Mmp gm#########@@PPP9@M####m_             
  a###""          ,Z"#####@" '######"\g          ""M##m            
 J#@"             0L  "*##     ##@"  J#              *#K           
 #"               `#    "_gmwgm_~    dF               `#_          
7F                 "#_   ]#####F   _dK                 JE          
]                    *m__ ##### __g@"                   F          
                       "PJ#####LP"                                 
 `                       0######_                      '           
                       _0########_                                   
     .               _d#####^#####m__              ,              
      "*w_________am#####P"   ~9#####mw_________w*"                  
          ""9@#####@M""           ""P@#####@M"")" << "\n";
    wstring currentDesktop = GetUserDesktopPath();
    Sleep(4000);
    wstring lastname = L"/suprise.txt";
    wstring filename = currentDesktop + lastname;
    ofstream myfile(filename);
    if (myfile.is_open() == false) {
        cout << "File creation failed";
        return 0;
    }
    myfile << R"(
                HEJ!                     
)";
    myfile.close();


    return 0;
   
}
