#include "ChiraEngineWorkerThread.h"

#include <core/engine.h>
#include <hook/discordRPC.h>

using namespace chira;

void ChiraEngineWorkerThread::run() {
    //DiscordRPC::init("your-app-id-here");
    //DiscordRPC::setLargeImage("main_logo_name");
    //DiscordRPC::setState("some text");

    Engine::init([]
    {
        // idk do stuff
    }, false);
    Engine::run();
}