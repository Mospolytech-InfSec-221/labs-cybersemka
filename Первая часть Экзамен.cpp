#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

class kishiev_kinsburg {
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

struct Adviser {
    std::string name;
    std::string playerName;
};

std::vector<Player> players;
std::vector<Adviser> advisers;
int year;
int phase;
std::string enemy;

void start();
void stage1();
void stage2();
void stage3();
void stage4();
void stage5();
void stage6();
void stage7();
void stage8();
void applyBattleResults(Player& kishiev_kinsburg, int battleResult);
};

void Game_Surname::start() {
    std::cout << "Welcome to Kingsburg!" << std::endl;

    std::cout << "Enter the number of players: ";
    int numPlayers;
    std::cin >> numPlayers;
    for (int i = 0; i < numPlayers; i++) {
        Player player;
        std::cout << "Enter player " << i + 1 << "'s name: ";
        std::cin >> kishiev_kinsburg.name;
        kishiev_kinsburg.gold = 2;
        kishiev_kinsburg.wood = 1;
        kishiev_kinsburg.tokens = 1;
        kishiev_kinsburg.cube1 = 0;
        kishiev_kinsburg.cube2 = 0;
        kishiev_kinsburg.cube3 = 0;
        kishiev_kinsburg.additionalCube = 0;
        kishiev_kinsburg.hasAdviser = false;
        kishiev_kinsburg.militaryRegister = 0;
        kishiev_kinsburg.victoryPoints = 0;
        players.push_back(kishiev_kinsburg);
    }

    year = 1;
    while (year <= 5) {
        std::cout << "Year " << year << std::endl;
        for (phase = 1; phase <= 8; phase++) {
            switch (phase) {
            case 1:
                stage1();
                break;
            case 2:
                stage2();
                break;
            case 3:
                stage3();
                break;
            case 4:
                stage4();
                break;
            case 5:
                stage5();
                break;
            case 6:
                stage6();
                break;
            case 7:
                stage7();
                break;
            case 8:
                stage8();
                break;
            }
        }
        year++;
    }

    std::cout << "game over!" << std::endl;
}

void Game_Surname::stage1() {
    std::cout << "stage 1: Roll dice" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;
        int cube1, cube2;
        std::cout << "enter player " << i + 1 << "'s dice roll: ";
        std::cin >> cube1 >> cube2;
        players[i].cube1 = cube1;
        players[i].cube2 = cube2;
        std::cout << "Dice roll: " << players[i].cube1 << ", " << players[i].cube2 << std::endl;

        std::cout << std::endl;
    }
}

void Game_Surname::stage2() {
    std::cout << "stage 2: Take action" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;

        if (players[i].hasAdviser) {
            std::cout << "enter the number of the action you want to take (1-5): ";
            int action;
            std::cin >> action;

            switch (action) {
            case 1:
                players[i].gold++;
                break;
            case 2:
                players[i].wood++;
                break;
            case 3:
                players[i].tokens++;
                break;
            case 4:
                players[i].additionalCube++;
                break;
            case 5:
                players[i].militaryRegister++;
                break;
            }
        }

        std::cout << "Resources: " << players[i].gold << " gold, " << players[i].wood << " wood, " << players[i].tokens << " tokens, " << players[i].additionalCube << " additional cube, " << players[i].militaryRegister << " military register." << std::endl;
        std::cout << std::endl;
    }
}

