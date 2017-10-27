#ifndef CF_STOCK_H_
#define CF_STOCK_H_
#include "Facility.h"
#include "StockList.h"


class Stock final : public Facility
{
public:
	Stock(vector<Abstract*>* abs_list, int size, int init_durability = 100);

	~Stock(){ delete stock_list_; }

	void time_pass_by();

	void when_atmosphere_changed();

	void put_in(Entity* entity);

	void get_out(Entity* entity);

	bool is_full();

	bool is_empty();

	int get_rest_size() { return max_size_ - size_;  }

	StockIterator* find(Entity* entity);

	void expand(int ex_size);

private:
	StockList* stock_list_;
	int max_size_;
};
#endif

