#include "TradingStrategy.h"



void TradingStrategy::onMarketDataUpdate(const std::string& symbol, double price)
{
	double currentPrice = marketDataHandler_.getPrice(symbol);

	if (price < currentPrice * 0.99) {
		// Buy Logic
		Order order = { ++orderCounter_, symbol, OrderType::BUY, price, 100 };
		orderManagementSystem_.sendOrder(order);
	}
	else if (price > currentPrice * 1.01) {
		Order order = { ++orderCounter_, symbol, OrderType::SELL, price, 100 };
		orderManagementSystem_.sendOrder(order);
	}
}
