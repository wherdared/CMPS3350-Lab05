#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>

using namespace std;
// Function to read a random word from a file
string getRandomWord(const string& filePath) {
    vector<string> words;
    ifstream file(filePath);
    string word;

    // Check if the file is open
    if (file.is_open()) {
        while (getline(file, word)) {
            words.push_back(word);
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filePath << endl;
        return "";
    }

    // Seed the random number generator
    srand(time(NULL));

    // Return a random word from the vector
    if (!words.empty()) {
        int randomIndex = rand() % words.size();
        return words[randomIndex];
    } else {
        return "";
    }
}

// Function to start the guessing game
void startGame(const string& mode) {
    string filePath;

    if (mode == "Normal Mode") {
        filePath = "words.txt";
    } else if (mode == "Food Mode") {
        filePath = "food.txt";
    } else if (mode == "US Cities Mode") {
        filePath = "uscities.txt";
    } else {
        cout << "Invalid mode selected." << endl;
        return;
    }

    string secretWord = getRandomWord(filePath);
    string guess;
    cout << "Guess the word: " << endl;

    while (true) {
        cin >> guess;

        // Length check
        if (guess.length() != secretWord.length()) {
            cout << "Incorrect length, try again." << endl;
            continue;
        }
        //check for exact match
        if (guess == secretWord) {
            cout << "Congratulations! You've guessed correctly." << endl;
            break;
        } 
        // Matching and contained letters
        string feedback = "";
        unordered_set<char> secretLetters(secretWord.begin(), secretWord.end());
        for (size_t i = 0; i < guess.length(); ++i) {
            if (guess[i] == secretWord[i]) {
                feedback += guess[i]; // Correctly placed letter
            } else if (secretLetters.count(guess[i])) {
                feedback += "*"; // Right letter, wrong position
            } else {
                feedback += "_"; // Wrong letter
            }
        }
        cout << "Feedback: " << feedback << endl;
        cout << "Incorrect, try again." << endl;
    }
}
//function to choose the game mode and start game
void mode(string mode_name) {
    cout << mode_name << endl;
    startGame(mode_name);
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
    
    // Change the text color to green
    cout << "\033[32m";

    cout << R"(
 __      __       .__                                  __            __      __                .___.__
/  \    /  \ ____ |  |   ____  ____   _____   ____   _/  |_  ____   /  \    /  \___________  __| _/|  |   ____
\   \/\/   // __ \|  | _/ ___\/  _ \ /     \_/ __ \  \   __\/  _ \  \   \/\/   /  _ \_  __ \/ __ | |  | _/ __ \
 \        /\  ___/|  |_\  \__(  <_> )  Y Y  \  ___/   |  | (  <_> )  \        (  <_> )  | \/ /_/ | |  |_\  ___/
  \__/\  /  \___  >____/\___  >____/|__|_|  /\___  >  |__|  \____/    \__/\  / \____/|__|  \____ | |____/\___  >
       \/       \/          \/            \/     \/                        \/                   \/           \/)" << endl;

    // Reset the text color to default
    cout << "\033[0m";

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
