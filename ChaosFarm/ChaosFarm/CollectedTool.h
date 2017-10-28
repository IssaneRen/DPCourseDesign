#pragma once
#include "Tool.h"
#include <vector>

class CollectedTool :
	public Tool
{
public:
	CollectedTool(string name);
	CollectedTool(string name, vector<Tool*>* toolList);
	CollectedTool(vector<Abstract*>* abs_list, int size, string name, int init_durability = 100, MaterialType material = MaterialType::NILL);
	~CollectedTool();

	void update(AbstractType type);
	void outputDurability();
	int getDurability();
	void fix(int n = 1);
	void loss();

	void addTool(Tool* tool);
	void removeTool(Tool* tool);
	vector<Tool*>* getToolList();

	string getUnitName(Tool* tool);

	vector<Tool*>* checkFixNeededTool();
	Tool* checkWorstTool();

private:
	vector<Tool*> toolList_;
};
