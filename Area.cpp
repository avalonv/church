#include "Area.h"

//    std::vector<char> default_hard() {std::vector<char> h_tiles{'|','/','\\','-','_','[',']','+','^','%';}
bool Area::is_hard(const char &tile)
{
    std::string hard_tiles{"|/\\-_[]+^%"};
    if (hard_tiles.find(tile) == std::string::npos)
        return false;
    return true;
}

