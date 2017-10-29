#include "Crop.h"
#include "Atmosphere.h"

Crop::Crop(vector<Abstract*>* abs_list, int size, int max_age)
:Plant(abs_list, size, max_age), fruit_size_(0){
	state = new Growing();         //初始选择未成熟
	output_rate_ = 1.0;
	mature_age_ = 5;
}

void Crop::absorb_water()
{
	if (!is_alive())
	{
		return;
	}
	if (energy_ >= 1)
	{
		energy_--;
		water_content_ += 5;
		format_output("Crop::absorb_water()", "is absorbing water.");
	}
}

void Crop::bear_fruit()
{
	if (!is_alive())
	{
		return;
	}
	if (energy_ >= 5)
	{
		energy_ -= 5;
		fruit_size_ += output_rate_;
		format_output("Crop::bear_fruit()", "is bearing fruit.");
	}
}

void Crop::plant_on(BaseFarmLand* farmland){
	if (!is_alive())
	{
		return;
	}
	farmland->plant_a_crop(this); 
}


void Crop::bloom()
{
	if (!is_alive())
	{
		return;
	}
	if (energy_ >= 3)
	{
		energy_ -= 3;		
		format_output("Crop::bloom()", "is blooming.");
	}
}

bool Crop::defend()
{
	if (!is_alive())
	{
		return false;
	}
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
	if (!is_alive())
	{
		return;
	}
	health_ -= num;
	format_output("Crop::weaken()", "is weakened.");
	if (health_ <= 0)
	{
		die();
	}
}

void Crop::growbigger()
{
	if (!is_alive())
	{
		return;
	}
	if (energy_ >= 3)
	{
		format_output("Crop::growbigger()", "is growing bigger.");
		energy_ -= 3;
		size_ += Time::instance()->get_d_hour();
	}
}

void Crop::grow()
{
	if (!is_alive())
	{
		return;
	}
	state->grow(this);
}

void Crop::reproduce()
{
	if (!is_alive())
	{
		return;
	}
	state->reproduce(this);
}

void Crop::die()
{
	if (!is_alive())
	{
		return;
	}
	if (health_ <= 0 || age_ > max_age_)
	{
		set_alive(false);
		format_output("Crop::die()", "is dying.");
	}
}

void Crop::photosynthesis()
{
	if (!is_alive())
	{
		return;
	}
	Atmosphere* atm = Atmosphere::getInstance();
	if (water_content_ > 0)							    //光合作用
	{
		
		water_content_--;
		energy_ += 5 * atm->get_lux();

	}
}

void Crop::breath()
{
	if (!is_alive())
	{
		return;
	}
	if (fruit_size_ > 0)								//进行呼吸
	{
		format_output("Crop::breath()", "is breath.");
		fruit_size_--;
		energy_ += 10;
	}
}

void Crop::time_pass_by()
{
	if (!is_alive())
	{
		return;
	}
	//age_++;
	age_ += Time::instance()->get_d_hour();				//经过的时间
	format_output("Crop::time_pass_by()", "is aging.");
	if (age_ > max_age_)
	{
		die();
	}
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
	if (!is_alive())
	{
		return;
	}
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
	if (!is_alive())
	{
		return;
	}
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
	cout << "it cannot grow." << endl;
}

void CropState::reproduce(Crop* c)
{
	cout << "it cannot reproduce." << endl;
}

void Growing::grow(Crop* c)
{
	c->growbigger();
	if (c->get_age() > c->get_mature_age())									//由生长期变为成熟期
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