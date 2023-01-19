#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

class player {
public:
    std::string name;
    int gold;
    int wood;
    int tokens;
    int cube1;
    int cube2;
    int cube3;
    int additionalCube;
    bool hasAnAdviser;
    int militaryRegister;
    int victoryPoints;
    std::vector<std::string> buildings;
};

class adviser {
public:
    std::string name;
    std::string playerName;
};

class Game_Surname {
public:
    std::vector<player> players;
    std::vector<adviser> advisers;
    int year;
    int stage;
    std::string enemy;
    void stage1();
    void stage2();
    void stage3();
    void stage4();
    void stage5();
    void stage6();
    void stage7();
    void stage8();
    void applyBattleResults(player& player,int battleResult,std::vector<adviser>& advisers,int year,std::string enemy);
    void start();
};

void Game_Surname::start() {
    stage1();
    stage2();
    stage3();
    stage4();
    stage5();
    stage6();
}

void Game_Surname::stage1() {
    std::cout << "stage 1: Initialization" << std::endl;
    std::cout << "Enter number of players: ";
    int numPlayers;
    std::cin >> numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        player kishiev_kinsburg;
        std::cout << "Enter player " << i + 1 << " name: ";
        std::cin >> kishiev_kinsburg.name;
        kishiev_kinsburg.gold = 5;
        kishiev_kinsburg.wood = 5;
        kishiev_kinsburg.tokens = 5;
        kishiev_kinsburg.cube1 = 0;
        kishiev_kinsburg.cube2 = 0;
        kishiev_kinsburg.cube3 = 0;
        kishiev_kinsburg.hasAnAdviser = false;
        kishiev_kinsburg.additionalCube = 0;
        kishiev_kinsburg.militaryRegister = 0;
        kishiev_kinsburg.victoryPoints = 0;
        players.push_back(kishiev_kinsburg);
    }
}

void Game_Surname::stage2() {
    std::cout << "stage 2 hire advisers" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        if (players[i].gold >= 2 && players[i].tokens >= 1) {
            std::cout << "Advisers available for hire: King, Trader, Builder" << std::endl;
            std::cout << "Enter the name of the advisor you want to hire: ";
            std::string advisorName;
            std::cin >> advisorName;

            bool advisorAvailable = false;
            for (int j = 0; j < advisers.size(); j++) {
                if (advisers[j].name == advisorName && advisers[j].playerName.empty()) {
                    advisorAvailable = true;
                    break;
                }
            }

            if (advisorAvailable) {
                players[i].gold -= 2;
                players[i].tokens -= 1;
                players[i].hasAnAdviser = true;

                adviser advisor;
                advisor.name = advisorName;
                advisor.playerName = players[i].name;
                advisers.push_back(advisor);
                std::cout << "advisor hired successfully!" << std::endl;
            }
            else {
                std::cout << "advisor not available. Hiring failed." << std::endl;
            }
        }
        else {
            std::cout << "not enough resources to hire an advisor." << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Surname::stage3() {
    std::cout << "stage 3: building" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        if (players[i].gold >= 2 && players[i].wood >= 1) {
            std::cout << "buildings available for construction: Market, Sawmill, Smithy" << std::endl;
            std::cout << "enter the name of the building you want to construct: ";
            std::string buildingName;
            std::cin >> buildingName;

            bool buildingAvailable = false;
            for (int j = 0; j < players[i].buildings.size(); j++) {
                if (players[i].buildings[j] == buildingName) {
                    buildingAvailable = true;
                    break;
                }
            }

            if (!buildingAvailable) {
                players[i].gold -= 2;
                players[i].wood -= 1;
                players[i].buildings.push_back(buildingName);
                std::cout << "building constructed successfully!" << std::endl;
            }
            else {
                std::cout << "building already constructed." << std::endl;
            }
        }
        else {
            std::cout << "not enough resources to construct a building." << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Surname::stage4() {
    std::cout << "stage 4: Production" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;

        bool hasSawmill = false;
        for (int j = 0; j < players[i].buildings.size(); j++) {
            if (players[i].buildings[j] == "Sawmill") {
                hasSawmill = true;
                break;
            }
        }

        if (hasSawmill) {
            players[i].wood++;
            std::cout << "1 wood produced at the sawmill." << std::endl;
        }
        else {
            std::cout << "Sawmill not constructed. No wood produced." << std::endl;
        }

        bool hasSmithy = false;
        for (int j = 0; j < players[i].buildings.size(); j++) {
            if (players[i].buildings[j] == "Smithy") {
                hasSmithy = true;
                break;
            }
        }

        if (hasSmithy) {
            players[i].tokens++;
            std::cout << "1 token produced at the smithy." << std::endl;
        }
        else {
            std::cout << "smithy not constructed. No tokens produced." << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Surname::stage5() {
    std::cout << "stage 5: Military" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;

        if (players[i].gold >= 2 && players[i].tokens >= 1) {
            std::cout << "enter the number of soldiers you want to recruit: ";
            int numSoldiers;
            std::cin >> numSoldiers;

            players[i].gold -= 2;
            players[i].tokens -= 1;
            players[i].militaryRegister += numSoldiers;
            std::cout << numSoldiers << " soldiers recruited successfully!" << std::endl;
        }
        else {
            std::cout << "not enough resources to recruit soldiers." << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << "enemy attack you!" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        int defenseValue = players[i].militaryRegister;
        for (int j = 0; j < advisers.size(); j++) {
            if (advisers[j].playerName == players[i].name && advisers[j].name == "King") {
                defenseValue += 2;
                break;
            }
        }
        for (int j = 0; j < players[i].buildings.size(); j++) {
            if (players[i].buildings[j] == "Wall") {
                defenseValue++;
            }
        }

        int battleResult = rand() % 2;
        applyBattleResults(players[i], battleResult, advisers, year, enemy);

        std::cout << std::endl;
    }
}


void Game_Surname::applyBattleResults(player& player, int battleResult, std::vector<adviser>& advisers, int year, std::string enemy) {
    if (battleResult == 0) {
        std::cout << "fight lost. guard value: " << player.militaryRegister << std::endl;
        player.militaryRegister = std::max(0, player.militaryRegister - 1);
    }
    else {
        std::cout << "fight won. guard value: " << player.militaryRegister << std::endl;
        player.victoryPoints++;
    }
}

int main() {
    srand(time(0));
    Game_Surname game;
    game.start();
    return 0;
}

