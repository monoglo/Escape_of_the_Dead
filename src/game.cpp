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
        if (1 <= n && n <= 30)
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
    srand(time(0)); //设置种子数，由于有了间隔，能够保证种子数不同
    return (rand() % 6 + 1);
}
bool game::throw_dice()
{
    int i, d;
    for (i = 0; i < distribution_killzombies; i++)
    {
        d = dice();
        if (d > 2)
        {
            kill_zombies(1);
            cout << "The dice is " << d << ", kill successful!" << endl;
        }
        else
            cout << "The dice is " << d << ", kill failed!" << endl;
        Sleep(1000);
    }
    for (i = 0; i < distribution_addhp; i++)
    {
        d = dice();
        if (d > 2)
        {
            add_hp(1);
            cout << "The dice is " << d << ", heal successful!" << endl;
        }
        else
            cout << "The dice is " << d << ", heal failed!" << endl;
        Sleep(1000);
    }
    for (i = 0; i < distribution_fix; i++)
    {
        d = dice();
        if (d > 4)
        {
            fix_car(1);
            cout << "The dice is " << d << ", fix successful!" << endl;
        }
        else
            cout << "The dice is " << d << ", fix failed!" << endl;
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
            break;
        case 2:
            fix_car(1);
            break;
        case 3:
            addzombiestime();
            break;
        case 4:
            add_hp(3);
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
    cout << "zombiesnum:" << returnzombienum() << endl;
    cout << "barricadehp:" << returnbarricadehp() << "/10" << endl;
    cout << "fixprocess:" << returnfixprocess() << "0%" << endl;
    cout << "killedzombies:" << returnkilledzombies() << "/10" << endl;
    cout << "=================" << endl;
    return 1;
}
int game::startgame()
{
    while (1)
    {
        situation();
        zombiescoming(returnfixprocess());
        distribution_dice();
        throw_dice();
        if (iswin())
        {
            cout << "You win!" << endl;
            break;
        }
        zombiesdamage();
        if (islose())
        {
            cout << "You lose!" << endl;
            break;
        }
        killbonus();
        if (iswin())
        {
            cout << "You win!" << endl;
            break;
        }
        round++;
    }
    return 1;
}
int main()
{
    game g;
    g.startgame();
    return 0;
}
