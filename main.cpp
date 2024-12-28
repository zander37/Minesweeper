#include <iostream>
#include <fstream>
#include "window.h"


int main() {

    std::cout << "Starting Minesweeper!" << std::endl;

    std::ifstream file("files/config.cfg");

    if (!file.is_open()) {
        std::cerr << "File Not Found." << std::endl;
        return EXIT_FAILURE;
    }

    std::string tempRows;
    std::string tempColumns;
    std::string tempMines;

    std::getline(file, tempColumns);
    std::getline(file, tempRows);
    std::getline(file, tempMines);

    int NUMBER_ROWS = std::stoi(tempRows);
    int NUMBER_COLUMNS = std::stoi(tempColumns);
    int NUMBER_MINES = std::stoi(tempMines);

    windows::WelcomeScreen welcomeScreen(NUMBER_ROWS, NUMBER_COLUMNS);

    if (welcomeScreen.ExecuteWelcomeScreen()) {
        windows::GameWindow gameWindow(NUMBER_ROWS, NUMBER_COLUMNS, NUMBER_MINES, welcomeScreen.stringName);
        gameWindow.ExecuteGameWindow();
    }
    return EXIT_SUCCESS;
}
