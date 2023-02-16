#pragma once

#include "Trade.h"
#include "Order.h"

class User
{
private:
	char* username;
	char* password;
	float balance;
	Trade* trade;
public:
	User();
	~User();
	void login(char* username, char* password);
	void logout();
	void viewMarketData();
	void viewPortfolio();
	void viewTrades();
	void placeOrder(Order order);
	void manageOrder(Order order);
	void createTrade(Trade trade);
	void updateTrade(Trade trade);
	void deleteTrade(Trade trade);
};


