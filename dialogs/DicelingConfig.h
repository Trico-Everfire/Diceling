//
// Created by trico on 1-2-22.
//
#pragma once
#include "libs/JSON/json.hpp"
#include "QTextStream"
#include "QFile"
#include "QDir"
#include "QDebug"
#include <QVector>

using json = nlohmann::json;

struct diceBaggie
{
    diceBaggie(std::string name, std::string color, std::string type) : diceName(name) ,diceHexCode(color), diceType(type){}
    std::string diceName;
    std::string diceHexCode;
    std::string diceType;
};

struct DicelingConfig
{
	DicelingConfig() = delete;
	inline static std::vector<diceBaggie> DiceBaggies;
	static void LoadP2MapConfig();
};

