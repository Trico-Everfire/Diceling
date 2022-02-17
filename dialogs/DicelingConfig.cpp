//
// Created by trico on 1-2-22.
//
#include "DicelingConfig.h"

void DicelingConfig::LoadP2MapConfig()
{
	QString path = QDir::currentPath()+"/configs/config_defaults.json" ;

	if(!QFile::exists(QDir::currentPath()+"/configs/config.json"))
	{
		QFile defaults = QFile(QDir::currentPath()+"/configs/config_defaults.json");
		defaults.open(QIODevice::ReadOnly);
		QFile configuration = QFile(QDir::currentPath()+"/configs/config.json" );
		configuration.open(QIODevice::WriteOnly );
		QTextStream stream( &configuration );
		stream << defaults.readAll() << Qt::endl;
		configuration.close();
	} else {
		path = QDir::currentPath()+"/configs/config.json" ;
	}

	QFile file = QFile( path );
	file.open(QIODevice::ReadOnly);
	qInfo() << path;
	json config = json::parse( file.readAll().toStdString());

    for(const auto& diceStuff : config["Dice Baggies"]){
        std::string name = diceStuff["name"];//.get<std::string>();
        std::string color = diceStuff["color"];//.get<std::string>();
        std::string type = diceStuff["type"];//.get<std::string>();
        DiceBaggies.emplace_back(name, color, type);
    }

	file.close();
}