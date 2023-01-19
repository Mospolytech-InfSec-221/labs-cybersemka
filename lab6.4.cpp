#include <iostream>
#include <string>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::set;
using std::string;
using std::to_string;

int main() {
    set<string> stLogin;
    set<string> stLoginNum;
    string input = "";
    int inputNum;
    cout << "Break: exit" << endl;
    while (true) {
        cout << "Login: " << endl;
        cin >> input;
        if (input == "exit") {
            break;
        }
        cin >> inputNum;
        if (stLogin.empty() || stLogin.find(input) == stLogin.end()) {
            cout << "Login True: " << input << endl << endl;

            stLogin.insert(input);
            stLoginNum.insert(input + " " + to_string(inputNum));

            for (auto loginNum : stLoginNum) {
                cout << loginNum << endl;
            }
            cout << endl;
        } else {
            cout << "Login False: " << input << endl << endl;

            for (auto loginNum : stLoginNum) {
                cout << loginNum << endl;
            }
            cout << endl;
        }
    }
}