#include "Game.h"
//#include <vector>
//#include <string>
//#include <iostream>
//#include <stdio.h>

using namespace std;

void tty_break()
{

}

int main()
{
    Game running;
    tty_break();
    running.begin_instance();

    while (true)
    {
        running.wait_for_input();
    }

    running.end_instance();
    return 0;
}
