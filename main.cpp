#include "displaying_data.h"
#include "cities_to_display.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Box.H>


using std::string_literals::operator""s;
using std::literals::operator""sv;

void FetchWeatherCB(Fl_Widget*, void*);

int main() {
	/*std::vector<City> cities;
	cities.emplace_back("Moscow"sv, 55.75222, 37.61556);
	cities.emplace_back("Toronto"sv, 43.70011, -79.4163);
	cities.emplace_back("Berlin"sv, 52.52437, 13.41053);
	int city;
	std::cout << "Choose the city: "sv << std::endl;
	std::cout << "[0] - Moscow"sv << std::endl;
	std::cout << "[1] - Toronto"sv << std::endl;
	std::cout << "[2] - Berlin"sv << std::endl;
	std::cin >> city;
	while (true) {
		DisplayRealTimeWeather(cities, city);
		std::this_thread::sleep_for(std::chrono::minutes(1));
	}*/
	Fl_Window* window = new Fl_Window(400, 300, "Weather application");
	Fl_Choice* city_choice = new Fl_Choice(50, 10, 120, 25, "City:");
	city_choice->add("Moscow|Toronto|Berlin");
	Fl_Button* fetch_weather = new Fl_Button(180, 10, 120, 25, "Fetch city weather");
	fetch_weather->callback(FetchWeatherCB);
	Fl_Box* weather_display = new Fl_Box(50, 50, 300, 200, "Weather info");
	weather_display->box(FL_UP_BOX);
	weather_display->labelfont(FL_BOLD);
	weather_display->labelsize(14);
	window->end();
	window->show();
	return Fl::run();
}


