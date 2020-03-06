#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>

class Player
{
private:
    // Attributes
    std::string name;
    /*
    double max_health;
    double health;
    double money;
    size_t xp;
    bool dead{false};
    std::vector<unsigned int> pos{0,0};
    */

public:
    int x_pos;
    int y_pos;

// Getters
    //double get_health() {return health;}
    std::string get_name() {return name;}
    //double get_balance() {return money;}
    //std::vector<unsigned int> get_position();

// Setters
    void set_name(std::string new_name) {name = new_name;}/*
    void set_xp(size_t new_xp) {xp += new_xp;}
    bool set_balance(double);
    bool set_health(double);
    bool deposit(double);
    bool withdraw(double);*/
    void set_position(int, int);
    void move();
};

#endif
