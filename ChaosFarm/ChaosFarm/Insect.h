#pragma once
#include<map>
#include "Animal.h"
#include "Collection.h"
#include "List.h"
#include "Atmosphere.h"
#include<vector>
#include<math.h>

/*Insect*/
class Insect:public Animal
{
public:
	friend class InsectData;
	virtual ~Insect(){}
	//*����species������Ӧ�����Insect
	static Insect* find_and_clone(vector<Abstract*>* abs_list, string* species)
	{
		map<string*, Insect*>::iterator it;
		
		for (it = prototype_.begin(); ; it++)
		{
			if (*(*it).first == *species)break;
			if (it == prototype_.end())
			{
				if (*(*it).first != *species)
				{
					return NULL;
				}
			}
		}
		Insect*temp = (*it).second->clone(abs_list, 1);
		return temp;
	}
	//*��Ӧ��������ʱ������ʱ����update()���ô˺�����
	virtual void time_pass_by();
	//*�ɳ�����
	virtual void grow();
	//*��ȡ��ǰ��ֳ��
	float get_reproduction_rate();
	//*��Ӧ�������������仯ʱ����update()���ô˺�����
	virtual void when_atmosphere_changed();
	//*��ȡ��������࣬Ҫ������ʵ��
	virtual string* get_species() = 0;
	//*����д�Ļ�ȡ�����ĺ���������"Insect"
	virtual const char* get_class_name(){ return "Insect"; }
protected:
	//*�����õĴ�����Ϊ0ʱ��delete
	int ref_count_;
	//*��ֳ��
	float reproduction_rate_;
	//*abs_list����Ҫע���subject�б�
	//*size��������Ĵ�С��
	//*max_age���������������䡣
	Insect(vector<Abstract*>* abs_list, int size, int max_age) :Animal(abs_list, size, max_age),reproduction_rate_(1) {}
	//*����ԭ�Ϳ�¡һ���Լ�����������ʵ��
	virtual Insect* clone(vector<Abstract*>* abs_list, int size) = 0;
	//*��ԭ�ͷ����б���
	static void addPrototype(Insect* insect);
private:
	//*��¼ÿһ�������ԭ��
	static map<string*, Insect*> prototype_;
};

inline void Insect::addPrototype(Insect * insect)
{
	prototype_.insert(map<string*, Insect*>::value_type(insect->get_species(), insect));
}
map<string*, Insect*> Insect::prototype_;

void Insect::time_pass_by()
{
	if (alive_)
	{
		Time::instance()->do_something(this);
		grow();
	}
}

float Insect::get_reproduction_rate()
{
	return reproduction_rate_;
}

void Insect::when_atmosphere_changed()
{
	if (alive_)
	{
		Atmosphere* atmosphere = Atmosphere::get_instance();
		if (atmosphere->get_weather_type() == WINDY)
		{
			reproduction_rate_ = 0.5;
			format_output("Insect::when_atmosphere_changed()", "low reproduction rate!");
		}
		if (atmosphere->get_weather_type() == RAINY)
		{
			reproduction_rate_ = 0.25;
			format_output("Insect::when_atmosphere_changed()", "low reproduction rate!");
		}
	}
}

void Insect::grow()
{
	age_ += Time::instance()->get_d_hour();
	if (age_ >= max_age_)die();
}

/*InsectData����װInsect��ʵ��reference counting*/
class InsectData :public Entity
{
public:
	//*����species������Ӧ�����InsectData
	InsectData(vector<Abstract*>* abs_list, string* species) :Entity(abs_list, 1)
	{
		insect_ = Insect::find_and_clone(NULL, species);
		insect_->ref_count_ = 1;
	}
	//*������һ��InsectData�����¶���
	InsectData(vector<Abstract*>* abs_list, InsectData& another) :Entity(abs_list, 1)
	{
		insect_ = another.insect_;
		(insect_->ref_count_)++;
	}
	//*�������õ�Insect����-1�����������Ϊ0��ɾ��
	~InsectData()
	{
		if (insect_ != NULL)
		{
			(insect_->ref_count_)--;
			if (insect_->ref_count_ == 0)
			{
				delete insect_;
			}
		}
	}
	//*��Ӧ��������ʱ������ʱ����update()���ô˺�����
	virtual void time_pass_by();
	//*��ȡ��ֳ��
	float get_reproduction_rate();
	//*��Ӧ�������������仯ʱ����update()���ô˺�����
	virtual void when_atmosphere_changed();
	//*��ȡ��������
	string* get_species();
	//*����д�Ļ�ȡ�����ĺ���
	const char* get_class_name() { return insect_->get_class_name(); }
private:
	//*�����õ�Insect����
	Insect* insect_;
	//*����������ʱ���ã������ԭ��������ã�������һ���¶���
	void copy_on_write();
};

void InsectData::time_pass_by()
{
	copy_on_write();
	insect_->time_pass_by();
}

float InsectData::get_reproduction_rate()
{
	return insect_->get_reproduction_rate();
}

void InsectData::when_atmosphere_changed()
{
	copy_on_write();
	insect_->when_atmosphere_changed();
}

string* InsectData::get_species()
{
	return insect_->get_species();
}

void InsectData::copy_on_write()
{
	if (insect_->ref_count_ > 1)
	{
		Insect* temp = Insect::find_and_clone(NULL, insect_->get_species());
		int id = temp->get_id();
		*temp = *insect_;
		temp->id_ = id;
		temp->ref_count_ = 1;
		insect_->ref_count_--;
		if (insect_->ref_count_ == 0)
		{
			delete insect_;
		}
		insect_ = temp;
	}
}

