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


int main()
{
    Player player;
    player.init_player("Spruce");

    std::cout << "Players name is " << player.get_name() << "\n";
    std::cout << "Players position is " << player.get_formatted_position() << "\n";
    std::cout << "Players armour level is " << std::to_string(player.get_armour_level()) << "\n";
    return 0;
}