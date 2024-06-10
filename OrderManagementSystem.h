#pragma once
#include<queue>
#include<mutex>
#include<unordered_map>
#include<iostream>

enum class OrderType {BUY, SELL};

struct Order {
	int id;
	std::string symbol;
	OrderType type;
	double price;
	int quantity;
};

class OrderManagementSystem {
public:
	void sendOrder(const Order& order);
	void cancelOrder(int orderId);

private:
	std::mutex mutex_;
	std::unordered_map<int, Order> orders_;
};