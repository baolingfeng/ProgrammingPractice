#include <iostream>
#include <string.h>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

using namespace std;

std::string to_utf8(const wchar_t* buffer, int len)
{
    //assert(buffer != NULL);
    if(buffer == NULL)
    {
        return "";
    }
  
    int nLen = ::WideCharToMultiByte(CP_ACP, 0, buffer, -1, NULL, 0, NULL, NULL);  
    if (nLen == 0)   
    {  
        return "";  
    }  
    
        std::string newbuffer;
        newbuffer.resize(nLen) ;
    ::WideCharToMultiByte(CP_ACP, 0, buffer, -1, const_cast< char* >(newbuffer.c_str()), nLen, NULL, NULL);  

    return newbuffer;
}

void trim(std::string& str)
{
    string::size_type pos = str.find_last_not_of(" \f\n\r\t\v");
    if(pos != string::npos) 
    {
        str.erase(pos + 1);
        pos = str.find_first_not_of(" \f\n\r\t\v");
        if(pos != string::npos) 
        {
            str.erase(0, pos);
        }
    }
    else 
    {
        str.erase(str.begin(), str.end());
    }
}

int main(int argc, char const *argv[])
{
   wchar_t s[] = _T("abcdefg");

    return 0;
}