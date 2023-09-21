/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** utils
*/

#pragma once
#include <SFML/Network.hpp>
#include <string>

namespace utils {
std::string receiveAndBuffer(sf::TcpSocket &socket) {
    std::string buffer;
    if (buffer.find("\n") == std::string::npos) {
        std::cout << "Waiting for data..." << std::endl;
        char tmp[1024];
        std::size_t received;
        socket.receive(tmp, 1024, received);
        buffer += tmp;
    }
    std::size_t pos = buffer.find_last_of("\n");
    buffer.erase(pos, buffer.size() - pos);
    std::cout << "Received: " << buffer << std::endl;
    return buffer;
}

std::vector<std::string> cutAtseparator(std::string str, char separator)
{
    std::vector<std::string> result;
    std::string tmp = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == separator) {
            result.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += str[i];
        }
    }
    result.push_back(tmp);
    return result;
}

float randFloat(float a, float b)
{
    return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

}  // namespace utils