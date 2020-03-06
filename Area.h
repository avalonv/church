#ifndef _AREA_H_
#define _AREA_H_
#include <string>
#include <vector>
#include <algorithm>

struct Area
{
    std::string name;
    std::vector<std::vector<char>> map;
    std::vector<int[2]> exits;
//    std::vector<std::vector<std::vector<int>>> entrances;

    // setters
    void set_map(std::vector<std::vector<char>> new_map) {map = new_map;}
    std::vector<std::vector<char>> get_map() {return map;}
//    std::vector<char> default_hard() {std::vector<char> h_tiles{'|','/','\\','-','_','[',']','+','^','%';}
    bool is_hard(const char &tile);
};
#endif
