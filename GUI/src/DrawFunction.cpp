/*
** EPITECH PROJECT, 2023
** B-YEP-400-NCY-4-1-zappy-mohsine.fajli
** File description:
** DrawFunction
*/

#include "Drawer.hpp"
#include "utils.hpp"

void Drawer::drawGround()
{
    // Dessiner les tuiles jusqu'à un maximum de 50 devant la caméra
    int tileCount = 0;
    for (auto &tile : _tiles)
    {
        float dotProduct = Vector3DotProduct(Vector3Subtract(tile.getPos(), _AllCameras._MainCamera.position), _AllVector3._cameraDirection);
        float distance = Vector3Distance(tile.getPos(), _AllCameras._MainCamera.position);
        if (dotProduct < 0 || distance > 15)
            continue;
        tile.draw(_AllModels._basicGround, tile.getPos(), 1.0f);
        tileCount++;
    }
}
void Drawer::drawPlayers()
{
    for (auto &tile : _tiles) {
        for (auto &player : _players) {
            if (tile.getLogicPos().first == player.getPosition().x && tile.getLogicPos().second == player.getPosition().y) {
                player.draw(_AllModels._player, {tile.getPos().x, tile.getPos().y + 1.1f, tile.getPos().z}, 0.1f);
            }
        }
    }
}

void Drawer::drawFood()
{
    for (auto &tile : _tiles) {
        float dotProduct = Vector3DotProduct(Vector3Subtract(tile.getPos(), _AllCameras._MainCamera.position), _AllVector3._cameraDirection);
        float distance = Vector3Distance(tile.getPos(), _AllCameras._MainCamera.position);
        if (dotProduct < 0 || distance > 15)
            continue;
        if (tile.getData().q0 > 0) {
            tile.draw(_food,{tile.getPos().x, tile.getPos().y + 1.0f+ countforanimationY, tile.getPos().z},0.2f);
        }
        if (tile.getData().q1 > 0) {
            _diamondpike.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = _mytextures._textureorange;
            tile.draw(_diamondpike,{tile.getPos().x + 0.3f, tile.getPos().y + 1.02f+ countforanimationY, tile.getPos().z + 0.3f},0.08f);
        }
        if (tile.getData().q2 > 0) {
            _diamondpike.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = _mytextures._textureblue;
            tile.draw(_diamondpike,{tile.getPos().x - 0.3f, tile.getPos().y + 1.02f+ countforanimationY, tile.getPos().z - 0.3f},0.08f);
        }
        if (tile.getData().q3 > 0) {
            _diamond.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = _mytextures._texturered;
            tile.draw(_diamond,{tile.getPos().x + 0.1f, tile.getPos().y + 1.05f+ countforanimationY, tile.getPos().z - 0.4f},0.08f);
        }
        if (tile.getData().q4 > 0) {
            _diamond.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = _mytextures._texturegreen;
            tile.draw(_diamond,{tile.getPos().x - 0.1f, tile.getPos().y + 1.05f+ countforanimationY, tile.getPos().z + 0.3f},0.08f);
        }
        if (tile.getData().q5 > 0) {
            _diamond.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = _mytextures._texturelightblue;
            tile.draw(_diamond,{tile.getPos().x + 0.3f, tile.getPos().y + 1.05f+ countforanimationY, tile.getPos().z - 0.1f},0.08f);
        }
        if (tile.getData().q6 > 0) {
            _diamondpike.materials[0].maps[MATERIAL_MAP_ALBEDO].texture = _mytextures._texturepink;
            tile.draw(_diamondpike,{tile.getPos().x - 0.3f, tile.getPos().y + 1.02f+ countforanimationY, tile.getPos().z + 0.1f},0.08f);
        }
    }
}


