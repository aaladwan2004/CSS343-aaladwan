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

void printShuffledString(std::string str, int iteration)
{
    std::cout << "The " << intToString(iteration) << " shuffled output is:\n";
    for (int i = 0; i < 9; i++)
    {
        std::cout << str[i] << ' ';
        if ((i + 1) % 3 == 0)
        {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}
