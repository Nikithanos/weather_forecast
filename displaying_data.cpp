#include "displaying_data.h"

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
	userp->append(static_cast<char*>(contents), size * nmemb);
	return size * nmemb;
}

void DisplayRealTimeWeather(const std::vector<City>& cities, const int city) {
	CURL* curl = curl_easy_init();
	CURLcode res;
	std::string read_buffer;
	if (curl) {
		std::string url = "https://api.open-meteo.com/v1/forecast?latitude=" + std::to_string(cities[city].GetLatitude()) + "&longitude=" + std::to_string(cities[city].GetLongtitude()) + "&current_weather=true";
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		//std::cout << read_buffer << std::endl;
		if (res == CURLE_OK) {
			auto json = nlohmann::json::parse(read_buffer);
			auto current_time = std::chrono::system_clock::now();
			auto in_time_t = std::chrono::system_clock::to_time_t(current_time);
			std::tm buf;
			localtime_s(&buf, &in_time_t);
			std::cout << "The time is: " << std::put_time(&buf, "%Y-%m-%d %X") << std::endl;
			std::cout << "Current weather in " << cities[city].GetName() << std::endl;
			std::cout << "Temperature: " << json["current_weather"]["temperature"] << "°C" << std::endl;
			std::cout << "Wind speed: " << json["current_weather"]["windspeed"] << "km/h" << std::endl;
			std::cout << "Wind direction: " << json["current_weather"]["winddirection"] << std::endl;
		}
		else {
			std::cerr << "Failed to parse data" << std::endl;
		}
	}
}