#pragma once
#include <iostream>



class MyBinTree
{
private:
	struct Node
	{
		int data;
		Node* right, * left;

		Node(const int& data, Node* right = nullptr, Node* left = nullptr) :
			data{ data }, right{ right }, left{ left } {}

	};

	Node* root;
	int count;

	void add(Node*& node, const int& data);
	void delete_sub_my_tree(Node* node);
	void show(Node* node)const;
	Node* search(Node* node, const int& data)const;
	void save_to_txt(Node* node, FILE* file)const;
	void save_to_bin(Node* node, FILE* file)const;
	/*void read_from_bin_file(FILE* file);*/
public:
	MyBinTree();

	void add(const int& val);
	void show()const;
	void save_to_txt(FILE* file)const;
	void save_to_bin(FILE* file);
	void read_from_bin(FILE* file);
	bool search(const int& data)const;

	int get_count()const { return count; }

	~MyBinTree();



};