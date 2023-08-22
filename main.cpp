#include <iostream>
#include "requests.h"
#include <clocale>
//#include "labwork-6-elizabetinka/lib/parser.h"
#include <unordered_map>
#include "constants.h"
#include <ncurses.h>
#include "Printer.h"
#include "OMFL-parser/lib/parser.h"

uint64_t count_of_days;
std::string city;
std::vector<dayTempreture> temp;
uint64_t current_city;
uint64_t current_day;
uint64_t I_can_show_days;
omfl::NewYear root;


std::string SwitchErorr(int error) {
    switch (error) {
        case 0:
            return "0 No internet connection";
        case 303:
            return "303 See Other";
        case 400:
            return "400 Bad request";
        case 404:
            return "404 Resource not found";
        case 500:
            return "500 Internal server error";
        default:
            return "error";
    }
}

void Update(){
    printw("Секундочку, происходит обновление...\n");
    refresh();

    clear();
    city = root.Get("city")[current_city].AsString();
    temp = getTempr(city, count_of_days);
    if (kERROR != 200){
        return;
    }
    current_day = std::min(current_day, count_of_days);
    if (current_day >= I_can_show_days) {
        current_day = current_day - I_can_show_days;
    } else {
        current_day = 0;
    }
    if (current_day == 0) {
        // вывод погоды на сегодня
        PrintCur(temp[0].mass[1], city);
    }
    for (uint64_t i = 0; i < I_can_show_days; ++i) {
        MyPrinter(temp[current_day + i]);
        refresh();
        if (i + current_day + 1 >= count_of_days) {
            current_day = count_of_days;
            break;
        }
    }
    current_day = current_day + I_can_show_days;
    current_day = std::min(current_day, count_of_days);
    return;
}


int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    if (argc < 2) {
        return 0;
    }


    initscr();
    cbreak();
    keypad(stdscr, true);
    idlok(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    noecho();

    // парсинг omfl
    std::filesystem::path paths = argv[1];

    root = omfl::parse(paths);
    if (!root.valid()) {
        std::cout << "Не получилось" << std::endl;
    }

    count_of_days = root.Get("countD").AsInt();
    //resizeterm(count_of_days * 20, kSizeOfTableDlina); //размер окна


    uint64_t city_count = root.Get("cityC").AsInt();
    uint64_t frequency_count = root.Get("frequency").AsInt();
    halfdelay(frequency_count * 10); // ожидание клавиши


    current_city = 0;
    current_day = 0;
    I_can_show_days = 0;

    // парсинг API
    city = root.Get("city")[current_city].AsString();
    temp = getTempr(city, count_of_days);

    int mrow, mcol;

    // get terminal size
    getmaxyx(stdscr, mrow, mcol);

    if (mrow < 18 || mcol < 125) {
        printw("Сделайте размер окна хотя бы 125x18");
        getch();
        refresh();
        getch();
        endwin();
        return 0;
    }
    I_can_show_days = (mrow - 8) / 10;

    if (kERROR != 200) {
        printw(SwitchErorr(kERROR).c_str());
        getch();
        refresh();
        getch();
        endwin();
        return 0;

    }

    // программа
    printw("Чтобы завершить программу, нажмите esc\n ");
    printw("Чтобы увидеть больше - используйте навигацию w/s\n ");
    refresh();

    PrintCur(temp[0].mass[1], city);
    refresh();
    for (uint64_t i = 0; i < I_can_show_days; ++i) {
        MyPrinter(temp[current_day + i]);
        refresh();
        if (i + current_day + 1 >= count_of_days) {
            current_day = count_of_days;
            break;
        }
    }
    current_day = current_day + I_can_show_days;
    current_day = std::min(current_day, count_of_days);


    bool ex = false;
    while (!ex) {
        int ch = getch();

        switch (ch) {
            case ERR:
                Update();
                if (kERROR != 200) {
                    printw(SwitchErorr(kERROR).c_str());
                    refresh();
                    getch();
                    endwin();
                    return 0;

                }
                break;
            case KEY_UP: // игнорируем скроллы
            case 'u':
            case 'U':;
                break;
            case KEY_DOWN: // игнорируем скроллы
            case 'd':
            case 'D':;
                break;
            case KEY_LEFT: // игнорируем скроллы
            case 'l':
            case 'L':;
                break;
            case KEY_RIGHT: // игнорируем скроллы
            case 'r':
            case 'R':;
                break;
            case 27: //Выходим из программы, если была нажата esc
                ex = true;
                break;
            case 410: // игнорируем нажатие мышкой
                break;
            case 110: //Выходим из программы, если была нажата n
                printw("Code of pressed key is %d\n", ch);
                refresh();
                clear();
                current_city = (current_city + 1) % city_count;
                current_day = std::min(I_can_show_days,count_of_days);
                Update();
                if (kERROR != 200) {
                    printw(SwitchErorr(kERROR).c_str());
                    refresh();
                    getch();
                    endwin();
                    return 0;

                }
                break;
            case 112: //Выходим из программы, если была нажата p
                printw("Code of pressed key is %d\n", ch);
                refresh();
                clear();
                if (current_city == 0) {
                    current_city = city_count - 1;
                } else {
                    current_city = (current_city - 1) % city_count;
                }
                current_day = std::min(I_can_show_days,count_of_days);
                Update();
                if (kERROR != 200) {
                    printw(SwitchErorr(kERROR).c_str());
                    refresh();
                    getch();
                    endwin();
                    return 0;

                }
                break;
            case 115: //s
                clear();
                if (current_day >= count_of_days) {
                    break;
                }
                for (uint64_t i = 0; i < I_can_show_days; ++i) {
                    MyPrinter(temp[current_day + i]);
                    refresh();
                    if (i + current_day + 1 >= count_of_days) {
                        current_day = count_of_days;
                        break;
                    }
                }
                current_day = current_day + I_can_show_days;
                current_day = std::min(current_day, count_of_days);
                break;
            case 119://w
                clear();
                if (current_day >= I_can_show_days) { //0 1 2 3 4 5 6 7
                    current_day = current_day - I_can_show_days + 1;
                } else {
                    current_day = 0;
                }
                if (current_day >= I_can_show_days) {
                    current_day = current_day - I_can_show_days;
                } else {
                    current_day = 0;
                }
                if (current_day >= count_of_days) {
                    break;
                }
                if (current_day == 0) {
                    // вывод погоды на сегодня
                    PrintCur(temp[0].mass[1], city);
                }
                for (uint64_t i = 0; i < I_can_show_days; ++i) {
                    MyPrinter(temp[current_day + i]);
                    refresh();
                    if (i + current_day + 1 >= count_of_days) {
                        current_day = count_of_days;
                        break;
                    }
                }
                current_day = current_day + I_can_show_days;
                current_day = std::min(current_day, count_of_days);
                break;
            case 43://+
                ++count_of_days;
                Update();
                if (kERROR != 200) {
                    printw(SwitchErorr(kERROR).c_str());
                    refresh();
                    getch();
                    endwin();
                    return 0;

                }
                break;
            case 95://-
                if (count_of_days==1){
                    break;
                }
                --count_of_days;
                Update();
                if (kERROR != 200) {
                    printw(SwitchErorr(kERROR).c_str());
                    refresh();
                    getch();
                    endwin();
                    return 0;

                }
                break;

            default:  //если нажали на какую то странную клавишу
                printw("Code of pressed key is %d\n", ch);
                refresh();
                break;
        }
        refresh(); //Выводим на настоящий экран
    }

    printw("Thank you. Good buy!");
    refresh();
    getch();
    endwin();
    return 0;
}

