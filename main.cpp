#include <iostream>
using namespace std;

void gameMSG(string msg){
    cout << "===============================================================" << endl;
    cout << msg << endl;
    cout << "===============================================================" << endl;
}

class Entity{
    public:
        double health, attack, defense, coins, rubys;
        string name;
        int level, experience;

        Entity(string nm, double atk, double hp, double df, double co, double rubs, int lvl, int xp) 
            : name(nm), attack(atk), health(hp), defense(df), coins(co), rubys(rubs), level(lvl), experience(xp) {}

        void takeDemage(double dmg){ health = health - (dmg - (defense / 100)); }
        void upgradeLevel(){ level = experience / 5; }
};

class Player : public Entity{
    private:
        bool supreme_mode = false;

        void getSupremeMode(){
            int bonusSupreme = 50;
            if(level > 5){ supreme_mode = true; }
            if(supreme_mode){
                attack = attack + ((bonusSupreme * attack) / 100);
                health = health + ((bonusSupreme * health) / 100);
                defense = defense + ((bonusSupreme * defense) / 100);
            }
        }
    public:
        Player(string nm, double atk, double hp, double df, double co, double rubs, int lvl, int xp)
            : Entity(nm, atk, hp, df, co, rubs, lvl, xp){}
        void activateSupremeMode(){ 
            if(level > 5){ 
                supreme_mode = true; 
                gameMSG("Modo Supremo Ativado!");
            }
        }
        double getExperience(bool enemieDefeat, bool playerDefeat){
            if(enemieDefeat){ experience += 3; }
            else if(playerDefeat){ experience += 1; }
        }
        double basicAttack(double bonus){ return attack + ((bonus * attack) / 100); }
};

class Enemies : public Entity{

};

class Skeleton : public Enemies{

};

class Main{
    public:
        int main(){
            return 0;
        }
};