void Drawer::DrawLogs()
{
    int x = GetScreenWidth() - 300;
    int y = GetScreenHeight() / 2 - 100;
    DrawRectangle(x, y, 300, 350, Fade(WHITE, 0.5f));
    int nbToDraw = 0;
    for (int i = 0; i < _logs.size(); i++, nbToDraw++) {
        // if > 10 logs, delete the first one
        if (i > 15) {
           _logs.erase(_logs.begin());
           nbToDraw--;
        }
        if (_logs[nbToDraw].second.size() > 20) {
            _logs[nbToDraw].second = _logs[nbToDraw].second.substr(0, 20);
        }
        std::string to_draw = _logs[nbToDraw].first + " " + _logs[nbToDraw].second;
        DrawText(_logs[nbToDraw].first.c_str(), x + 10, y + 10 + (i * 20), 20, BLACK);
        DrawText(_logs[nbToDraw].second.c_str(), x + _logs[nbToDraw].first.size() + 80, y + 10 + (i * 20), 20, RED);
    }
}


void Drawer::DrawInventory()
{
    DrawTexture(_mytextures._inventoryHud , GetScreenWidth() / 2 - _mytextures._inventoryHud.width / 2, GetScreenHeight() / 2 - _mytextures._inventoryHud.height / 2, WHITE);
    if (_inventoryOfSelectedPlayer != "") {
        int level = 0;
        for (int i = 0; i < _players.size(); i++) {
            std::vector<std::string> inventory = utils::cutAtseparator(_inventoryOfSelectedPlayer, ' ');
            if (inventory[0] == std::to_string(_players[i].getID())) {
                level = _players[i].getLevel();
            }
        }
        std::vector<std::string> inventory = utils::cutAtseparator(_inventoryOfSelectedPlayer, ' ');
        for (int i = 0; i < inventory.size(); i++) {
        }
        std::string playerid = "Player #" + inventory[0] + " (level " + std::to_string(level) + ")";
        DrawText(playerid.c_str(), GetScreenWidth() / 2 - _mytextures._inventoryHud.width / 2 + 50, GetScreenHeight() / 2 - _mytextures._inventoryHud.height / 2 + 90, 25, DARKGREEN);
        std::string food = "food : " + inventory[3];
        std::string linemate = "linemate : " + inventory[4];
        std::string deraumere = "deraumere : " + inventory[5];
        std::string sibur = "sibur : " + inventory[6];
        std::string mendiane = "mendiane : " + inventory[7];
        std::string phiras = "phiras : " + inventory[8];
        std::string thystame = "thystame : " + inventory[9];
        DrawText(food.c_str(), GetScreenWidth() / 2 - _mytextures._inventoryHud.width / 2 + 50, GetScreenHeight() / 2 - _mytextures._inventoryHud.height / 2 + 120, 25, DARKGREEN);
        DrawText(linemate.c_str(), GetScreenWidth() / 2 - _mytextures._inventoryHud.width / 2 + 50, GetScreenHeight() / 2 - _mytextures._inventoryHud.height / 2 + 150, 25, DARKGREEN);
        DrawText(deraumere.c_str(), GetScreenWidth() / 2 - _mytextures._inventoryHud.width / 2 + 50, GetScreenHeight() / 2 - _mytextures._inventoryHud.height / 2 + 180, 25, DARKGREEN);
        DrawText(sibur.c_str(), GetScreenWidth() / 2 - _mytextures._inventoryHud.width / 2 + 50, GetScreenHeight() / 2 - _mytextures._inventoryHud.height / 2 + 210, 25, DARKGREEN);
        DrawText(mendiane.c_str(), GetScreenWidth() / 2 - _mytextures._inventoryHud.width / 2 + 50, GetScreenHeight() / 2 - _mytextures._inventoryHud.height / 2 + 240, 25, DARKGREEN);
        DrawText(phiras.c_str(), GetScreenWidth() / 2 - _mytextures._inventoryHud.width / 2 + 50, GetScreenHeight() / 2 - _mytextures._inventoryHud.height / 2 + 270, 25, DARKGREEN);
        DrawText(thystame.c_str(), GetScreenWidth() / 2 - _mytextures._inventoryHud.width / 2 + 50, GetScreenHeight() / 2 - _mytextures._inventoryHud.height / 2 + 300, 25, DARKGREEN);

    }
}


