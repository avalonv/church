#include "Player.h"

using namespace std;
/*
bool Player::set_balance(new_bal)
{
    if (new_bal >= 0)
        return true;
    std::cout << "Not enough funds" << std::endl;
    return false;

bool Player::deposit(val)
{
    if (val >= 0)
        return true;
    std::cout << "Cannot deposit negative ammount" << std::endl;
    return false;
}

bool Player::withdraw(val)
{
    if (balance - val >= 0)
        return true;
    std::cout << "Not enough funds" << std::endl;
    return false;
}

bool Player::set_health(new_health)
{
    if (new_health > 0)
        health = new_health;
    dead = true;
}

bool Player::set_xp(new_xp)
{

}
*/
void Player::set_position(int x, int y)
{
    x_pos = x;
    y_pos = y;
}

//vector<unsigned int> Player::get_position()
//{
//    vector<unsigned int> my_vec;
//    for (auto i: pos)
//        my_vec.push_back(i)
//    return pos;
//}

//void Player::move()
//{
////    if ((x_pos >= 16) | (y_pos >= 70))
////        return false;
//
//    switch (heading)
//    {
//        case left:y_pos -= 1; break;
//        case right: y_pos += 1; break;
//        case up: x_pos -= 1; break;
//        case down: x_pos += 1; break;
//    }
//
//}
