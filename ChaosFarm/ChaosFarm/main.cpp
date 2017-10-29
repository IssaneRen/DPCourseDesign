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

	InsectGroup::Iterator it;

	for (int i = 0; i < 50; i++)
	{
		beeGroup->begin(it);

		Bee* temp = (Bee*)it.value();

		cout << *(temp->get_species()) << endl;

		beeGroup->remove(it);
	}
	cout << beeGroup->size() << endl;
	system("pause");
	return 0;
}