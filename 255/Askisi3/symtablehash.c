/* Karathanasis Dimitris 3547
Ask3
symtablehash.c */


#include "symtable.h"


#define HASH_MULTIPLIER 65599
#define SIZE 509

typedef struct Node { 
        char *key;                                                             
        void *data;
        }Node_S,*Node_T;
         
struct SymTable {
        unsigned int num_of_bindings;                                                                               
        Node_T head[SIZE];              
        };  
             
/* Return a hash code for pcKey. */
static unsigned int SymTable_hash(const char *pcKey)
{
  size_t ui;
  unsigned int uiHash = 0U;
  for (ui = 0U; pcKey[ui] != '\0'; ui++)
    uiHash =( uiHash * HASH_MULTIPLIER + pcKey[ui]);                            
  return uiHash;
}

SymTable_T   SymTable_new(void)
{

  SymTable_T symtable;                           
  symtable=(SymTable_T)malloc(sizeof(SymTable_T));                 
  assert(symtable != NULL);
  symtable->num_of_bindings=0U;
  Node_T newnode=(Node_S *)malloc(sizeof(Node_S));
  assert(newnode!= NULL);
  newnode->key=NULL;
  newnode->data=NULL;
  int i;
  for(i=0; i<509; i++)
    symtable->head[i]=newnode;
  return symtable;
}

void SymTable_free(SymTable_T oSymTable)
{
  if(oSymTable != NULL)
    free(oSymTable);
  return;
}
             
unsigned int SymTable_getLength(SymTable_T oSymTable)
{
  assert(oSymTable != NULL);
  return oSymTable->num_of_bindings;
}

int SymTable_put(SymTable_T oSymTable, const char *pcKey,const void *pvValue)
{
  assert(oSymTable != NULL);
  assert(pcKey != NULL);
  unsigned int hash_number=SymTable_hash(pcKey);
  int i;
  for(i=0; i<509; i++)
  
{    if(strcmp(oSymTable->head[i]->key , pcKey ) == 0)
      return 0;
  }
  Node_T newnode=(Node_S *)malloc(sizeof(Node_S));
  assert(newnode != NULL);
  newnode->key=malloc((strlen(pcKey) + 1)*sizeof(char));
  strcpy(newnode->key,pcKey);
  newnode->data=(void *) pvValue;
  oSymTable->head[hash_number]=newnode;
  oSymTable->num_of_bindings++;
  return 1;
}

int SymTable_remove(SymTable_T oSymTable, const char *pcKey)
{
  assert(oSymTable != NULL);
  assert(pcKey != NULL);
  int i;
  for(i=0; i<509; i++)
  {
    if(strcmp(oSymTable->head[i]->key , pcKey ) == 0)
      oSymTable->head[i]->key=NULL;
      oSymTable->head[i]->data=NULL;
      oSymTable->num_of_bindings--;
      return 1;
    }
    return 0;
  }

int SymTable_contains(SymTable_T oSymTable, const char *pcKey)
{
  assert(oSymTable != NULL);
  assert(pcKey != NULL);
  int i;
  for(i=0; i<509; i++)
  {
    if(strcmp(oSymTable->head[i]->key , pcKey ) == 0)
      return 1;
  }
  return 0;
}     

void* SymTable_get(SymTable_T oSymTable, const char *pcKey)
{
  assert(oSymTable != NULL);
  assert(pcKey != NULL);
  int i;
  for(i=0; i<509; i++)
  {
    if(strcmp(oSymTable->head[i]->key , pcKey ) == 0)
      return oSymTable->head[i]->data;
  }
  return NULL;   
  } 

void  SymTable_map(SymTable_T oSymTable,void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),const void *pvExtra)
{
  assert(oSymTable != NULL);
  assert(pfApply != NULL);
  int i;
  for(i=0; i<509; i++)
           pfApply(oSymTable->head[i]->key, oSymTable->head[i]->data,(void *) pvExtra);
}








