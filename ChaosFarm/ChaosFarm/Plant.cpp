#include "Plant.h"

Plant::Plant(vector<Abstract*>* abs_list, int size, int max_age)
:Living(abs_list, size, max_age), energy_(50), water_content_(50){

}