void Drawer::DrawMenu()
{
    SetSoundVolume(_AllSounds._scrollSound, _effectSound / 100.0);
    SetSoundVolume(_AllSounds._selectSound, _effectSound / 100.0);
    SetMusicVolume(_AllMusic._mainMusic, _musicSound / 100.0);
    int x = GetScreenWidth() / 2 - _mytextures._menuHud.width / 2;
    int y = GetScreenHeight() / 2 - _mytextures._menuHud.height / 2;
    _myHUD._slideuptoppos.x = x + 105 + (_effectSound * 2.0);
    _myHUD._slideuptoppos.y = y + 95;
    _myHUD._slideupbotpos.x = x + 105 + (_musicSound * 2.0);
    _myHUD._slideupbotpos.y = y + 210;
    DrawTexture(_mytextures._menuHud , x, y, WHITE);
    DrawTexture(_mytextures._slideUp , _myHUD._slideuptoppos.x, _myHUD._slideuptoppos.y, WHITE);
    DrawTexture(_mytextures._slideUp , _myHUD._slideupbotpos.x, _myHUD._slideupbotpos.y, WHITE);
    int mouseX = GetMouseX();
    if (_myBools._mousePressed) {
        if (GetMouseX() >= _myHUD._slideuptoppos.x &&
            GetMouseX() <= _myHUD._slideuptoppos.x + _mytextures._slideUp.width &&
            GetMouseY() >= _myHUD._slideuptoppos.y &&
            GetMouseY() <= _myHUD._slideuptoppos.y + _mytextures._slideUp.height) {
                mouseX = GetMouseX();
                _myBools._moovetop = true;
        }
        else if (GetMouseX() >= _myHUD._slideupbotpos.x &&
            GetMouseX() <= _myHUD._slideupbotpos.x + _mytextures._slideUp.width &&
            GetMouseY() >= _myHUD._slideupbotpos.y &&
            GetMouseY() <= _myHUD._slideupbotpos.y + _mytextures._slideUp.height) {
                mouseX = GetMouseX();
                _myBools._moovebot = true;
        }
    }
    if (_myBools._moovetop) {
        if (mouseX > _myHUD._slideuptoppos.x + _mytextures._slideUp.width) {
            _myHUD._slideuptoppos.x = mouseX - _mytextures._slideUp.width;
            _effectSound = (_myHUD._slideuptoppos.x - x - 105) / 2;
            // if sound not already playing
            if (_effectSound > 0 && !IsSoundPlaying(_AllSounds._scrollSound)) {
                PlaySound(_AllSounds._scrollSound);
            }
            if (_effectSound > 100) {
                _effectSound = 100;
            }
        }
        else if (mouseX < _myHUD._slideuptoppos.x) {
            _myHUD._slideuptoppos.x = mouseX;
            _effectSound = (_myHUD._slideuptoppos.x - x - 105) / 2;
            if (_effectSound > 0 && !IsSoundPlaying(_AllSounds._scrollSound)) {
                PlaySound(_AllSounds._scrollSound);
            }
            if (_effectSound < 0) {
                _effectSound = 0;
            }
        }
    }
    else if (_myBools._moovebot) {
        if (mouseX > _myHUD._slideupbotpos.x + _mytextures._slideUp.width) {
            _myHUD._slideupbotpos.x = mouseX - _mytextures._slideUp.width;
            _musicSound = (_myHUD._slideupbotpos.x - x - 105) / 2;
            if (_musicSound > 0 && !IsSoundPlaying(_AllSounds._scrollSound)) {
                PlaySound(_AllSounds._scrollSound);
            }
            if (_musicSound > 100) {
                _musicSound = 100;
            }
        }
        else if (mouseX < _myHUD._slideupbotpos.x) {
            _myHUD._slideupbotpos.x = mouseX;
            _musicSound = (_myHUD._slideupbotpos.x - x - 105) / 2;
            if (_musicSound > 0 && !IsSoundPlaying(_AllSounds._scrollSound)) {
                PlaySound(_AllSounds._scrollSound);
            }
            if (_musicSound < 0) {
                _musicSound = 0;
            }
        }
    }
}
void Drawer::DrawInfoTeam()
{
    if (_selectedTeam == "")
        return;
    DrawRectangle(0, 0, 300, GetScreenHeight(), Fade(WHITE, 0.5f));
    std::string team_text = "Team : " + _selectedTeam;
    DrawText(team_text.c_str(), 10, 100, 20, BLACK);
    int _playersInTeam = 0;
    _myHUD._yellowButooninfopos.clear();
    for (auto &player : _players) {
        if (player.getTeam().getName() == _selectedTeam) {
            std::string to_draw = "Player #" + std::to_string(player.getID());
            DrawText(to_draw.c_str(), 10, 150 + 50 * _playersInTeam, 20, BLACK);
            DrawTexture(_mytextures._yellowButton, 115 + to_draw.size(), 145 + 50 * _playersInTeam, WHITE);
            to_draw = "X : " + std::to_string(player.getPosition().x) + " Y : " + std::to_string(player.getPosition().y);
            DrawText(to_draw.c_str(), 115 + to_draw.size() + 40, 150 + 50 * _playersInTeam, 20, BLACK);
            position pos;
            pos.x = 115 + to_draw.size();
            pos.y = 145 + 50 * _playersInTeam;
            _myHUD._yellowButooninfopos.push_back(std::make_pair(pos, player.getID()));
            _playersInTeam++;
        }
    }
}

