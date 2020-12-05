/*
  This program is a B+Tree implementation of the corresponding frequency pattern by reading the result.txt file.
  In the main function, bptree->printFrequency ("soup", 2); enter the item you want to search instead of soup,
  and enter the minimum frequency instead of 2, to print all the set of items above that frequency.
All factors in result.txt are separated by tab, and the frequency is stored in the beginning, followed by the item set.

*/

#include <fstream>
#include <iostream>
#include <typeinfo>
#include <cmath>
#include <list>
#include <string>
#include <map>
#include <set>

#pragma warning(disable:4996)

using namespace std;

class FrequentPatternNode
{
private:
	int frequency;		// FrequentPattern frequency
	multimap<int, set<string> > FrequentPatternList;	//first is FrequentPattern size, second is FrequentPattern data

public:
	FrequentPatternNode() { frequency = 0; }
	~FrequentPatternNode() { FrequentPatternList.clear(); }
	void setFrequency(int frequency) { this->frequency = frequency; }
	void InsertList(set<string> item) { FrequentPatternList.insert(multimap<int, set<string>>::value_type(item.size(), item)); }
	int getFrequency() { return frequency; }
	multimap<int, set<string> > getList() { return FrequentPatternList; }
};

class BpTreeNode
{
private:
	BpTreeNode* pParent;
	BpTreeNode* pMostLeftChild;

public:
	BpTreeNode() {
		pParent = NULL;
		pMostLeftChild = NULL;
	}
	~BpTreeNode() {

	}

	void setMostLeftChild(BpTreeNode* pN) { pMostLeftChild = pN; }
	void setParent(BpTreeNode* pN) { pParent = pN; }

	BpTreeNode* getParent() { return pParent; }
	BpTreeNode* getMostLeftChild() { return pMostLeftChild; }

	virtual void setNext(BpTreeNode* pN) {}
	virtual void setPrev(BpTreeNode* pN) {}
	virtual BpTreeNode* getNext() { return NULL; }
	virtual BpTreeNode* getPrev() { return NULL; }

	virtual void insertDataMap(int n, FrequentPatternNode* pN) {}
	virtual void insertIndexMap(int n, BpTreeNode* pN) {}
	virtual void deleteMap(int n) {}

	virtual map<int, BpTreeNode*>* getIndexMap() { return {}; }
	virtual map<int, FrequentPatternNode*>* getDataMap() { return {}; }

	virtual bool checkEnd(BpTreeNode*) = 0;

};

class BpTreeDataNode : public BpTreeNode
{
private:
	map <int, FrequentPatternNode*> mapData;
	BpTreeNode* pNext;
	BpTreeNode* pPrev;
public:
	BpTreeDataNode() {
		pNext = NULL;
		pPrev = NULL;
	}
	~BpTreeDataNode()
	{
		mapData.clear();
	}

	void setNext(BpTreeNode* pN) { pNext = pN; }
	void setPrev(BpTreeNode* pN) { pPrev = pN; }
	BpTreeNode* getNext() { return pNext; }
	BpTreeNode* getPrev() { return pPrev; }

	void insertDataMap(int n, FrequentPatternNode* pN) {
		mapData.insert(map<int, FrequentPatternNode*>::value_type(n, pN));
	}

	void deleteMap(int n) {
		mapData.erase(n);
	}
	map<int, FrequentPatternNode*>* getDataMap() { return &mapData; }

	virtual bool checkEnd(BpTreeNode*) { return true; }
};

class BpTreeIndexNode : public BpTreeNode {
private:
	map <int, BpTreeNode*> mapIndex;

public:
	BpTreeIndexNode() {}
	~BpTreeIndexNode() { mapIndex.clear(); }


	void insertIndexMap(int n, BpTreeNode* pN) {
		mapIndex.insert(map<int, BpTreeNode*>::value_type(n, pN));
	}

	void deleteMap(int n) {
		mapIndex.erase(n);
	}

	map <int, BpTreeNode*>* getIndexMap() { return &mapIndex; }

	virtual bool checkEnd(BpTreeNode*) { return false; }
};

class BpTree {
private:
	BpTreeNode* root;
	int			order;		// m children
public:
	BpTree(int order = 3) {
		root = NULL;
		this->order = order;
	}
	~BpTree();
	bool		Insert(int key, set<string> set);
	bool		excessDataNode(BpTreeNode* pDataNode);
	bool		excessIndexNode(BpTreeNode* pIndexNode);
	void		splitDataNode(BpTreeNode* pDataNode);
	void		splitIndexNode(BpTreeNode* pIndexNode);
	BpTreeNode* getRoot() { return root; }
	BpTreeNode* searchDataNode(int n);

