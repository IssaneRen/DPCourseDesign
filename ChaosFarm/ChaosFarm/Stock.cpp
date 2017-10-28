#include "Stock.h"

Stock::Stock(vector<Abstract*>* abs_list, int max_size, int init_durability ) : Facility(abs_list, 0, init_durability)
{
	stock_list_ = new StockList();
	size_ = 0;
}


void Stock::time_pass_by()
{
	if (durability_ > 0)durability_--;
}

void Stock::when_atmosphere_changed()
{
}

void Stock::put_in(Entity* entity)
{
	stock_list_->add(entity);
}

void Stock::get_out(Entity* entity)
{
	StockList::Iterator* stock_it = new StockList::Iterator();
	for (stock_list_->begin(stock_it); stock_it->has_next(); stock_it->turn_next()){
		if (stock_it->value() == entity){
			size_ -= ((Entity*)stock_it->value())->get_size();
			stock_list_->remove(stock_it);
		}
	}
	delete stock_it;
}

bool Stock::is_empty()
{
	return (size_ == 0) ? true : false;
}

bool Stock::is_full()
{
	return (size_ >= max_size_ ) ? true : false;
}

StockList::Iterator* Stock::find(Entity* entity)
{
	StockList::Iterator* stock_it = new StockList::Iterator();
	for (stock_list_->begin(stock_it); stock_it->has_next(); stock_it->turn_next()){
		if (stock_it->value() == entity){
			return stock_it;
		}
	}
	return NULL;
}

void Stock::expand(int ex_size)
{
	max_size_ += ex_size;
}


