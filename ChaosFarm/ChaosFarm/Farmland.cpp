#include"Farmland.h"

int main()
{
	Farmland *f1 = new Redland();
	f1 = new Kcl(f1);
	f1 = new Kcl(f1);
	f1 = new Nh4(f1);
	cout << "description: " << f1->get_discription() << endl;;
	cout << "size: " << f1->size() << endl;

	cout << "-----------------------" << endl;

	Farmland *f2 = new Blackland();
	f2 = new Nh4(f2);
	f2 = new Kcl(f2);
	cout << "description: " << f2->get_discription() << endl;;
	cout << "size: " << f2->size() << endl;

	cout << "-----------------------" << endl;

	Control *remote = new Control();
	Farmland *f3 = new Farmland();
	Plow *plow = new Plow(f3);
	Smell *smell = new Smell(f3);
	Ftime *time = new Ftime(f3);
	remote->set_command(0,plow);
	remote->set_command(1, smell);
	remote->set_command(2, time);
	remote->button_is_pressed(0);
	remote->button_is_pressed(1);
	remote->button_is_pressed(2);
	remote->button_is_pressed(2);

}
