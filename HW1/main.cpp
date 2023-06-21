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

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./myhw <number_of_shuffles>\n";
        return 1;
    }

    int numberOfShuffles = std::stoi(argv[1]);

    std::cout << "Please input 9 digits to be randomly shuffled:\n";
    std::string input;
    std::cin >> input;

    std::srand(std::time(0));

    for (int i = 1; i <= numberOfShuffles; i++)
    {
        std::random_shuffle(input.begin(), input.end());
        printShuffledString(input, i);
    }

    return 0;
}