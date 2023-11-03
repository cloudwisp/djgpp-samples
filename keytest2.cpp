#include <time.h>
#include <iostream>
#include "keyboard.h"

int main(){
    SetKb();
    std::cout << "KEYBOARD DRIVER - KEYUP INFO - ASCII MAP TEST" << std::endl;
    std::cout << "This sample will echo the ASCII character for whatever keys are pressed" << std::endl;
    std::cout << "It respects shift states, caps lock and num lock." << std::endl;
    while (1 == 1) {
        
        if (!KeyUpWaiting()){
            continue;
        }
        auto keyUp = GetNextKeyUpCode();
        if (keyUp.ScanCode == KEY_ESC){
            break;
        }
        if (keyUp.AsciiCharacter == 0x0){
            continue;
        }
        std::cout << keyUp.AsciiCharacter << std::flush;
    };
    ResetKb();
	return 0;
}
