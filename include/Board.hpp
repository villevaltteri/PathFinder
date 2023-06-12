#ifndef Board_hpp
#define Board_hpp

#include "PathFinder.hpp"
#include <SFML/Graphics.hpp>
#include <vector>


class Board
{
public:
    Board();
    void Run();

private:
    const int gridSize {16};
    const float tileSize {50.0};
    sf::RenderWindow window;
    std::vector<sf::RectangleShape> grid;
    Coordinates start {0,0};
    Coordinates end {14, 14};
    void Draw();
    void handleMouseEvent(sf::Event);
    void handleKeyPress(sf::Event);
};

#endif
