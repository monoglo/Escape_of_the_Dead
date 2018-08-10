#include "module.cpp"
game::game()
{
    round = 0;
    distribution_killzombies = 0;
    distribution_addhp = 0;
    distribution_fix = 0;
    cout << "Game loaded successful." << endl;
}
bool game::zombiescoming(int n)
{
    if (10 <= n && n <= 30)
        add_zombies(1);
    else if (40 <= n && n <= 50)
        add_zombies(2);
    else if (60 <= n && n <= 80)
        add_zombies(3);
    else if (90 <= n && n <= 100)
        add_zombies(4);
    return 1;
}
bool game::distribution_dice()
{
    cout << "Please input the plan of distribution:(kill addhp fix)" << endl;
    cin >> distribution_killzombies>>distribution_addhp>>distribution_fix;
    return 1;
}
