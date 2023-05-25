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

        int get_x()
        {
            return position[0];
        }

        int get_y()
        {
            return position[1];
        }
};

class World
{
    public:
        static const int NOTHING = 0;
        static const int CHEST = 1;
        static const int ITEM = 2;
        static const int PLAYER = 3;

    private:
        Player player;
        int world[10][10];

    public:
        void init_world(Player &playerIn)
        {
            clear_world();
            player = playerIn;
            set_player_pos(player.get_x(), player.get_y());
        }

        void clear_world()
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    world[i][j] = NOTHING;
                }
            }
        }

        void set_player_pos(int x, int y)
        {
            world[x][y] = PLAYER;
        }

        void draw_world()
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    std::cout << std::to_string(world[i][j]);
                }
                std::cout << "\n";
            }
        }
};

void new_game()
{
    std::cout << "You will start by creating your charcter!\n";
    std::cout << "Enter a character name: ";

    std::string input;
    getline(std::cin, input);
    Player thePlayer;
    thePlayer.init_player(input);
    std::cout << "Player created!\n";

    World theWorld;
    theWorld.init_world(thePlayer);
    theWorld.draw_world();
}

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
                new_game();
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