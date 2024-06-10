#pragma once
#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<map>
#include <unordered_map>

class MarketDataHandler {
public:
	void onMarketDataupdate(const std::string& symbol, double price);
	double getPrice(const std::string& symbol);

private:
	std::mutex mutex_;
	std::unordered_map<std::string, double> marketData_;


};