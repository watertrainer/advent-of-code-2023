

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
    std::string digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (!fin.eof())
    {
        once = false;
        std::string number;
        getline(fin, line);
        // line = "1abc2";
        bool first = true;
        char last;
        char last5[5];
        int curr = 0;
        int start = 0;
        int end = 0;
        bool reset = true;
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
                start = end = 0;
                curr = 0;
                reset = true;
            }
            else
            {

                last5[curr] = c;
                end = curr;
                curr++;
                curr %= 5;
                if (start == end && !reset)
                {
                    start += 1;
                    start %= 5;
                }
                reset = false;
                std::string current_string;
                for (int i = start; i != end; i = (i + 1) % 5)
                {
                    current_string = current_string + last5[i];
                }
                current_string = current_string + last5[end];
                // std::cout << current_string << std::endl;
                for (int i = 0; i < 9; i++)
                {
                    std::string to_compare = digits[i];
                    int n = to_compare.length();
                    if (n > current_string.length())
                    {
                        continue;
                    }
                    int shift = current_string.length() - n;
                    const char *digit_array = to_compare.c_str();
                    const char *current_array = current_string.c_str();
                    bool correct = true;
                    for (int j = n - 1; j >= 0; j--)
                    {
                        if (digit_array[j] != current_array[j + shift])
                        {
                            correct = false;
                            // std::cout << " tried " << (i + 1) << " but failed at char " << current_array[j + shift] << " " << j << " " << std::endl;
                            break;
                        }
                    }
                    if (correct)
                    {
                        char d = '0' + (i + 1);
                        // std::cout << shift << std::endl;
                        if (first)
                        {
                            number = number + d;
                            first = false;
                        }

                        last = d;
                        // no reset: twone wouldn't be detected otherwise
                    }
                }
            }
        }
        number = number + last;
        std::cout << number << " for " << line << std::endl;

        sum += stoi(number);

        number = "0";
    }
    std::cout << sum << std::endl;
}