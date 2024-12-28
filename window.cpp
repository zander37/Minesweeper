#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "window.h"


windows::WelcomeScreen::WelcomeScreen(int height, int width) :
window(sf::VideoMode(width * 32, (height * 32) + 100), "Minesweeper") {
    if (!font.loadFromFile("files/font.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }
    this->height = (height * 32) + 100;
    this->width = width *32;
    SetWelcomeText();
    SetEnterNameText();
    SetName();
}
void windows::WelcomeScreen::setText(sf::Text& text, float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

void windows::WelcomeScreen::SetWelcomeText() {
    welcomeText.setString("WELCOME TO MINESWEEPER!");
    welcomeText.setCharacterSize(24);
    welcomeText.setFont(font);
    welcomeText.setFillColor(sf::Color::White);
    welcomeText.setStyle(sf::Text::Bold);
    welcomeText.setStyle(sf::Text::Underlined);
    setText(welcomeText, width/2, (height/2)-150);
}
void windows::WelcomeScreen::SetEnterNameText() {
    enterNameText.setString("Enter your name:");
    enterNameText.setCharacterSize(20);
    enterNameText.setFont(font);
    enterNameText.setFillColor(sf::Color::White);
    enterNameText.setStyle(sf::Text::Bold);
    setText(enterNameText, width/2, (height/2)-75);
}
void windows::WelcomeScreen::SetName() {
    name.setFont(font);
    name.setString(showText);
    name.setCharacterSize(18);
    name.setFillColor(sf::Color::White);
    name.setStyle(sf::Text::Bold);
    setText(name, width/2, (height/2)-45);
}
void windows::WelcomeScreen::DrawWelcomeScreen(sf::RenderWindow& window) {
    window.clear(sf::Color::Blue);
    window.draw(welcomeText);
    window.draw(enterNameText);
    window.draw(name);
    setText(name, width/2, (height/2)-45);
}

void windows::WelcomeScreen::UpdateName() {
    if (!stringName.empty()) {
        showText = stringName.substr(0, 1);
        showText[0] = toupper((showText[0]));

        if (stringName.size() > 1) {
            std::string otherCharacters = stringName.substr(1);
            for (char& character : otherCharacters) {
                character = tolower(character);
            }
            showText += otherCharacters;
        }
    }
    else {
        showText = "";
    }
    showText += "|";
    name.setString(showText);
}

void windows::WelcomeScreen::GetKeyBoardInput(sf::Keyboard::Key key) {
    if (!stringName.empty() && key == sf::Keyboard::Backspace) {
        stringName = stringName.substr(0, stringName.size() - 1);
    }
    else if (key == sf::Keyboard::Enter) {
        if (!stringName.empty()) {
            stringName[0] = toupper(stringName[0]);
            window.close();
        }
    }
    else if (key == sf::Keyboard::A && stringName.length() < 10) {
        stringName += 'a';
    }
    else if (key == sf::Keyboard::B && stringName.length() < 10) {
        stringName += 'b';
    }
    else if (key == sf::Keyboard::C && stringName.length() < 10) {
        stringName += 'c';
    }
    else if (key == sf::Keyboard::D && stringName.length() < 10) {
        stringName += 'd';
    }
    else if (key == sf::Keyboard::E && stringName.length() < 10) {
        stringName += 'e';
    }
    else if (key == sf::Keyboard::F && stringName.length() < 10) {
        stringName += 'f';
    }
    else if (key == sf::Keyboard::G && stringName.length() < 10) {
        stringName += 'g';
    }
    else if (key == sf::Keyboard::H && stringName.length() < 10) {
        stringName += 'h';
    }
    else if (key == sf::Keyboard::I && stringName.length() < 10) {
        stringName += 'i';
    }
    else if (key == sf::Keyboard::J && stringName.length() < 10) {
        stringName += 'j';
    }
    else if (key == sf::Keyboard::K && stringName.length() < 10) {
        stringName += 'k';
    }
    else if (key == sf::Keyboard::L && stringName.length() < 10) {
        stringName += 'l';
    }
    else if (key == sf::Keyboard::M && stringName.length() < 10) {
        stringName += 'm';
    }
    else if (key == sf::Keyboard::N && stringName.length() < 10) {
        stringName += 'n';
    }
    else if (key == sf::Keyboard::O && stringName.length() < 10) {
        stringName += 'o';
    }
    else if (key == sf::Keyboard::P && stringName.length() < 10) {
        stringName += 'p';
    }
    else if (key == sf::Keyboard::Q && stringName.length() < 10) {
        stringName += 'q';
    }
    else if (key == sf::Keyboard::R && stringName.length() < 10) {
        stringName += 'r';
    }
    else if (key == sf::Keyboard::S && stringName.length() < 10) {
        stringName += 's';
    }
    else if (key == sf::Keyboard::T && stringName.length() < 10) {
        stringName += 't';
    }
    else if (key == sf::Keyboard::U && stringName.length() < 10) {
        stringName += 'u';
    }
    else if (key == sf::Keyboard::V && stringName.length() < 10) {
        stringName += 'v';
    }
    else if (key == sf::Keyboard::W && stringName.length() < 10) {
        stringName += 'w';
    }
    else if (key == sf::Keyboard::X && stringName.length() < 10) {
        stringName += 'x';
    }
    else if (key == sf::Keyboard::Y && stringName.length() < 10) {
        stringName += 'y';
    }
    else if (key == sf::Keyboard::Z && stringName.length() < 10) {
        stringName += 'z';
    }
    UpdateName();
}

bool windows::WelcomeScreen::ExecuteWelcomeScreen() {
    while(window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            }
            if (event.type == sf::Event::KeyPressed) {
                GetKeyBoardInput(event.key.code);
            }
        }
        DrawWelcomeScreen(window);
        window.display();
    }
    return true;
}

windows::LeaderBoard::LeaderBoard(int height, int width, bool winner, std::string playerName, int playerTime)
: window(sf::VideoMode((height * 16)+50,width*16), "Minesweeper") {
    if (!font.loadFromFile("files/font.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }
    if (winner) {
        GetPlayer("files/leaderboard.txt", playerName, playerTime);
    }
    GetLeaderBoardStats("files/leaderboard.txt");
    SetTitle(height, width);
    SetPlaceText(height, width);
}

void windows::LeaderBoard::setText(sf::Text& text, float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

void windows::LeaderBoard::SetTitle(int height, int width) {
    title.setString("LEADERBOARD");
    title.setCharacterSize(20);
    title.setFont(font);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold);
    title.setStyle(sf::Text::Underlined);
    setText(title, ((height * 16) + 50)/2, ((width * 16) / 2) - 120);
}

void windows::LeaderBoard::SetPlaceText(int height, int width) {
    std::string content = "";
    int place = 1;
    auto iter = leaderboard.begin();
    for (; iter != leaderboard.end() && place <= 5; iter++, place++) {
        content += (std::to_string(place) + ".\t" + iter->first + '\t' + iter->second + "\n\n");
    }

    contents.setString(content);
    contents.setCharacterSize(18);
    contents.setFont(font);
    contents.setFillColor(sf::Color::White);
    contents.setStyle(sf::Text::Bold);
    setText(contents, ((height * 16) + 50)/2, ((width * 16) / 2) + 20);
}

void windows::LeaderBoard::GetPlayer(std::string fileName, std::string name, int time) {
    GetLeaderBoardStats(fileName);

    std::string stringTime;
    int minutes = time / 60;
    int seconds = time % 60;

    if (minutes < 10) {
        stringTime += ("0" + std::to_string(minutes));
    } else stringTime += std::to_string(minutes);

    if (seconds < 10) {
        stringTime += (":0" + std::to_string(seconds));
    } else stringTime += (":" + std::to_string(seconds));

    leaderboard.emplace(stringTime, name + '*');

    while (leaderboard.size() > 5) {
        leaderboard.erase(prev(leaderboard.end()));
    }

    UpdateLeaderboard(fileName);
}

void windows::LeaderBoard::UpdateLeaderboard(std::string fileName) {

    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "File Failed To Open" << std::endl;
    }

    for (auto& iter : leaderboard) {
        file << iter.first + ", " + iter.second << '\n';
    }
    file.close();
}

void windows::LeaderBoard::GetLeaderBoardStats(std::string filePath) {
    std::map<std::string, std::string> temp1;

    std::ifstream file(filePath);

    if(!file.is_open()) {
        std::cerr << "File Does Not Exist." << std::endl;
    }

    std::string read;

    while(getline(file, read)) {

        int commaIndex = read.find(',');
        std::string time = read.substr(0, commaIndex);
        std::string name = read.substr(commaIndex + 2);

        temp1.emplace(time, name);
    }
    file.close();

    leaderboard = temp1;

}

void windows::LeaderBoard::ExecuteLeaderBoardWindow(bool& pause, bool& enabled) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                enabled = !enabled;
                pause = !pause;
                window.close();
            }
        }
        window.clear(sf::Color::Blue);
        window.draw(title);
        window.draw(contents);
        window.display();
    }
}

