/*
** EPITECH PROJECT, 2023
** ZAPPY
** File description:
** Tile
*/

#pragma once

#include <iostream>
#include <vector>
#include "SFML/Network.hpp"
#include <list>
#include <chrono>
#include <cstring>
#include "player.hpp"
#include "Tile.hpp"
#include <map>

struct _AllRaylib {
    struct _AllTextures {
        Texture2D _texturegreen;
        Texture2D _texturered;
        Texture2D _textureorange;
        Texture2D _textureblue;
        Texture2D _textureyellow;
        Texture2D _texturepink;
        Texture2D _texturelightblue;
        Texture2D _leaderboardButton;
        Texture2D _menuButton;
        Texture2D _menuHud;
        Texture2D _slideUp;
        Texture2D _teamsButton;
        Texture2D _TeamsUp;
        Texture2D _TeamsDown;
        Texture2D _yellowButton;
        Texture2D _greenButton;
        Texture2D _inventoryHud;
        Texture2D _textureplayer;
    };
    struct _AllHUD {
        position _slideuptoppos;
        position _slideupbotpos;
        position _TeamsUpPos;
        position _TeamsDownPos;
        std::vector<position> _greenbuttonpos;
        std::vector<position> _yellowbuttonpos;
        std::vector<std::pair<position, int>> _yellowButooninfopos;
        position _dropTeamsButtonPos;
    };
    struct _AllSounds {
        Sound _selectSound;
        Sound _scrollSound;
    };
    struct _AllMusic {
        Music _mainMusic;
    };
    struct _AllModels {
        Model _basicGround;
        Model _player;
    };
    struct _AllCameras {
        Camera _MainCamera;
        Camera _secondCamera;
    };
    struct _AllVector3 {
        Vector3 _cameraPosition;
        Vector3 _cameraDirection;
    };
};

struct _AllBools {
    bool _infoTeam = false;
    bool _close = false;
    bool goUp = true;
    bool _isMainCamera = true;
    bool _isSecondCamera = false;
    bool _ismenu = false;
    bool _mousePressed = false;
    bool _moovetop = false;
    bool _moovebot = false;
    bool _inventory = false;
    bool _drawEchap = false;
    bool _isdropteams = false;
};

class Drawer {
   public:
    Drawer();
    ~Drawer();
    void refresh (sf::TcpSocket &socket);
    void draw(sf::TcpSocket &socket);
    void loadMap(sf::TcpSocket &socket);
    void load(int width, int height, sf::TcpSocket &socket);
    void translatecalculate(std::vector<Model> &models);
    void drawGround();
    bool handleCommand(sf::TcpSocket &socket);
    void GetclickInput();
    void drawPlayers();
    void DrawEvolve();
    std::pair<int,int> handleClick();
    void drawHUD(std::pair<int,int> selectedTile);
    void checkLeaderboardclick(int x, int y);
    void checkMenuClick(int x, int y);
    void checkTeamsClick(int x, int y);
    bool checkInfoClick(int x, int y);
    void drawFood();
    void DrawInfoTeam();
    void DrawMenu();
    void sendPBC(int x, std::string message);
    void DrawTeams();
    void DrawLogs();
    void DrawInventory();
    void updateMycamera(Camera *camera);
    Camera createCamera(Vector3 pos, Vector3 target, Vector3 up,
                                float fovy);
   private:
    // ALL Raylib variables
    Model _diamond;
    Model _diamondpike;
    Model _food;
    std::vector<Model> _models{_diamond, _diamondpike, _food};
    std::list<Tile> _tiles;
    std::vector<Player> _players;
    std::vector<Camera> _cameras;
    std::vector<std::string> _teamsnames;
    // ALL variables string
    std::string _inventoryOfSelectedPlayer = "";
    std::string _selectedTeam = "";
    std::string _timestamp = "";
    // ALL variables vector , pair , map
    std::map<int, std::pair<std::pair<int, int>, std::pair<int, int>>> _leaderplayers;
    std::pair<int,int> _selectedTile = {-1,-1};
    std::vector<std::pair<std::string,std::string>> _logs;
    std::vector<int> _idsinEvolving;
    // ALL variables bool
    _AllBools _myBools;
    // ALL variables float
    float countforanimationX = 0;
    float countforanimationY = 0;
    // ALL variables int
    int _width = 0;
    int _height = 0;
    int _page = 0;
    int maxcube = 100;
    int animCurrentFrame = 0;
    int animIndex = 0;
    int _maxpage = 0;
    int _effectSound = 50;
    int _musicSound = 50;
    int _iDinventory = -1;
    // ALL structure
    _AllRaylib::_AllTextures _mytextures;
    _AllRaylib::_AllHUD _myHUD;
    _AllRaylib::_AllSounds _AllSounds;
    _AllRaylib::_AllMusic _AllMusic;
    _AllRaylib::_AllModels _AllModels;
    _AllRaylib::_AllCameras _AllCameras;
    _AllRaylib::_AllVector3 _AllVector3;
};