#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "utility.h"

namespace utility
{

std::string to_string(const std::wstring& str)
{

    int len=WideCharToMultiByte(CP_ACP,0,str.c_str(),str.size(),NULL,0,NULL,NULL);
    char *buffer=new char[len+1];
    WideCharToMultiByte(CP_ACP,0,str.c_str(),str.size(),buffer,len,NULL,NULL);
    buffer[len]='\0';
    std::string result(std::move(buffer));
//    result.append(buffer);
//    delete []buffer;
    return result;
}

std::wstring to_wstring(const std::string& str)
{
    int len=MultiByteToWideChar(CP_ACP,0,str.c_str(),str.size(),NULL,0);
    TCHAR *buffer=new TCHAR[len+1];
    MultiByteToWideChar(CP_ACP,0,str.c_str(),str.size(),buffer,len);
    buffer[len]='\0';
    std::wstring result(std::move(buffer));
//    result.append(buffer);
//    delete []buffer;
    return result;

}
}


