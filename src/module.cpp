#include "module.h"
bool module_lawn::add_zombies(int n)
{
    zombienum += n;
    return 1;
}
bool module_lawn::kill_zombies(int n)
{
    zombienum -= n;
    killedzombie += n;
    if (zombienum < 0)
        zombienum = 0;
    return 1;
}
int module_lawn::returnzombienum()
{
    return zombienum;
}
int module_lawn::returnkilledzombies()
{
    return killedzombie;
}
module_lawn::module_lawn()
{
    zombienum = 1;
    killedzombie = 0;
    cout << "Lawn loaded successful." << endl;
}
bool module_barricade::add_hp(int n)
{
    barricade_hp += n;
    if (barricade_hp > 10)
        barricade_hp = 10;
    return 1;
}
int module_barricade::count_hp(int n)
{
    barricade_hp -= n;
    return barricade_hp;
}
int module_barricade::returnbarricadehp()
{
    return barricade_hp;
}
module_barricade::module_barricade()
{
    barricade_hp = 10;
    cout << "Barricade loaded successful." << endl;
}
int module_garage::fix_car(int n)
{
    fix_process += n;
    return fix_process;
}
int module_garage::returnfixprocess()
{
    return fix_process;
}
module_garage::module_garage()
{
    fix_process = 1;
    cout << "Garage loaded successful." << endl;
}