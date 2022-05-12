#include <iostream>
#include "iterator.h"
#include "RBTree.h"
#include "list.h"
#include "pair.h"
using namespace std;


template <class T1, class T2>
class Map
{
private:
	RBTree<T1, T2>* rbtree;
public:
	Map()
	{
		rbtree = new RBTree<T1, T2>();
	}

	~Map()
	{
		delete rbtree;
	}

	void Insert(const T1& key, const T2& data)
	{
		rbtree->Insert(key, data);
	}

	void Delete(T1 key)
	{
		rbtree->Delete(key);
	}

	T2 Find(T1 key)
	{
		return rbtree->FindData(key);
	}

	void Get_Keys(List<T1>* keys)
	{
		auto itr = this->create_iterator();
		while (itr->has_next())
		{
			Pair<T1, T2> pair = itr->next();
			keys->push_back(pair.first);
			
		}
		
	}

	void Get_Values(List<T2>* values)
	{
		auto itr = this->create_iterator();
		while (itr->has_next())
		{
			Pair<T1, T2> pair = itr->next();
			values->push_back(pair.second);

		}
	}
	void print() {
		auto itr = this->create_iterator();
		cout << "(KEY: VALUE): ";
		while (itr->has_next()) 
		{
			Pair<T1, T2> pair = itr->next();
			cout << pair.first << ": " << pair.second << "; ";
		}
		cout << "\n";
	}

	void Clear()
	{
		delete rbtree;
		rbtree = new RBTree<T1, T2>();
	}

	class MapIterator : public Iterator<Pair<T1, T2>>
	{
	public:
		friend class Map;

		Iterator<Pair<T1, T2>>* treeiter;

		MapIterator(RBTree<T1, T2>* rbtree)
		{
			treeiter = rbtree->create_iterator();
		}

		~MapIterator()
		{
			delete treeiter;
		}

		bool has_next()
		{
			return treeiter->has_next();
		}

		Pair<T1, T2> next()
		{
			return treeiter->next();
		}
	};

	MapIterator* create_iterator()
	{
		return new MapIterator(rbtree);
	}
};


int main() {
	Map<char, int> myMap;
	myMap.Insert('A', 5);
	myMap.Insert('B', 7);
	myMap.Insert('C', 2);
	myMap.Insert('D', 1);
	myMap.print();
	myMap.Delete('A');
	myMap.print();
	List<char> keys;
	myMap.Get_Keys(&keys);
	keys.print();
	return 0;
}