#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>

using namespace std;

// ANSI escape codes for colors
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[94m";
const string RESET = "\033[0m";

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

// Modified feedback function to include colors
void giveFeedback(const string& guess, const string& secretWord) {
    unordered_set<char> secretLetters(secretWord.begin(), secretWord.end());
    string feedback = "";

    for (size_t i = 0; i < guess.length(); ++i) {
        if (guess[i] == secretWord[i]) {
            feedback += GREEN + guess[i] + RESET; // Correctly placed letter
        } else if (secretLetters.count(guess[i])) {
            feedback += YELLOW + "*" + RESET; // Right letter, wrong position
        } else {
            feedback += RED + "_" + RESET; // Wrong letter
        }
    }

    cout << "Feedback: " << feedback << endl;
    cout << "Incorrect, try again." << endl;
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
            cout << "\033[33m";
            cout << "Correct" << endl;
            cout << R"(
_____.___.                      .__         ._.
\__  |   | ____  __ __  __  _  _|__| ____   | |
 /   |   |/  _ \|  |  \ \ \/ \/ /  |/    \  | |
 \____   (  <_> )  |  /  \     /|  |   |  \  \|
 / ______|\____/|____/    \/\_/ |__|___|  /  __
 \/                                     \/   \/)" << endl;
            // Reset the text color to default
            cout << "\033[0m";

            break;
        } 
        // Provide feedback with colors
        giveFeedback(guess, secretWord);
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
        cout << "\033[96m";
        cout << "---------------------------------------------------------------------------------------------" << endl;
        cout << R"(  _         _  _                    _   __  __         _     
 / |  ___  | \| |___ _ _ _ __  __ _| | |  \/  |___  __| |___ 
 | | |___| | .` / _ \ '_| '  \/ _` | | | |\/| / _ \/ _` / -_)
 |_|       |_|\_\___/_| |_|_|_\__,_|_| |_|  |_\___/\__,_\___|
                                                             
  ___         ___             _   __  __         _     
 |_  )  ___  | __|__  ___  __| | |  \/  |___  __| |___ 
  / /  |___| | _/ _ \/ _ \/ _` | | |\/| / _ \/ _` / -_)
 /___|       |_|\___/\___/\__,_| |_|  |_\___/\__,_\___|
                                                       
  ____        _   _ ___    ___ _ _   _          __  __         _     
 |__ /  ___  | | | / __|  / __(_) |_(_)___ ___ |  \/  |___  __| |___ 
  |_ \ |___| | |_| \__ \ | (__| |  _| / -_|_-< | |\/| / _ \/ _` / -_)
 |___/        \___/|___/  \___|_|\__|_\___/__/ |_|  |_\___/\__,_\___|
                                                                     
 ___          ___       ___          _   
 | _ )  ___   / __|___  | _ ) __ _ __| |__
 | _ \ |___| | (_ / _ \ | _ \/ _` / _| / /
 |___/        \___\___/ |___/\__,_\__|_\_\
                                          
)" << endl << "---------------------------------------------------------------------------------------------" << endl;;
        cout << "\033[0m";
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
        else {
             cout << "\033[31m";
             cout << R"(  _
 / ` _   _ _   _ _   _   _   _ )   / / _ ( _  _   _         _
(_. (_) ) ) ) ) ) ) (_( ) ) (_(   (_/ ) ) )\ ) ) (_) )_)_) ) )
             )" << endl;
             cout << "\033[0m";
         }
    }

    // when round ends user has these options
    while (true) {
        cout << "\033[96m";
        cout << "---------------------------------------------------------------------------------------------" << endl;
        cout << R"(  ___         ___ _               _             _      
 | _ \  ___  | _ \ |__ _ _  _    /_\  __ _ __ _(_)_ _  
 |  _/ |___| |  _/ / _` | || |  / _ \/ _` / _` | | ' \\
 |_|         |_| |_\__,_|\_, | /_/ \_\__, \__,_|_|_||_|
                         |__/        |___/             
   ___        ___ _                       __  __         _     
  / __|  ___ / __| |_  ___  ___ ___ ___  |  \/  |___  __| |___ 
 | (__  |___| (__| ' \/ _ \/ _ (_-</ -_) | |\/| / _ \/ _` / -_)
  \___|      \___|_||_\___/\___/__/\___| |_|  |_\___/\__,_\___|
                                                                                                                                                                     
  __  __         __  __      _        __  __              
 |  \/  |  ___  |  \/  |__ _(_)_ _   |  \/  |___ _ _ _  _ 
 | |\/| | |___| | |\/| / _` | | ' \  | |\/| / -_) ' \ || |
 |_|  |_|       |_|  |_\__,_|_|_||_| |_|  |_\___|_||_\_,_|                                                          
)" << endl << endl << "---------------------------------------------------------------------------------------------" << endl;
        cout << "\033[0m";
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
        else {
            cout << "\033[31m";
            cout << R"(  _
 / ` _   _ _   _ _   _   _   _ )   / / _ ( _  _   _         _
(_. (_) ) ) ) ) ) ) (_( ) ) (_(   (_/ ) ) )\ ) ) (_) )_)_) ) )
            )" << endl;
            cout << "\033[0m";
        }
    }
}

