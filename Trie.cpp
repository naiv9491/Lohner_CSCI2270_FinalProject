#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"

using namespace std;
 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// Alphabet size (# of symbols)
 
#define ALPHABET_SIZE (26)
#define INDEX(c) ((int)c - (int)'a')
 
#define FREE(p)
    free(p);    
    p = NULL;

Trie::~Trie() {
}

Trie::getNode(){
	
}