void windows::GameWindow::GetImages() {
    images[0].loadFromFile("files/images/tile_hidden.png");
    images[1].loadFromFile("files/images/tile_revealed.png");
    images[2].loadFromFile("files/images/mine.png");
    images[3].loadFromFile("files/images/flag.png");
    for (int i = 1; i <= 8; i++) {
        images[i + 3].loadFromFile("files/images/number_" + std::to_string(i) + ".png");
    }
    images[12].loadFromFile("files/images/face_happy.png");
    images[13].loadFromFile("files/images/face_win.png");
    images[14].loadFromFile("files/images/face_lose.png");
    images[15].loadFromFile("files/images/digits.png");
    images[16].loadFromFile("files/images/debug.png");
    images[17].loadFromFile("files/images/pause.png");
    images[18].loadFromFile("files/images/play.png");
    images[19].loadFromFile("files/images/leaderboard.png");
    images[20].loadFromFile("files/images/digits.png");
}

std::map<int, sf::Sprite> windows::GameWindow::GetDigits(sf::Sprite digits) {
    std::map<int, sf::Sprite> digitsMap;

    for (int i = 0; i < 11; i++) {
        sf::IntRect rect(i*21, 0, 21, 32);
        digits.setTextureRect(rect);
        sf::Sprite sprite = digits;
        digitsMap.emplace(i, sprite);
    }

    return digitsMap;
}

