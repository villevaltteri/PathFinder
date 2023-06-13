#ifndef Astar_hpp
#define Astar_hpp

#include "PathFinder.hpp"
#include <vector>

class Astar
{
public:
    /**
     * Astar constructor
     * 
     * @param board The board representing the map.
     * @param start The starting coordinates.
     * @param end The ending coordinates.
    */
    Astar(std::vector<std::vector<int>> board, Coordinates start, Coordinates end);

    /**
     * Search function performs the A* search algortihm.
     * 
     * @return The board with the A* path
    */
    std::vector<std::vector<int>> Search();

private:
    std::vector<std::vector<int>> board;        // The board representing the map
    std::vector<std::vector<int>> openPoints;   // Open points to explore
    const Coordinates start;                    // Starting coordinates
    const Coordinates end;                      // Ending coordinates

    /**
     * Heuristic function calculates the absolute value between two points.
     * 
     * @param y The y-coordinate of the first point.
     * @param x The x-coordinate of the first point.
     * @param y2 The y-coordinate of the second point.
     * @param x2 The x-coordinate of the second point.
     * 
     * @return The heuristic value.
    */
    int Heuristic(int y, int x, int y2, int x2);

    /**
     * CheckValidCell function check if the y and x coordinates are valid.
     * If they are limits of the board and the cell is free e.g '0'.
     * 
     * @param y The y-coordinate of the cell.
     * @param x The x-coordinate of the cell.
     * 
     * @return True if the cell is valid, false otherwise.
    */
    bool CheckValidCell(int y, int x);

    /**
     * AddToOpen function adds a cell to the openPoints list.
     * 
     * @param y The y-coordinate of the cell.
     * @param x The x-coordinate of the cell.
     * @param h The heuristic value.
     * @param g The cost to reach the cell.
     * 
     * @return Nothing
    */
    void AddToOpen(int y, int x, int h, int g);

    /**
     * ExpandNeighbours function exapands the neighbors of a given cell.
     * 
     * @param bestOption The cell to expand neighbours for.
     * 
     * @return Nothing
    */
    void ExpandNeighbours(const std::vector<int> &bestOption);

    /**
     * SortOpenList function compares two cells based on their g and h value.
     * 
     * @param a The first cell.
     * @param b The second cell.
     * 
     * @return True if the g + h value of cell a is greater than cell b's, false otherwise.
    */
    static bool SortOpenList(const std::vector<int> &a, const std::vector<int> &b);
};

#endif