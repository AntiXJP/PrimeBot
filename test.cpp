#include <string>
#include <iostream>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <string>
#include <vector>
#include <tgbot/tgbot.h>
#include "module.h"

using namespace TgBot;
using namespace std;


int main()
{
    string token = "PLACE YOUT R TOKEN HERE";
    Bot bot(token);

    bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
    });
    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start"))
        {
            return;
        }

        string temp=Prime(message->text);
            if (temp.length() <= 2000)
            {
                bot.getApi().sendMessage(message->chat->id, temp);
            }
            else
            {
                bot.getApi().sendMessage(message->chat->id, to_string(temp.length()));
            }
    });
    try
    {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgLongPoll longPoll(bot);
        while (true)
        {
            longPoll.start();
        }
    }
    catch (TgException &e)
    {
        printf("error: %s\n", e.what());
    }
    return 0;
}