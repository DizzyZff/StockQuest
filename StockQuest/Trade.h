#pragma once
class Trade
{
private:
	int tradeID;
	char* tradeType;
	int quantity;
	float price;
	char* status;
public:
	Trade();
	~Trade();
	void setTradeID(int tradeID);
	void setTradeType(char* tradeType);
	void setQuantity(int quantity);
	void setPrice(float price);
	void setStatus(char* status);
	int getTradeID();
	char* getTradeType();
	int getQuantity();
	float getPrice();
	char* getStatus();
};

