#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

std::string intToString(int number)
{
    if (number == 1)
        return "first";
    if (number == 2)
        return "second";
    if (number == 3)
        return "third";
    return std::to_string(number) + "th";
}