	void	printFrequentPatterns(set<string> pFrequentPattern, string item);
	bool	printFrequency(string item, int min_frequency);
};


BpTree::~BpTree()
{
	delete root;	//if root not empty, delete each map or multimap in order
}

bool BpTree::Insert(int key, set<string> set) {
	if (root == NULL)	//if root node==null
	{
		//make new datanode and input data
		BpTreeDataNode* newbptdnode = new BpTreeDataNode;
		FrequentPatternNode* newfpnode = new FrequentPatternNode;
		newfpnode->InsertList(set);
		newfpnode->setFrequency(key);
		newbptdnode->insertDataMap(key, newfpnode);
		root = newbptdnode;
		return true;
	}

	//Search to find last data node
	BpTreeNode* search = searchDataNode(key);

	//If there is a desired frequency pattern node in the corresponding node, add a set to the node and exit
	auto test = search->getDataMap();
	auto test1 = test->find(key);
	if (test1 != test->end())
	{
		test1->second->InsertList(set);
		return true;
	}

	//If the desired Fruquant pattern node does not exist in the node, create and insert 
	FrequentPatternNode* newfpnode = new FrequentPatternNode;
	newfpnode->InsertList(set);
	newfpnode->setFrequency(key);
	search->insertDataMap(key, newfpnode);

	if (excessDataNode(search))	//overflow check
		splitDataNode(search);	//splitDatanode

	return true;
}

BpTreeNode* BpTree::searchDataNode(int n) {		//find datanode
	BpTreeNode* pCur = root;

	while (1)
	{
		//If pcur is a data node, return
		if (pCur->checkEnd(pCur))
			break;

		map <int, BpTreeNode*>* temp = pCur->getIndexMap();
		auto find = temp->begin();
		auto next = temp->begin();
		next++;

		if (find->first > n)
		{
			pCur = pCur->getMostLeftChild();	//go mostleft child
			continue;
		}
		while (1)
		{
			if (temp->size() == 1)	//map has one data
			{
				pCur = find->second;	//go that's address
				break;
			}
			else
			{
				if (next == temp->end())	//if end data
				{
					pCur = find->second;	//go end address
					break;
				}
				if (find->first <= n && next->first > n)	//or find address
				{
					pCur = find->second;	//go to address
					break;
				}
			}
			find++;
			next++;
		}
	}
	return pCur;
}

void BpTree::splitDataNode(BpTreeNode* pDataNode) {
	//Index node overflow is checked and performed here
	int center = ceil(((order - 1) / 2.0) + 1);		//split center
	int check_num = 1;

	BpTreeDataNode* newnode = new BpTreeDataNode;	//new datanode
	auto d_map = pDataNode->getDataMap();
	auto check = d_map->begin();
	int key;	//new datanode's key

	list<int>tmp;
	for (; check != d_map->end(); check++)
	{
		if (check_num >= center)
		{
			newnode->insertDataMap(check->first, check->second);	//input key,address in newnode
			tmp.push_back(check->first);	//for delete oldnode
		}
		if (check_num == center)
		{
			key = check->first;	//save key
		}
		check_num++;
	}

	while (!tmp.empty())	//delete at old node
	{
		d_map->erase(tmp.front());
		tmp.pop_front();
	}

	//link datanode side
	newnode->setNext(pDataNode->getNext());
	newnode->setPrev(pDataNode);
	if (pDataNode->getNext() != NULL)
		pDataNode->getNext()->setPrev(newnode);
	pDataNode->setNext(newnode);

	if (pDataNode == root)	//if oldnod==root
	{
		//make new root ans link
		BpTreeIndexNode* newindexnode = new BpTreeIndexNode;
		newindexnode->setMostLeftChild(pDataNode);
		newindexnode->insertIndexMap(key, newnode);
		pDataNode->setParent(newindexnode);
		newnode->setParent(newindexnode);
		root = newindexnode;
	}
	else
	{
		//input key,address at parent
		BpTreeNode* index = pDataNode->getParent();
		index->insertIndexMap(key, newnode);
		newnode->setParent(index);
		pDataNode->setParent(index);

		if (excessIndexNode(index))	//indexnode split check
			splitIndexNode(index);	//split indexnode
	}
}

