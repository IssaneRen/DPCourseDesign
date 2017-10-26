#include "Crop.h"
#include "Atmosphere.h"

Crop::Crop(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex)
:Plant(abs_list, size, max_age, sex), fruit_size_(0){
}

void Crop::absorb_water()
{
	if (energy_ >= 1)
	{
		energy_--;
		water_content_ += 5;
	}
}

void Crop::bear_fruit()
{
	if (energy_ >= 5)
	{
		energy_ -= 5;
		fruit_size_++;
	}
}

void Crop::bloom()
{
	Atmosphere* atm = Atmosphere::getInstance();
	if (energy_ >= 3)
	{
		energy_ -= 3;		
		atm->smell[FRAGRANCE] += 0.01;
	}
}

bool Crop::defend()
{
	if (rand() % 2)
	{
		return true;
	}
	else
	{
		weaken(rand() % 20);
		return false;
	}
}

void Crop::weaken(int num)
{
	health_ -= num;
	if (health_ <= 0)
	{
		die();
	}
}

void Crop::grow()
{
	if (energy_ >= 3)
	{
		energy_ -= 3;
		age_++;
		if (age_ > max_age_)
		{
			die();
		}
		size_ = size_ * (1 + grow_speed_);
	}
}

void Crop::die()
{
	if (health_ == 0 || age_ > max_age_)
	{
		cout << " died just now." << endl;
	}
}

void Crop::photoshythesize()
{
	Atmosphere* atm = Atmosphere::getInstance();
	if (atm->weather == SUNNY && atm->carbon_dioxide_content > 0.2 && water_content_ > 0)							    //光合作用
	{
		atm->carbon_dioxide_content -= 0.01;
		atm->oxygen_content += 0.01;
		water_content_--;
		energy_ += 5;

	}
}

void Crop::breath()
{
	Atmosphere* atm = Atmosphere::getInstance();
	if (atm->oxygen_content > 0.2 && fruit_size_ > 0)								//进行呼吸
	{
		atm->oxygen_content -= 0.01;
		atm->carbon_dioxide_content += 0.01;
		fruit_size_--;
		energy_ += 10;
	}
}

void Crop::time_pass_by()
{
	if (energy_ >= 20)
	{
		grow();
		if (age_ > 5)
		{
			bloom();
			bear_fruit();
		}
	}
	else
	{
		photoshythesize();
		breath();
	}
	if (water_content_ < 10)
	{
		absorb_water();
	}
}

void Crop::when_atmosphere_changed()
{

}

void Crop::update(Abstract* abs, AbstractType type)
{
	switch (type)
	{
	TIME:
		time_pass_by();
		break;
	ATMOSPHERE:
		when_atmosphere_changed();
		break;
	default:
		cout << "error type";
		break;
	}
}