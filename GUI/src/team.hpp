/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** team
*/

#pragma once
#include <string>
#include <iostream>

class team
{
public:
    team(std::string name) : name(name) {}
    ~team() {}
    std::string getName() const {
        return name;}
private:
    std::string name;
};