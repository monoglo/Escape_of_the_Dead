#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
class module_lawn
{
public:
  bool add_zombies(int n);
  bool kill_zombies(int n);
  int returnzombienum();
  int returnkilledzombies();
  int setkilledzombies();
  module_lawn();

private:
  int zombienum;
  int killedzombie;
};
class module_barricade
{
public:
  bool add_hp(int n);
  int count_hp(int n);
  int returnbarricadehp();
  module_barricade();

private:
  int barricade_hp;
};

class module_garage
{
public:
  int fix_car(int n);
  int returnfixprocess();
  module_garage();

private:
  int fix_process;
};

class game : public module_lawn, public module_barricade, public module_garage
{
public:
  game();
  bool zombiescoming(int n);
  bool distribution_dice();
  bool throw_dice();
  bool zombiesdamage();
  bool killbonus();
  bool addzombiestime();
  bool iswin();
  bool islose();
  bool situation();
  int startgame();
  int dice();

private:
  int distribution_killzombies;
  int distribution_addhp;
  int distribution_fix;
  int zombies_time;
  int round;
};
