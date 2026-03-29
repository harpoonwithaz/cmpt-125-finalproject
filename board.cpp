#include "piece.h"
#include <iostream>
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
            // Initalize board to be all empty pieces
            board_matrix.resize(rows);
            for (int row = 0; row < 6; row++) {
                for (int col = 0; col < 7; col++) {
                    board_matrix[row].push_back(Piece::Empty);
                }
            }
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

        void print_board(){
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                // std::cout << "2" << std::endl;
                switch (board_matrix[row][col]) {
                    case Piece::Empty:
                        std::cout << ".";
                        break;
                    case Piece::Player1:
                        std::cout << "X";
                        break;
                    case Piece::Player2:
                        std::cout << "O";
                        break;
                
                }
            }
            std::cout << std::endl;
        }
    }
};