void BpTree::splitIndexNode(BpTreeNode* pIndexNode) {	//Similar to Datanode Split
	int center = ceil(((order - 1) / 2.0) + 1);
	int check_num = 1;

	BpTreeIndexNode* newnode = new BpTreeIndexNode;	//new indexnode
	auto i_map = pIndexNode->getIndexMap();
	auto check = i_map->begin();


	int key;
	list<int>tmp;
	for (; check != i_map->end(); check++)
	{
		if (check_num > center)
		{
			newnode->insertIndexMap(check->first, check->second);
			check->second->setParent(newnode);
			tmp.push_back(check->first);
		}
		if (check_num == center)
		{
			tmp.push_back(check->first);	//delete key data too
			key = check->first;
			newnode->setMostLeftChild(check->second);
			check->second->setParent(newnode);
		}
		check_num++;
	}

	while (!tmp.empty())
	{
		i_map->erase(tmp.front());
		tmp.pop_front();
	}

	if (pIndexNode == root)
	{
		BpTreeIndexNode* newindexnode = new BpTreeIndexNode;
		newindexnode->setMostLeftChild(pIndexNode);
		newindexnode->insertIndexMap(key, newnode);
		pIndexNode->setParent(newindexnode);
		newnode->setParent(newindexnode);
		root = newindexnode;
	}
	else
	{
		BpTreeNode* index = pIndexNode->getParent();
		index->insertIndexMap(key, newnode);
		newnode->setParent(index);
		pIndexNode->setParent(index);

		if (excessIndexNode(index))	//check parent
			splitIndexNode(index);	//split parent

	}
}

bool BpTree::excessDataNode(BpTreeNode* pDataNode) {
	if (pDataNode->getDataMap()->size() > order - 1) return true;//order is equal to the number of elements 
	else return false;
}

bool BpTree::excessIndexNode(BpTreeNode* pIndexNode) {
	if (pIndexNode->getIndexMap()->size() > order - 1)return true;//order is equal to the number of elements 
	else return false;
}

bool BpTree::printFrequency(string item, int min_frequency)//print winratio in ascending order
{
	//similar print function each other
	if (root == NULL)
		return false;
	BpTreeNode* search = searchDataNode(min_frequency);
	map<int, FrequentPatternNode*>* d_map = search->getDataMap();
	auto temp = d_map->begin();
	FrequentPatternNode* fp = NULL;

	if (d_map->find(min_frequency) == d_map->end())
		return false;
	else
	{
		cout << "StandardItem	FrequentPatternFrequency" << endl;
		while (true)
		{
			temp = d_map->begin();
			while (temp != d_map->end())
			{
				if (temp->first < min_frequency)
				{
					temp++;
					continue;
				}
				fp = temp->second;
				multimap<int, set<string> > mm = fp->getList();
				set<string> cur;
				auto check = mm.begin();
				while (check != mm.end())
				{
					cur = check->second;
					if (cur.find(item) != cur.end())
					{
						cout << item << " -> ";
						printFrequentPatterns(cur, item);
						cout << " " << fp->getFrequency() << endl;
					}
					check++;
				}
				temp++;
			}
			search = search->getNext();
			if (search == NULL)
				break;
			d_map = search->getDataMap();
		}
	}
	return true;
}


void BpTree::printFrequentPatterns(set<string> pFrequentPattern, string item) {
	cout << "{";
	set<string> curPattern = pFrequentPattern;
	curPattern.erase(item);
	for (set<string>::iterator it = curPattern.begin(); it != curPattern.end();) {
		string temp = *it++;
		if (temp != item) cout << temp;
		if (it == curPattern.end()) {
			cout << "} ";
			break;
		}
		cout << ", ";
	}
}

int main(void)
{
	BpTree* bptree = new BpTree;
	char read_line[1000];		//file line
	int fre;

	ifstream result;
	result.open("result.txt");	//read file
	if (!result)
	{
		cout << "open fale" << endl;	//testcase error
		return false;
	}
	if (bptree->getRoot() != NULL)
	{
		cout << "error" << endl;		//bptree is not empty
		return false;
	}

	while (!result.eof())	//file is eof break
	{
		result.getline(read_line, 1000);	//get one line
		if (read_line[0] == 0)
			break;

		set<string>input_set;	//data set
		char* temp = strtok(read_line, "	");
		fre = atoi(temp);		//get frequency
		while (1)				//make data set
		{
			char* temp = strtok(NULL, "	");
			if (temp == NULL)
				break;
			input_set.insert(temp);
		}
		bptree->Insert(fre, input_set);	//insert to bptree
	}
	bptree->printFrequency("soup", 2);
	return 0;
}