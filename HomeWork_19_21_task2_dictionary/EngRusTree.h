#pragma once
#include <iostream>
#include "MyString.h"


struct Translation
{
	MyString english;
	MyString russian;
};

class EngRusTree
{
private:
	struct Node
	{
		Translation data;
		Node* right, * left;

		Node(Translation& data, Node* right = nullptr, Node* left = nullptr) :
			data{ data }, right{ right }, left{ left } {}

	};

	Node* root;
	int count;

	void add(Node*& node, Translation& data);
	void delete_sub_my_tree(Node* node);
	void show(Node* node)const;
	Node* search(Node* node, const MyString& data)const;
	void save_to_txt(Node* node, FILE* file)const;
	void save_to_bin(Node* node, FILE* file)const;
	MyString get_data(Node* node, MyString data)const;
public:

	EngRusTree();

	bool add(Translation& data);
	void show()const;
	bool save_to_txt(FILE* file)const;
	bool save_to_bin(FILE* file);
	bool read_from_bin(FILE* file);
	bool search(const MyString& data)const;
	MyString get_translation(const MyString& str_eng)const;
	

	int get_count()const { return count; }

	~EngRusTree();



};