void windows::GameWindow::DrawBoard() {
    for (const std::vector<Tile>& row : board) {
        for (const Tile& tile : row) {
            window.draw(tile.backgroundImage);
            if ((tile.state == "Revealed" && (tile.adjacentMines > 0 || tile.isMine)) || tile.state == "Flagged") {
                window.draw(tile.topImage);
            }
        }
    }
}

void windows::GameWindow::DrawHiddenBoard() {
    for (const std::vector<Tile>& row : hiddenBoard) {
        for (const Tile& tile : row) {
            window.draw(tile.backgroundImage);
        }
    }
}

void windows::GameWindow::SetGameBoard() {
    for (int i = 0; i < NUMBER_ROWS; i++) {
        std::vector<Tile> row;
        board.push_back(row);
        for(int j = 0; j < NUMBER_COLUMNS; j++) {
            Tile tile;
            board[i].push_back(tile);
        }
    }
    for (int i = 0; i < NUMBER_ROWS; i++) {
        for (int j = 0; j < NUMBER_COLUMNS; j++) {
            board[i][j].backgroundImage.setTexture(images[0]);
            board[i][j].backgroundImage.setPosition(j * 32, i * 32);
            board[i][j].topImage.setPosition(j * 32, i * 32);
        }
    }
    GenerateMines();
}

void windows::GameWindow::SetHiddenBoard() {
    for (int i = 0; i < NUMBER_ROWS; i++) {
        std::vector<Tile> row;
        hiddenBoard.push_back(row);
        for(int j = 0; j < NUMBER_COLUMNS; j++) {
            Tile tile;
            hiddenBoard[i].push_back(tile);
        }
    }
    for (int i = 0; i < NUMBER_ROWS; i++) {
        for (int j = 0; j < NUMBER_COLUMNS; j++) {
            hiddenBoard[i][j].backgroundImage.setTexture(images[1]);
            hiddenBoard[i][j].topImage.setTexture(images[1]);
            hiddenBoard[i][j].backgroundImage.setPosition(j * 32, i * 32);
            hiddenBoard[i][j].topImage.setPosition(j * 32, i * 32);
        }
    }
}

void windows::GameWindow::IncreaseSurroundings(int x, int y) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int new_x = x + i;
            int new_y = y + j;
            if (new_x >= 0 && new_x < NUMBER_COLUMNS && new_y >= 0 && new_y < NUMBER_ROWS) {
                if (new_x != x || new_y != y) {
                    board[new_y][new_x].adjacentMines += 1;
                }
            }
        }
    }
}

