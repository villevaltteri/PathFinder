#include "PathFinder.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

PathFinder::PathFinder(std::vector<sf::RectangleShape> &grid, Coordinates start, 
                       Coordinates end, short algorithm, int gridSize) : start(start), end(end), pathingAlgorithm(algorithm),
                       board(gridSize, std::vector<int>(gridSize, 0))
{
    ConverGrid(grid, gridSize);
}

void
PathFinder::ConverGrid(std::vector<sf::RectangleShape> &grid, int gridSize)
{
    size_t j {};
    for (size_t i {}; i < grid.size(); i++) {
        if (i % gridSize == 0 && i != 0) j++;

        sf::Color colorAtCell = grid.at(i).getFillColor();

        if (colorAtCell == sf::Color::White) {
            board[j][i % gridSize] = 0;
        } else if (colorAtCell == sf::Color::Black) {
            board[j][i % gridSize] = 1;
        } else if (colorAtCell == sf::Color::Green) {
            board[j][i % gridSize] = 2;
        } else if (colorAtCell == sf::Color::Red) {
            board[j][i % gridSize] = 3;
        }
    }

    for (const auto &row : board) {
        for (const auto &element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

}

void
PathFinder::PickTheAlgorithm()
{
    switch (pathingAlgorithm)
    {
    case 1:
        /* code */
        break;
    
    default:
        break;
    }
}