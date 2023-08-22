#include <string>
#include <iostream>
#include <unordered_map>
#include <array>

const std::unordered_map<uint64_t, std::string> WWO_CODE = {{0,  "Ясно"},{1,  "Малооблачно"},
                                                            {2,  "Облачно"},{3,  "Пасмурно"},
                                                            {45, "Туман"},{48, "Изморозь"},
                                                            {51, "Легкий моросящий дождь"},{53, "Легкий моросящий дождь"},{55, "Средний моросящий дождь"},
                                                            {56, "Моросящий дождь со снегом"},{57, "Моросящий дождь со снегом"},
                                                            {61, "Легкий дождь"},{63, "Дождь"},{65, "Сильный дождь"},
                                                            {66, "Легкий дождь со снегом"},{67, "Дождь со снегом"},
                                                            {71, "Небольшой снег"},{73, "Снег"},{75, "Сильный снег"},
                                                            {77, "Снежные зерна"},
                                                            {80, "Небольшой ливень"},{81, "Ливень"},{82, "Сильный ливень"},
                                                            {85, "Снегопад"},{86, "Сильный снегопад"},
                                                            {95, "Гроза"},
                                                            {96, "Гроза с незначительным градом"},{99, "Гроза с градом"}
};


const std::unordered_map<std::string, std::array<std::string, 5>> WEATHER_SYMBOL_WEGO = {
        {"Неизвестно",                    {
                                                  "    .-.      ",
                                                  "     __)     ",
                                                  "    (        ",
                                                  "     `-’     ",
                                                  "      •      "
                                          }},
        {"Облачно",                       {
                                                  "             ",
                                                  "     .--.    ",
                                                  "  .-(    ).  ",
                                                  " (___.__)__) ",
                                                  "             "
                                          }},
        {"Ясно",                          {
                                                  "    \\   /    ",
                                                  "     .-.     ",
                                                  "  ― (   ) ―  ",
                                                  "     `-’     ",
                                                  "    /   \\    "
                                          }},
        {"Малооблачно",                   {
                                                  "   \\  /      ",
                                                  " _ /\"\".-.    ",
                                                  "   \\_(   ).  ",
                                                  "   /(___(__) ",
                                                  "             "
                                          }},
        {"Пасмурно",                      {
                                                  "             ",
                                                  "     .--.    ",
                                                  "  .-(    ).  ",
                                                  " (___.__)__) ",
                                                  "             "
                                          }},
        {"Легкий моросящий дождь",        {
                                                  " _`/\"\".-.    ",
                                                  "  ,\\_(   ).  ",
                                                  "   /(___(__) ",
                                                  "     ‘ ‘ ‘ ‘ ",
                                                  "    ‘ ‘ ‘ ‘  "
                                          }},
        {"Средний моросящий дождь",       {
                                                  " _`/\"\".-.    ",
                                                  "  ,\\_(   ).  ",
                                                  "   /(___(__) ",
                                                  "     ‘ ‘ ‘ ‘ ",
                                                  "    ‘ ‘ ‘ ‘  "
                                          }},
        {"Сильно моросящий дождь",        {
                                                  " _`/\"\".-.    ",
                                                  "  ,\\_(   ).  ",
                                                  "   /(___(__) ",
                                                  "   ‚‘‚‘‚‘‚‘  ",
                                                  "   ‚’‚’‚’‚’  "
                                          }},

        {"Легкий дождь со снегом",        {
                                                  " _`/\"\".-.    ",
                                                  "  ,\\_(   ).  ",
                                                  "   /(___(__) ",
                                                  "    * * * *  ",
                                                  "   * * * *   "
                                          }},
        {"Моросящий дождь со снегом",     {
                                                  " _`/\"\".-.    ",
                                                  "  ,\\_(   ).  ",
                                                  "   /(___(__) ",
                                                  "     ‘ * ‘ * ",
                                                  "    * ‘ * ‘  "
                                          }},
        {"Дождь со снегом",               {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "    ‘ * ‘ *  ",
                                                  "   * ‘ * ‘   "
                                          }},
        {"Легкий дождь",                  {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "    ‘ ‘ ‘ ‘  ",
                                                  "   ‘ ‘ ‘ ‘   "
                                          }},
        {"Дождь",                         {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "    ‘ ‘ ‘ ‘  ",
                                                  "   ‘ ‘ ‘ ‘   "
                                          }},
        {"Сильный дождь",                 {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "  ‚‘‚‘‚‘‚‘   ",
                                                  "  ‚’‚’‚’‚’   "
                                          }},
        {"Ливень",                        {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "  ‚‘‚‘‚‘‚‘   ",
                                                  "  ‚’‚’‚’‚’   "
                                          }},
        {"Небольшой ливень",              {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "  ‚‘‚‘‚‘‚‘   ",
                                                  "  ‚’‚’‚’‚’   "
                                          }},
        {"Сильный ливень",                {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "  ‚‘‚‘‚‘‚‘   ",
                                                  "  ‚’‚’‚’‚’   "
                                          }},
        {"Небольшой снег",                {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "    *  *  *  ",
                                                  "   *  *  *   "
                                          }},
        {"Снег",                          {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "   * * * *   ",
                                                  "  * * * *    "
                                          }},
        {"Сильный снег",                  {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "   * * * *   ",
                                                  "  * * * *    "
                                          }},
        {"Снегопад",                      {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "   * * * *   ",
                                                  "  * * * *    "
                                          }},
        {"Сильный снегопад",              {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "   * * * *   ",
                                                  "  * * * *    "
                                          }},
        {"Снежные зерна",                 {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "   * * * *   ",
                                                  "  * * * *    "
                                          }},
        {"Гроза",                         {
                                                  "     .-.     ",
                                                  "    (   ).   ",
                                                  "   (___(__)  ",
                                                  "  ‚‘⚡‘‚⚡‚‘   ",
                                                  "  ‚’‚’⚡’‚’   "
                                          }},
        {"Гроза с незначительным градом", {
                                                  " _`/\"\".-.    ",
                                                  "  ,\\_(   ).  ",
                                                  "   /(___(__) ",
                                                  "     *⚡*⚡*   ",
                                                  "    *  *  *  "
                                          }},
        {"Гроза с градом",                {
                                                  " _`/\"\".-.    ",
                                                  "  ,\\_(   ).  ",
                                                  "   /(___(__) ",
                                                  "     *⚡*⚡*   ",
                                                  "    *  *  *  "
                                          }},
        {"Туман",                         {
                                                  "             ",
                                                  " _ - _ - _ - ",
                                                  "  _ - _ - _  ",
                                                  " _ - _ - _ - ",
                                                  "             "
                                          }},
        {"Изморозь",                      {
                                                  "             ",
                                                  " _ - _ - _ - ",
                                                  "  _ - _ - _  ",
                                                  " _ - _ - _ - ",
                                                  "             "
                                          }}
};

