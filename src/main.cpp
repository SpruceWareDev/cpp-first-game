#include<iostream>

class Player
{
    private:
        std::string name;
        int armour_level;
        int position[2];

    public:
        void init_player(std::string player_name)
        {
            name = player_name;
            armour_level = 1;
            set_position(0, 0);
        }

        void set_position(int x, int y)
        {
            position[0] = x;
            position[1] = y;
        }

    public:
        std::string get_name()
        {
            return name;
        }

        std::string get_formatted_position()
        {
            std::string pos_string = "(" + std::to_string(position[0]) + "," + std::to_string(position[1]) + ")";
            return pos_string;
        }

        int get_armour_level()
        {
            return armour_level;
        }
};

void game_menu(bool &playing)
{
    std::cout << "Cool Epic Adventure Game!\n";
    std::cout << "[1] New Game\n";
    std::cout << "[2] Load Game\n";
    std::cout << "[3] Exit\n";
    std::cout << "\n";
    bool menu = true;

    while (menu)
    {
        int input;
        std::cin >> input;

        switch (input)
        {
            case 1:
                std::cout << "Deez!\n";
                break;

            case 2:
                std::cout << "Not Implemented Yet!\n";
                break;

            case 3:
                std::cout << "Goodbye...\n";
                menu = false;
                playing = false;
                break;

            default:
                std::cout << "Wrong Input!\n";
                break;
        }
    }
}

void game_loop()
{
    bool playing = true;

    while (playing)
    {
        game_menu(playing);
    }
}

int main()
{
    game_loop();
    return 0;
}