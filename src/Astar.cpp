#include "Astar.hpp"
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>

Astar::Astar(std::vector<std::vector<int>> board, Coordinates start, Coordinates end):
        board(board), start(start), end(end)
{

}

int
Astar::Heuristic(int y, int x, int y2, int x2)
{
    return std::abs(y2 - y) + std::abs(x2 - x);
}

bool
Astar::CheckValidCell(int y, int x)
{
    bool validY = (0 <= y && y < board.size());
    bool validX = (0 <= x && x < board[0].size());
    if (validX && validY) {
        return board[y][x] == 0;
    }
    return false;
}

void
Astar::AddToOpen(int y, int x, int h, int g)
{
    openPoints.push_back(std::vector<int>{y, x, h, g});
    board[y][x] = 4;
}

void
Astar::ExpandNeighbours(const std::vector<int> &bestOption)
{
    std::vector<std::pair<int, int>> delta {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int y = bestOption.at(0);
    int x = bestOption.at(1);
    int g = bestOption.at(2);

    for (size_t i {}; i < delta.size(); i++) {
        int newY = y + delta[i].first;
        int newX = x + delta[i].second;
        if (CheckValidCell(newY, newX)) {
            int newH = Heuristic(newY, newX, end.y, end.x);
            int newG = g + 1;
            AddToOpen(newY, newX, newH, newG);
        }
    }
}

bool
Astar::SortOpenList(const std::vector<int> &a, const std::vector<int> &b)
{
    int sumA = a[a.size() - 1] + a[a.size() - 2];
    int sumB = b[b.size() - 1] + b[b.size() - 2];
    return sumA > sumB;
}

std::vector<std::vector<int>>
Astar::Search()
{
    int y = start.y;
    int x = start.x;
    int h = Heuristic(y, x, end.y, end.x);
    int g = 0;
    AddToOpen(y, x, h, g);
    while (!openPoints.empty()) {
        std::sort(openPoints.begin(), openPoints.end(), SortOpenList);
        std::vector<int> bestOption = openPoints.back();
        openPoints.pop_back();
        int newY = bestOption[0];
        int newX = bestOption[1];
        board[newY][newX] = 5;
        if (newY == end.y && newX == end.x) {
            board[end.y][end.x] = 5;
            return board;
        }
        ExpandNeighbours(bestOption);
    }
    return board;
}


