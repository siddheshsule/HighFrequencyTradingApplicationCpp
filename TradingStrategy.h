#pragma once
#include"MarketDataHandler.h"
#include"OrderManagementSystem.h"

class TradingStrategy {
public:
	TradingStrategy(MarketDataHandler& marketDataHandler, OrderManagementSystem& orderManagementSystem)
		:marketDataHandler_(marketDataHandler), orderManagementSystem_(orderManagementSystem), orderCounter_(0) {};

	void onMarketDataUpdate(const std::string& symbol, double price);

private:
	MarketDataHandler& marketDataHandler_;
	OrderManagementSystem& orderManagementSystem_;
	int orderCounter_;
};