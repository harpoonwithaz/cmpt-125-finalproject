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

        // Getter methods
        int get_rows() const
        {
            return rows;
        }
        int get_cols() const
        {
            return cols;
        }

        bool is_legal_col(int col) const
        {
            bool seen_empty = false;
            for (int r = 0; r < rows; r++)
            {
                if (board_matrix[col][r] == Piece::Empty) seen_empty = true;
                else if (!seen_empty) return false;
            }
            return true;
        }
};
