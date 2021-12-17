#include "WeatherProvider.h"
#include <Utils/Log.h>
#include <HTTPRequest.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>

#define WEATHER_API_SLUG "https://api.weather.gov/"

WeatherData WeatherProvider::getWeatherInfo(float latitude, float longitude) {
	WeatherData data;
	data.latitude = latitude;
	data.longitude = longitude;

	// convert latitude and longitude to gridpoints
	std::string endpoint = convertGCoordToForecast(latitude, longitude);
	// request gridpoint
	data.temperature = 100.0f;

	return data;
}

std::string WeatherProvider::convertGCoordToForecast(float latitude, float longitude) {
	try {
		std::string url = WEATHER_API_SLUG "points/";

		url += std::to_string(latitude);
		url += ",";
		url += std::to_string(longitude);

		http::Request request{ url };

		// send a get request
		const auto response = request.send("GET");

		std::string body{response.body.begin(), response.body.end()};

		std::cout << body << std::endl;

		// parse body into json format
		nlohmann::json bodyJson = nlohmann::json::parse(body);


	} catch (const std::exception& e) {
		LOG_ERROR("Failed to find forecast gridpoint! Error: {}", e.what());
	}
}