void Drawer::DrawTeams()
{
    if (_teamsnames.size() == 0)
        return;
        DrawTexture(_mytextures._teamsButton, GetScreenWidth() - _mytextures._leaderboardButton.width - 25 - _mytextures._teamsButton.width - 25, 25, WHITE);
    if (_teamsnames.size() > 3) {
        DrawTexture(_mytextures._TeamsUp, GetScreenWidth() - _mytextures._teamsButton.width - 120, 27, WHITE);
        _myHUD._TeamsUpPos = {GetScreenWidth() - _mytextures._teamsButton.width - 120, 27};
        DrawTexture(_mytextures._TeamsDown, GetScreenWidth() - _mytextures._teamsButton.width - 85, 28, WHITE);
        _myHUD._TeamsDownPos = {GetScreenWidth() - _mytextures._teamsButton.width - 85, 28};
    }
    _myHUD._yellowbuttonpos.clear();
    _myHUD._greenbuttonpos.clear();
    for (int i = 0; i < 3; i++) {
        if (_page * 3 + i < _teamsnames.size()) {
            DrawText(_teamsnames[_page * 3 + i].c_str(), GetScreenWidth() - _mytextures._teamsButton.width - 225, 80 + i * 30, 20, RED);
            DrawTexture(_mytextures._yellowButton, GetScreenWidth() - _mytextures._teamsButton.width - 125, 80 + i * 30, WHITE);
            _myHUD._yellowbuttonpos.push_back({GetScreenWidth() - _mytextures._teamsButton.width - 125, 80 + i * 30});
            DrawTexture(_mytextures._greenButton, GetScreenWidth() - _mytextures._teamsButton.width - 90, 80 + i * 30, WHITE);
            _myHUD._greenbuttonpos.push_back({GetScreenWidth() - _mytextures._teamsButton.width - 90, 80 + i * 30});
        }
    }
}

