

#include <fstream>
#include <iostream>

using std::ifstream;

int main()
{
    ifstream fin("day1input.txt");
    int sum = 0;
    std::string line;
    int max = 2;
    bool once = true;
    while (!fin.eof())
    {
        once = false;
        std::string number;
        getline(fin, line);
        // line = "1abc2";
        bool first = true;
        char last;
        for (char &c : line)
        {
            if (isdigit(c))
            {
                if (first)
                {
                    number = number + c;
                    first = false;
                }

                last = c;
            }
        }
        number = number + last;
        std::cout << number << std::endl;
        sum += stoi(number);

        number = "0";
    }
    std::cout << sum << std::endl;
}