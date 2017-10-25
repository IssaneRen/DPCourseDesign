#include "Facility.h"

Facility::Facility(vector<Abstract*>* abs_list, int size, int init_durability)
	:Entity(abs_list, size), durability_(init_durability)
{

}