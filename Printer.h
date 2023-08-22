//
// Created by Елизавета Кравченкова on 04.04.2023.
//

#pragma once


const uint64_t kSizeOfPartTableDlina = 31; // без крайней
const uint64_t kSizeOfPartTableDlinaMid = 15; // без крайней
const uint64_t kSizeOfTableDlina = kSizeOfPartTableDlina * 4 + 1;//125

const uint64_t kSizeOfTableHeight = 9; // без верхней


const uint64_t XDate = 55 - 2;
const uint64_t DateSizeDlina = 15 + 4;
const uint64_t DateSizeHeight = 3;

const std::string line = "─";
const std::string line_perp = "│";
const std::string krest = "┼";

const std::string UgLeftUp = "┌";
const std::string UgRightUp = "┐";
const std::string UgLeftDown = "└";
const std::string UgRightDown = "┘";

const std::string TriangToRight = "├";
const std::string TriangToLeftt = "┤";
const std::string TriangUp = "┴";
const std::string TriangDown = "┬";

const int kSizeOfRusWord = 2;

// определяетт вид стрелочки для ветра
std::string SwitchDirection(double dir) {
    if (dir >= 22.5 & dir <= 67.5) {
        return "↗";
    } else if (dir > 67.5 & dir < 112.5) {
        return "→";
    } else if (dir >= 112.5 & dir <= 157.5) {
        return "↘";
    } else if (dir > 157.5 & dir < 202.5) {
        return "↓";
    } else if (dir >= 202.5 & dir <= 247.5) {
        return "↙";
    } else if (dir > 247.5 & dir < 292.5) {
        return "←";
    } else if (dir >= 292.5 & dir < 337.5) {
        return "↖";
    } else {
        return "↑";
    }
}

// убирает лишние знаки после запятой
std::string SplitDouble(double dir) {
    std::string start = std::to_string(dir);
    std::string::size_type n = start.find(',');
    if (n != std::string::npos) {
        start = start.substr(0, n + 2);
    }
    return start;
}

// превращает данные об 1/4 дня в готовые для вывода строки (с картинками)
std::array<std::string, 5> ParsePartOfDayTemreture(const TempPart& Tdata) {
    std::array<std::string, 5> ans;
    if (!Tdata.valid) {
        ans[0] = "      Погода на это время     ";
        ans[1] = "          неизвестна          ";
        ans[2] = "";
        ans[3] = "";
        ans[4] = "";
        return ans;
    }
    std::string description;
    if (WWO_CODE.contains(Tdata.weatherCode)) {
        description = WWO_CODE.find(Tdata.weatherCode)->second;
    } else {
        description = "Неизвестно";
    }

    std::array<std::string, 5> picture = WEATHER_SYMBOL_WEGO.find(description)->second;

    if (description.size() / kSizeOfRusWord > 15) {
        ans[0] = picture[0] + " " + description.substr(0, 14 * kSizeOfRusWord) + "...";
    } else {
        ans[0] = picture[0] + " " + description;
    }

    ans[1] = picture[1] + " " + std::to_string(Tdata.temp_c) + "(" + std::to_string(Tdata.not_really_temp_c) + ") °C";

    std::string direction = SwitchDirection(Tdata.wind_direction_circuit);
    ans[2] = picture[2] + " " + direction + " " + SplitDouble(Tdata.wind_speed_km) + " км/ч";

    ans[3] = picture[3] + " " + std::to_string(Tdata.visibility_km) + " км";

    ans[4] =
            picture[4] + " " + SplitDouble(Tdata.precipitation_mm) + " мм | " + std::to_string(Tdata.precipitation_pr) +
            "%%%";
    return ans;
}

// для таблицы
void PrintData(std::array<std::string, 5> data) {
    int x, y;
    getyx(stdscr, y, x);
    for (uint64_t i = 0; i < 5; ++i) {
        printw(line_perp.c_str());
        printw(data[i].c_str());
        move(y + i + 1, x);
    }
}

// перед таблицей
void PrintCur(const TempPart& Tdata, std::string city) {
    printw(("Прогноз погоды: " + city + "\n").c_str());
    std::array<std::string, 5> parse = ParsePartOfDayTemreture(Tdata);

    std::string description = WWO_CODE.find(Tdata.weatherCode)->second;
    std::array<std::string, 5> picture = WEATHER_SYMBOL_WEGO.find(description)->second;
    parse[0] = picture[0] + " " + description;

    for (uint64_t i = 0; i < 5; ++i) {
        printw(parse[i].c_str());
        printw("\n");
    }
    refresh();
}