void Game_Surname::stage3() {
    std::cout << "stage 3: build" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;

        std::cout << "Enter the number of the building you want to build (1-5): ";
        int building;
        std::cin >> building;

        switch (building) {
        case 1:
            players[i].buildings.push_back("Farm");
            break;
        case 2:
            players[i].buildings.push_back("Mine");
            break;
        case 3:
            players[i].buildings.push_back("Lumber Mill");
            break;
        case 4:
            players[i].buildings.push_back("Temple");
            break;
        case 5:
            players[i].buildings.push_back("Palace");
            break;
        }

        std::cout << "Buildings: ";
        for (int j = 0; j < players[i].buildings.size(); j++) {
            std::cout << players[i].buildings[j] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}


void Game_Surname::stage4() {
    std::cout << "stage 4: Hire advisers" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        std::cout << "Do you want to hire an adviser? (y/n): ";
        char hire;
        std::cin >> hire;

        if (hire == 'y') {
            players[i].hasAdviser = true;

            Adviser adviser;
            std::cout << "Enter the name of the adviser: ";
            std::cin >> adviser.name;
            adviser.playerName = players[i].name;
            advisers.push_back(adviser);

            std::cout << "Adviser hired: " << adviser.name << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Surname::stage5() {
    std::cout << "stage 5: Attack" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;

        std::cout << "Enter the number of tokens you want to use to attack the enemy: ";
        int tokens;
        std::cin >> tokens;

        players[i].tokens -= tokens;
        players[i].militaryRegister += tokens;

        std::cout << "Tokens used: " << tokens << std::endl;
        std::cout << "Military register: " << players[i].militaryRegister << std::endl;

        std::cout << std::endl;
    }
}

void Game_Surname::stage6() {
    std::cout << "stage 6: resources" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;
        int gold = 0, wood = 0, tokens = 0;
        for (int j = 0; j < players[i].buildings.size(); j++) {
            if (players[i].buildings[j] == "Farm") {
                gold++;
            }
            else if (players[i].buildings[j] == "Mine") {
                gold++;
                tokens++;
            }
            else if (players[i].buildings[j] == "Lumber Mill") {
                wood++;
            }
            else if (players[i].buildings[j] == "Temple") {
                tokens++;
            }
            else if (players[i].buildings[j] == "Palace") {
                gold++;
                wood++;
                tokens++;
            }
        }
        players[i].gold += gold;
        players[i].wood += wood;
        players[i].tokens += tokens;
        std::cout << "Resources: " << gold << " gold, " << wood << " wood, " << tokens << " tokens." << std::endl;
        std::cout << std::endl;
    }
}

void Game_Surname::stage7() {
    std::cout << "stage 7: End year" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;
        int victoryPoints = 0;
        for (int j = 0; j < players[i].buildings.size(); j++) {
            if (players[i].buildings[j] == "Farm") {
                victoryPoints++;
            }
            else if (players[i].buildings[j] == "Mine") {
                victoryPoints += 2;
            }
            else if (players[i].buildings[j] == "Lumber Mill") {
                victoryPoints++;
            }
            else if (players[i].buildings[j] == "Temple") {
                victoryPoints += 2;
            }
            else if (players[i].buildings[j] == "Palace") {
                victoryPoints += 3;
            }
        }

        players[i].victoryPoints += victoryPoints;

        std::cout << "Victory points: " << players[i].victoryPoints << std::endl;
        std::cout << std::endl;
    }
}

void Game_Surname::stage8() {
    std::cout << "stage 8: Battle with enemy" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;
        int battleResult;
        std::cout << "Enter the battle result for player " << players[i].name << " (1-5): ";
        std::cin >> battleResult;
        applyBattleResults(players[i], battleResult);
        std::cout << "Resources: " << players[i].gold << " gold, " << players[i].wood << " wood, " << players[i].tokens << " tokens, " << players[i].additionalCube << " additional cube, " << players[i].militaryRegister << " military register." << std::endl;
        std::cout << std::endl;
    }
}

void Game_Surname::applyBattleResults(Player& player, int battleResult) {
    switch (battleResult) {
    case 1:
        player.gold += 2;
        player.wood++;
        break;
    case 2:
        player.gold++;
        player.wood += 2;
        break;
    case 3:
        player.gold++;
        player.wood++;
        player.tokens++;
        break;
    case 4:
        player.gold += 2;
        player.wood += 2;
        player.tokens++;
        break;
    case 5:
        player.gold++;
        kishiev_kinsburg.wood++;
        kishiev_kinsburg.tokens += 2;
        kishiev_kinsburg.additionalCube++;
        break;
    }
}

int main() {
    Game_Surname game;
    game.start();
    return 0;
}

