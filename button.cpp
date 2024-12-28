#include <iostream>
#include <vector>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "button.h"

buttons::DebugButton::DebugButton(int height, int width, sf::Texture &texture) {
    sprite.setTexture(texture);
    sprite.setPosition((width * 32) - 304, 32 * (height + 0.5));
}

void buttons::DebugButton::DrawButton(sf::RenderWindow &window) {
    window.draw(sprite);
}

void buttons::DebugButton::RevealAllMinesDebug(std::vector<std::vector<Tile>>& board, sf::Texture& texture) {
    for (std::vector<Tile>& row : board) {
        for (Tile& tile : row) {
            if (tile.isMine) {
                tile.state = "Revealed";
                tile.topImage.setTexture(texture);
            }
        }
    }
}

void buttons::DebugButton::HideAllMinesDebug(std::vector<std::vector<Tile>>& board, sf::Texture& texture) {
    for (std::vector<Tile>& row : board) {
        for (Tile& tile : row) {
            if (tile.isMine) {
                tile.state = "Hidden";
                tile.topImage.setTexture(texture);
            }
        }
    }
}

bool buttons::DebugButton::IsClicked(sf::RenderWindow& window) {
    int x = sf::Mouse::getPosition(window).x;
    int y = sf::Mouse::getPosition(window).y;

    sf::FloatRect area = sprite.getGlobalBounds();
    if (area.contains(x, y)) {
        return true;
    }
    return false;
}

buttons::HappyButton::HappyButton(int height, int width, sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition(((width / 2) * 32) - 32, 32 * (height + 0.5));
}

void buttons::HappyButton::DrawButton(sf::RenderWindow& window) {
    window.draw(sprite);
}

void buttons::HappyButton::ChangeState(sf::RenderWindow& window, sf::Texture& texture) {
    sprite.setTexture(texture);
    window.draw(sprite);
}

bool buttons::HappyButton::IsClicked(sf::RenderWindow& window) {
    int x = sf::Mouse::getPosition(window).x;
    int y = sf::Mouse::getPosition(window).y;

    sf::FloatRect area = sprite.getGlobalBounds();
    if (area.contains(x, y)) {
        return true;
    }
    return false;
}

buttons::PauseButton::PauseButton(int height, int width, sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition((width * 32) - 240, 32 * (height + 0.5));
}

void buttons::PauseButton::DrawButton(sf::RenderWindow& window) {
    window.draw(sprite);
}

void buttons::PauseButton::ChangeState(sf::RenderWindow& window, sf::Texture& texture) {
    sprite.setTexture(texture);
    window.draw(sprite);
}

bool buttons::PauseButton::IsClicked(sf::RenderWindow &window) {
    int x = sf::Mouse::getPosition(window).x;
    int y = sf::Mouse::getPosition(window).y;

    sf::FloatRect area = sprite.getGlobalBounds();
    if (area.contains(x, y)) {
        return true;
    }
    return false;
}

buttons::LeaderBoardButton::LeaderBoardButton(int height, int width, sf::Texture& texture) {
    sprite.setTexture(texture);
    sprite.setPosition((width * 32) - 176, 32 * (height + 0.5));
}

void buttons::LeaderBoardButton::DrawButton(sf::RenderWindow& window) {
    window.draw(sprite);
}

bool buttons::LeaderBoardButton::IsClicked(sf::RenderWindow &window) {
    int x = sf::Mouse::getPosition(window).x;
    int y = sf::Mouse::getPosition(window).y;

    sf::FloatRect area = sprite.getGlobalBounds();
    if (area.contains(x, y)) {
        return true;
    }
    return false;
}
