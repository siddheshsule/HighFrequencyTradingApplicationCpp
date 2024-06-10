#include "MarketDataHandler.h"

void MarketDataHandler::onMarketDataupdate(const std::string& symbol, double price)
{
	std::lock_guard<std::mutex> lock(mutex_);
	marketData_[symbol] = price;
	std::cout << "Market data updated: " << symbol << " -> " << price << std::endl;
}

double MarketDataHandler::getPrice(const std::string& symbol)
{
	std::lock_guard<std::mutex> lock(mutex_);
	return marketData_[symbol];
}
