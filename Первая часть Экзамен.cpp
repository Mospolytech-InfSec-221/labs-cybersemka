<<<<<<< HEAD
﻿#include <iostream>
=======
#include <iostream>
>>>>>>> 7ee9c141c9f4a2a33473a0277bf29f787bd163db
#include <string>
#include <vector>

class Game_Surname {
public:
    struct kishiev_kinsburg {
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
        std::vector<std::string> buildings;
    };

    struct Adviser {
        std::string name;
        std::string playerName;
    };

    std::vector<kishiev_kinsburg> players;
    std::vector<Adviser> advisers;
    int year;
    int stage;
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
    void applyBattleResults(kishiev_kinsburg& player, int battleResult);
};

void Game_Surname::start() {
    std::cout << "Welcome to Kingsburg!" << std::endl;

    std::cout << "Enter the number of players: ";
    int numPlayers;
    std::cin >> numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        kishiev_kinsburg player;
        std::cout << "Enter player " << i + 1 << "'s name: ";
        std::cin >> player.name;
        player.gold = 2;
        player.wood = 1;
        player.tokens = 1;
        player.cube1 = 0;
        player.cube2 = 0;
        player.cube3 = 0;
        player.additionalCube = 0;
        player.hasAdviser = false;
        player.militaryRegister = 0;
        player.victoryPoints = 0;
        players.push_back(player);
    }

    year = 1;
    while (year <= 5) {
        std::cout << "Year " << year << std::endl;
        for (stage = 1; stage <= 8; stage++) {
            switch (stage) {
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

    std::cout << "Game over!" << std::endl;
}

void Game_Surname::stage1() {
    std::cout << "stage 1: Roll dice" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "Player: " << players[i].name << std::endl;

        int cube1, cube2;
        std::cout << "enter player " << i + 1 << "'s dice roll: ";
        std::cin >> cube1 >> cube2;
        players[i].cube1 = cube1;
        players[i].cube2 = cube2;
        std::cout << "dice roll: " << players[i].cube1 << ", " << players[i].cube2 << std::endl;

        std::cout << std::endl;
    }
}

void Game_Surname::stage2() {
    std::cout << "stage 2: Take action" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;

        if (players[i].hasAdviser) {
            std::cout << "enter the number of the action you want (1,2,3,4,5): ";
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

        std::cout << "resources: " << players[i].gold << " gold, " << players[i].wood << " wood, " << players[i].tokens << " tokens, " << players[i].additionalCube << " additional cube, " << players[i].militaryRegister << " military register." << std::endl;
        std::cout << std::endl;
    }
}

void Game_Surname::stage3() {
    std::cout << "stage 3: Build" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;

        std::cout << "Enter the number of the building you want to build (1-5): ";
        int building;
        std::cin >> building;

        switch (building) {
        case 1:
            players[i].buildings.push_back("farm");
            break;
        case 2:
            players[i].buildings.push_back("mine");
            break;
        case 3:
            players[i].buildings.push_back("lumber mill");
            break;
        case 4:
            players[i].buildings.push_back("temple");
            break;
        case 5:
            players[i].buildings.push_back("palace");
            break;
        }

        std::cout << "buildings: ";
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
        std::cout << "player: " << players[i].name << std::endl;

        std::cout << "do you want to hire adviser? (y/n): ";
        char hire;
        std::cin >> hire;

        if (hire == 'y') {
            players[i].hasAdviser = true;

            Adviser adviser;
            std::cout << "enter the name of the adviser: ";
            std::cin >> adviser.name;
            adviser.playerName = players[i].name;
            advisers.push_back(adviser);

            std::cout << "adviser hired: " << adviser.name << std::endl;
        }

        std::cout << std::endl;
    }
}

void Game_Surname::stage5() {
    std::cout << "stage 5: Attack enemy" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;

        std::cout << "enter the number of tokens you want to use to attack the enemy: ";
        int tokens;
        std::cin >> tokens;
        players[i].militaryRegister += tokens;
        players[i].tokens -= tokens;
        std::cout << "tokens used: " << tokens << std::endl;
        std::cout << "military register: " << players[i].militaryRegister << std::endl;

        std::cout << std::endl;
    }
}

void Game_Surname::stage6() {
    std::cout << "stage 6: collect resources" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;

        int gold = 0, wood = 0, tokens = 0;
        for (int j = 0; j < players[i].buildings.size(); j++) {
            if (players[i].buildings[j] == "farm") {
                gold++;
            }
            else if (players[i].buildings[j] == "mine") {
                gold++;
                tokens++;
            }
            else if (players[i].buildings[j] == "lumber mill") {
                wood++;
            }
            else if (players[i].buildings[j] == "temple") {
                tokens++;
            }
            else if (players[i].buildings[j] == "palace") {
                gold++;
                wood++;
                tokens++;
            }
        }

        players[i].gold += gold;
        players[i].wood += wood;
        players[i].tokens += tokens;

        std::cout << "resources: " << gold << " gold, " << wood << " wood, " << tokens << " tokens." << std::endl;
        std::cout << std::endl;
    }
}

void Game_Surname::stage7() {
    std::cout << "stage 7: End year" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;
        int victoryPoints = 0;
        for (int j = 0; j < players[i].buildings.size(); j++) {
            if (players[i].buildings[j] == "farm") {
                victoryPoints++;
            }
            else if (players[i].buildings[j] == "mine") {
                victoryPoints += 2;
            }
            else if (players[i].buildings[j] == "lumber mill") {
                victoryPoints++;
            }
            else if (players[i].buildings[j] == "temple") {
                victoryPoints += 2;
            }
            else if (players[i].buildings[j] == "palace") {
                victoryPoints += 3;
            }
        }

        players[i].victoryPoints += victoryPoints;

        std::cout << "win points: " << players[i].victoryPoints << std::endl;
        std::cout << std::endl;
    }
}

void Game_Surname::stage8() {
    std::cout << "stage 8: Battle with enemy" << std::endl;

    for (int i = 0; i < players.size(); i++) {
        std::cout << "player: " << players[i].name << std::endl;

        int battleResult;
        std::cout << "enter the battle result for player " << players[i].name << " (1,2,3,4,5): ";
        std::cin >> battleResult;

        applyBattleResults(players[i], battleResult);

        std::cout << "resources: " << players[i].gold << " gold, " << players[i].wood << " wood, " << players[i].tokens << " tokens, " << players[i].additionalCube << " additional cube, " << players[i].militaryRegister << " military register." << std::endl;
        std::cout << std::endl;
    }
}

void Game_Surname::applyBattleResults(kishiev_kinsburg& player, int battleResult) {
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
        player.wood++;
        player.tokens += 2;
        player.additionalCube++;
        break;
    }
}

int main() {
    Game_Surname game;
    game.start();
    return 0;
}














