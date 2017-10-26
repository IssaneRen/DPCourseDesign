#include "Weed.h"

Weed::Weed(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex)
	:Plant(abs_list, size, max_age, name, sex){
	strategy_ = NULL;
}


void Weed::grow()
{
	photoshythesize();
	
}

void Weed::die()
{
	cout << "Weed is dead"
		<< endl;

}

void Weed::bloom()
{

}

void Weed::photoshythesize()
{
	energy_ = energy_ + 10;
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

void Weed::breath(Atmosphere* atm)
{

}

void Weed::time_pass_by()
{
	grow();
	water_absorb();

}

void Weed::when_atmosphere_changed()
{

}

void Weed::update(Abstract* abs, AbstractType type)
{
	time_pass_by();
}

void Weed::setStrategy(int type)
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

void Weed::doIt()
{
	strategy_->format();
}

