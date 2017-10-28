#include "Time.h"
#include "InsectGroup.h"
#include "Bee.h"

int main() {
	InsectGroup* beeGroup = new InsectGroup(new string("bee"));
	
	for (int i = 0; i < 20; i++)
	{
		beeGroup->hatch(NULL);
	}

	cout << beeGroup->size() << endl;

	InsectGroup::Iterator* it = new InsectGroup::Iterator();

	beeGroup->begin(it);

	for (int i = 0; i < 50; i++)
	{
		it->turn_next();

		Bee* temp = (Bee*)it->value();

		cout << *(temp->get_species()) << endl;
	}
	system("pause");
	return 0;
}