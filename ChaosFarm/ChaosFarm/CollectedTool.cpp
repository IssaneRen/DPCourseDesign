#include "CollectedTool.h"

//#define DEBUG

const int needFixValue = 20;

CollectedTool::CollectedTool(string name)
	:Tool(name)
{
}

CollectedTool::CollectedTool(string name, vector<Tool*>* toolList)
	:Tool(name)
{
	toolList_ =  *toolList;
}

CollectedTool::CollectedTool(vector<Abstract*>* abs_list, int size, string name, int init_durability, MaterialType material)
	: Tool(abs_list, size, name, init_durability, material)
{
}


CollectedTool::~CollectedTool()
{
}

void CollectedTool::outputDurability() 
{
#ifdef DEBUG
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		cout << "工具成员：" << (*it)->getName() << " 剩余耐久度:" << (*it)->getDurability() << endl;
	}
#endif // DEBUG

}

//return worst Tool's durability
int CollectedTool::getDurability()
{
	format_output("CollectedTool::getDurability");
	int worstToolDurability = this->checkWorstTool()->getDurability();
	return worstToolDurability;
}

//reduce every member's
void CollectedTool::loss()
{
	format_output("CollectedTool::loss", ("every composition in " + this->getName() + " lost its DurabilityUnit" ).c_str());
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		(*it)->loss();
	}
#ifdef DEBUG
	cout << "我(" << this->getName() << ")磨损啦!!虽然我是工具组合！" << endl;
#endif // DEBUG

}

void CollectedTool::fix(int n)
{
	format_output("CollectedTool::loss", ("every composition in " + this->getName() + " fix " + to_string(n) + " durability").c_str());
	durability_ += n;
#ifdef DEBUG
	cout << "我(" << this->getName() << ")被修理了 " << n << " 点耐久度啦！" << endl;
	outputDurability();
#endif // DEBUG
}

void CollectedTool::addTool(Tool* tool)
{
	format_output("CollectedTool::addTool", ("add Tool:" + tool->getName() + " into Tool: " + this->getName()).c_str());
	toolList_.push_back(tool);
}

void CollectedTool::removeTool(Tool* tool)
{
	format_output("CollectedTool::removeTool", ("remove tool composition Tool: " + tool->getName()).c_str());
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		if (*it == tool) {
			toolList_.erase(it);
			return;
		}
	}
	cout << "ERROR!" << endl;
}

vector<Tool*>* CollectedTool::getToolList()
{
	format_output("CollectedTool::getToolList()");
	auto toolList = &toolList_;
	return toolList;
}

//仅仅为了逻辑的实现，实际上大多数时候可以直接使用tool->getName()来替代
string CollectedTool::getUnitName(Tool* tool)
{
	format_output("CollectedTool::getUnitName");
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		if (*it == tool) {
			cout << "name: " << endl;
			return (*it)->getName();
		}
	}
	cout << "ERROR!" << endl;
	return nullptr;
}

vector<Tool*>* CollectedTool::checkFixNeededTool()
{
	format_output("CollectedTool::checkFixNeededTool");
	vector<Tool*>* newToolVector = new vector<Tool*>();
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		if (durability_ <= needFixValue) {	//需要修理了！
			newToolVector->push_back(*it);
		}
	}
	return newToolVector;
}

Tool* CollectedTool::checkWorstTool()
{
	format_output("CollectedTool::checkWorstTool");
	Tool* worstTool = nullptr;
	auto it = toolList_.begin();
	for (; it != toolList_.end(); it++) {
		if (worstTool == nullptr)
			worstTool = *it;
		else if ((*it)->getDurability() <= worstTool->getDurability())
			worstTool = *it;
	}
	return worstTool;
}