#pragma once

#include "resource.h"

class MarketDataAPI
{
public:
	MarketDataAPI();
	~MarketDataAPI();
	void getMarketData(char* symbol);
};

class TradingAPI
{
public:
	TradingAPI();
	~TradingAPI();
	void placeOrder(char* symbol, int quantity, float price);
	void manageOrder(char* symbol, int quantity, float price);
};

class Database {
public:
	Database();
	~Database();
	void execute(char* query);
};
