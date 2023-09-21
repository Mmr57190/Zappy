import socket
import os
import sys
import select
import re

# Case ordered by distance from the player
index = [0, 2, 6, 1, 3, 12, 5, 7, 4, 8, 11, 13, 10, 14, 9, 15]

# What we need to evolve until level 8
level = [{'linemate': 9, 'deraumere': 8, 'sibur': 10, 'mendiane': 5, 'phiras': 6,'thystame': 1, 'player': 1},
         {'linemate': 8, 'deraumere': 8, 'sibur': 10, 'mendiane': 5, 'phiras': 6,'thystame': 1, 'player': 2},
         {'linemate': 7, 'deraumere': 7, 'sibur': 9, 'mendiane': 5, 'phiras': 6,'thystame': 1, 'player': 2},
         {'linemate': 5, 'deraumere': 7, 'sibur': 8, 'mendiane': 5, 'phiras': 4,'thystame': 1, 'player': 4},
         {'linemate': 4, 'deraumere': 6, 'sibur': 6, 'mendiane': 5, 'phiras': 3,'thystame': 1, 'player': 4},
         {'linemate': 3, 'deraumere': 4, 'sibur': 5, 'mendiane': 2, 'phiras': 3,'thystame': 1, 'player': 6},
         {'linemate': 2, 'deraumere': 2, 'sibur': 2, 'mendiane': 2, 'phiras': 2,'thystame': 1, 'player': 6}]

# List of stones in the Trantorian world ordered by rarity
stones = ["thystame", "phiras", "sibur", "mendiane", "deraumere", "linemate"]

# Check if there is enough players to incant
def check_pl(pl, vision):
    if (vision[0].count("player") < level[pl.level - 1]["player"]):
        return False
    return True

