// #include "board.h"
// #include "computer_strategy.cpp"
#include "cmpt_error.h"
#include "piece.h"

#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <ctime>

#include <stdexcept>

// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"

#define CIRCLE "\u25EF"

class Board {
    private:
        std::vector<std::vector<Piece>> board_matrix;
        int rows;
        int cols;
    public:
        // Constructor initilaizes an 6 x 7 board with all empty pieces
        Board(): rows(6), cols(7)
        {
            board_matrix.resize(rows);
            for (int row = 0; row < 6; row++) {
                for (int col = 0; col < 7; col++) {
                    board_matrix[row].push_back(Piece::Empty);
                }
            }
        }

        // Getter methods
        std::vector<std::vector<Piece>> get_board() const
        {
            return board_matrix;
        }

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
            if (col < 0 || col >= cols) return false;

            // We just care if the first slot is legal, and the other ones don't matter
            return (board_matrix[0][col] == Piece::Empty);
        }

        void print_board()
        {
            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    switch (board_matrix[row][col])
                    {
                        case Piece::Empty:
                            std::cout << ".";
                            break;
                        case Piece::Player1:
                            std::cout << RED << CIRCLE << RESET;
                            break;
                        case Piece::Player2:
                            std::cout << YELLOW << CIRCLE << RESET;
                            break;
                    }
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        void place_piece(int col, Piece piece)
        {
            if (!is_legal_col(col))
            {
                cmpt::error("Error: Cannot add piece since it isn't a legal move");
            }

            // Add piece at first available row starting from the bottom
            for (int row = (rows - 1); row >= 0; row--)
            {
                if (board_matrix[row][col] == Piece::Empty)
                {
                    board_matrix[row][col] = piece;
                    return;
                }
            }
        }

        // Returns gamestate struct containing piece that won
        bool check_win()
        {
            for (int row = (rows-1); row >= 0; row--)
            {
                for (int col = 0; col < cols; col++)
                {
                    Piece p = board_matrix[row][col];
                    if (p == Piece::Empty) continue;

                    // Horizontal check
                    if (col + 3 < cols &&
                    p == board_matrix[row][col+1] && p == board_matrix[row][col+2] && p == board_matrix[row][col+3])
                    {
                        return true;
                    }

                    // Vertical check
                    if (row - 3 >= 0 &&
                    p == board_matrix[row-1][col] && p == board_matrix[row-2][col] && p == board_matrix[row-3][col])
                    {
                        return true;
                    }

                    // Diagonal up
                    if (row - 3 >= 0 && col + 3 < cols &&
                        p == board_matrix[row-1][col+1] && p == board_matrix[row-2][col+2] && p == board_matrix[row-3][col+3])
                    {
                        return true;
                    }

                    // Diagonal down
                    if (row + 3 < rows && col + 3 < cols &&
                        p == board_matrix[row+1][col+1] && p == board_matrix[row+2][col+2] && p == board_matrix[row+3][col+3])
                    {
                        return true;
                    }
                }
            }

            return false;
        }
};



// ==========================================================
//                     Computer Strategy
// ==========================================================
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

    std::srand(std::time(0));
    int random_idx = std::rand() % legal_cols.size();
    if (random_idx > legal_cols.size())
    {
        cmpt::error("Error: Random col idx not in legal cols range");
    }

    return legal_cols[random_idx];
}

// ==========================================================
//                     Helper functions
// ==========================================================
//
void clear_screen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void title_screen()
{

}


// ==========================================================
//                     Game Interaction
// ==========================================================
//
int get_input(const Board& board)
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        try
        {
            size_t pos;
            int value = std::stoi(line, &pos);

            // Strict checking for only numeric inputs
            // stoi successfully converts 42abc to 42, so we verify the length
            if (pos < line.length())
            {
                cmpt::error("input must only contain numbers");
            }

            if (!board.is_legal_col(value))
            {
                cmpt::error("must be a legal column on the board");
            }

            return value;
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Error: input must be all numeric characters. Try again: ";
        }
        catch (const std::runtime_error& e)
        {
            std::cout << "Error: " << e.what() << ". Try again: ";
        }
        catch (...)
        {
            std::cout << "Error: Unknown. Try again: ";
        }
    }

    cmpt::error("Unexpected error getting input");
    return -1;
}

// hard coded test values for now
void play_computer()
{
    Board board;
    bool computer_move = false;
    int move;

    // Decide if player or computer goes first
    std::string order;
    std::cout << "Which order do you want to go in?" << std::endl
              << "\tFirst"  << std::cout.width(4) << "(type \'f\')" << std::endl
              << "\tSecond" << std::cout.width(4) << "(type \'s\')" << std::endl
              << "\tRandom" << std::cout.width(4) << "(type \'r\')" << std::endl
              << "--> ";
    while (std::getline(std::cin, order))
    {
        if (order == "f")
        {
            break;
        }
        else if (order == "s")
        {
            computer_move = true;
            break;
        }
        else if (order == "r")
        {
            std::srand(std::time(0));
            computer_move = std::rand() % 2;
            break;
        }
        else
        {
            std::cout << "Unrecognized choice. Try Again: ";
        }
    }

    // GAME LOOP:
    // - Clear screen, Print board, Ask for which column
    // - Check legal col, if not loop back to 1
    // - Place piece
    while (true)
    {
        if (computer_move)
        {
            int rand_move = random_legal_move(board);
            board.place_piece(rand_move, Piece::Player2);

            computer_move = false;
        }
        else
        {
            clear_screen();
            board.print_board();
            std::cout << "Your move player 1" << std::endl;

            move = get_input(board);
            board.place_piece(move, Piece::Player1);

            if (board.check_win())
            {
                clear_screen();
                board.print_board();
                std::cout << "Player 1 won" << std::endl;
                return;
            }

            computer_move = true;
        }
    }

    return;
}

int main()
{
    std::cout << "Welcome to Connect Four" << std::endl;
    std::string menu_choice;
    while (true)
    {

        std::cout << "Choose a menu option:" << std::endl;
        std::cout << "  0. Exit" << std::endl;
        std::cout << "  1. Play against computer" << std::endl;
        std::cout << "  2. Play against another person" << std::endl;
        std::cout << ">> ";
        std::getline(std::cin, menu_choice);

        if (menu_choice == "0") return 0;
        else if (menu_choice == "1") play_computer();
        else if (menu_choice == "2") return 0;
        else
        {
            std::cout << "Could not recognize choice, try again." << std::endl;
        }
    }

    std::cout << menu_choice << std::endl;
    return 0;
}
