import random
import os

ZOMBIE_NUM = 0
BARRICADE_HP = 10
FIX_PROCESS = 1
KILLED_ZOMBIE_NUM = 0
ZOMBIE_WAVE = 0
GAME_ROUND = 1
NO_ZOMBIE_TIMES = 0


def kill_one_zombie():
    global ZOMBIE_NUM
    global KILLED_ZOMBIE_NUM
    i = random.randint(1, 6)
    if (ZOMBIE_NUM):
        if (i > 2):
            before_zombie_num = ZOMBIE_NUM
            ZOMBIE_NUM -= 1
            KILLED_ZOMBIE_NUM += 1
            print('Your dice is %d, you sucessfully killed a zombie! Zombie num: %d -> %d' %
                (i, before_zombie_num, ZOMBIE_NUM))
        else:
            print('Your dice is %d, Failed kill! Zombie num: 0 -> 0' % i)
    else:
        print('There is no zombie on the lawn!')


def add_one_health():
    global BARRICADE_HP
    i = random.randint(1, 6)
    if (BARRICADE_HP < 10):
        if (i > 2):
            BARRICADE_HP += 1
            print('Your dice is %d, you sucessfully healed yourself!' % i)
        else:
            print('Your dice is %d, Failed heal' % i)
    else:
        print('Your barriage is totally healthy!')


def fix_you_car_ten_percent():
    global FIX_PROCESS
    i = random.randint(1, 6)
    if (FIX_PROCESS < 10):
        if (i > 4):
            FIX_PROCESS += 1
            print('Your dice is %d, you sucessfully fixed your car!' % i)
        else:
            print('Your dice is %d, Failed fix' % i)
    else:
        print('You win!')


def zombie_coming():
    global ZOMBIE_NUM
    global NO_ZOMBIE_TIMES
    global FIX_PROCESS
    if (NO_ZOMBIE_TIMES):
        NO_ZOMBIE_TIMES -= 1
        print('No Zombie Come!')
        return
    elif (1 <= FIX_PROCESS & FIX_PROCESS <= 3):
        ZOMBIE_NUM += 1
        print('1 Zombie Coming!!!!')
    elif (4 <= FIX_PROCESS & FIX_PROCESS <= 5):
        ZOMBIE_NUM += 2
        print('2 Zombie Coming!!!!')
    elif (6 <= FIX_PROCESS & FIX_PROCESS <= 8):
        ZOMBIE_NUM += 3
        print('3 Zombie Coming!!!!')
    elif (9 <= FIX_PROCESS):
        ZOMBIE_NUM += 4
        print('4 Zombie Coming!!!!')


def zombie_damage():
    global BARRICADE_HP
    before_hp = BARRICADE_HP
    BARRICADE_HP -= ZOMBIE_NUM
    print('[Zombie Attack]' + str(ZOMBIE_NUM) + ' zombies damage your Barriage, Barriage health:' +
        str(before_hp) + '->' + str(BARRICADE_HP))


def roll_dice():
    global ZOMBIE_NUM
    print('please input kill:')
    usage_kill = int(input())
    print('please input addhp:')
    usage_addhp = int(input())
    print('please input fixcar:')
    usage_fixcar = int(input())
    while (usage_kill):
        usage_kill -= 1
        kill_one_zombie()
    while (usage_addhp):
        usage_addhp -= 1
        add_one_health()
    while (usage_fixcar):
        usage_fixcar -= 1
        fix_you_car_ten_percent()


def show_data():
    print('======================')
    print('ROUND - %d' % GAME_ROUND)
    print('Zombies on the lawn: %d' % ZOMBIE_NUM)
    print('Barriage health: %d' % BARRICADE_HP)
    print('Car fix process: %d' % FIX_PROCESS)
    print('======================')


def show_data_result():
    print('======================')
    print('ROUND - %d [Result]' % GAME_ROUND)
    print('Zombies on the lawn: %d' % ZOMBIE_NUM)
    print('Barriage health: %d' % BARRICADE_HP)
    print('Car fix process: %d' % FIX_PROCESS)
    print('======================')


def killed_bonus():
    global ZOMBIE_NUM
    global FIX_PROCESS
    global NO_ZOMBIE_TIMES
    global BARRICADE_HP
    global KILLED_ZOMBIE_NUM
    if (KILLED_ZOMBIE_NUM >= 10):
        print('You have killed 10+ zombies, please choose your bonus:')
        print('1.Kill all zombies!')
        print('2.Fix your car for 10%!')
        print('3.No zombies coming next turn!')
        print('4.Heal your barricade for 3 hp!')
        i = int(input())
        if (i == 1):
            ZOMBIE_NUM = 0
        elif (i == 2):
            FIX_PROCESS += 1
        elif (i == 3):
            NO_ZOMBIE_TIMES += 1
        elif (i == 4):
            BARRICADE_HP += 3


def main():
    global GAME_ROUND
    while (FIX_PROCESS < 10):
        zombie_coming()
        show_data()
        roll_dice()
        killed_bonus()
        zombie_damage()
        show_data_result()
        if (BARRICADE_HP <= 0):
            print('gameover!')
            break
        os.system('pause')
        GAME_ROUND += 1
    os.system('pause')
    os.system('quit')


if __name__ == "__main__":
    main()
