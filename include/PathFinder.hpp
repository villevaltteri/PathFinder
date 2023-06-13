#ifndef PathFinder_hpp
#define PathFinder_hpp

#include <SFML/Graphics.hpp>
#include <vector>

/**
 * Coordinates structure holds x-coordinate and y-coordinate of the cell
*/
struct Coordinates
{
    int x;
    int y;
};

class PathFinder
{
public:
    /**
     * PathFinder constructor.
     * 
     * @param grid Orginal map from the board class
     * @param start Start coordinates
     * @param end End coordinates
     * @param algorithm Which algorithm is choosen
     * @param gridSize Size of the grid
    */
    PathFinder(std::vector<sf::RectangleShape> &grid, Coordinates start, Coordinates end,
              short algorithm, int gridSize);
private:
    const short pathingAlgorithm;           // Holds the algortihm that is choosen
    const Coordinates start;                // Start coordinates
    const Coordinates end;                  // End coordinates
    std::vector<std::vector<int>> board;    // Holds the converted grid from std::vector<sf::RectangleShape> -> std::vector<std::vector<int>>

    /**
     * Converts the grid from std::vector<sf::RectangleShape>> to std::vector<std::vector<int>>
     * Mainly done so class Board works with existing code.
     * 
     * @param grid Orginal map from the board class
     * @param gridSize Size of the grid
     * 
     * @return Nothing
    */
    void ConverGrid(std::vector<sf::RectangleShape> &grid, int gridSize);
    void PickTheAlgorithm();
};

#endif