/*
const std::unordered_map<std::string,std::array<std::string,5>> WEATHER_SYMBOL_WEGO_COLOR={
        {"Неизвестно",{
            "    .-.      ",
            "     __)     ",
            "    (        ",
            "     `-’     ",
            "      •      "
        }},
        {"Облачно",{
            "             ",
            "\033[38;5;250m     .--.    \033[0m",
            "\033[38;5;250m  .-(    ).  \033[0m",
            "\033[38;5;250m (___.__)__) \033[0m",
            "             "
        }},
        {"Ясно",{
            "\033[38;5;226m    \\   /    \033[0m",
            "\033[38;5;226m     .-.     \033[0m",
            "\033[38;5;226m  ― (   ) ―  \033[0m",
            "\033[38;5;226m     `-’     \033[0m",
            "\033[38;5;226m    /   \\    \033[0m"
        }},
        {"Малооблачно",{
            "\033[38;5;226m   \\  /\033[0m      ",
            "\033[38;5;226m _ /\"\"\033[38;5;250m.-.    \033[0m",
            "\033[38;5;226m   \\_\033[38;5;250m(   ).  \033[0m",
            "\033[38;5;226m   /\033[38;5;250m(___(__) \033[0m",
            "             "
        }},
        {"Пасмурно",{
            "             ",
            "\033[38;5;240;1m     .--.    \033[0m",
            "\033[38;5;240;1m  .-(    ).  \033[0m",
            "\033[38;5;240;1m (___.__)__) \033[0m",
            "             "
        }},
        {"Легкий моросящий дождь",{
                                "\033[38;5;226m _`/\"\"\033[38;5;250m.-.    \033[0m",
                                "\033[38;5;226m  ,\\_\033[38;5;250m(   ).  \033[0m",
                                "\033[38;5;226m   /\033[38;5;250m(___(__) \033[0m",
                                "\033[38;5;111m     ‘ ‘ ‘ ‘ \033[0m",
                                "\033[38;5;111m    ‘ ‘ ‘ ‘  \033[0m"
        }},
        {"Средний моросящий дождь",{
                "\033[38;5;226m _`/\"\"\033[38;5;250m.-.    \033[0m",
                "\033[38;5;226m  ,\\_\033[38;5;250m(   ).  \033[0m",
                "\033[38;5;226m   /\033[38;5;250m(___(__) \033[0m",
                "\033[38;5;111m     ‘ ‘ ‘ ‘ \033[0m",
                "\033[38;5;111m    ‘ ‘ ‘ ‘  \033[0m"
        }},
        {"Сильно моросящий дождь",{
                                "\033[38;5;226m _`/\"\"\033[38;5;240;1m.-.    \033[0m",
                                "\033[38;5;226m  ,\\_\033[38;5;240;1m(   ).  \033[0m",
                                "\033[38;5;226m   /\033[38;5;240;1m(___(__) \033[0m",
                                "\033[38;5;21;1m   ‚‘‚‘‚‘‚‘  \033[0m",
                                "\033[38;5;21;1m   ‚’‚’‚’‚’  \033[0m"
        }},

        {"Легкий дождь со снегом",{
                                    "\033[38;5;226m _`/\"\"\033[38;5;240;1m.-.    \033[0m",
                                    "\033[38;5;226m  ,\\_\033[38;5;240;1m(   ).  \033[0m",
                                    "\033[38;5;226m   /\033[38;5;240;1m(___(__) \033[0m",
                                    "\033[38;5;255;1m    * * * *  \033[0m",
                                    "\033[38;5;255;1m   * * * *   \033[0m"
        }},
        {"Моросящий дождь со снегом",{
                "\033[38;5;226m _`/\"\"\033[38;5;250m.-.    \033[0m",
                "\033[38;5;226m  ,\\_\033[38;5;250m(   ).  \033[0m",
                "\033[38;5;226m   /\033[38;5;250m(___(__) \033[0m",
                "\033[38;5;111m     ‘ \033[38;5;255m*\033[38;5;111m ‘ \033[38;5;255m* \033[0m",
                "\033[38;5;255m    *\033[38;5;111m ‘ \033[38;5;255m*\033[38;5;111m ‘  \033[0m"
        }},
        {"Дождь со снегом",{
                "\033[38;5;250m     .-.     \033[0m",
                "\033[38;5;250m    (   ).   \033[0m",
                "\033[38;5;250m   (___(__)  \033[0m",
                "\033[38;5;111m    ‘ \033[38;5;255m*\033[38;5;111m ‘ \033[38;5;255m*  \033[0m",
                "\033[38;5;255m   *\033[38;5;111m ‘ \033[38;5;255m*\033[38;5;111m ‘   \033[0m"
        }},
        {"Легкий дождь",{
                "\033[38;5;250m     .-.     \033[0m",
                "\033[38;5;250m    (   ).   \033[0m",
                "\033[38;5;250m   (___(__)  \033[0m",
                "\033[38;5;111m    ‘ ‘ ‘ ‘  \033[0m",
                "\033[38;5;111m   ‘ ‘ ‘ ‘   \033[0m"
        }},
        {"Дождь",{
                "\033[38;5;250m     .-.     \033[0m",
                "\033[38;5;250m    (   ).   \033[0m",
                "\033[38;5;250m   (___(__)  \033[0m",
                "\033[38;5;111m    ‘ ‘ ‘ ‘  \033[0m",
                "\033[38;5;111m   ‘ ‘ ‘ ‘   \033[0m"
        }},
        {"Сильный дождь",{
                "\033[38;5;240;1m     .-.     \033[0m",
                "\033[38;5;240;1m    (   ).   \033[0m",
                "\033[38;5;240;1m   (___(__)  \033[0m",
                "\033[38;5;21;1m  ‚‘‚‘‚‘‚‘   \033[0m",
                "\033[38;5;21;1m  ‚’‚’‚’‚’   \033[0m"
        }},
        {"Ливень",{
                "\033[38;5;240;1m     .-.     \033[0m",
                "\033[38;5;240;1m    (   ).   \033[0m",
                "\033[38;5;240;1m   (___(__)  \033[0m",
                "\033[38;5;21;1m  ‚‘‚‘‚‘‚‘   \033[0m",
                "\033[38;5;21;1m  ‚’‚’‚’‚’   \033[0m"
        }},
        {"Незначительный ливень",{
                "\033[38;5;240;1m     .-.     \033[0m",
                "\033[38;5;240;1m    (   ).   \033[0m",
                "\033[38;5;240;1m   (___(__)  \033[0m",
                "\033[38;5;21;1m  ‚‘‚‘‚‘‚‘   \033[0m",
                "\033[38;5;21;1m  ‚’‚’‚’‚’   \033[0m"
        }},
        {"Сильный ливень",{
                "\033[38;5;240;1m     .-.     \033[0m",
                "\033[38;5;240;1m    (   ).   \033[0m",
                "\033[38;5;240;1m   (___(__)  \033[0m",
                "\033[38;5;21;1m  ‚‘‚‘‚‘‚‘   \033[0m",
                "\033[38;5;21;1m  ‚’‚’‚’‚’   \033[0m"
        }},
        {"Незначительный снег",{
                "\033[38;5;250m     .-.     \033[0m",
                "\033[38;5;250m    (   ).   \033[0m",
                "\033[38;5;250m   (___(__)  \033[0m",
                "\033[38;5;255m    *  *  *  \033[0m",
                "\033[38;5;255m   *  *  *   \033[0m"
        }},
        {"Снег",{
                "\033[38;5;240;1m     .-.     \033[0m",
                "\033[38;5;240;1m    (   ).   \033[0m",
                "\033[38;5;240;1m   (___(__)  \033[0m",
                "\033[38;5;255;1m   * * * *   \033[0m",
                "\033[38;5;255;1m  * * * *    \033[0m"
        }},
        {"Сильный снег",{
                "\033[38;5;240;1m     .-.     \033[0m",
                "\033[38;5;240;1m    (   ).   \033[0m",
                "\033[38;5;240;1m   (___(__)  \033[0m",
                "\033[38;5;255;1m   * * * *   \033[0m",
                "\033[38;5;255;1m  * * * *    \033[0m"
        }},
        {"Снегопад",{
                "\033[38;5;240;1m     .-.     \033[0m",
                "\033[38;5;240;1m    (   ).   \033[0m",
                "\033[38;5;240;1m   (___(__)  \033[0m",
                "\033[38;5;255;1m   * * * *   \033[0m",
                "\033[38;5;255;1m  * * * *    \033[0m"
        }},
        {"Сильный снегопад",{
                "\033[38;5;240;1m     .-.     \033[0m",
                "\033[38;5;240;1m    (   ).   \033[0m",
                "\033[38;5;240;1m   (___(__)  \033[0m",
                "\033[38;5;255;1m   * * * *   \033[0m",
                "\033[38;5;255;1m  * * * *    \033[0m"
        }},
        {"Снежные зерна",{
                "\033[38;5;240;1m     .-.     \033[0m",
                "\033[38;5;240;1m    (   ).   \033[0m",
                "\033[38;5;240;1m   (___(__)  \033[0m",
                "\033[38;5;255;1m   * * * *   \033[0m",
                "\033[38;5;255;1m  * * * *    \033[0m"
        }},
        {"Гроза",{
                "\033[38;5;240;1m     .-.     \033[0m",
                "\033[38;5;240;1m    (   ).   \033[0m",
                "\033[38;5;240;1m   (___(__)  \033[0m",
                "\033[38;5;21;1m  ‚‘\033[38;5;228;5m⚡\033[38;5;21;25m‘‚\033[38;5;228;5m⚡\033[38;5;21;25m‚‘ \033[0m",
                "\033[38;5;21;1m  ‚’‚’\033[38;5;228;5m⚡\033[38;5;21;25m’‚’  \033[0m"
        }},
        {"Гроза с незначительным градом",{
                "\033[38;5;226m _`/\"\"\033[38;5;250m.-.    \033[0m",
                "\033[38;5;226m  ,\\_\033[38;5;250m(   ).  \033[0m",
                "\033[38;5;226m   /\033[38;5;250m(___(__) \033[0m",
                "\033[38;5;255m     *\033[38;5;228;5m⚡\033[38;5;255;25m*\033[38;5;228;5m⚡\033[38;5;255;25m* \033[0m",
                "\033[38;5;255m    *  *  *  \033[0m"
        }},
        {"Гроза с градом",{
                "\033[38;5;226m _`/\"\"\033[38;5;250m.-.    \033[0m",
                "\033[38;5;226m  ,\\_\033[38;5;250m(   ).  \033[0m",
                "\033[38;5;226m   /\033[38;5;250m(___(__) \033[0m",
                "\033[38;5;255m     *\033[38;5;228;5m⚡\033[38;5;255;25m*\033[38;5;228;5m⚡\033[38;5;255;25m* \033[0m",
                "\033[38;5;255m    *  *  *  \033[0m"
        }},
        {"Туман",{
                "             ",
                "\033[38;5;251m _ - _ - _ - \033[0m",
                "\033[38;5;251m  _ - _ - _  \033[0m",
                "\033[38;5;251m _ - _ - _ - \033[0m",
                "             "
        }},
        {"Oтложение изморози туман",{
                "             ",
                "\033[38;5;251m _ - _ - _ - \033[0m",
                "\033[38;5;251m  _ - _ - _  \033[0m",
                "\033[38;5;251m _ - _ - _ - \033[0m",
                "             "
        }}
};

*/
