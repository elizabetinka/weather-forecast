//
// Created by Елизавета Кравченкова on 30.03.2023.
//

#pragma once

#include <iostream>
#include <cpr/cpr.h>
#include <wchar.h>
#include <clocale>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

std::string GetDayOfWeek(int D, int M, int Y) {
    std::string S[7] = {"Вс", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб"};
    int a, y, m, R;
    a = (14 - M) / 12;
    y = Y - a;
    m = M + 12 * a - 2;
    R = 7000 + (D + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    return S[R % 7];

}

std::string ParseDate(const std::string& old_date) {
    std::string new_date;
    int Y = stoi(old_date.substr(0, 4));
    int M = stoi(old_date.substr(5, 2));
    int D = stoi(old_date.substr(8, 2));
    new_date = " " + GetDayOfWeek(D, M, Y) + "." + std::to_string(D);
    switch (M) {
        case 1:
            new_date = new_date + " Января";
            break;
        case 2:
            new_date = new_date + " Февраля";
            break;
        case 3:
            new_date = new_date + " Марта";
            break;
        case 4:
            new_date = new_date + " Апреля";
            break;
        case 5:
            new_date = new_date + " Мая";
            break;
        case 6:
            new_date = new_date + " Июня";
            break;
        case 7:
            new_date = new_date + " Июля";
            break;
        case 8:
            new_date = new_date + " Августа";
            break;
        case 9:
            new_date = new_date + " Сентября";
            break;
        case 10:
            new_date = new_date + " Октября";
            break;
        case 11:
            new_date = new_date + " Ноября";
            break;
        case 12:
            new_date = new_date + " Декабря";
            break;
        default:
            break;

    }
    return new_date;

}



using json = nlohmann::json;

// 1/4 дня
struct TempPart {
    uint64_t weatherCode;
    int64_t temp_c;
    int64_t not_really_temp_c;
    double wind_direction_circuit;
    double wind_speed_km;
    double precipitation_mm;
    int precipitation_pr;
    uint64_t visibility_km;
    bool valid = true;
};

// день
struct dayTempreture {
    std::string date;
    TempPart mass[4];
};

int kERROR = 200;

std::vector<dayTempreture> getTempr(std::string city, uint64_t count_of_days) {
    std::vector<dayTempreture> days;
    cpr::Response r = cpr::Get(cpr::Url{"https://api.api-ninjas.com/v1/city"}, cpr::Parameters{{"name", city}},
                               cpr::Header{{"X-Api-Key", "k7mYoWREfw9iT3ZmrCFkEQ==R1isiQ1pIJJspTYa"}});

    if (r.status_code != 200) {
        kERROR = r.status_code;
        return days;
    }

    std::string for_parse = r.text.substr(1, r.text.size() - 2);
    json responseJson = json::parse(for_parse);

    json lat = responseJson["latitude"];
    json lot = responseJson["longitude"];

    cpr::Response r2 = cpr::Get(cpr::Url{"https://api.open-meteo.com/v1/forecast"},
                                cpr::Parameters{{"latitude", lat.dump()},
                                                {"longitude",     lot.dump()},
                                                {"hourly",        "windspeed_10m"},
                                                {"hourly",        "winddirection_10m"},
                                                {"hourly",        "weathercode"},
                                                {"hourly",        "temperature_2m"},
                                                {"hourly",        "apparent_temperature"},
                                                {"hourly",        "relativehumidity_2m"},
                                                {"hourly",        "precipitation"},
                                                {"hourly",        "visibility"},
                                                {"forecast_days", std::to_string(count_of_days)}});
    if (r2.status_code != 200) {
        kERROR = r2.status_code;
        return days;
    }


    json www = json::parse(r2.text);
    days.resize(count_of_days);

    for (uint64_t i = 0; i < count_of_days; ++i) {
        for (uint64_t j = 1; j < 5; j++) {
            uint64_t indx = i * 24 + j * 6;
            if (i == count_of_days - 1 && j == 4) {
                --indx;
            }
            TempPart temp;
            if (www["hourly"]["windspeed_10m"][indx] == "null" | www["hourly"]["weathercode"][indx] == "null" |
                www["hourly"]["visibility"][indx] == "null" | www["hourly"]["temperature_2m"][indx] == "null" |
                www["hourly"]["apparent_temperature"][indx] == "null" |
                www["hourly"]["relativehumidity_2m"][indx] == "null" | www["hourly"]["precipitation"][indx] == "null") {
                temp.valid = false;
                days[i].mass[j - 1] = temp;
                if (j == 1) {
                    days[i].date = ParseDate(www["hourly"]["time"][i * 24 + j * 6]);

                }
                continue;
            }
            temp.wind_speed_km = www["hourly"]["windspeed_10m"][indx];
            temp.wind_direction_circuit = www["hourly"]["winddirection_10m"][indx];
            temp.weatherCode = www["hourly"]["weathercode"][indx];
            temp.visibility_km = int(www["hourly"]["visibility"][indx]) / 1000;
            temp.temp_c = www["hourly"]["temperature_2m"][indx];
            temp.not_really_temp_c = www["hourly"]["apparent_temperature"][indx];
            temp.precipitation_pr = www["hourly"]["relativehumidity_2m"][indx];
            temp.precipitation_mm = www["hourly"]["precipitation"][indx];
            days[i].mass[j - 1] = temp;
            if (j == 1) {
                days[i].date = ParseDate(www["hourly"]["time"][i * 24 + j * 6]);

            }

        }
    }
    return days;
}


