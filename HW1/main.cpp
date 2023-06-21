#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

// convert nubmer to word for the first three to print 'first' 'second' 'third'
string intToString(int number)
{
    if (number == 1)
    {
        return "first";
    }
    if (number == 2)
    {
        return "second";
    }
    if (number == 3)
    {
        return "third";
    }
    return to_string(number) + "th";
}

// Function to print the shuffled string in grid format
void printShuffledString(string str, int iteration)
{
    cout << "The " << intToString(iteration) << " shuffled output is:\n";
    cout << "+-----+\n";
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << "|";
        }
        cout << str[i] << ' ';
        if ((i + 1) % 3 == 0)
        {
            cout << "|\n";
        }
    }
    cout << "+-----+\n\n";
}

int main(int argc, char *argv[])
{
    // Check to see if the number of command-line arguments is right
    if (argc != 2)
    {
        cerr << "Usage: ./myhw <number_of_shuffles>\n";
        return 1;
    }

    // Converts the command-line number to an integer
    int numberOfShuffles = std::stoi(argv[1]);

    cout << "Please input 9 digits to be randomly shuffled:\n";
    string input;
    cin >> input;

    // random number generator with current time
    srand(time(0));

    // does the number of shuffles and prints it
    for (int i = 1; i <= numberOfShuffles; i++)
    {
        random_shuffle(input.begin(), input.end());
        printShuffledString(input, i);
    }

    return 0;
}
