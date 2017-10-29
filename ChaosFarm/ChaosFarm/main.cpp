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

	Shelf* shelf = warehouse->get_shelf();
	shelf->dilate(1000);
	cout << shelf->capacity() << endl;
	beeGroup->begin(it);

	for (int i = 0; i < 50; i++)
	{
		it.turn_next();

		Bee* temp = (Bee*)it.value();

		shelf->add(temp);

		cout << *(temp->get_species()) << endl;
	}
	cout << beeGroup->size() << endl;
	shelf->show_list();

	Shelf::Iterator shelf_iterator;

	shelf->begin(shelf_iterator);

	cout << shelf->usable_capacity() << endl;

	for (int i = 0; i < 50; i++)
	{
		shelf->remove(shelf_iterator);
		shelf->begin(shelf_iterator);
	}
	shelf->show_list();
	cout << shelf->usable_capacity()<< endl;

	system("pause");
	return 0;
}