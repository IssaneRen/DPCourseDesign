#pragma once
#include "Tool.h"

class UnitTool :
	public Tool
{
public:
	UnitTool(string name);
	UnitTool(vector<Abstract*>* abs_list, int size, string name, int init_durability = 100, MaterialType material = MaterialType::NILL);
	~UnitTool();

	void update(AbstractType type);
	void outputDurability();
	int getDurability() { return durability_; }
	void loss();
	void fix(int n = 1);

	MaterialType getMaterial() { return material_; }

	int getDurabilityUnit() { return durabilityUnit_; }
	void setDurabilityUnit(int durabilityUnit) { durabilityUnit_ = durabilityUnit; }

	virtual const char* get_class_name(){ return "UnitTool"; }

private:
	int durabilityUnit_;
};
