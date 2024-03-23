#include "cities_to_display.h"

City::City(std::string_view city_name, long double latitude, long double longtitude) : name_(std::move(std::string(city_name))), latitude_(std::move(latitude)), longtitude_(std::move(longtitude)) {}

City::City(City&& other) : name_(std::move(other.name_)), latitude_(std::move(other.latitude_)), longtitude_(std::move(other.longtitude_)) {}

City& City::operator=(City&& other) noexcept {
	if (this != &other) {
		std::swap(name_, other.name_);
		std::swap(latitude_, other.latitude_);
		std::swap(longtitude_, other.longtitude_);
	}
	return *this;
}

std::string_view City::GetName() const {
	return name_;
}
long double City::GetLatitude() const {
	return latitude_;
}
long double City::GetLongtitude() const {
	return longtitude_;
}


