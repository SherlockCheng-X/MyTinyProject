#include <iostream>
#include <limits>
#include "fun.h"
#include <vector>

//int main()
//{
//    std::cout << __cplusplus << std::endl;
//    std::vector<std::string> tasks;
//    int choice;
//    do {
//        std::cout << "1.Add 2.Display 3.Delete 0.Quit\nchoice:";
//        std::cin >> choice;
//        if (std::cin.fail())
//        {
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            choice = -1;
//        }
//        switch (choice)
//        {
//        case 0:
//        {
//            std::cout << "Ok, see ya!";
//            choice = 0;
//            break;
//        }
//        case 1:
//        {
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            tasks.push_back(add_mode());
//            break;
//        }
//        case 2:
//        {
//            if (tasks.size() != 0) display(tasks.begin(), tasks.end());
//            else
//            {
//                std::cout << "You don't have any task yet." << std::endl;
//            }
//            break;
//        }
//        case 3:
//        {
//            std::cout << "delete" << std::endl;
//            break;
//        }
//        default:
//            std::cout << "Unexpected choice, plz enter a number. again! :(" << std::endl;
//            break;
//        }
//    } while (choice != 0);
//}

struct Point {
    int x;
    int y;
};

int main() {
    Point p = { .x = 10, .y = 20 }; // 这是 C++20 才有的语法
    std::cout << p.x << ", " << p.y << std::endl;
}