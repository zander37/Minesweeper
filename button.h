#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <vector>
#include <chrono>
#include <SFML/Graphics.hpp>

struct Tile {
    std::string TileStates[3] = {"Hidden", "Revealed", "Flagged"};
    sf::Sprite backgroundImage;
    sf::Sprite topImage;
    int adjacentMines = 0;
    bool isMine = false;
    std::string state = TileStates[0];
};

namespace buttons {

    class DebugButton {

    private:
        sf::Sprite sprite;

    public:
        DebugButton(int height, int width, sf::Texture &texture);

        void DrawButton(sf::RenderWindow &window);

        static void RevealAllMinesDebug(std::vector<std::vector<Tile>> &board, sf::Texture &texture);

        void HideAllMinesDebug(std::vector<std::vector<Tile>> &board, sf::Texture &texture);

        bool IsClicked(sf::RenderWindow &window);
    };

    class HappyButton {

    private:
        sf::Sprite sprite;

    public:
        HappyButton(int height, int width, sf::Texture &texture);

        void DrawButton(sf::RenderWindow &window);

        void ChangeState(sf::RenderWindow &window, sf::Texture &texture);

        bool IsClicked(sf::RenderWindow &window);
    };

    class PauseButton {
    private:
        sf::Sprite sprite;

    public:
        PauseButton(int height, int width, sf::Texture &texture);

        void DrawButton(sf::RenderWindow &window);

        void ChangeState(sf::RenderWindow &window, sf::Texture &texture);

        bool IsClicked(sf::RenderWindow &window);
    };

    class LeaderBoardButton {
    private:
        sf::Sprite sprite;

    public:
        LeaderBoardButton(int height, int width, sf::Texture &texture);

        void DrawButton(sf::RenderWindow &window);

        bool IsClicked(sf::RenderWindow &window);
    };
}

#endif // BUTTON_H