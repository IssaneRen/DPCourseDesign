#ifndef CF_TOOL_H
#define CF_TOOL_H
#include <string>
#include "Facility.h"
#include "MaterialType.h"

class Tool : public Facility
{
public:
	Tool(string name);
	Tool(vector<Abstract*>* abs_list, int size, string name, int init_durability = 100, MaterialType material = MaterialType::NILL);
	~Tool();

	void time_pass_by();
	void when_atmosphere_changed();
	
	void update(AbstractType type) = 0;
	virtual void fix(int n = 1) = 0;
	virtual void loss() = 0;
	virtual void outputDurability() = 0;
	virtual int getDurability() = 0;
	string getName() { return name_; }

protected:
	string name_;
	MaterialType material_;

private:

};

#endif //CF_TOOL_H