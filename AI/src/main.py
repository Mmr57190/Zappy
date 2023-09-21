import sys
import argparse
from AI.player import Player, level, stones, check_pl

def check_args(args):
    if len(args) < 4 or args[1] == "-help":
        print("USAGE: ./zappy_ai -p port -n name -h machine\n\tport is the port number\n\tname is the name of the team\n\tmachine is the name of the machine; localhost by default")
        return
    parser = argparse.ArgumentParser(description='Zappy AI', add_help=False)
    parser.add_argument('-p', dest='port', type=int, help='Port number', required=True)
    parser.add_argument('-n', dest='name', type=str, help='Name of the team', required=True)
    parser.add_argument('-h', dest='machine', help='Name of the machine; localhost by default', default='localhost')
    args = parser.parse_args()
    if(len(sys.argv) == 4):
        pl = Player(args.port ,args.name)
    else:
        pl = Player(args.port, args.name, args.machine)
    return pl

# Check if there is an object in the case
def is_there(case, object):
    if object in case:
        return True
    return False

# Check if there is no stone on our case
def no_stone(case, stock, lvl):
    for stone in stones:
        if (is_there(case, stone) and level[lvl - 1][stone] != stock[stone]):
            return False
    return True

# Check if we have enough stones to incant
def have_stone(pl, stock):
    for stone in stones:
        if (stock[stone] < (level[pl.level - 1][stone] - level[pl.level][stone])):
            return False
    return True

# Check if there is enough stones on our case to incant
def check_incant(pl, vision):
    for stone in stones:
        if (vision[0].count(stone) < (level[pl.level - 1][stone] - level[pl.level][stone]) * level[pl.level - 1]["player"]):
            return False
    return True and check_pl(pl, vision)

# Set all stones needed for incantation
def set_incant(pl, vision, stock):
    for stone in stones:
        for i in  range(level[pl.level - 1][stone] - level[pl.level][stone]):
            if (pl.set(stone)):
                stock[stone] -= 1
                vision[0].append(stone)
    return vision, stock

def collect(stock, vision, pl):
    # Collect stones
    if pl.mode != "Food":
        for stone in stones:
            if (is_there(vision[0], stone) and stock[stone] < (level[pl.level - 1][stone])):
                if (pl.take(stone)):
                    vision[0].remove(stone)
                    stock[stone] += 1
                else:
                    vision = pl.look()
    # Collect food
    while (stock["food"] < 13 and is_there(vision[0], "food")):
        if (pl.take("food")):
            vision[0].remove("food")
            stock["food"] += 1
        else:
            vision = pl.look()
    # IA Mode Food Gestion
    if (stock["food"] < 7 and pl.mode != "Food"):
        pl.mode = "Food"
    if (stock["food"] >= 13 and pl.mode == "Food"):
        pl.mode = "Collect"
    print("MODE: " + pl.mode)
    return stock, vision

def move(pl, stock, vision, count = 1):
    # Check if we have enough food to survive and search for food if not
    if pl.mode == "Food":
        pos = pl.find_food(vision)
        if pos != -1:
            pl.goto(pos)
            return
        if count != 6:
            pl.forward()
            vision = pl.look()
            move(pl, stock, vision, count + 1)
        else:
            pl.right()
        return
    # Check if we have stone to collect and search for stone if not
    if no_stone(vision[0], stock, pl.level):
        pl.goto(pl.find_stone(vision, stock))

def evolution(pl, stock, vision):
    # Check food for incantation
    if (stock["food"] < 7):
        pl.mode = "Food"
        return
    # If we can incant or not
    if (check_pl(pl, vision)):
        set_incant(pl, vision, stock)
        pl.broadcast("evolve " + str(pl.level))
        if (pl.leader):
            while not check_incant(pl, vision) and stock["food"] > 7:
                stock = pl.inventory()
                vision = pl.look()
            if check_incant(pl, vision):
                pl.incantation()
        else:
            while pl.mode != "Incantation" and stock["food"] > 6 and pl.leader == False:
                stock = pl.inventory()
        pl.leader = True
    else:
        if pl.found != -1:
            pl.find_player(pl.found)
            pl.found = -1
            return
        pl.broadcast("incant " + str(pl.level))


def main():
    # Args Gestion
    pl = check_args(sys.argv)
    if not pl:
        return
    # IA Gestion
    pl.connect_server()
    while pl.alive:
        vision = pl.look()
        stock = pl.inventory()
        if pl.mode != "Evolving" and stock and vision:
            # Check stone for incantation
            if (have_stone(pl, stock)):
                pl.mode = "Evolving"
                print("MODE: " + pl.mode)
            stock, vision = collect(stock, vision, pl)
            move(pl, stock, vision)
        elif stock and vision :
            evolution(pl, stock, vision)
        while pl.mode == "Incantation":
            pl.receive()
        # print("STOCK: " + str(stock))