void rules() {
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << R"(Game Rules:
    1. You will have 6 chances to guess a random target word that is chosen with the game.
    2. The target word will have 5 letters within it, therefore you can only make guesses 
       with 5 letter words.
    3. You cannot enter words scrambled with random letters such as “abcde” 
       since it is not an actual word that exists within the game or in general.
    4. If you guess a word that is not within the game mode, you will be given 
       another try to guess a word.
    5. As you make your guesses throughout the game, the system will be dropping hints in 
       order to help you figure out what your word could be before you make your final guess. 
       For Example:
        a. Let's say the target word is “hatch”.
        b. Your first guess is “mouse”. Since there are no letters in the word that 
           match with the target word, you will receive no hints.
        c. Your second guess is “crash”. Since you guessed the word “crash”, 
           your hint will be that your target word will contain the letters ‘a’ and 
           ‘c’.
        d. Your third guess is “house”. Since you guess the word “house”, 
           your hint will be that you found a letter that is not only in the target word, 
           but it matches the exact location of where it was guessed, in this case being the 
           first letter of the target word ‘h’.
    6. Once you have made your 6 guesses, you will receive a message whether you have either 
       guessed the word or if you haven't.
    7. If you are able to guess the word before your 6th try, the game will end and you will 
       receive a message that you won the game.
    8. There are 3 different modes in this game:
        a. Normal Mode - This mode will contain random 5-letter words in general.
        b. Food Mode - This mode will contain 5-letter words that are related to the topic 
           of “food”
        c. US Cities Mode - This mode will contain 5-letter words that are names of cities 
           located in the country, United States of America.)" << endl;
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
        cout << "\033[96m";
        cout << "---------------------------------------------------------------------------------------------" << endl;
        cout << R"(   ___          ___ _                       __  __         _                               
  / __|  ___   / __| |_  ___  ___ ___ ___  |  \/  |___  __| |___                           
 | (__  |___| | (__| ' \/ _ \/ _ (_-</ -_) | |\/| / _ \/ _` / -_)                          
  \___|        \___|_||_\___/\___/__/\___| |_|  |_\___/\__,_\___|

 __   __       __   ___               ___                  ___      _        
 \ \ / /  ___  \ \ / (_)_____ __ __  / __|__ _ _ __  ___  | _ \_  _| |___ ___
  \ V /  |___|  \ V /| / -_) V  V / | (_ / _` | '  \/ -_) |   / || | / -_|_-<
   \_/           \_/ |_\___|\_/\_/   \___\__,_|_|_|_\___| |_|_\\_,_|_\___/__/
                                                                             
 __  __        ___     _ _      ___                
 \ \/ /  ___  | __|_ _(_) |_   / __|__ _ _ __  ___ 
  >  <  |___| | _|\ \ / |  _| | (_ / _` | '  \/ -_)
 /_/\_\       |___/_\_\_|\__|  \___\__,_|_|_|_\___| 
        )" << endl << "---------------------------------------------------------------------------------------------" << endl;
        cout << "\033[0m";

        cin >> c;
        cout << endl;

        if (c == 'C' || c == 'c')
            choose_mode();
        else if (c == 'V' || c == 'v')
            rules();
        else if (c == 'X' || c == 'x')
            game_running = false;
        else {
            cout << "\033[31m";
            cout << R"(  _                                                            
 / ` _   _ _   _ _   _   _   _ )   / / _ ( _  _   _         _  
(_. (_) ) ) ) ) ) ) (_( ) ) (_(   (_/ ) ) )\ ) ) (_) )_)_) ) ) 
            )" << endl;
            cout << "\033[0m";
        }
    } while (game_running != false);

    cout << "Exit Success!" << endl;

    return 0;
}
