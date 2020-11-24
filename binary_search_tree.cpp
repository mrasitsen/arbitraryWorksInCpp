#include <iostream>

/*binary search tree yapar. class seklinde degildir. sadece tek list vardir.*/

using namespace std;

struct BinaryTree{

	int value;
	BinaryTree *leftChild;
	BinaryTree *rightChild;
	//BinaryTree *parent;
};

BinaryTree *root = NULL;

void insertTree(int data){

	if (root == NULL) //root empty olursa, ilk insertion
	{
		root = new BinaryTree;
		root->value = data;
		root->leftChild = NULL;
		root->rightChild = NULL;
	}
	else
	{
		BinaryTree *track;
		track = root;

		while(track != NULL)
		{
			if (data < track->value)
			{
				if (track->leftChild == NULL)
				{
					BinaryTree *instance;
					instance = new BinaryTree;
					instance->value = data;
					instance->leftChild = NULL;
					instance->rightChild = NULL;
					track->leftChild = instance;
					break;
				}
				track = track->leftChild;
			}
			else
			{
				if (track->rightChild == NULL)
				{
					BinaryTree *instance;
					instance = new BinaryTree;
					instance->value = data;
					instance->leftChild = NULL;
					instance->rightChild = NULL;
					track->rightChild = instance;
					break;
				}
				track = track->rightChild;
			}
		}
	}
}



void traverse(BinaryTree *instant){

	if (instant == NULL)
	{
		return;
	}
	else
	{
		cout<<instant->value<<" ";
		//cout<<" --left--> ";
		//cout<<" "
		traverse(instant->leftChild);
		//cout<<" --right--> ";
		traverse(instant->rightChild);
	}

}

int main(){

	insertTree(3);
	insertTree(2);
	insertTree(1);
	insertTree(4);
	insertTree(5);
	traverse(root);


}
