#include "OrderManagementSystem.h"

void OrderManagementSystem::sendOrder(const Order& order)
{
	std::lock_guard<std::mutex> lock(mutex_);
	orders_[order.id] = order;
	std::cout << "Order sent: " << order.id << std::endl;
}

void OrderManagementSystem::cancelOrder(int orderId)
{
	std::lock_guard<std::mutex> lock(mutex_);
	if (orders_.find(orderId) != orders_.end()) {
		orders_.erase(orderId);
		std::cout << "Order cancelled: " << orderId << std::endl;
	}
}