void windows::GameWindow::ResetGameBoard() {
    ClearMines();
    SetGameBoard();
}

void windows::GameWindow::GenerateMines() {
    int minesPlaced = 0;
    srand(static_cast<unsigned int>(time(nullptr)));
    while (minesPlaced < NUMBER_MINES) {
        int x = rand() % 25;
        int y = rand() % 16;
        if(!board[y][x].isMine) {
            board[y][x].isMine = true;
            IncreaseSurroundings(x, y);
            minesPlaced++;
        }
    }
}

void windows::GameWindow::ClearMines() {
    for (std::vector<Tile>& row : board) {
        for (Tile& tile : row) {
            tile.isMine = false;
            tile.adjacentMines = 0;
            tile.state = "Hidden";
            tile.topImage.setTexture(images[0]);
        }
    }
}

void windows::GameWindow::Reveal(int x, int y) {
    if (board[y][x].state == "Hidden") {
        board[y][x].state = "Revealed";
        board[y][x].backgroundImage.setTexture(images[1]);
        if (board[y][x].isMine) {
            board[y][x].topImage.setTexture(images[2]);
            RevealAllMines();
            gameOver = true;
        }
        else if (board[y][x].adjacentMines > 0) {
            board[y][x].topImage.setTexture(images[3 + board[y][x].adjacentMines]);
        }
        else {
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int new_x = x + i;
                    int new_y = y + j;
                    if (new_x >= 0 && new_x < NUMBER_COLUMNS && new_y >= 0 && new_y < NUMBER_ROWS
                        && board[new_y][new_x].state == "Hidden") {
                        Reveal(new_x, new_y);
                    }
                }
            }
        }
    }
}

void windows::GameWindow::Flag(int x, int y) {
    if (board[y][x].state == "Hidden") {
        minesRemaining -= 1;
        board[y][x].state = "Flagged";
        board[y][x].topImage.setTexture(images[3]);
    }
    else if (board[y][x].state == "Flagged") {
        minesRemaining += 1;
        board[y][x].state = "Hidden";
        board[y][x].topImage.setTexture(images[0]);
    }
}

void windows::GameWindow::RevealAllMines() {
    for (std::vector<Tile>& row : board) {
        for (Tile& tile : row) {
            if (tile.isMine) {
                tile.state = "Revealed";
                tile.topImage.setTexture(images[2]);
                tile.backgroundImage.setTexture(images[1]);
            }
        }
    }
}

void windows::GameWindow::FlagAllMines() {
    minesRemaining = 0;
    for (std::vector<Tile>& row : board) {
        for (Tile& tile : row) {
            if (tile.isMine && tile.state != "Flagged") {
                tile.state = "Flagged";
                tile.topImage.setTexture(images[3]);
            }
        }
    }
}

int windows::GameWindow::GetNumberOfFlags(std::vector<std::vector<Tile>>& board) {
    int numberOfFlags = 0;
    for (std::vector<Tile>& row : board) {
        for (Tile& tile : row) {
            if (tile.state == "Flagged") {
                numberOfFlags += 1;
            }
        }
    }
    return numberOfFlags;
}

bool windows::GameWindow::CheckWinner() {
    int numberRevealed = 0;
    for (std::vector<Tile>& row : board) {
        for (Tile& tile : row) {
            if (!tile.isMine && tile.state == "Revealed") {
                numberRevealed += 1;
            }
        }
    }
    if (numberRevealed == (NUMBER_ROWS * NUMBER_COLUMNS) - NUMBER_MINES) {
        FlagAllMines();
        return true;
    }
    return false;
}

