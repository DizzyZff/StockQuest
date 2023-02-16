#pragma once
class Order
{
private:
	int orderID;
	char* orderType;
	int quantity;
	float price;
	char* orderStatus;
public:
	Order();
	~Order();
	void createOrder();
	void updateOrder();
	void deleteOrder();
};

