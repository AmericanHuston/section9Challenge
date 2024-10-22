#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

std::vector<int> addNums(std::vector<int> vec);
void printNums(std::vector<int> vec);

int main(){
    char chr;
    std::vector<int> lists{};
    std::cout << "Welcome!" << std::endl;
    std::cout << "Please select what you'd like to do: " << std::endl;
    while (true){
        std::cout << "\nP - Print numbers\nA - Add a number to a list\nM - Display mean of the numbers\nS - Display the smallest number\nL - Display the largest number\nQ - Quit" << std::endl;
        std::cin >> chr;
        switch (chr){
            case 'P': case 'p':
                printNums(lists);
                break;
            case 'A': case 'a':
                lists = addNums(lists);
                break;
            case 'M': case 'm':
                if (lists.size() == 0)
                    std::cout << "The average is: 0" << std::endl;
                else
                    std::cout << "The average is: " << std::accumulate(lists.begin(), lists.end(), 0.0)/lists.size() << std::endl;
                break;
            case 'S': case 's':
            {
                std::vector<int>::iterator small;
                small = std::min_element(lists.begin(), lists.end());
                std::cout << "The smallest number is: " << *small << std::endl;
                break;
            }
            case 'L': case 'l':
            {
                std::vector<int>::iterator large;
                large = std::max_element(lists.begin(), lists.end());
                std::cout << "The largest number is: " << *large << std::endl;
                break;
            }
            case 'Q': case 'q':
            {
                exit(0);
                break;
            }
            default:
                std::cout << "Ha yeah no, try again" << std::endl;
        }
    }
    return 0;
}

std::vector<int> addNums(std::vector<int> vec){
    int numData {}, i {}, input {};
    std::cout << "How many pieces of data do you want to input?" << std::endl;
    std::cin >> numData;
    while (!std::cin){ //Check for int
        std::cout << "\nNot a number! Please enter an integer." << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> numData;
    }
    while (i < numData){
        std::cout << "Input your data (integers only): " << std::endl;
        std::cin >> input;
        while (!std::cin){
            std::cout << "\nNot a number! Please enter an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> input;
        }
        vec.push_back(input);
        i++;
    }
    return vec;
}

void printNums(std::vector<int> vec){
    std::cout << "[ ";
    for (int i : vec)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}