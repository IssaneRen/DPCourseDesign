#include "UnitTool.h"

#define DEBUG

const int initDurabilityUnit = 1;

UnitTool::UnitTool(string name)
	:Tool(name), durabilityUnit_(initDurabilityUnit)
{
}


UnitTool::UnitTool(vector<Abstract*>* abs_list, int size,string name, int init_durability, MaterialType material)
	:Tool(abs_list, size, name, init_durability, material), durabilityUnit_(initDurabilityUnit)
{
}


UnitTool::~UnitTool()
{
}

void UnitTool::update(AbstractType type)
{

}

void UnitTool::outputDurability()
{
#ifdef DEBUG
	cout << "我(" << this->getName() << ")当前耐久度" << durability_ << endl;
#endif // DEBUG
}

void UnitTool::loss()
{
	durability_ -= durabilityUnit_;
#ifdef DEBUG
	cout << "我(" << this->getName() << ")磨损了 " << durabilityUnit_ << "点耐久度啦！" << endl;
	outputDurability();
#endif //DEBUG
}

void UnitTool::fix(int n)
{
	durability_ += n;
#ifdef DEBUG
	cout << "我(" << this->getName() << ")被修理了 " << n << " 点耐久度啦！" << endl;
	outputDurability();
#endif // DEBUG
}

