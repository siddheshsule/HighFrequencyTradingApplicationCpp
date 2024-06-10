// HighFrequencyTradingApplicationCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OrderManagementSystem.h"
#include "MarketDataHandler.h"
#include "TradingStrategy.h"

int main()
{
    MarketDataHandler marketDataHandler;
    OrderManagementSystem orderManagementSystem;
    TradingStrategy strategy (marketDataHandler, orderManagementSystem);

    // Simulated market data updates
    std::vector<std::thread> threads;
    std::vector<std::string> symbols = { "AAPL", "NVDA", "GOOG", "MSFT" };

    for (const auto& symbol : symbols) {
        threads.emplace_back([&]() {
            for (int i = 0; i < 10; ++i) {
                double price = 100 + (rand() % 100); // simulate price between 100 and 200
                marketDataHandler.onMarketDataupdate(symbol, price);
                strategy.onMarketDataUpdate(symbol, price);
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;    
}
