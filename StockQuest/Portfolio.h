#pragma once

#include "Trade.h"

class Portfolio
{
private:
	Trade* trade;
	float balance;
public:
	Portfolio();
	~Portfolio();
	void setTrade(Trade* trade);
	void setBalance(float balance);
	Trade* getTrade();
	float getBalance();
	void addTrade(Trade trade);
	void removeTrade(Trade trade);
};