// таблица для одного дня
void MyPrinter(const dayTempreture& Day) {
    int x = 0;
    int y = 0;
    std::string lines;
    getyx(stdscr, y, x);

    // 0 строка
    move(y, XDate);
    printw(UgLeftUp.c_str());
    for (uint64_t i = 0; i < (DateSizeDlina - 2); ++i) {
        printw(line.c_str());
    }
    printw(UgRightUp.c_str());


    // 1 строка
    move(y + 1, 0);
    printw(UgLeftUp.c_str());
    uint64_t l = 1;
    while (l < XDate) {
        if (l == kSizeOfPartTableDlina) {
            printw(TriangDown.c_str());
        } else {
            printw(line.c_str());
        }
        ++l;
    }


    printw(TriangToLeftt.c_str());
    printw(Day.date.c_str());
    move(y + 1, XDate + DateSizeDlina - 1);
    printw(TriangToRight.c_str());
    l = l + DateSizeDlina;
    while (l < (kSizeOfTableDlina - 1)) {
        if (l == kSizeOfPartTableDlina * 3) {
            printw(TriangDown.c_str());
        } else {
            printw(line.c_str());
        }
        ++l;
    }
    printw(UgRightUp.c_str());



    // 2 строка
    move(y + 2, 0);
    l = 0;
    while (l < kSizeOfTableDlina) {
        if (l == XDate) {
            printw(UgLeftDown.c_str());
            ++l;
            for (uint64_t j = 0; j < (DateSizeDlina - 2); ++j) {
                if (l % kSizeOfPartTableDlina == 0) {
                    printw(TriangDown.c_str());
                } else {
                    printw(line.c_str());
                }
                ++l;
            }
            printw(UgRightDown.c_str());
            //++l;
        } else if (l == kSizeOfPartTableDlinaMid | l == kSizeOfPartTableDlina + kSizeOfPartTableDlinaMid |
                   l == 2 * kSizeOfPartTableDlina + kSizeOfPartTableDlinaMid |
                   l == 3 * kSizeOfPartTableDlina + kSizeOfPartTableDlinaMid) {
            switch (int(l / kSizeOfPartTableDlina)) {
                case 0: //Выходим из программы, если была нажата esc
                    printw("Утро");
                    break;
                case 1:
                    printw("День");
                    break;
                case 2:
                    printw("Вечер");
                    break;
                case 3:
                    printw("Ночь");
                    break;
                default:  //Если всё нормально, выводим код нажатой клавиш
                    break;
            }
        } else if (l % kSizeOfPartTableDlina == 0) {
            printw(line_perp.c_str());
        } else {
            move(y + 2, l + 1);
        }
        ++l;
    }




    // 3 строка
    move(y + 3, 0);
    printw(TriangToRight.c_str());
    l = 1;
    while (l < (kSizeOfTableDlina - 1)) {
        if (l % kSizeOfPartTableDlina == 0) {
            printw(krest.c_str());
        } else {
            printw(line.c_str());
        }
        ++l;
    }
    printw(TriangToLeftt.c_str());
    refresh();


    // Данные (4-8 строки)
    move(y + 4, 0);
    PrintData(ParsePartOfDayTemreture(Day.mass[0]));

    move(y + 4, kSizeOfPartTableDlina);
    PrintData(ParsePartOfDayTemreture(Day.mass[1]));

    move(y + 4, kSizeOfPartTableDlina * 2);
    PrintData(ParsePartOfDayTemreture(Day.mass[2]));

    move(y + 4, kSizeOfPartTableDlina * 3);
    PrintData(ParsePartOfDayTemreture(Day.mass[3]));


    for (uint64_t i = 0; i < 5; ++i) {
        move(y + 4 + i, kSizeOfTableDlina - 1);
        printw(line_perp.c_str());
    }


    // 9 строка
    move(y + 9, 0);
    printw(UgLeftDown.c_str());
    l = 1;
    while (l < (kSizeOfTableDlina - 1)) {
        if (l % kSizeOfPartTableDlina == 0) {
            printw(TriangUp.c_str());
        } else {
            printw(line.c_str());
        }
        ++l;
    }
    printw(UgRightDown.c_str());
    move(y + 11, 0);
    refresh();
}


