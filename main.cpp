#include <iostream>

using namespace std;

void mode(string mode) {
    cout << mode << endl;
}

void choose_mode() {
    char c;
    string mode_name;

    while (true) {
        cout << "-----------" << endl;
        cout << " - 1 for Normal Mode" << endl;
        cout << " - 2 for Food Mode" << endl;
        cout << " - 3 for US Cities Mode" << endl;
        cout << " - B to Go Back" << endl << "--------------" << endl;
        cin >> c;
        cout << endl;

        if (c == '1') {
            mode_name = "Normal Mode";
            mode(mode_name);
            break;
        }
        else if (c == '2') {
            mode_name = "Food Mode";
            mode(mode_name);
            break;
        }
        else if (c == '3') {
            mode_name = "US Cities Mode";
            mode(mode_name);
            break;
        }
        else if (c == 'b' || c =='B')
            return;
        else
            cout << "Command Unknown" << endl;
    }

    // when round ends user has these options
    while (true) {
        cout << "--------------" << endl;
        cout << " - P to Play Again" << endl;
        cout << " - C to Choose Different Mode" << endl;
        cout << " - M to go to Main Menu" << endl << "-----------" << endl;
        cin >> c;
        cout << endl;

        if (c == 'P' || c == 'p')
            mode(mode_name);
        else if (c == 'C' || c == 'c') {
            choose_mode();
            break;
        }
        else if (c == 'M' || c == 'm')
            return;
        else
            cout << "Command Unknown" << endl;
    }
}

void rules() {
    cout << "Rules of game: " << endl;
}

int main() {

    bool game_running = true;       // Keeps Game running
    char c;                         // Tracks user's input in main menu

    cout << "Welcome to Wordle" << endl;

    // Loop to keep the game running unless users chooses to exit
    do {
        cout << "-----------" << endl;
        cout << " - C to Choose Mode" << endl;
        cout << " - V to View Game Rules" << endl;
        cout << " - X to Exit Game" << endl << "----------" << endl;;
        cin >> c;
        cout << endl;

        if (c == 'C' || c == 'c')
            choose_mode();
        else if (c == 'V' || c == 'v')
            rules();
        else if (c == 'X' || c == 'x')
            game_running = false;
        else
            cout << "Command unrecognized try again" << endl;

    } while (game_running != false);

    cout << "Exit Success!" << endl;

  return 0;
}
