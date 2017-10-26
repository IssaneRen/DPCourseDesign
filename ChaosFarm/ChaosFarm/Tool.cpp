#include "Tool.h"



Tool::Tool(vector<Abstract*>* abs_list, int size, int init_durability, MaterialType material) 
	:Facility(abs_list, size, init_durability), material_(material)
{
}


Tool::~Tool()
{
}