windows::GameWindow::GameWindow(int height, int width, int mines, std::string playerName) :
window(sf::VideoMode(width * 32, (height * 32) + 100), "Minesweeper"),
    debugButton(NUMBER_ROWS, NUMBER_COLUMNS, images[16]),
    happyButton(NUMBER_ROWS, NUMBER_COLUMNS, images[12]),
    pauseButton(NUMBER_ROWS, NUMBER_COLUMNS, images[17]),
    leaderBoardButton(NUMBER_ROWS, NUMBER_COLUMNS, images[19]), playerName(playerName) {
    this->NUMBER_ROWS = height;
    this->NUMBER_COLUMNS = width;
    this->NUMBER_MINES = mines;
    GetImages();
    SetGameBoard();
    SetHiddenBoard();
    debugButton = buttons::DebugButton(NUMBER_ROWS, NUMBER_COLUMNS, images[16]);
    happyButton = buttons::HappyButton(NUMBER_ROWS, NUMBER_COLUMNS, images[12]);
    pauseButton = buttons::PauseButton(NUMBER_ROWS, NUMBER_COLUMNS, images[17]);
    leaderBoardButton = buttons::LeaderBoardButton(NUMBER_ROWS, NUMBER_COLUMNS, images[19]);
    minesRemaining = NUMBER_MINES;
}

