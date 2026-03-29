#include "cmpt_error.h"
#include "board.cpp"

#include <vector>
#include <cstdlib>
#include <ctime>

// Returns an int containing a random legal column move
// Throws a runtime error if there are no empty columns
int random_legal_move(const Board& board)
{
    // Keep track of legal columns which will later be picked from
    std::vector<int> legal_cols;
    int cols = board.get_cols();

    for (int col = 0; col < cols; col++)
    {
        if (board.is_legal_col(col))
        {
            legal_cols.push_back(col);
        }
    }

    if (legal_cols.empty())
    {
        cmpt::error("Error: There are no legal moves");
    }

    // Return random legal column

    srand(time(0));
    int random_idx = rand() % legal_cols.size();
    if (random_idx > legal_cols.size())
    {
        cmpt::error("Error: Random col idx not in legal cols range");
    }

    return legal_cols[random_idx];
}
