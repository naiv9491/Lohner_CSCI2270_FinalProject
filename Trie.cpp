#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"

using namespace std;
 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 
#define ALPHABET_SIZE (26)
#define INDEX(c) ((int)c - (int)'a')
 
#define FREE(p)
    free(p);    
    p = NULL;

Trie::~Trie() {
}

Trie::getNode(){
	trie_node_t *pNode = NULL;
    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));
 
    if(pNode)
    {
        int i;
        pNode->value   = 0;
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }
    return pNode;
}

void Trie::initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}