class Player:
    def __init__(self, port, name, localhost="localhost"):
        self.port = port
        self.name = name
        self.localhost = localhost
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.buffer = ""
        self.alive = True
        self.level = 1
        self.mode = "Normal"
        self.leader = True
        self.found = -1

    def send(self, message):
        if self.mode == "Incantation":
            return
        self.socket.sendall((message + '\n').encode())

    def receive(self):
        select.select([self.socket], [], [])
        self.buffer = ""
        while "\n" not in self.buffer:
            self.buffer += str(self.socket.recv(2048).decode())
        if "dead" in self.buffer:
            print("You died")
            exit(0)
        if "Elevation underway" in self.buffer:
            self.mode = "Incantation"
            print("MODE: " + self.mode)
            print("Incantation started")
        if "Current level" in self.buffer:
            self.level_up()
        if "ko" in self.buffer and self.mode == "Incantation":
            print("Incantation failed")
            self.mode = "Collect"
        if "message" in self.buffer and self.mode != "Food":
            if (int(self.buffer[18]) == self.level and self.mode == "Evolving"):
                if "evolve" in self.buffer:
                    self.leader = False
                else:
                    self.found = int(self.buffer[8])
        if (self.buffer.count("\n") > 1):
            return self.buffer.split("\n")
        else:
            return self.buffer.replace("\n", "")

    def connect_server(self):
        print(self.localhost, self.port)
        self.socket.connect((self.localhost, int(self.port)))
        print("Connexion en cours avec le serveur.")
        response = self.receive()
        print(response)
        print("Essai pour rejoindre la team \"" + self.name + "\"")
        self.send(self.name)
        response = []
        response = self.receive()
        if response[0] == "ko":
            print("Connexion échouée avec le serveur.")
            exit(84)
        else:
            print("Connexion établie avec le serveur.")
            print("Il reste " + response[0] + " places dans votre team.")
            print("Taille de la map :", response[1])
            if (int(response[0]) > 0):
                self.fork()

    def find_food(self, vision):
        size = len(vision)
        if size > 16:
            size = 16
        for i in range(size):
            if (index[i] >= size):
                continue
            if "food" in vision[index[i]]:
                return (index[i])
        return (-1)

    def find_stone(self, vision, stock):
        size = len(vision)
        if size > 16:
            size = 16
        for i in range(size):
            if (index[i] >= size):
                continue
            for stone in stones:
                if stock[stone] >= level[self.level - 1][stone]:
                    continue
                if stone in vision[index[i]]:
                    return (index[i])
        return (-1)

    def find_player(self, direction):
        if (direction == 0):
            return
        elif (direction == 1):
            self.forward()
        elif (direction == 2):
            self.forward()
            self.left()
        elif (direction == 3):
            self.left()
        elif (direction == 4):
            self.left()
            self.left()
        elif (direction == 5):
            self.left()
            self.left()
            self.left()
        elif (direction == 6):
            self.right()
            self.right()
        elif (direction == 7):
            self.right()
        else:
            self.forward()
            self.right()

    def goto(self, pos):
        match (pos):
            case 0:
                return
            case 1:
                self.forward()
                self.left()
            case 2:
                self.forward()
            case 3:
                self.forward()
                self.right()
            case 4:
                self.goto(6)
                self.left()
                self.forward()
            case 5:
                self.goto(6)
                self.left()
            case 6:
                self.forward()
                self.forward()
            case 7:
                self.goto(6)
                self.right()
            case 8:
                self.goto(6)
                self.right()
                self.forward()
            case 9:
                self.goto(12)
                self.left()
                self.forward()
                self.forward()
            case 10:
                self.goto(12)
                self.left()
                self.forward()
            case 11:
                self.goto(12)
                self.forward()
            case 12:
                self.forward()
                self.forward()
                self.forward()
            case 13:
                self.goto(12)
                self.right()
            case 14:
                self.goto(12)
                self.right()
                self.forward()
            case 15:
                self.goto(12)
                self.left()
                self.forward()
                self.forward()

    def look(self):
        self.send("Look\n")
        response = self.receive()
        while response[0] != "[" and self.mode != "Incantation":
            response = self.receive()
        if self.mode == "Incantation":
            return ([])
        response = re.split('[,]', response[1:-1])
        for i in range(len(response)):
            response[i] = response[i].split(' ')
        return (response)

    def inventory(self):
        self.send("Inventory\n")
        response = self.receive()
        while response[0] != "[" and self.mode != "Incantation":
            response = self.receive()
        if self.mode == "Incantation":
            return ({})
        stock = {}
        response = response[1:-1].split(", ")
        if (response[0][0] == ' '):
            response[0] = response[0][1:]
        if (response[-1][-1] == ' '):
            response[-1] = response[-1][:-1]
        for pair in response:
            pair = pair.split(' ')
            stock[pair[0]] = int(pair[1])
        return (stock)

    def fork(self):
        pid = os.fork()
        if pid > 0:
            pass
        else:
            os.setsid()
            pid = os.fork()
            if pid > 0:
                exit(0)
            else:
                python = sys.executable
                os.execl(python, python, *sys.argv)

    def right(self):
        self.send("Right\n")
        response = self.receive()
        while "ok" not in response and self.mode != "Incantation":
            response = self.receive()
        if self.mode == "Incantation":
            return
        self.forward()

    def left(self):
        self.send("Left\n")
        response = self.receive()
        while "ok" not in response and self.mode != "Incantation":
            response = self.receive()
        if self.mode == "Incantation":
            return
        self.forward()

    def forward(self):
        self.send("Forward\n")
        response = self.receive()
        while "ok" not in response and self.mode != "Incantation":
            response = self.receive()
        if self.mode == "Incantation":
            return

    def take(self, object):
        self.send("Take " + object + "\n")
        response = self.receive()
        while "ok" not in response and "ko" not in response and self.mode != "Incantation":
            response = self.receive()
        if self.mode == "Incantation":
            return (False)
        if "ok" in response:
            return (True)
        return (False)

    def set(self, object):
        self.send("Set " + object + "\n")
        response = self.receive()
        while "ok" not in response and "ko" not in response and self.mode != "Incantation":
            response = self.receive()
        if self.mode == "Incantation":
            return (False)
        if "ok" in response:
            return (True)
        return (False)

    def incantation(self):
        print("Incantation")
        self.send("Incantation\n")
        self.mode = "Evolving"
        response = self.receive()
        while "ko" not in response and "Current" not in response:
            response = self.receive()

    def level_up(self):
        self.level += 1
        self.leader = True
        self.mode = "Collect"
        print("MODE: " + self.mode)
        print("Level up " + str(self.level) + "!")

    def broadcast(self, message):
        self.send("Broadcast " + message + "\n")
        response = self.receive()
        while "ok" not in response:
            response = self.receive()
