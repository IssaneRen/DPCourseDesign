#include "Plant.h"

Plant::Plant(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex)
	:Living(abs_list, size, max_age, name, sex), energy_(50), water_content_(50) {

}
