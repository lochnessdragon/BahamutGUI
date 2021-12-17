#pragma once

#include "WeatherData.h"
#include <string>

// TODO:
// - Implement cache for improved latency to get gridpoints
class WeatherProvider {
private:
	std::string convertGCoordToForecast(float latitude, float longitude);

public:
	WeatherProvider() {};
	
	WeatherData getWeatherInfo(float latitude, float longitude);
};