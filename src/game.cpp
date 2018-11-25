#include "module.cpp"
game::game()
{
    round = 1;
    distribution_killzombies = 0;
    distribution_addhp = 0;
    distribution_fix = 0;
    zombies_time = 0;
    cout << "Game loaded successful." << endl;
}
bool game::zombiescoming(int n)
{
    if (zombies_time == 0)
    {
        if (1 <= n && n <= 3)
            add_zombies(1);
        else if (4 <= n && n <= 5)
            add_zombies(2);
        else if (6 <= n && n <= 8)
            add_zombies(3);
        else if (9 <= n && n <= 10)
            add_zombies(4);
    }
    else
        zombies_time--;
    return 1;
}
bool game::distribution_dice()
{
    while (1)
    {
        cin.clear();
        cin.sync();
        cout << "Please input the plan of distribution:(killzombie addhp fixcar)" << endl;
        cin >> distribution_killzombies >> distribution_addhp >> distribution_fix;
        if (distribution_killzombies >= 0 && distribution_killzombies <= 4 && distribution_addhp >= 0 && distribution_addhp <= 4 && distribution_fix >= 0 && distribution_fix <= 4 && distribution_killzombies + distribution_addhp + distribution_fix == 4)
            break;
        else
            cout << "Sorry, you have only 4 dices!" << endl;
    }
    return 1;
}
int game::dice()
{
    srand(time(0));
    return (rand() % 6 + 1);
}
bool game::throw_dice()
{
    int i, d, n;
    for (i = 0; i < distribution_killzombies; i++)
    {
        d = dice();
        if (d > 2)
        {
            n = returnzombienum();
            kill_zombies(1);
            cout << "The dice is " << d << ", kill successful!(" << n << "->" << returnzombienum() << ")" << endl;
        }
        else
            cout << "The dice is " << d << ", kill failed!(" << returnzombienum() << "->" << returnzombienum() << ")" << endl;
        Sleep(1000);
    }
    for (i = 0; i < distribution_addhp; i++)
    {
        d = dice();
        if (d > 2)
        {
            n = returnbarricadehp();
            add_hp(1);
            cout << "The dice is " << d << ", heal successful!(" << n << "->" << returnbarricadehp() << ")" << endl;
        }
        else
            cout << "The dice is " << d << ", heal failed!(" << returnbarricadehp() << "->" << returnbarricadehp() << ")" << endl;
        Sleep(1000);
    }
    for (i = 0; i < distribution_fix; i++)
    {
        d = dice();
        if (d > 4)
        {
            n = returnfixprocess();
            fix_car(1);
            cout << "The dice is " << d << ", fix successful!(" << n << "->" << returnfixprocess() << ")" << endl;
        }
        else
            cout << "The dice is " << d << ", fix failed!(" << returnfixprocess() << "->" << returnfixprocess() << ")" << endl;
        Sleep(1000);
    }
    return 1;
}
bool game::zombiesdamage()
{
    cout << "There are " << returnzombienum() << " zombies on the lawn, you receive " << returnzombienum() << " damage!" << endl;
    count_hp(returnzombienum());
    return 1;
}
bool game::killbonus()
{
    int cho;
    if (returnkilledzombies() >= 10)
    {
        cout << "You have killed 10+ zombies, please choose your bonus:" << endl;
        cout << "1.Kill all zombies!" << endl;
        cout << "2.Fix your car for 10%!" << endl;
        cout << "3.No zombies coming next turn!" << endl;
        cout << "4.Heal your barricade for 3 hp !" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            kill_zombies(100);
            setkilledzombies();
            break;
        case 2:
            fix_car(1);
            setkilledzombies();
            break;
        case 3:
            addzombiestime();
            setkilledzombies();
            break;
        case 4:
            add_hp(3);
            setkilledzombies();
            break;
        default:
            break;
        }
    }
    return 1;
}
bool game::addzombiestime()
{
    zombies_time++;
    return 1;
}
bool game::iswin()
{
    if (returnfixprocess() >= 10)
        return 1;
    else
        return 0;
}
bool game::islose()
{
    if (returnbarricadehp() <= 0)
        return 1;
    else
        return 0;
}
bool game::situation()
{
    cout << "=====ROUND:" << round << "=====" << endl;
    cout << "Zombiesnum:" << returnzombienum() << endl;
    cout << "Barricadehp:" << returnbarricadehp() << "/10" << endl;
    cout << "Fixprocess:" << returnfixprocess() << "0%" << endl;
    cout << "Killedzombies:" << returnkilledzombies() << "/10" << endl;
    cout << "=================" << endl;
    return 1;
}
int game::startgame()
{
    while (1)
    {
        zombiescoming(returnfixprocess());
        situation();
        distribution_dice();
        throw_dice();
        if (iswin())
        {
            cout << "You win!" << endl;
            system("pause");
            break;
        }
        zombiesdamage();
        if (islose())
        {
            cout << "You lose!" << endl;
            system("pause");
            break;
        }
        killbonus();
        if (iswin())
        {
            cout << "You win!" << endl;
            break;
        }
        round++;
        system("pause");
    }
    return 1;
}
int main()
{
    int cho;
    game g;
    cout << "  ______                            ______                  " << endl;
    cout << "|  ____|                          |  ____|                  " << endl;
    cout << "| |__   ___  ___ __ _ _ __   ___  | |__ _ __ ___  _ __ ___  " << endl;
    cout << "|  __| / __|/ __/ _` | '_ \\ / _ \\ |  __| '__/ _ \\| '_ ` _ \\ " << endl;
    cout << "| |____\\__ \\ (_| (_| | |_) |  __/ | |  | | | (_) | | | | | |" << endl;
    cout << "|______|___/\\___\\__,_| .__/ \\___| |_|  |_|  \\___/|_| |_| |_|" << endl;
    cout << "                     | |                                    " << endl;
    cout << " _______ _           |_|___                 _               " << endl;
    cout << "|__   __| |          |  __ \\               | |              " << endl;
    cout << "   | |  | |__   ___  | |  | | ___  __ _  __| |              " << endl;
    cout << "   | |  | '_ \\ / _ \\ | |  | |/ _ \\/ _` |/ _` |              " << endl;
    cout << "   | |  | | | |  __/ | |__| |  __/ (_| | (_| | by:          " << endl;
    cout << "   |_|  |_| |_|\\___| |_____/ \\___|\\__,_|\\__,_| rankofmatrix " << endl;
    cout << "                                                            " << endl;
    cout << "============================================================" << endl;
    cout << "                          1.Play                            " << endl;
    cout << "                          2.Exit                            " << endl;
    cin >> cho;
    system("cls");
    if (cho == 1)
        g.startgame();
    return 0;
}
