#include "Game.h"

WINDOW *plr_pos_win;

void Game::begin_instance()
{
    initscr(); // start screen
    cbreak();  // don't buffer
    keypad(stdscr, TRUE); // enable arrow & f keys
    curs_set(0); // make cursor invisbile

    current_area.name = "church/grass";
    current_area.set_map(areas_vec.at(0));
//    current_area.exits =

    nee.set_position(13,32);
    update_state();

    plr_pos_win = newwin(7, 16, 17, 80); // height, widht, line, column
    mvprintw(20, 80, "Use arrow keys"); // print at line 20, column 80
    mvprintw(21, 82, "to move"); // print below the last line
    box(plr_pos_win,0,0);
}

void Game::update_state()
{
    move(0,0); // ncurses function, not related to this class
    std::vector<std::vector<char>> map_copy;
    map_copy = current_area.get_map();
    map_copy.at(nee.x_pos).at(nee.y_pos) = 'X';
    for (auto &vec: map_copy)
    {
        for (auto c: vec)
        {
            printw("%c",c); // << flush;
        }
        printw("\n");
    }
//    move(0,0);
}

bool Game::move_player(int key) //    int key = getch();
{
    bool rtnVal{false};
    std::vector<std::vector<char>> map_copy = current_area.get_map();
    char tile;

    switch(key)
    {
    case KEY_LEFT:
        if (nee.y_pos >= 1) // && (!current_area.is_hard(tile)))
        {
            tile = map_copy.at(nee.x_pos).at(nee.y_pos-1);
            if (!current_area.is_hard(tile))
            {
                nee.y_pos--;
                rtnVal = true;
            }
        }
        break;
    case KEY_RIGHT:
        // tile = map_copy.at(nee.x_pos).at(nee.y_pos+1); // create exception here
        // if ((nee.y_pos <= 70) && (!current_area.is_hard(tile)))
        if (nee.y_pos <= 71)
        {
            tile = map_copy.at(nee.x_pos).at(nee.y_pos+1);
            if (!current_area.is_hard(tile))
            {
                nee.y_pos++;
                rtnVal = true;
            }
        }
        break;
    case KEY_UP:
        if (nee.x_pos >= 1)
        {
            tile = map_copy.at(nee.x_pos-1).at(nee.y_pos);
            if (!current_area.is_hard(tile))
            {
                nee.x_pos--;
                rtnVal = true;
            }
        }
        break;
    case KEY_DOWN:
        if (nee.x_pos <= 16)
        {
            tile = map_copy.at(nee.x_pos+1).at(nee.y_pos);
            if (!current_area.is_hard(tile))
            {
                nee.x_pos++;
                rtnVal = true;
            }
        }
        break;
    }
    return rtnVal;
}

void Game::wait(double seconds = 1)
{
    int microsec = static_cast<size_t>(seconds * 1000000);
    usleep(microsec);
}

void Game::update_hud()
{
    mvwprintw(plr_pos_win, 2, 2, "x: %d, y: %d ", nee.x_pos, nee.y_pos); // leave a space after the last number so that the last "0" is refreshed when it becomes single digit
    wrefresh(plr_pos_win);
}

void Game::wait_for_input()
{
//    notimeout(stdscr, TRUE);
//    nodelay(stdscr, TRUE);
    int key = getch();
//    wait(0.125);
    if (move_player(key))
    {
        update_state();
        update_hud();
    }
//    printw("\nYou cannot go that way");
//    printw("x: %d, y: %d", nee.x_pos, nee.y_pos);
    refresh();
}
