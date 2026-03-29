#include <iostream>
#include <string>

// Test push

void print_screen()
{

}

void title_screen()
{

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
        else if (menu_choice == "1") return 0;
        else if (menu_choice == "2") return 0;
        else
        {
            std::cout << "Could not recognize choice, try again." << std::endl;
        }
    }

    std::cout << menu_choice << std::endl;
    return 0;
}
