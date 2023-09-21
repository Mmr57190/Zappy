/*
** EPITECH PROJECT, 2023
** ZAPPY
** File description:
** main
*/

#include "Director.hpp"

std::pair<int,std::string> check_args(int ac, char **av)
{
    if (ac != 5) {
        std::cerr << "Usage: ./zappy_gui -p port -h machine" << std::endl;
        std::exit(84);
    }
    return {atoi(av[2]), av[4]};
}

int main(int ac, char **av)
{
    std::pair<int, std::string> args = check_args(ac, av);
    Director director(args.first, args.second);
    try
    {
        director.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}