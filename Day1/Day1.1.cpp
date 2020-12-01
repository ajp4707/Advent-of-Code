//ajp4707
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main()
{
    // Part 1
    std::map<int, int> data;
    std::string token = "";
    std::ifstream file("input1.txt");
    int num = 0;
    int seek = 0;
    while (std::getline(file, token))
    {
        num = std::stoi(token);
        seek = 2020 - num;
        if (data.find(seek) != data.end())
        {
            std::cout << "num1 * num2 = " << num * seek << std::endl;
        }
        data.emplace(num, num);
    }

    file.close();

    // Part 2
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    seek = 0;

    auto iter = data.begin();

    for(; iter != data.end(); iter++)
    {
        num1 = iter->first;
        seek = 2020 - num1;     //necessary sum of num2 and num3
        auto iter2 = data.begin();
        for (; iter2 != data.end(); iter2++)
        {
            num2 = iter2->first;
            num3 = seek - num2;
            if (data.find(num3) != data.end())
            {
                std::cout << "num1 * num2 * num3 = " << num1 * num3 * num2 << std::endl;
                break;
            }
        }
    }
    
}


