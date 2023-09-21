/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** Tile
*/

#pragma once
#include "raylib.h"
#include "raymath.h"
// #include "/opt/homebrew/Cellar/raylib/4.5.0/include/raylib.h"
// #include "/opt/homebrew/Cellar/raylib/4.5.0/include/raymath.h"

struct Data
{
    int q0;
    int q1;
    int q2;
    int q3;
    int q4;
    int q5;
    int q6;
};

class Tile {
   public:
    Tile(Vector3 pos, Vector3 size, std::pair<int, int> logicPos)
        : _pos(pos), _size(size), _logicPos(logicPos) {
            _data = {0, 0, 0, 0, 0, 0, 0};
            selected = false;
            _box = {Vector3{pos.x - size.x / 2, (pos.y - size.y / 2) + 0.5f, pos.z - size.z / 2}, Vector3{pos.x + size.x / 2, (pos.y + size.y / 2) + 0.5f, pos.z + size.z / 2}};
        };
    ~Tile(){};
    inline void draw(Model model, Vector3 pos,float size) {
        if (selected) {
            // make model red
            model.materials[0].maps[MATERIAL_MAP_NORMAL].color = RED;
            DrawModel(model, pos, size, RED);
        }
        else {
            // go back to default color
            model.materials[0].maps[MATERIAL_MAP_NORMAL].color = WHITE;
            DrawModel(model, pos, size, WHITE);
        }
        DrawBoundingBox(_box, BLACK);
    };
    Vector3 getPos() const { return _pos; };
    BoundingBox getBox() const { return _box; };
    // Vector3 getSize() const { return _size; };
    // void setPos(Vector3 pos) { _pos = pos; };
    // void setSize(Vector3 size) { _size = size; };
    std::pair<int, int> getLogicPos() const { return _logicPos; };
    void setLogicPos(std::pair<int, int> logicPos) { _logicPos = logicPos; };
    void setData(Data data) { _data = data; };
    Data getData() { return _data; };
    bool selected;
   private:
    Vector3 _pos;
    Vector3 _size;
    Texture2D _texture;
    std::pair<int, int> _logicPos;
    BoundingBox _box;
    Data _data;
};
