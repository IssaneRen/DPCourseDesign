#ifndef CF_TOOL_H
#define CF_TOOL_H
#include "Facility.h"
#include "MaterialType.h"

class Tool : public Facility
{
public:
	Tool(vector<Abstract*>* abs_list, int size, int init_durability = 100, MaterialType material = MaterialType::NILL);
	~Tool();
private:
	MaterialType material_;
};

#endif //CF_TOOL_H