void windows::GameWindow::ExecuteGameWindow() {

    auto startTime = std::chrono::high_resolution_clock::now();

    auto pauseTime = std::chrono::high_resolution_clock::now();
    auto elapsedPausedTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - pauseTime).count();

    int totalTime;

    bool paused = false;
    bool timerIsActive = true;

    sf::Texture& digitsText = images[20];
    sf::Sprite digits;
    digits.setTexture(digitsText);

    sf::Sprite negativeSign;
    sf::Sprite mineCountTens;
    sf::Sprite mineCountOnes;

    sf::Sprite min0;
    sf::Sprite min1;
    sf::Sprite sec0;
    sf::Sprite sec1;

    std::map<int, sf::Sprite> digitsMap = GetDigits(digits);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && happyButton.IsClicked(window) && gameOver) {
                happyButton.ChangeState(window, images[12]);
                happyButton.DrawButton(window);
                ResetGameBoard();
                DrawBoard();
                window.display();

                startTime = std::chrono::high_resolution_clock::now();
                pauseTime = std::chrono::high_resolution_clock::now();
                elapsedPausedTime = 0;
                timerIsActive = true;
                gameOver = false;
                winner = false;
            }
            else if (event.type == sf::Event::MouseButtonPressed && leaderBoardButton.IsClicked(window) && !paused) {
                leaderboardEnabled = !leaderboardEnabled;
                if (leaderboardEnabled || pauseEnabled) {
                    DrawHiddenBoard();
                    window.display();
                }
                pauseTime = std::chrono::high_resolution_clock::now();
                LeaderBoard leaderboard(NUMBER_ROWS, NUMBER_COLUMNS, winner, playerName, totalTime);
                paused = !paused;
                leaderboard.ExecuteLeaderBoardWindow(paused, leaderboardEnabled);
                auto unPausedTime = std::chrono::high_resolution_clock::now();
                elapsedPausedTime += std::chrono::duration_cast<std::chrono::seconds>(unPausedTime - pauseTime).count();
            }
            else if (event.type == sf::Event::MouseButtonPressed && !gameOver) {
                int x = event.mouseButton.x / 32;
                int y = event.mouseButton.y / 32;
                if (x < 25 && y < 16) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        Reveal(x, y);
                    }
                    else if (event.mouseButton.button == sf::Mouse::Right) {
                        Flag(x, y);
                        int numberOfFlags = GetNumberOfFlags(board);
                    }
                }
                else if (happyButton.IsClicked(window) && !paused) {
                    minesRemaining = NUMBER_MINES;
                    totalTime = 0;
                    happyButton.ChangeState(window, images[12]);
                    ResetGameBoard();
                    DrawBoard();
                    window.display();

                    startTime = std::chrono::high_resolution_clock::now();
                    pauseTime = std::chrono::high_resolution_clock::now();
                    elapsedPausedTime = 0;
                    timerIsActive = true;
                    gameOver = false;
                    winner = false;
                }
                else if (debugButton.IsClicked(window) && !winner) {
                    if (!debugMode) {
                        debugButton.RevealAllMinesDebug(board, images[2]);
                        debugMode = true;
                    }
                    else if (debugMode) {
                        debugButton.HideAllMinesDebug(board, images[0]);
                        debugMode = false;
                    }
                }
                else if (pauseButton.IsClicked(window) && !gameOver && !winner) {
                    paused = !paused;
                    pauseEnabled = !pauseEnabled;
                    if (pauseEnabled) {
                        DrawHiddenBoard();
                        happyButton.DrawButton(window);
                        debugButton.DrawButton(window);
                        leaderBoardButton.DrawButton(window);

                    }
                    if (paused) {
                        pauseTime = std::chrono::high_resolution_clock::now();
                    }
                    else {
                        auto unPausedTime = std::chrono::high_resolution_clock::now();
                        elapsedPausedTime += std::chrono::duration_cast<std::chrono::seconds>(unPausedTime - pauseTime).count();
                        pauseButton.ChangeState(window, images[17]);
                    }
                }
            }
        }

        window.clear(sf::Color::White);

        if (minesRemaining < 0) {
            int counterTens = abs(minesRemaining) / 10;
            int counterOnes = abs(minesRemaining) % 10;

            negativeSign = digitsMap[10];
            mineCountTens = digitsMap[counterTens];
            mineCountTens.setPosition(33, 32 * (NUMBER_ROWS + 0.5) + 16);
            mineCountOnes = digitsMap[counterOnes];
            mineCountOnes.setPosition(51, 32 * (NUMBER_ROWS + 0.5) + 16);
        }
        else {
            int counterTens = minesRemaining / 10;
            int counterOnes = minesRemaining % 10;

            negativeSign = digitsMap[0];
            mineCountTens = digitsMap[counterTens];
            mineCountTens.setPosition(33, 32 * (NUMBER_ROWS + 0.5) + 16);
            mineCountOnes = digitsMap[counterOnes];
            mineCountOnes.setPosition(51, 32 * (NUMBER_ROWS + 0.5) + 16);
        }
        negativeSign.setPosition(12, 32 * (NUMBER_ROWS + 0.5) + 16);

        window.draw(negativeSign);
        window.draw(mineCountTens);
        window.draw(mineCountOnes);

        if (!leaderboardEnabled && !pauseEnabled) {
            DrawBoard();
        }
        else if (leaderboardEnabled || pauseEnabled) {
            DrawHiddenBoard();
        }

        happyButton.DrawButton(window);
        debugButton.DrawButton(window);
        pauseButton.DrawButton(window);
        leaderBoardButton.DrawButton(window);

        if (!gameOver && timerIsActive) {
            auto gameDuration = std::chrono::duration_cast<std::chrono::seconds>(
                    std::chrono::high_resolution_clock::now() - startTime);
            totalTime = gameDuration.count();

            int minutes;
            int seconds;

            if (!paused) {
                totalTime = totalTime - elapsedPausedTime;
                minutes = totalTime / 60;
                seconds = totalTime % 60;
            }

            int minutes0 = minutes / 10 % 10;
            int minutes1 = minutes % 10;
            int seconds0 = seconds / 10 % 10;
            int seconds1 = seconds % 10;

            min0 = digitsMap[minutes0];
            min0.setPosition((NUMBER_COLUMNS * 32) - 97, 32 * (NUMBER_ROWS + 0.5) + 16);
            min1 = digitsMap[minutes1];
            min1.setPosition((NUMBER_COLUMNS * 32) - 76, 32 * (NUMBER_ROWS + 0.5) + 16);
            sec0 = digitsMap[seconds0];
            sec0.setPosition((NUMBER_COLUMNS * 32) - 54, 32 * (NUMBER_ROWS + 0.5) + 16);
            sec1 = digitsMap[seconds1];
            sec1.setPosition((NUMBER_COLUMNS * 32) - 33, 32 * (NUMBER_ROWS + 0.5) + 16);

            window.draw(min0);
            window.draw(min1);
            window.draw(sec0);
            window.draw(sec1);

        }

        window.draw(min0);
        window.draw(min1);
        window.draw(sec0);
        window.draw(sec1);

        if (paused) {
            pauseButton.ChangeState(window, images[18]);
        }

        window.display();

        if (gameOver) {
            timerIsActive = false;
            happyButton.ChangeState(window, images[14]);
            DrawBoard();
            happyButton.DrawButton(window);
            window.display();
        }
        else if (CheckWinner() && !gameOver && !winner) {
            timerIsActive = false;
            winner = true;
            FlagAllMines();
            window.draw(negativeSign);
            window.draw(mineCountTens);
            window.draw(mineCountOnes);
            happyButton.ChangeState(window, images[13]);
            DrawBoard();
            happyButton.DrawButton(window);
            window.display();
        }

    }
}
