#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include "button.h"
#include <SFML/Graphics.hpp>

namespace windows {

    class WelcomeScreen {
    public:
        sf::RenderWindow window;
        sf::Font font;
        sf::Text welcomeText;
        sf::Text enterNameText;
        sf::Text name;
        std::string stringName = "";
        std::string showText = "|";

        int height;
        int width;

        WelcomeScreen(int height, int width);

        void setText(sf::Text &text, float x, float y);

        void SetWelcomeText();

        void SetEnterNameText();

        void SetName();

        void DrawWelcomeScreen(sf::RenderWindow &window);

        void UpdateName();

        void GetKeyBoardInput(sf::Keyboard::Key key);

        bool ExecuteWelcomeScreen();
    };

    class LeaderBoard {
    private:
        std::map<std::string, std::string> leaderboard;
        sf::RenderWindow window;
        sf::Font font;
        sf::Text title;
        sf::Text contents;

        int width;
        int height;

    public:
        LeaderBoard(int height, int width, bool winner, std::string playerName, int playerTime);

        void setText(sf::Text &text, float x, float y);

        void SetTitle(int height, int width);

        void SetPlaceText(int height, int width);

        void GetPlayer(std::string fileName, std::string name, int time);

        void UpdateLeaderboard(std::string fileName);

        void GetLeaderBoardStats(std::string filePath);

        void ExecuteLeaderBoardWindow(bool &pause, bool &enabled);
    };

    class GameWindow {
    private:
        sf::RenderWindow window;
        sf::Texture images[21];
        std::vector<std::vector<Tile>> board;
        std::vector<std::vector<Tile>> hiddenBoard;
        buttons::DebugButton debugButton;
        buttons::HappyButton happyButton;
        buttons::PauseButton pauseButton;
        buttons::LeaderBoardButton leaderBoardButton;
        std::string playerName;
        bool gameOver = false;
        bool winner = false;
        bool debugMode = false;
        bool leaderboardEnabled = false;
        bool pauseEnabled = false;
        int NUMBER_ROWS;
        int NUMBER_COLUMNS;
        int NUMBER_MINES;
        int minesRemaining;

    private:
        void GetImages();

        std::map<int, sf::Sprite> GetDigits(sf::Sprite digits);

        void DrawBoard();

        void DrawHiddenBoard();

        void SetGameBoard();

        void SetHiddenBoard();

        void ResetGameBoard();

        void IncreaseSurroundings(int x, int y);

        void GenerateMines();

        void ClearMines();

        void Reveal(int x, int y);

        void Flag(int x, int y);

        void RevealAllMines();

        void FlagAllMines();

        int GetNumberOfFlags(std::vector<std::vector<Tile>> &board);

        bool CheckWinner();

    public:
        GameWindow(int height, int width, int mines, std::string playerName);

        void ExecuteGameWindow();
    };
}

#endif // WINDOW_H