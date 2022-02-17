//
// Created by trico on 15-2-22.
//

#pragma once

class DicelingConfigHandler
{

};

struct Ability
{
    signed int score;
    signed int mod;
    signed int tempScore;
    signed int tempMod;
};

struct HealthPoints
{
    signed int total;
    signed int current;
    signed int nonlethaldamage;
    char* hitDice;
    char* damageReduction;
};

struct ActionClass
{
    signed int armor;
    signed int shield;
    signed int dexterity;
    signed int size;
    signed int natural;
    signed int deflect;
    signed int misc;

    int getTotal()
    {
        return 10 + armor + shield + dexterity + size + natural + deflect + misc;
    }
};

struct Initiative
{
    signed int dexterity;
    signed int misc;

    signed int getTotal()
    {
        return dexterity + misc;
    }
};

struct SavingThrow
{
    signed int base;
    signed int abilityMod;
    signed int magicMod;
    signed int miscMod;
    signed int tempMod;
    signed int getTotal()
    {
        return base + abilityMod + magicMod + miscMod + tempMod;
    }

};

struct BaseAttackBonus
{
    signed int baseAttackBonus;
    signed int strOrDexMod;
    signed int sizeMod;
    signed int miscMod;
    signed int tempMod;
    signed int getTotal()
    {
        return baseAttackBonus + strOrDexMod + sizeMod + miscMod + tempMod;
    }

};

struct WeaponSlot
{
    char* weaponName;
    signed int totalAttackBonus;
    char* damage;
    char* critical;
    unsigned int range;
    char* specialProperties;
    char* Ammunition;
    signed int Weight;
    unsigned int size;
    char* type;
};

struct ProtectiveItem
{
    char* Name;
    char* type;
    signed int acBonus;
    signed int checkPenality;
    signed int maxDexerity;
    char* specialProperties;
    signed int weight;
    signed int spellFail;
    signed int speed;
};

struct Skill
{
    char* skillName;
    char* keyAttribite;
    bool classSkill;
    signed int skillMod;
    signed int attributeMod;
    signed int rank;
    signed int miscMod;
    signed int armorClassPentalty;
};

struct Currency
{
    signed int copperPieces;
    signed int silverPieces;
    signed int goldPieces;
    signed int platinumPieces;
    signed int astralDiamonds;
};

struct SpellsAndPowers
{
    char* spellName;
    unsigned int numOfTimesCast;
};

struct DicelingConfig
{
    char* characterName;
    char* playerName;
    char* alignment;
    unsigned int currentXP;
    unsigned int nextLevelXP;
    unsigned int XPChange;
    char* className;
    char* raceName;
    char* Campaign;
    char* deityName;
    unsigned int level;
    char* size;
    unsigned int age;
    char* gender;
    unsigned int height;
    signed int weight; //I know from experience that due to tomfooldery, players can have a negative weight under certain condtitions.
    char* eyeColor;
    char* hairColor;
    Ability strength;
    Ability dexterity;
    Ability constitution;
    Ability intelligence;
    Ability wisdom;
    Ability charisma;
    HealthPoints hp;
    ActionClass ac;
    unsigned int touch;
    unsigned int flatFooted;
    Initiative init;
    unsigned int speed;
    char* armorType;
    SavingThrow fortitude;
    SavingThrow reflex;
    SavingThrow will;
    BaseAttackBonus melee;
    BaseAttackBonus grapple;
    BaseAttackBonus ranged;
    WeaponSlot weapons[4];
    ProtectiveItem armor[2];
    char** featsAndSpecialAbilities;
    Skill skills[51];
    char** invetory;
    Currency money;
    char** langauges;
    SpellsAndPowers spells[40];
};