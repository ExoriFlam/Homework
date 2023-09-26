#pragma once
#include "Vehicle.h"
class Cart : public Vehicle
{
public:

	Cart();

	int get_profit(int hours)const override;
	void show()const override;

	~Cart()override;
};

