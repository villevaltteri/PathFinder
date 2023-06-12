#include "Board.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Board::Board() : 
    window(sf::VideoMode(gridSize * tileSize + gridSize, gridSize * tileSize + gridSize), "My window")
{
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            sf::RectangleShape n({tileSize, tileSize});
            n.setFillColor(sf::Color::White);
            n.setPosition({tileSize * j + j , tileSize * i + i});
            grid.push_back(n);
        }
    }
}

void
Board::handleMouseEvent(sf::Event event) 
{
    int x = sf::Mouse::getPosition(window).x / tileSize;
    int y = sf::Mouse::getPosition(window).y / tileSize;
    std::cout << x << " " << y << "\n";
    if (event.mouseButton.button == sf::Mouse::Left) {
        grid.at(start.x + start.y * gridSize).setFillColor(sf::Color::White);
        if (x < gridSize && x >= 0 && y < gridSize && y >= 0) {
            grid.at(x + y * gridSize).setFillColor(sf::Color::Green);
            start.x = x;
            start.y = y;
        }

    }
    if (event.mouseButton.button == sf::Mouse::Right) {
        grid.at(end.x + end.y * gridSize).setFillColor(sf::Color::White);
        if (x < gridSize && x >= 0 && y < gridSize && y >= 0) {
            grid.at(x + y * gridSize).setFillColor(sf::Color::Red);
            end.x = x;
            end.y = y;
        }
    }

    if (event.mouseButton.button == sf::Mouse::Middle) {
        if (x < gridSize && x >= 0 && y < gridSize && y >= 0) {       
            grid.at(x + y * gridSize).setFillColor(sf::Color::Black);
        }
    }
}

void
Board::Draw()
{
    for (int i = 0; i < (gridSize * gridSize); i++) {
        window.draw(grid.at(i));
    }
}

void 
Board::handleKeyPress(sf::Event event)
{
    if (event.key.code == 27) {
        PathFinder p(grid, start, end, 1, gridSize);
        
    }
}

void
Board::Run()
{
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                handleMouseEvent(event);
            }

            if (event.type == sf::Event::KeyPressed) {
                handleKeyPress(event);
            }
        }
        window.clear();
        Draw();
        window.display();
    }
}
