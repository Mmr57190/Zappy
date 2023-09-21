/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** Director
*/

#include "Director.hpp"

Director::Director(int port, std::string machine)
{
    _drawer = std::make_unique<Drawer>();
    _port = port;
    _machine = machine;
}

Director::~Director()
{
}

void Director::run()
{
    std::cout << "Connecting to " << _machine << " on port " << _port << std::endl;
    if (_socket.connect(_machine, _port) != sf::Socket::Done)
        throw std::runtime_error("Connection failed");
    _drawer->loadMap(_socket);
    _drawer->draw(_socket);
}