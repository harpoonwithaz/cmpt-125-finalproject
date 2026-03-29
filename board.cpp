#include "piece.h"

#include <vector>

class Board {
    private:
        std::vector<std::vector<Piece>> board_matrix;
        int rows;
        int cols;
    public:
        // Constructor initilaizes an empty board with 6 rows and 7 columns
        Board(): rows(6), cols(7)
        {
            // board_matrix(rows, std::vector<Piece>(cols, Piece::Empty));
        }
};
