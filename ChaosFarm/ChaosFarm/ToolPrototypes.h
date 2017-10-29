#ifndef CF_TOOLPROTOTYPES_H
#define CF_TOOLPROTOTYPES_H

#include <iostream>
#include "UnitTool.h"
#include "CollectedTool.h"

using namespace std;

//ENUM varieties of sample tools
enum toolType{
	COACH, CART, FARMTOOLKIT, SCISSORS
};

class CoachTool : public CollectedTool {
public:
	toolType returnType() { return COACH; }
	void use();
private:

};

class CartTool : public CollectedTool {

};

class FarmToolkitTool : public CollectedTool {

};

class ScissorsTool :public UnitTool {

};

#endif // !CF_TOOLPROTOTYPES_H
