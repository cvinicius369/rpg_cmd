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
        string name, entityType;
        int level, experience, counter;
        bool ultimateActivated;

        Entity(
            string nm, double atk, double hp, double df, double co, double rubs, int lvl, int xp,
            string etype
        ): 
            name(nm), attack(atk), health(hp), defense(df), coins(co), rubys(rubs), 
            level(lvl), experience(xp), entityType(etype) {}

        void takeDemage(double dmg){ 
            double finalDemage = dmg - (defense / 100);
            if(finalDemage < 0){ finalDemage = 0; }
            health -= finalDemage;
        }
        void upgradeLevel(){ 
            while (experience >= level * 5){
                experience -= level * 5; level++;
                gameMSG(name + " subiu para o nivel: " + to_string(level) + "!");
            }
        }
        void buff(double bonus, bool typeAtk, bool typeHp, bool typeDef){
            if(typeAtk){ attack += (bonus * attack) / 100; }
            if(typeHp){ health += (bonus * health) / 100; }
            if(typeDef){ defense += (bonus * defense) / 100; }
        }
        void nerf(double nerfValue, bool typeAtk, bool typeHp, bool typeDef){
            if(typeAtk){ attack -= (nerfValue * attack) / 100; }
            if(typeHp){ health -= (nerfValue * health) / 100; }
            if(typeDef){ defense -= (nerfValue * defense) / 100; }
        }
};

class Player : public Entity{
    private:
        bool supreme_mode = false, colarDoSange = false, escudoDivino = false, espadaSombria = false;

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
        Player(
            string nm, double atk, double hp, double df, double co, double rubs, int lvl, int xp,
            string etype
        ) : Entity(nm, atk, hp, df, co, rubs, lvl, xp, etype){}

        /*--[ MECANICAS DO PLAYER ]--*/
        void activateSupremeMode(){ 
            if(level > 5){ 
                supreme_mode = true; 
                gameMSG("Modo Supremo Ativado!");
            }
        }
        double getExperience(bool enemieDefeat, bool playerDefeat){
            if(enemieDefeat){ return experience += 3; }
            else if(playerDefeat){ return experience += 1; }
            else { return experience; }
        }
        double basicAttack(double bonus){ 
            counter++;
            if(counter >= 10){ ultimateActivated = true; counter = 0; }
            return attack + ((bonus * attack) / 100); 
        }
        void ultimate(bool typeAtk, bool typeHp, bool typeDef){
            double tempAtk = attack, tempHp = health, tempDef = defense;
            if(typeAtk){ attack += (90 * attack) / 100; }
            if(typeHp){ health += (90 * health) / 100; }
            if(typeDef){ defense += (90 * defense) / 100; }
            counter = 0;
            basicAttack(0);
            attack = tempAtk; health = tempHp, defense = tempDef;
        }
        void obtainAttribute(double qtd, bool isCoin, bool isRuby, bool isXp){
            if(isCoin){ coins += qtd; }
            if(isRuby){ rubys += qtd; }
            if(isXp){ experience += qtd; }
        }
};

class Enemies : public Entity{
    public:
        Enemies(
            string nm, double atk, double hp, double df, double co, double rubs, int lvl, int xp,
            string etype
        ): Entity(nm, atk, hp, df, co, rubs, lvl, xp, etype){}

        double basicAttack(double bonus){ return attack + ((bonus * attack) / 100); }
        
};

class Skeleton : public Enemies{
    public:
        Skeleton(
            string nm, double atk, double hp, double df, double co, double rubs, int lvl, int xp
        ): Enemies(nm, atk, hp, df, co, rubs, lvl, xp, "guerreiro"){}
};

int main(){
    /*--[ MANIPULAVEL PELO PLAYER ]--*/
    /* 
        Uso do switchtype:
            quando o usuario atingir 10 no counter, o mesmo conseguirá utilizar a
            ultimate uma vez, a mesa terá os buffs de acordo com o tipo do player
        Exemplo:
            mago:
                ultimate(true, false, true); isso faria o poder dele aumentar mas
                sua vida ainda será a mesma, isso funcionará em uma rodada apenas
    
    switch (option){
        case 0: entityType = "guerreiro"; break;
        case 1: entityType = "mago"; break;
        case 2: entityType = "arqueiro"; break;
        default: entityType = "guerreiro"; break;
    }*/
    return 0;
}