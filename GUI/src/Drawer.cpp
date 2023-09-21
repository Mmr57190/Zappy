/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** drawer
*/

#include "Drawer.hpp"

Drawer::Drawer()
{
    _timestamp = "00:00:00";
    // put timestamp at the actual time
    _AllCameras._MainCamera = createCamera({ -4.0f, 2.0f, -4.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f);
    _AllCameras._secondCamera = createCamera({ -4.0f, 2.0f, -4.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f);
    _cameras.push_back(_AllCameras._MainCamera);
    _cameras.push_back(_AllCameras._secondCamera);
    SetTargetFPS(60);
    InitWindow(1280, 720, "Zappy");
    InitAudioDevice();
    // remove sfml waringin
    sf::err().rdbuf(NULL);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetMousePosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
    _AllMusic._mainMusic = LoadMusicStream("GUI/assets/song.mp3");
    _AllMusic._mainMusic.looping = true;
    _mytextures._yellowButton = LoadTexture("GUI/assets/yellow_button.png");
    _mytextures._greenButton = LoadTexture("GUI/assets/green_button.png");
    _mytextures._TeamsUp = LoadTexture("GUI/assets/slideup.png");
    _mytextures._TeamsDown = LoadTexture("GUI/assets/slidedown.png");
    SetSoundVolume(_AllSounds._selectSound, 0.5);
    SetSoundVolume(_AllSounds._scrollSound, 0.5);
    SetMusicVolume(_AllMusic._mainMusic, 0.5);
    _mytextures._inventoryHud = LoadTexture("GUI/assets/inventory.png");
    _mytextures._teamsButton = LoadTexture("GUI/assets/teams_button.png");
    _AllSounds._selectSound = LoadSound("GUI/assets/select.ogg");
    _AllSounds._scrollSound = LoadSound("GUI/assets/scroll.ogg");
    _mytextures._menuButton = LoadTexture("GUI/assets/menu_button.png");
    _mytextures._slideUp = LoadTexture("GUI/assets/slideup.png");
    _mytextures._menuHud = LoadTexture("GUI/assets/menu.png");
    _mytextures._leaderboardButton = LoadTexture("GUI/assets/leaderboard.png");
    _AllModels._basicGround = LoadModel("GUI/assets/OBJ/ground/block.obj");
    _diamond = LoadModel("GUI/assets/OBJ/food/diamond/Stone1.obj");
    _diamondpike = LoadModel("GUI/assets/OBJ/food/diamond/CrystalsOBJ.obj");
    _mytextures._texturegreen = LoadTexture("GUI/assets/OBJ/food/diamond/green.png");
    _mytextures._texturered = LoadTexture("GUI/assets/OBJ/food/diamond/red.png");
    _mytextures._textureorange = LoadTexture("GUI/assets/OBJ/food/diamond/orange.png");
    _mytextures._textureblue = LoadTexture("GUI/assets/OBJ/food/diamond/blue.png");
    _mytextures._textureyellow = LoadTexture("GUI/assets/OBJ/food/diamond/yellow.png");
    _mytextures._texturepink = LoadTexture("GUI/assets/OBJ/food/diamond/pink.png");
    _mytextures._texturelightblue = LoadTexture("GUI/assets/OBJ/food/diamond/lightblue.png");
    _food = LoadModel("GUI/assets/OBJ/food/food/wholerHam.obj");
    _AllModels._player = LoadModel("GUI/assets/OBJ/player/Astronaut.obj");
    Texture2D texturee = LoadTexture("GUI/assets/OBJ/player/UVastronaut.png");
    _AllModels._player.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texturee;
}

Drawer::~Drawer()
{
}

std::string receiveWithTimeout(sf::TcpSocket &socket, float timeout)
{
    sf::SocketSelector selector;
    selector.add(socket);
    if (selector.wait(sf::seconds(timeout))) {
        std::string buffer;
        while (buffer.find("\n") == std::string::npos) {
            char tmp[1024];
            std::size_t received;
            socket.receive(tmp, 1024, received);
            buffer += tmp;
        }
        std::size_t pos = buffer.find_last_of("\n");
        buffer.erase(pos, buffer.size() - pos);
        return buffer;
    }
    return "";
}

void Drawer::refresh(sf::TcpSocket &socket)
{
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    _timestamp = std::to_string(tm.tm_hour) + ":" + std::to_string(tm.tm_min) +
                 ":" + std::to_string(tm.tm_sec);
    if (_iDinventory != -1) {
        std::string to_send = "pin #" + std::to_string(_iDinventory) + "\n";
        socket.send(to_send.c_str(), to_send.size());
    }
}

void Drawer::sendPBC(int id , std::string msg)
{
}

bool Drawer::handleCommand(sf::TcpSocket &socket) {
    std::size_t received;
    std::vector<std::string> commands;
    std::string buffer;
    char *data = new char[100];
    while (socket.receive(data, 100, received) == sf::Socket::Done) {
        std::string command(data, received);
        buffer += command;
        size_t pos = 0;
        while ((pos = buffer.find('\n')) != std::string::npos) {
            std::string currentCommand = buffer.substr(0, pos);
            commands.push_back(currentCommand);
            buffer.erase(0, pos + 1);
        }

        if (!buffer.empty()) {
            buffer.clear();
        }
    }
    for (auto &msg : commands) {
        if (msg.find("pin") != std::string::npos) {
            msg.erase(0, 4);
            _inventoryOfSelectedPlayer = msg;
        } else if (msg.find("pnw") != std::string::npos) {
            while (msg.find("pnw") != std::string::npos) {
                    msg.erase(0, 4);
                    int id = std::stoi(msg.substr(1, msg.find(" ")));
                    msg.erase(0, msg.find(" ") + 1);
                    int x = std::stoi(msg.substr(0, msg.find(" ")));
                    msg.erase(0, msg.find(" ") + 1);
                    int y = std::stoi(msg.substr(0, msg.find(" ")));
                    msg.erase(0, msg.find(" ") + 1);
                    char orientation = msg.substr(0, msg.find(" "))[0];
                    msg.erase(0, msg.find(" ") + 1);
                    int level = std::stoi(msg.substr(0, msg.find(" ")));
                    msg.erase(0, msg.find(" ") + 1);
                    std::string teamname = msg.substr(0, msg.find(" "));
                    msg.erase(0, msg.find("\n") + 1);
                    _players.push_back(Player(id, teamname, orientation, level,
                                              {x, y}, _players.size()));
            }
        } else if (msg.find("ppo") != std::string::npos) {
                msg.erase(0, 4);
                int id = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int x = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int y = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                char orientation = msg.substr(0, msg.find("\n"))[0];
                msg.erase(0, msg.find("\n") + 1);
                for (auto &player : _players) {
                    if (player.getID() == id) {
                        player.setPosition({x, y});
                        player.setOrientation(orientation);
                    }
                }
        } else if (msg.find("plv") != std::string::npos) {
                msg.erase(0, 4);
                int id = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int level = std::stoi(msg.substr(0, msg.find("\n")));
                for (auto &player : _players) {
                    if (player.getID() == id) {
                        if (player.getLevel() < level) {
                            std::string to_save = "#" + std::to_string(id) +
                                                  " -> lvl " +
                                                  std::to_string(level);
                            _logs.push_back(
                                std::make_pair(_timestamp, to_save));
                                for (auto &id : _idsinEvolving) {
                                    if (id == player.getID()) {
                                        _idsinEvolving.erase(std::remove(_idsinEvolving.begin(), _idsinEvolving.end(), id), _idsinEvolving.end());
                                        break;
                                    }
                                }
                            player.setLevel(level);
                        }
                    }
                }
        } else if (msg.find("bct") != std::string::npos) {
                msg.erase(0, 4);
                int x = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int y = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int q0 = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int q1 = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int q2 = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int q3 = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int q4 = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int q5 = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int q6 = std::stoi(msg.substr(0, msg.find("\n")));
                msg.erase(0, msg.find("\n") + 1);
                for (auto &tile : _tiles) {
                    if (tile.getLogicPos().first == x &&
                        tile.getLogicPos().second == y) {
                        tile.setData({q0, q1, q2, q3, q4, q5, q6});
                    }
                }
        } else if (msg.find("pdi") != std::string::npos) {
                msg.erase(0, 4);
                int id = std::stoi(msg.substr(0, msg.find("\n")));
                msg.erase(0, msg.find("\n") + 1);
                std::string to_save = "player #" + std::to_string(id) + "died\n";
                _logs.push_back(std::make_pair(_timestamp, to_save));
                for (auto &player : _players) {
                    if (player.getID() == id) {
                        _players.erase(_players.begin() + player.getIndex());
                    }
                }
        } else if (msg.find("tna") != std::string::npos) {
                while (msg.find("tna") != std::string::npos) {
                    msg.erase(0, 4);
                    std::string teamname = msg.substr(0, msg.find("\n"));
                    msg.erase(0, msg.find("\n") + 1);
                    _teamsnames.push_back(teamname);
                }
            _maxpage = _teamsnames.size() / 3;
            if (_teamsnames.size() % 3 != 0) _maxpage++;
        } else if (msg.find("pex") != std::string::npos) {
                int id = std::stoi(msg.substr(4, msg.find("\n")));
                std::string to_save =
                    "#" + std::to_string(id) + " get expulsed\n";
                _logs.push_back(std::make_pair(_timestamp, to_save));
        } else if (msg.find("pbc") != std::string::npos) {
                int id = std::stoi(msg.substr(4, msg.find(" ")));
                std::string message = msg.substr(
                    4 + std::to_string(id).size() + 1, msg.find("\n"));
                std::string to_save =
                    "#" + std::to_string(id) + " br " + message + "\n";
                _logs.push_back(std::make_pair(_timestamp, to_save));
                sendPBC(id, message);
        } else if (msg.find("pic") != std::string::npos) {
                msg.erase(0, 4);
                int x = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int y = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int level = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                std::vector<int> ids;
                while (msg.find(" ") != std::string::npos) {
                    int id = std::stoi(msg.substr(0, msg.find(" ")));
                    msg.erase(0, msg.find(" ") + 1);
                    ids.push_back(id);
                }
                if (ids.size() == 0)
                    ids.push_back(std::stoi(msg.substr(0, msg.find("\n"))));
                for (auto &id : ids) {
                    std::string to_save =
                        "incantation at (" + std::to_string(x) + ", " +
                        std::to_string(y) +
                        ") level : " + std::to_string(level) +
                        " player : " + std::to_string(id) + "\n";
                        std::cout << to_save << std::endl;
                    _idsinEvolving.push_back(id);
                    _logs.push_back(std::make_pair(_timestamp, to_save));
                }
        }
        else if (msg.find("pie") != std::string::npos) {
                int x = std::stoi(msg.substr(4, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int y = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int result = std::stoi(msg.substr(0, msg.find("\n")));
                std::string to_save = "incantation at (" + std::to_string(x) +
                                      ", " + std::to_string(y) +
                                      ") result : " + std::to_string(result) +
                                      "\n";
                for (auto &id : _idsinEvolving) {
                    for (auto &player : _players) {
                        Vector3 pos = player.getVecPosition();
                        std::cout << "player pos : " << pos.x << " " << pos.y
                                  << std::endl;
                        if (pos.x == x && pos.y == y) {
                            _idsinEvolving.erase(
                                std::remove(_idsinEvolving.begin(),
                                            _idsinEvolving.end(), player.getID()),
                                _idsinEvolving.end());
                        }
                        break;
                    }
                }
                _logs.push_back(std::make_pair(_timestamp, to_save));
        } else if (msg.find("pfk") != std::string::npos) {
                int id = std::stoi(msg.substr(4, msg.find("\n")));
                std::string to_save =
                    "#" + std::to_string(id) + " layed an egg\n";
                _logs.push_back(std::make_pair(_timestamp, to_save));
        } else if (msg.find("pdr") != std::string::npos) {
                int id = std::stoi(msg.substr(4, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int resource = std::stoi(msg.substr(0, msg.find("\n")));
                std::string to_save = "player #" + std::to_string(id) +
                                      " dropped resource " +
                                      std::to_string(resource) + "\n";
                _logs.push_back(std::make_pair(_timestamp, to_save));
        } else if (msg.find("pgt") != std::string::npos) {
                int id = std::stoi(msg.substr(4, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                msg.erase(0, msg.find(" ") + 1);
                int resource = std::stoi(msg.substr(0, msg.find("\n")));
                std::string foodname = "";
                if (resource == 0)
                    foodname = "food";
                else if (resource == 1)
                    foodname = "linemate";
                else if (resource == 2)
                    foodname = "deraumere";
                else if (resource == 3)
                    foodname = "sibur";
                else if (resource == 4)
                    foodname = "mendiane";
                else if (resource == 5)
                    foodname = "phiras";
                else if (resource == 6)
                    foodname = "thystame";
                std::string to_save =
                    " #" + std::to_string(id) + "Take " + foodname + "\n";
                _logs.push_back(std::make_pair(_timestamp, to_save));
        }else if (msg.find("enw") != std::string::npos) {
                int id = std::stoi(msg.substr(4, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int egg_id = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int x = std::stoi(msg.substr(0, msg.find(" ")));
                msg.erase(0, msg.find(" ") + 1);
                int y = std::stoi(msg.substr(0, msg.find("\n")));
                std::string to_save =
                    "egg #" + std::to_string(egg_id) + " was laid by player #" +
                    std::to_string(id) + " at (" + std::to_string(x) + ", " +
                    std::to_string(y) + ")\n";
                _logs.push_back(std::make_pair(_timestamp, to_save));
        } else if (msg.find("eht") != std::string::npos) {
                int egg_id = std::stoi(msg.substr(4, msg.find("\n")));
                std::string to_save =
                    "egg #" + std::to_string(egg_id) + " hatched\n";
                _logs.push_back(std::make_pair(_timestamp, to_save));
        } else if (msg.find("edi") != std::string::npos) {
                int egg_id = std::stoi(msg.substr(4, msg.find("\n")));
                std::string to_save =
                    "egg #" + std::to_string(egg_id) + "died\n";
                _logs.push_back(std::make_pair(_timestamp, to_save));
        }
    }
        return (true);
}

void Drawer::checkLeaderboardclick(int x, int y)
{
    for (auto &player : _leaderplayers) {
        if (x >= player.second.first.first && x <= player.second.second.first && y >= player.second.first.second && y <= player.second.second.second) {
            for (auto &player2 : _players) {
                if (player2.getID() == player.first) {
                    _AllCameras._MainCamera = player2.getCamera();
                    return;
                }
            }
        }
    }
}

void Drawer::checkMenuClick(int x, int y)
{
    // hcek if click on button _menuButton
    if (x >= 25 && x <= 25 + _mytextures._menuButton.width && y >= 25 && y <= 25 + _mytextures._menuButton.height) {
        _myBools._ismenu = !_myBools._ismenu;
    }
}

void Drawer::GetclickInput()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        _myBools._mousePressed = true;
    }
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        _myBools._mousePressed = false;
        _myBools._moovetop = false;
        _myBools._moovebot = false;
        StopSound(_AllSounds._scrollSound);
    }
    if (IsKeyReleased(KEY_ESCAPE)) {
        _myBools._drawEchap = !_myBools._drawEchap;
    }
}


bool Drawer::checkInfoClick(int x, int y)
{
    // for _yellowButooninfopos pos check if click
    for (auto &button : _myHUD._yellowButooninfopos) {
        if (x >= button.first.x && x <= button.first.x + _mytextures._yellowButton.width && y >= button.first.y && y <= button.first.y + _mytextures._yellowButton.height) {
            PlaySound(_AllSounds._selectSound);
            _iDinventory = button.second;
            _myBools._inventory = true;
            return true;
        }
    }
    _myBools._inventory = false;
    _iDinventory = -1;
    return false;
}

std::pair<int,int> Drawer::handleClick()
{
    std::vector<Tile> tiles;
    int tileCount = 0;
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        float distance = 0.0f;
        if(checkInfoClick(GetMouseX(), GetMouseY()))
            return {-1, -1};
        checkLeaderboardclick(GetMouseX(), GetMouseY());
        checkTeamsClick(GetMouseX(), GetMouseY());
        checkMenuClick(GetMouseX(), GetMouseY());
        if (!_myBools._ismenu) {
        for (auto &tile : _tiles) {
            Vector2 mousePosition = GetMousePosition();
            Ray ray;
            ray = GetMouseRay(mousePosition, _AllCameras._MainCamera);
            RayCollision collision = GetRayCollisionBox(ray, tile.getBox());
            if (collision.hit) {
                tiles.push_back(tile);
            }
        }
        tileCount = 0;
        for (auto &tile : tiles) {
            if (distance == 0.0f) {
                    distance = Vector3Distance(_AllCameras._MainCamera.position, tile.getPos());
                _selectedTile = tile.getLogicPos();
            }
            else if (Vector3Distance(_AllCameras._MainCamera.position, tile.getPos()) < distance) {
                distance = Vector3Distance(_AllCameras._MainCamera.position, tile.getPos());
                _selectedTile = tile.getLogicPos();
            }
        }
        if (distance != 0.0f) {
            PlaySound(_AllSounds._selectSound);
            return _selectedTile;
        }
        return {-2, -2};
        }
    }
    return {-1, -1};
}

void Drawer::checkTeamsClick(int x, int y)
{
    if (x >= _myHUD._TeamsUpPos.x &&
        x <= _myHUD._TeamsUpPos.x + _mytextures._TeamsUp.width &&
        y >= _myHUD._TeamsUpPos.y &&
        y <= _myHUD._TeamsUpPos.y + _mytextures._TeamsUp.height) {
            if (_page > 0) {
                _page--;
                PlaySound(_AllSounds._selectSound);
            }
    }
    else if (x >= _myHUD._TeamsDownPos.x &&
        x <= _myHUD._TeamsDownPos.x + _mytextures._TeamsDown.width &&
        y >= _myHUD._TeamsDownPos.y &&
        y <= _myHUD._TeamsDownPos.y + _mytextures._TeamsDown.height) {
            if (_page < _teamsnames.size() / 3) {
                _page++;
                PlaySound(_AllSounds._selectSound);
            }
    } else {
            std::string last = _selectedTeam;
            for (int i = 0; i < _myHUD._yellowbuttonpos.size(); i++) {
                if (x >= _myHUD._yellowbuttonpos[i].x &&
                    x <= _myHUD._yellowbuttonpos[i].x + _mytextures._greenButton.width &&
                    y >= _myHUD._yellowbuttonpos[i].y &&
                    y <= _myHUD._yellowbuttonpos[i].y + _mytextures._greenButton.height) {
            if (_selectedTeam == _teamsnames[_page * 3 + i]) {
                _selectedTeam = "";
                PlaySound(_AllSounds._selectSound);
                return;
            }
            _selectedTeam = _teamsnames[_page * 3 + i];
            PlaySound(_AllSounds._selectSound);
            return;
                }
                _selectedTeam = "";
            }
    }
}
void Drawer::loadMap(sf::TcpSocket &socket)
{
    socket.setBlocking(false);
    std::string buffer = receiveWithTimeout(socket, 2);
    socket.send("graphic\n", 8);
    buffer = receiveWithTimeout(socket, 2);
    int id = std::stoi(buffer.substr(0, buffer.find("\n")));
    if (id == -1) throw std::runtime_error("Connection failed");
    buffer.erase(0, buffer.find("\n") + 1);
    int width = std::stoi(buffer.substr(0, buffer.find(" ")));
    if (width == -1) throw std::runtime_error("Connection failed");
    buffer.erase(0, buffer.find(" ") + 1);
    int height = std::stoi(buffer.substr(0, buffer.find("\n")));
    if (height == -1) throw std::runtime_error("Connection failed");
    socket.send("tna\n", 4);
    load(width, height, socket);
    handleCommand(socket);
}

void Drawer::load(int width, int height, sf::TcpSocket &socket)
{
    for (float i = 0; i < width; i++) {
        for (float j = 0; j < height; j++) {
            _tiles.push_back(Tile({i - width / 2, 0, j - height / 2}, {1, 1, 1}, {i, j}));
        }
    }
    _width = width;
    _height = height;
}

void Drawer::updateMycamera(Camera *camera)
{
    if (!_myBools._drawEchap)
        UpdateCamera(camera, CAMERA_PERSPECTIVE);
}

Camera Drawer::createCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy)
{
    Camera camera = { 0 };
    camera.position = pos;
    camera.target = target;
    camera.up = up;
    camera.fovy = fovy;
    camera.projection = CAMERA_PERSPECTIVE;
    return (camera);
}
