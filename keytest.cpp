#include <time.h>
#include <iostream>
#include "keyboard.h"

int main(){
    SetKb();
    std::string lastDown = "";
    double lag = 0;
	double previous = clock();
    int ms_per_update = 250;
    int ctr = 0;
    while (1 ==1) {
        if (TrueKeyState(KEY_ESC)){
            break;
        }
        clock_t current = clock();
        double elapsed = current-previous;
        if (elapsed == 0){
            continue;
        }
        previous = current;
        lag += (elapsed / (double)CLOCKS_PER_SEC)*1000.0;

        if (lag > ms_per_update){
            lastDown = "";
            if (TrueKeyState(KEY_LEFT_ARROW)){
                lastDown += " LEFT";
            }
            if (TrueKeyState(KEY_RIGHT_ARROW)){
                lastDown += " RIGHT";
            }
            if (TrueKeyState(KEY_DOWN_ARROW)){
                lastDown += " DOWN";
            }
            if (TrueKeyState(KEY_UP_ARROW)){
                lastDown += " UP";
            }
            ScreenClear();
            ScreenSetCursor(2,1);
            std::cout << "KEYBOARD DRIVER - TrueKeyState TEST" << std::endl;
            std::cout << "Hold arrow keys in any combination to show currently pressed keys." << std::endl;
            std::cout << lag << " " << ctr << " " << lastDown << std::endl;
            lag -= ms_per_update;
            ctr++;
        }
    };
    ResetKb();
	return 0;
}
