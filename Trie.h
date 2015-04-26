#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 
#define ALPHABET_SIZE (26)
#define INDEX(c) ((int)c - (int)'a')
 
// #define FREE(p)
//     free(p);    
//     p = NULL;


typedef struct trie_node trie_node_t;

struct trie_node
{
    int value;
    trie_node_t *children[ALPHABET_SIZE];
};

typedef struct trie trie_t;
struct trie
{
    trie_node_t *root;
    int count;
};

class Trie
{
	public:
		Trie();
		~Trie();		
		trie_node_t *getNode(void);
		void initialize(trie_t *pTrie);
		void insert(trie_t *pTrie, char key[]);
		int search(trie_t *pTrie, char key[]);
		int leafNode(trie_node_t *pNode);
		int isItFreeNode(trie_node_t *pNode);
		bool deleteHelper(trie_node_t *pNode, char key[], int level, int len);
		void deleteKey(trie_t *pTrie, char key[]);


};

#endif