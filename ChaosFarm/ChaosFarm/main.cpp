#include "Time.h"
#include "BaseFarmland.h"
#include "Bee.h"
#include "Warehouse.h"

int main() {
	InsectGroup* beeGroup = new InsectGroup(new string("bee"));
	
	for (int i = 0; i < 20; i++)
	{
		beeGroup->hatch(NULL);
	}

	cout << beeGroup->size() << endl;

	InsectGroup::Iterator it;

	Warehouse* warehouse = Warehouse::get_instance(NULL);

	warehouse->set_max_durability(1000);
	cout << warehouse->get_durability() << endl;

	warehouse->dilate(1000);
	cout << warehouse->capacity() << endl;
	beeGroup->begin(it);

	for (int i = 0; i < 50; i++)
	{
		it.turn_next();

		InsectData* temp = (InsectData*)it.value();

		warehouse->add(temp);

		cout << *(temp->get_species()) << endl;
	}
	cout << beeGroup->size() << endl;
	warehouse->show_list();

	Shelf::Iterator shelf_iterator;

	warehouse->begin(shelf_iterator);

	cout << warehouse->usable_capacity() << endl;

	warehouse->find_kind("Bee");

	system("pause");
	return 0;
}