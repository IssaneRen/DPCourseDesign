#include "Crop.h"
#include "Atmosphere.h"

Crop::Crop(vector<Abstract*>* abs_list, int size, int max_age)
:Plant(abs_list, size, max_age), fruit_size_(0){
	state = new Growing();         //初始选择未成熟
	output_rate_ = 1.0;
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

void Crop::plant_on(BaseFarmLand* farmland){
	farmland->plant_a_crop(this); 
}


void Crop::bloom()
{
	if (energy_ >= 3)
	{
		energy_ -= 3;		
	}
}

bool Crop::defend()
{
	if (rand() % 2)											//随机成功或失败
	{
		return true;
	}
	else
	{
		weaken(rand() % 20);								//失败时调用weaken
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

void Crop::growbigger()
{
	if (energy_ >= 3)
	{
		energy_ -= 3;
		age_++;
		if (age_ > max_age_)
		{
			die();
		}
		size_ = size_ * 2;
	}
}

void Crop::grow()
{
	state->grow(this);
}

void Crop::reproduce()
{
	state->reproduce(this);
}

void Crop::die()
{
	if (health_ == 0 || age_ > max_age_)
	{
		cout << "A crop died just now." << endl;
	}
}

void Crop::photosynthesis()
{
	Atmosphere* atm = Atmosphere::getInstance();
	if (water_content_ > 0)							    //光合作用
	{
		
		water_content_--;
		energy_ += 5 * atm->get_lux();

	}
}

void Crop::breath()
{
	if (fruit_size_ > 0)								//进行呼吸
	{
		cout << "A crop is breathing." << endl;
		fruit_size_--;
		energy_ += 10;
	}
}

void Crop::time_pass_by()
{
	if (energy_ >= 20)
	{
		grow();
		reproduce();
	}
	else
	{
		photosynthesis();
		breath();
	}
	if (water_content_ < 10)
	{
		absorb_water();
	}
}

void Crop::when_atmosphere_changed()
{
	Atmosphere* atm = Atmosphere::getInstance();
	switch (atm->get_weather_type())
	{
	case SUNNY:
		water_content_ -= 3;
		break;
	case RAINY:
		water_content_ += 5;
		break;
	case WINDY:
		break;
	case CLOUDY:
		break;
	default:
		break;
	}
}

void Crop::update(AbstractType type)
{
	switch (type)
	{
	case TIME:
		this->time_pass_by();
		break;
	case ATMOSPHERE:
		this->when_atmosphere_changed();
		break;
	default:
		cout << "error type";
		break;
	}
}

void Crop::setState(CropState* s)
{
	state = s;                                                                //改变state
}

void CropState::grow(Crop* c)
{
	cout << "cannot grow." << endl;
}

void CropState::reproduce(Crop* c)
{
	cout << "cannot reproduce." << endl;
}

void Growing::grow(Crop* c)
{
	c->growbigger();
	if (c->get_age() > 5)
	{
		CropState* s = new Mature();
		c->setState(s);
	}
}

void Mature::reproduce(Crop* c)
{
	c->bloom();
	c->bear_fruit();
}