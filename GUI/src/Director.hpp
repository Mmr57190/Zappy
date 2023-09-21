/*
** EPITECH PROJECT, 2023
** ZAPPY
** File description:
** Object
*/

#pragma once

#include "Drawer.hpp"

class Director
{
public:
    Director(int port, std::string machine);
    void run();
    ~Director();
private:
    std::unique_ptr<Drawer> _drawer;
    int _port;
    std::string _machine;
    sf::TcpSocket _socket;
};