#pragma once

#include "curl/curl.h"
#include "cities_to_display.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <thread>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);

void DisplayRealTimeWeather(const std::vector<City>& cities, const int city);