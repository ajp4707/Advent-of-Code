#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main()
{
    // Part 1
    std::ifstream file("input2.txt");

    int min = 0;
    int max = 0;
    std::string policy;
    std::string password;

    std::string token;
    std::string line;

    int validcount = 0;

    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        getline(stream, token, '-');        //find min
        min = std::stoi(token);
        getline(stream, token, ' ');        //find max
        max = std::stoi(token);
        getline(stream, policy, ':');       //find policy
        getline(stream, password, '\n');    //find password
        password = password.substr(1);      //get rid of whitespace

        int lettercount = 0;
        std::size_t index = 0;
        while (password.find(policy, index) != std::string::npos && index < password.size())
        {
            lettercount++;
            index = password.find(policy, index) + 1;
        }
        
        if (lettercount >= min && lettercount <= max)
            validcount++;
    }

    std::cout << "In part 1, there are " << validcount << " valid passwords in this list" << std::endl;        //528

    file.close();


    //Part 2
    std::ifstream file2("input2.txt");
    validcount = 0;
    int i1 = 0;
    int i2 = 0;

    bool con1 = 0;
    bool con2 = 0;

    while (std::getline(file2, line))
    {
        std::istringstream stream(line);
        getline(stream, token, '-');        //find i1
        i1 = std::stoi(token) - 1;
        getline(stream, token, ' ');        //find i2
        i2 = std::stoi(token) - 1;
        getline(stream, policy, ':');       //find policy
        getline(stream, password, '\n');    //find password
        password = password.substr(1);      //get rid of whitespace
        con1 = password.substr(i1, 1) == policy;
        con2 = password.substr(i2, 1) == policy;


        if ((con1 || con2) && !(con1 && con2))
            validcount++;
    }

    std::cout << "In part 2, there are " << validcount << " valid passwords in this list" << std::endl;        //497

}