/*InsectGroup*/
class InsectGroup :public Collection
{
public:
	class Iterator :public FarmIterator
	{
	public:
		Iterator();
		virtual ~Iterator(){}
		friend class InsectGroup;
		Iterator(InsectGroup* group);
		Iterator(Iterator* another);
		//*��ȡ�ýڵ��ֵ
		virtual Object* value();
		//*ָ����һ�ڵ�
		virtual void turn_next();
		//*ָ����һ�ڵ�
		virtual void turn_previous();
		//*ָ���׽ڵ�
		virtual void turn_first();
		//*ָ��β�ڵ�
		virtual void turn_last();
		//*�ж��Ƿ�����һ�ڵ�
		virtual bool has_next();
		//*�ж��Ƿ�����һ�ڵ�
		virtual bool has_previous();
		//*����д�Ļ�ȡ�����ĺ���������"InsectGroup::Iterator"
		virtual const char* get_class_name() { return "InsectGroup::Iterator"; }
	};
	//*���ó�Ⱥ������
	InsectGroup(string* species) :species_(species)
	{
		list_ = new List();
	}
	//*��������
	~InsectGroup()
	{
		delete species_;
		delete list_;
	}
	//*��ȡ��С
	virtual int size();
	//*�ж��Ƿ�Ϊ��
	virtual bool is_empty();
	//*��iteratorָ��ʼ��
	virtual void begin(FarmIterator& iterator);
	//*��iteratorָ�������
	virtual void end(FarmIterator& iterator);
	//*����һ������������
	void hatch(vector<Abstract*>* abs_list);
	//*�����Ԫ��
	virtual void add(Object* new_element);
	//*�Ƴ�iteratorָ���Ԫ��
	virtual void remove(FarmIterator& iterator);
	//*����д�Ļ�ȡ�����ĺ���������"InsectGroup"
	virtual const char* get_class_name(){ return "InsectGroup"; }
private:
	string* species_;
	List*list_;
};

int InsectGroup::size()
{
	return list_->size();
}
bool InsectGroup::is_empty()
{
	return list_->is_empty();
}
void InsectGroup::begin(FarmIterator& iterator)
{
	if (size() > 0)
	{
		Iterator begin(this);
		iterator = begin;
	}
	else
	{
		Iterator begin;
		iterator = begin;
	}
}
void InsectGroup::end(FarmIterator& iterator)
{
	if (size() > 0)
	{
		Iterator end(this);
		iterator = end;
	}
	else
	{
		Iterator end;
		iterator = end;
	}
}
void InsectGroup::hatch(vector<Abstract*>* abs_list)
{
	int number;
	if (list_->size() > 0)
	{
		Iterator* it = new Iterator();
		begin(*it);
		float group_reproduction_rate = 0;
		for (; it->has_next(); it->turn_next())
		{
			group_reproduction_rate = group_reproduction_rate + ((InsectData*)it->value())->get_reproduction_rate();
		}
		group_reproduction_rate = group_reproduction_rate + ((InsectData*)it->value())->get_reproduction_rate();
		float average_rate = group_reproduction_rate / (list_->size());
		number = (int)(sqrt(list_->size())*average_rate);
		delete it;
	}
	else
	{
		number = 10;
	}
	if (number < 1)
	{
		number = 1;
	}
	InsectData* temp = new InsectData(abs_list, species_);
	Node* new_element = new Node(temp);
	list_->add(new_element);

	for (int i = 1; i < number; i++)
	{
		InsectData* data = new InsectData(abs_list, *temp);
		Node* new_element = new Node(data);
		list_->add(new_element);
	}
}
void InsectGroup::add(Object* new_element)
{
	if (new_element != NULL)
	{
		InsectData* temp = (InsectData*)new_element;
		if (*species_ == *(temp->get_species()))
		{
			Node* new_node = new Node(temp);
			list_->add(new_node);
		}
	}
}
void InsectGroup::remove(FarmIterator& iterator)
{
	Iterator* temp = (Iterator*)&iterator;
	list_->erase((Node*)temp->current_node_);
}


/*InsectGroup::Iterator*/
InsectGroup::Iterator::Iterator()
{
	current_node_ = NULL;
}

InsectGroup::Iterator::Iterator(InsectGroup* group)
{
	Node* node = group->list_->head();
	if (node != NULL)
	{
		current_node_ = node;
	}
	else
	{
		current_node_ = NULL;
	}
}

InsectGroup::Iterator::Iterator(Iterator* another)
{
	if (another != NULL)
	{
		current_node_ = another->current_node_;
	}
	else
	{
		current_node_ = NULL;
	}
}

Object* InsectGroup::Iterator::value()
{
	if (current_node_ != NULL)
	{
		return ((Node*)current_node_)->get_value();
	}
	else
	{
		return NULL;
	}
}

void InsectGroup::Iterator::turn_next()
{
	if (has_next())
	{
		current_node_ = ((Node*)current_node_)->get_next();
	}
}
void InsectGroup::Iterator::turn_previous()
{
	if (has_previous())
	{
		current_node_ = ((Node*)current_node_)->get_previous();
	}
}
void InsectGroup::Iterator::turn_first()
{
	if (current_node_ != NULL)
	{
		Node* temp = (Node*)current_node_;
		for (; temp->get_previous() != NULL; temp = temp->get_previous());
		current_node_ = temp;
	}
}
void InsectGroup::Iterator::turn_last()
{
	if (current_node_ != NULL)
	{
		Node* temp = (Node*)current_node_;
		for (; temp->get_next() != NULL; temp = temp->get_next());
		current_node_ = temp;
	}
}
bool InsectGroup::Iterator::has_next()
{
	if (current_node_ != NULL)
	{
		if (((Node*)current_node_)->get_next() == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
bool InsectGroup::Iterator::has_previous()
{
	if (current_node_ != NULL)
	{
		if (((Node*)current_node_)->get_previous() == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}