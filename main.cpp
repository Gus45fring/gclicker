#include<iostream>
#include<Windows.h>
#include<winuser.h>

int ms = 10;
bool started;
bool button; //false is left button, true is right button

DWORD MU;
DWORD MD;

int main() 
{
    while (true) 
    {
        if (GetAsyncKeyState(VK_F6) & 0x8000) (started = !started, Sleep(200));
        if (GetAsyncKeyState(VK_F4)) 
        {
            button = !button;
            Sleep(200);
            std::cout << (button ? "RButton" : "LButton") << "\r";
        }

        MU = button ? MOUSEEVENTF_RIGHTUP : MOUSEEVENTF_LEFTUP;
        MD = button ? MOUSEEVENTF_RIGHTDOWN : MOUSEEVENTF_LEFTDOWN;
        
        while (started) 
        {

            mouse_event(MD, 0, 0, 0, 0);
            Sleep(ms);
            mouse_event(MU, 0, 0, 0, 0);

            if (GetAsyncKeyState(VK_F6) & 0x8000) (started = !started, Sleep(200));
        }
        
    }
    return 0;
}