#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

class Player {
public:
    std::string name;
    int gold;
    int wood;
    int tokens;
    int cube1;
    int cube2;
    int cube3;
    int additionalCube;
    bool hasAdviser;
    int militaryRegister;
    int victoryPoints;
    int roll;
    std::vector<std::string> buildings;
};

class Adviser {
public:
    std::string name;
    std::string playerName;
};

class Game_Surname {
public:
    std::vector<Player> players;
    std::vector<Adviser> advisers;
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
    void rollDice();
    void changePlayerOrder();
    void influenceAdvisers();
    void getAdviserHelp();
    void buildBuilding();
    void applyBuildingEffect();

    void applyBattleResults(Player& player, int battleResult, std::vector<Adviser>& advisers, int year, std::string enemy);
    void start();
};

void Game_Surname::start() {
    stage1();
    stage2();
    stage3();
    stage4();
    stage5();
    stage6();
    stage7();
    stage8();
}

void Game_Surname::stage1() {
    std::cout << "stage 1: welcome to kingsburg" << std::endl;
    std::cout << "enter number of players: ";
    int numPlayers;
    std::cin >> numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        Player player;
        std::cout << "enter player " << i + 1 << " name: ";
        std::cin >> player.name;
        player.gold = 5;
        player.wood = 5;
        player.tokens = 5;
        player.cube1 = 0;
        player.cube2 = 0;
        player.cube3 = 0;
        player.additionalCube = 0;
        player.hasAdviser = false;
        player.militaryRegister = 0;
        player.victoryPoints = 0;
        players.push_back(player);
    }
}

void Game_Surname::stage2() {
    std::cout << "stage 2: hire advisers and roll dice" << std::endl;
    rollDice();
    changePlayerOrder();
    influenceAdvisers();
    getAdviserHelp();
    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;
        if (players[i].gold >= 2 && players[i].tokens >= 1) {
            std::cout << "advisers available for hire: Trader, King, Builder" << std::endl;
            std::cout << "enter the name of the advisor you want to hire: ";
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
                players[i].hasAdviser = true;

                Adviser advisor;
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
        std::cout << "player: " << players[i].name << std::endl;

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
    std::cout << "stage 4: buildings and roll dice" << std::endl;
    rollDice();
    changePlayerOrder();
    influenceAdvisers();
    getAdviserHelp();
    buildBuilding();
    applyBuildingEffect();
    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;
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
            std::cout << "sawmill not constructed. No wood produced." << std::endl;
        }
        bool hasSmithy = false;
        for (int j = 0; j < players[i].buildings.size(); j++) {
            if (players[i].buildings[j] == "smithy") {
                hasSmithy = true;
                break;
            }
        }
        if (hasSmithy) {
            players[i].tokens++;
            std::cout << "1 token produced at the smithy." << std::endl;
        }
        else {
            std::cout << "Smithy not constructed. No tokens produced." << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Surname::stage5() {
    std::cout << "stage 5: military" << std::endl;

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
            std::cout << "Not enough resources to recruit soldiers." << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << "enemy attack you!" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;
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


void Game_Surname::stage6() {
    std::cout << "stage 6: buildings and roll dice" << std::endl;
    rollDice();
    changePlayerOrder();
    influenceAdvisers();
    getAdviserHelp();
    buildBuilding();
    applyBuildingEffect();

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;
        if (players[i].gold >= 5 && players[i].wood >= 2) {
            std::cout << "do you want to go to battle? (y/n): ";
            char answer;
            std::cin >> answer;
            if (answer == 'y') {
                players[i].gold -= 5;
                players[i].wood -= 2;
                std::cout << "Enter the number of soldiers to send to battle: ";
                int numSoldiers;
                std::cin >> numSoldiers;
                int battleResult = std::rand() % 2; 

                applyBattleResults(players[i], battleResult, advisers, year, enemy);
            }
            else {
                std::cout << "Player chose not to go to battle." << std::endl;
            }
        }
        else {
            std::cout << "Not enough resources to go to battle." << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Surname::stage7() {
    std::cout << "stage 7: Trade" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;
        std::cout << "enter the resource you want to trade (gold/wood/tokens): ";
        std::string resource;
        std::cin >> resource;
        std::cout << "enter the amount you want to trade: ";
        int amount;
        std::cin >> amount;
        if (resource == "gold") {
            players[i].gold -= amount;
            players[i].wood += amount / 2;
            players[i].tokens += amount / 2;
        }
        else if (resource == "wood") {
            players[i].wood -= amount;
            players[i].gold += amount / 2;
            players[i].tokens += amount / 2;
        }
        else if (resource == "tokens") {
            players[i].tokens -= amount;
            players[i].gold += amount / 2;
            players[i].wood += amount / 2;
        }
        else {
            std::cout << "Invalid resource entered." << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Surname::stage8() {
    std::cout << "stage 8: end year" << std::endl;

    year++;
    std::cout << "Year " << year << " has ended." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        int points = players[i].gold + players[i].wood + players[i].tokens + players[i].cube1 + players[i].cube2 + players[i].cube3 + players[i].additionalCube;
        players[i].victoryPoints = points;
    }
    bool gameOver = false;
    std::string winner;
    int highestPoints = 0;
    for (int i = 0; i < players.size(); i++) {
        if (players[i].victoryPoints > highestPoints) {
            gameOver = true;
            winner = players[i].name;
            highestPoints = players[i].victoryPoints;
        }
    }

    if (gameOver) {
        std::cout << "game over! The winner is: " << winner << " with " << highestPoints << " victory score." << std::endl;
    }
    else {
        std::cout << "Next year..." << std::endl;
    }
}


void Game_Surname::applyBattleResults(Player& player, int battleResult, std::vector<Adviser>& advisers, int year, std::string enemy) {
    if (battleResult == 0) {
        std::cout << "fight lost. guard value: " << player.militaryRegister << std::endl;
        player.militaryRegister = std::max(0, player.militaryRegister - 1);
    }
    else {
        std::cout << "fight won. guard value: " << player.militaryRegister << std::endl;
        player.victoryPoints++;
    }
}

void Game_Surname::rollDice() {
    std::cout << "rolling dice..." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        int roll = std::rand() % 6 + 1;
        std::cout << players[i].name << " rolled a " << roll << std::endl;
    }
}

void Game_Surname::changePlayerOrder() {
    std::cout << "changing player order" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        players[i].roll = std::rand() % 6 + 1;
    }
    std::vector<Player> sortedPlayers = players;
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), [](const Player& p1, const Player& p2) {
        return p1.roll > p2.roll;
        });
    players = sortedPlayers;
    std::cout << "new player order: ";
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name << " ";
    }
    std::cout << std::endl;
}

void Game_Surname::getAdviserHelp() {
    std::cout << "getting adviser help..." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name << " is getting adviser help..." << std::endl;
    }
}

void Game_Surname::buildBuilding() {
    std::cout << "building buildings..." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name << " is building a building..." << std::endl;
    }
}

void Game_Surname::applyBuildingEffect() {
    std::cout << "applying building effects..." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name << " is applying building effects..." << std::endl;
    }
}


void Game_Surname::influenceAdvisers() {
    std::cout << "influencing advisers..." << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i].name << " is influencing advisers..." << std::endl;
    }
}


int main() {
    srand(time(0));
    Game_Surname game;
    game.start();
    return 0;
}