void Drawer::drawHUD(std::pair<int,int> pos)
{
    _leaderplayers.clear();
    if (pos.first != -1 && pos.second != -1 && pos.first != -2 && pos.second != -2) {
        DrawRectangle(0, 0, 300, GetScreenHeight(), Fade(WHITE, 0.5f));
        std::string to_draw = "Tile clicked : " + std::to_string(pos.first) + " " + std::to_string(pos.second);
        DrawText(to_draw.c_str(), 10, 100, 20, BLACK);
        // Calcul de la direction de vue de la caméra
        Vector3 cameraDirection = Vector3Normalize(Vector3Subtract(_AllCameras._MainCamera.target, _AllCameras._MainCamera.position));

    // Dessiner les 100 tuiles les plus proches
    for (auto &tile : _tiles)
    {
            if (tile.getLogicPos().first == pos.first &&
                tile.getLogicPos().second == pos.second) {
            tile.selected = true;
            std::string to_draw = "Tile content : \nfood :";
            to_draw += std::to_string(tile.getData().q0) + "\nlinemate :";
            to_draw += std::to_string(tile.getData().q1) + "\nderaumere :";
            to_draw += std::to_string(tile.getData().q2) + "\nsibur :";
            to_draw += std::to_string(tile.getData().q3) + "\nmendiane :";
            to_draw += std::to_string(tile.getData().q4) + "\nphiras :";
            to_draw += std::to_string(tile.getData().q5) + "\nthystame :";
            to_draw += std::to_string(tile.getData().q6);
            DrawText(to_draw.c_str(), 10, 130, 20, BLACK);
            } else
                tile.selected = false;
    }
    }
    else
        for (auto &tile : _tiles)
            tile.selected = false;
    if (_myBools._drawEchap) {
    DrawTexture(_mytextures._leaderboardButton, GetScreenWidth() - _mytextures._leaderboardButton.width - 25, 25, WHITE);
    int i = 0;
    std::vector<Player> bestPlayers;
    bestPlayers.clear();
    // bestplayer is player but sorted by level
    for (auto &player : _players) {
        if (player.getLevel() > 0)
            bestPlayers.push_back(player);
    }
    std::sort(bestPlayers.begin(), bestPlayers.end(), [](const Player &a, const Player &b) {
        return a.getLevel() > b.getLevel();
    });
    int count = 0;
    // flip the vector
    for (auto &bestPlayer : bestPlayers) {
        if (count == 3)
            break;
        std::string to_draw = "Player #" + std::to_string(bestPlayer.getID()) + " : lvl " + std::to_string(bestPlayer.getLevel());
        DrawText(to_draw.c_str(), GetScreenWidth() - _mytextures._leaderboardButton.width - 5, 80 + 35 * i, 20, DARKGREEN);
        _leaderplayers[bestPlayer.getID()] = std::make_pair(std::make_pair(GetScreenWidth() - _mytextures._leaderboardButton.width - 5, 80 + 35 * i), std::make_pair(GetScreenWidth() - _mytextures._leaderboardButton.width - 5 + MeasureText(to_draw.c_str(), 20), 80 + 35 * i + 20));
        i++;
        count++;
    }
    DrawTexture(_mytextures._menuButton, 25, 25, WHITE);
    if (_myBools._ismenu)
        DrawMenu();
    if (_myBools._inventory && _iDinventory != -1)
        DrawInventory();
    DrawTeams();
    }
}

void Drawer::DrawEvolve()
{
    for (auto &id : _idsinEvolving) {
    for (auto &player : _players) {
        if (player.getID() == id) {
            DrawSphereWires(player.getVecPosition(), 0.65f, 15, 15,
                            Fade(YELLOW, 1.0f));
        }
    }
    }
}

void Drawer::translatecalculate(std::vector<Model> &models)
{
    for (auto &model : models) {
        model.transform = MatrixRotateY(countforanimationX);
    }
    countforanimationX+=0.01;
    if (_myBools.goUp == true)
        countforanimationY+=0.0005;
    else
        countforanimationY-=0.0005;
    if (countforanimationY >= 0.05)
        _myBools.goUp = !_myBools.goUp;
    if (countforanimationY <= 0)
        _myBools.goUp = !_myBools.goUp;
}


void Drawer::draw(sf::TcpSocket &socket)
{
    PlayMusicStream(_AllMusic._mainMusic);
    TraceLogLevel(LOG_NONE);
    while (1) {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        updateMycamera(&_AllCameras._MainCamera);
        BeginMode3D(_AllCameras._MainCamera);
        animCurrentFrame++;
        translatecalculate(_models);
        refresh(socket);
        handleCommand(socket);
        std::pair<int,int> pos = handleClick();
        if (pos.first != -1 && pos.second != -1) {
            _selectedTile = pos;
        }
        drawPlayers();
        GetclickInput();
        drawFood();
        drawGround();
        DrawEvolve();
        EndMode3D();
        DrawInfoTeam();
        drawHUD(_selectedTile);
        // drawfps
        // DrawFPS(10, 10);
        DrawLogs();
        EndDrawing();
    }
}


