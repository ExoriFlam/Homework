#pragma once
class Vehicle
{
private:

	int passage_cap;
	int cargo_cap;
	int speed;

public:

	Vehicle();
	Vehicle(int pass_cap, int cargo_cap, int speed);

	virtual int get_profit(int hours)const;
	virtual void show()const;

	virtual ~Vehicle();
};

