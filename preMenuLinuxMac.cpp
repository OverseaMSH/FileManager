#include <iostream>
#include <ncurses.h>
#include <cstdlib> // For system()

using namespace std;

// Function to display the menu with a cursor
void displayMenu(int cursorPos) {
    clear(); // Clear the screen
    printw("================================================\n");
    printw("       Welcome to OverseaMSH File Manager       \n");
    printw("================================================\n");

    // Highlight the selected option
    if (cursorPos == 0) {
        printw("-> 1. Log In\n");
    } else {
        printw("   1. Log In\n");
    }

    if (cursorPos == 1) {
        printw("-> 2. Sign Up\n");
    } else {
        printw("   2. Sign Up\n");
    }

    if (cursorPos == 2) {
        printw("-> 3. Check Project Repository\n");
    } else {
        printw("   3. Check Project Repository\n");
    }

    printw("====================================\n");
    printw("Use arrow keys to navigate, Enter to select.\n");
    refresh(); // Refresh the screen
}

// Function to open the repository URL in the browser
void openRepoURL() {
    string url = "https://github.com/OverseaMSH/FileManager";
    string command = "xdg-open " + url;
    system(command.c_str()); // Open the URL in the default browser
}

int main() {
    // Initialize ncurses
    initscr(); // Start ncurses mode
    cbreak();  // Disable line buffering
    noecho();  // Don't echo input
    keypad(stdscr, TRUE); // Enable arrow keys

    int choice = 0; // Current cursor position
    int selected = -1; // Selected option

    while (true) {
        displayMenu(choice); // Display the menu
        int input = getch(); // Get user input

        switch (input) {
            case KEY_UP:
                if (choice > 0) choice--; // Move cursor up
                break;
            case KEY_DOWN:
                if (choice < 2) choice++; // Move cursor down
                break;
            case 10: // Enter key
                selected = choice;
                break;
            default:
                break;
        }

        if (selected != -1) break; // Exit loop if an option is selected
    }

    endwin(); // End ncurses mode

    // Handle the selected option
    switch (selected) {
        case 0:
            cout << "Log In selected.\n";
            // Add login logic here
            break;
        case 1:
            cout << "Sign Up selected.\n";
            // Add sign-up logic here
            break;
        case 2:
            cout << "Opening project repository...\n";
            openRepoURL(); // Open the repo URL in the browser
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }

    return 0;
}