#include <iostream>
#include <map>
#include <string>
#include "Enemy.h"
#include "Player.h"

int main()
{
    int limit = 100;
    std::map<std::string, int> params = {
        {"wrist", 0},
        {"backpress", 0},
        {"sidepress", 0}
    };

    std::cout << "Enter your power points from 0 to 100, the limit is 100 points" << std::endl;

    for (auto &param : params) {
        std::cout << limit << " power points left " << "\n" << std::endl;
        std::cout << param.first << " = ";
        std::cin >> param.second;
        limit -= param.second;
        if (limit < 0) {
            std::cout << "The limit of power points is exhausted" << std::endl;
            return 0;
        }
    }

    Player player("Me", params["wrist"], params["backpress"], params["sidepress"]);
    std::cout << player.name << player.wrist << player.backpress << player.sidepress;


    //Enemy enemy("Джон Брзенк", 30, 30, 40);
}
