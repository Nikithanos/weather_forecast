#pragma once

#include <string>
#include <string_view>

enum class CitiesAdded {
	Moscow,
	Toronto,
	Berlin,
};

class City {
private:
	std::string name_ = "default_city";
	long double latitude_ = 0.0;
	long double longtitude_ = 0.0;
public:
	explicit City() noexcept = default;
	~City() = default;
	City(std::string_view city_name, long double latitude, long double longtitude);
	City(const City& other) = delete;
	City(City&& other);
	City& operator=(const City& other) = delete;
	City& operator=(City&& other) noexcept;
	std::string_view GetName() const;
	long double GetLatitude() const;
	long double GetLongtitude() const;
};
