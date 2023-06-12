#ifndef Astar_hpp
#define Astar_hpp

#include "PathFinder.hpp"
#include <vector>

class Astar
{
public:
    Astar(std::vector<std::vector<int>>, Coordinates, Coordinates);
    std::vector<std::vector<int>> Search();
private:
    std::vector<std::vector<int>> board;
    std::vector<std::vector<int>> openPoints;
    const Coordinates start;
    const Coordinates end;
    int Heuristic(int, int, int, int);
    bool CheckValidCell(int, int);
    void AddToOpen(int, int, int, int);
    void ExpandNeighbours(const std::vector<int>&);
    static bool SortOpenList(const std::vector<int>&, const std::vector<int>&);
};

#endif