/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** Player
*/

#pragma once
#include "team.hpp"
#include "raylib.h"
#include "raymath.h"
struct position
{
    int x;
    int y;
};

class Player
{
public:
    Player(int id, team team, char orientation, int level, position position, int index) : _id(id), _team(team), _orientation(orientation), _level(level), _position(position), _index(index)
    {
        _MainCamera.position = Vector3{-4.0f, 2.0f, -4.0f};
        _MainCamera.target = Vector3{0.0f, 0.0f, 0.0f};
        _MainCamera.up = Vector3{0.0f, 1.0f, 0.0f};
        _MainCamera.fovy = 45.0f;
        _MainCamera.projection = CAMERA_PERSPECTIVE;
        _inIncantation = false;
    }

    ~Player() {}
    position getPosition() const {
        return _position;
    }
    Vector3 getVecPosition() const {
        return _pos;
    }
    inline void draw(Model model, Vector3 pos,float size) {
        // the pos is the center of the tile
        _pos = pos;
        if (_orientation == 'O')
            model.transform = MatrixRotateY(90 * DEG2RAD);
        else if (_orientation == 'S')
            model.transform = MatrixRotateY(180 * DEG2RAD);
        else if (_orientation == 'E')
            model.transform = MatrixRotateY(270 * DEG2RAD);
        else if (_orientation == 'N')
            model.transform = MatrixRotateY(0 * DEG2RAD);
        // make the camera look like to be in third person of the player with correct orientation
        _MainCamera.position = Vector3{pos.x, pos.y + 0.5f, 0.0f};
        _MainCamera.target = Vector3{pos.x, pos.y, pos.z};
        DrawModel(model, pos, size, WHITE);
        if (_inIncantation) {
            Model modelA = LoadModelFromMesh(GenMeshTorus(0.1f, 1.0f, 16, 32));
            modelA.transform = MatrixRotateX(90.0f * DEG2RAD);
            DrawModel(modelA, (Vector3){pos.x, pos.y, pos.z}, 1.0f, YELLOW);
        }

    };
    int getID() const {
        return _id;
    }
    int getIndex() const {
        return _index;
    }
    void setPosition(position pos) {
        _position = pos;
    }
    void setLevel(int level) {
        _level = level;
    }
    int getLevel() const {
        return _level;
    }
    void setOrientation(char orientation) {
        _orientation = orientation;
    }
    Camera getCamera() const {
        return _MainCamera;
    }
    team getTeam() const {
        return _team;
    }
    bool _inIncantation;
private:
    team _team;
    Camera _MainCamera;
    char _orientation;
    int _index;
    unsigned int animFrameCounter = 0;
    int _level;
    int _id;
    Vector3 _pos;
    position _position;
};
