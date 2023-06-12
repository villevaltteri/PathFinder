#ifndef PathFinder_hpp
#define PathFinder_hpp

#include <SFML/Graphics.hpp>
#include <vector>

struct Coordinates
{
    int x;
    int y;
};

class PathFinder
{
public:
    PathFinder(std::vector<sf::RectangleShape>&, Coordinates, Coordinates, short, int);
private:
    const short pathingAlgorithm;
    const Coordinates start;
    const Coordinates end;
    std::vector<std::vector<int>> board;
    void ConverGrid(std::vector<sf::RectangleShape>&, int);
};

#endif