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

void Trie::insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pTrie->count++;
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);
 
        if( pCrawl->children[index] )
        {
            // Skip current node
            pCrawl = pCrawl->children[index];
        }
        else
        {
            // Add new node
            pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
        }
    }
 
    // mark last node as leaf (non zero)
    pCrawl->value = pTrie->count;
}

int Trie::search(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);
 
        if( !pCrawl->children[index] )
        {
            return 0;
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    return (0 != pCrawl && pCrawl->value);
}
 
int Trie::leafNode(trie_node_t *pNode)
{
    return (pNode->value != 0);
}
 
int Trie::isItFreeNode(trie_node_t *pNode)
{
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++)
    {
        if( pNode->children[i] )
            return 0;
    }
 
    return 1;
}

bool Trie::deleteHelper(trie_node_t *pNode, char key[], int level, int len)
{
    if( pNode )
    {
        // Base case
        if( level == len )
        {
            if( pNode->value )
            {
                // Unmark leaf node
                pNode->value = 0;
 
                // If empty, node to be deleted
                if( isItFreeNode(pNode) )
                {
                    return true;
                }
 
                return false;
            }
        }
        else // Recursive case
        {
            int index = INDEX(key[level]);
 
            if( deleteHelper(pNode->children[index], key, level+1, len) )
            {
                // last node marked, delete it
                FREE(pNode->children[index]);
 
                // recursively climb up, and delete eligible nodes
                return ( !leafNode(pNode) && isItFreeNode(pNode) );
            }
        }
    }
 
    return false;
}
 
void Trie::deleteKey(trie_t *pTrie, char key[])
{
    int len = strlen(key);
 
    if( len > 0 )
    {
        deleteHelper(pTrie->root, key, 0, len);
    }
}