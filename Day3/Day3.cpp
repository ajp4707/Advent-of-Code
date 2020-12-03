#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

long long countTree(int rightShift, int downShift)
{
    std::ifstream file("input3.txt");

    std::string token;
    std::string line;
    int col = 0;

    int treeCount = 0;

    bool firstRun = true;

    int rowLength;

    std::string tree = "#";

    while (std::getline(file, line))
    {
        for (int i = 1; i < downShift && !firstRun; i++)
            if (!std::getline(file, line))
                goto breakOut;
        if (firstRun)
        {
            rowLength = line.size();
            firstRun = false;
        }

        if (line.substr(col, 1) == tree)
            treeCount++;
        col = (col + rightShift) % rowLength;
    }

    breakOut: std::cout << "On a slope of Right " << rightShift << " and Down " << downShift << ", You would encounter " << treeCount << " trees." << std::endl;
    return treeCount;
}

int main()
{
    // Part 1
    std::cout << "Part 1 answer is: ";
    countTree(3, 1);                    //184

    // Part 2
    std::cout << "Part 2 answer is: " << std::endl;
    long long product = countTree(1, 1) * countTree(3, 1) * countTree(5, 1) * countTree(7, 1) * countTree(1, 2);            //2431272960
    std::cout << "The product is " << product << std::endl;

}
