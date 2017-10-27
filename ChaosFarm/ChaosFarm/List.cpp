#include "List.h"

Node::Node()
{
	previous_ = NULL;
	content_ = NULL;
	next_ = NULL;
}

Node::Node(Object* value)
{
	previous_ = NULL;
	content_ = value;
	next_ = NULL;
}

Node::~Node()
{
	delete content_;
}

Node* Node::get_previous()
{
	return previous_;
}

Object* Node::get_value()
{
	return content_;
}

Node* Node::get_next()
{
	return next_;
}

void Node::set_previous(Node* previous)
{
	previous_ = previous;
}

void Node::set_value(Object* value)
{
	content_ = value;
}

void Node::set_next(Node* next)
{
	next_ = next;
}

List::List()
{
	head_ = new Node();
	size_ = 0;
}

Node* List::head()
{
	return head_;
}

void List::add(Node* new_node)
{
	if (head_->get_value() == NULL)
	{
		head_ = new_node;
		size_++;
	}
	else
	{
		Node* temp;
		for (temp = head_; ; temp = temp->get_next())
		{
			if (temp->get_next() == NULL)
			{
				temp->set_next(new_node);
				new_node->set_previous(temp);
				size_++;
				break;
			}
		}
	}
}

void List::remove(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		if (node->get_previous() != NULL)
		{
			if (node->get_next() != NULL)
			{
				node->get_previous()->set_next(node->get_next());
				node->get_next()->set_previous(node->get_previous());
				delete node;
				size_--;
				return;
			}
			else
			{
				node->get_previous()->set_next(NULL);
				delete node;
				size_--;
				return;
			}
		}
		else
		{
			if (node->get_next() != NULL)
			{
				node->get_next()->set_previous(NULL);
				delete node;
				size_--;
				return;
			}
			else
			{
				delete node;
				size_--;
				return;
			}
		}
	}
}

int List::size()
{
	return size_;
}

bool List::is_empty()
{
	if (size_ != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}