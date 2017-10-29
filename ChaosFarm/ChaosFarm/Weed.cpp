#include "Weed.h"

Weed::Weed(vector<Abstract*>* abs_list, int size, int max_age)
	:Plant(abs_list, size, max_age), strategy_(NULL) {

}


void Weed::grow()
{

	photosynthesis();
}

void Weed::die()
{
	cout << "Weed is dead"
		<< endl;

}

void Weed::bloom()
{

}

void Weed::photosynthesis()
{
	Atmosphere* atm = Atmosphere::getInstance();
	energy_ = energy_ + 10 * atm->get_lux();
	water_content_--;
	cout << "Weed has absorbed sunshine"
		<< endl;
}

void Weed::water_absorb()
{
	water_content_++;
	cout << "Weed has absorbed water"
		<< endl;
}

void Weed::breath()
{
	Atmosphere* atm = Atmosphere::getInstance();

	if (energy_ >= 5)
	{
		energy_ -= 5;
		water_content_++;
		cout << "Weed is breathing"
			<< endl;
	}
}

void Weed::time_pass_by()
{
	grow();
	if (water_content_ < 50)
	{
		water_absorb();
	}
	breath();

}

void Weed::when_atmosphere_changed()
{

}


void Weed::attack(Crop* crop)
{
	if (crop->defend())
	{
		energy_ -= 5;
		cout << "attack fail"
			<< endl;
	}
	else if (crop->defend())
	{
		energy_ += 5;
		cout << "attack success"
			<< endl;
	}
}

void Weed::setStrategy(StrategyType type)
{
	delete strategy_;
	if (type == Sing)
	{
		strategy_ = new SingStrategy();
	}
	else if (type == Dance)
	{
		strategy_ = new DanceStrategy();
	}
	else if (type == Chat)
	{
		strategy_ = new ChatStrategy();
	}
}

void Weed::doIt(StrategyType type)
{
	setStrategy(type);
	strategy_->format();
}
