#include "Tool.h"

const int initSize = 10;
const int initDurability = 100;

Tool::Tool(string name)
	:Facility(nullptr, initSize, initDurability), name_(name)
{
}

Tool::Tool(vector<Abstract*>* abs_list, int size, string name, int init_durability, MaterialType material) 
	:Facility(abs_list, size, init_durability), material_(material), name_(name)
{
}


Tool::~Tool()
{
}

void Tool::time_pass_by()
{

}

void Tool::when_atmosphere_changed()
{
	
}
