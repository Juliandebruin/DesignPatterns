#include "UserInterface.h"

void checkForLeaks() 
{
    #ifdef _DEBUG
        int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
        flag |= _CRTDBG_LEAK_CHECK_DF;
        _CrtSetDbgFlag(flag);
    #endif
}

int main() 
{
    checkForLeaks();

    UserInterface userinterface;
    userinterface.start_interface();

    return 0;
}