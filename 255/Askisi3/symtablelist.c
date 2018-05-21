/* Karathanasis Dimitris 3547
Ask3
symtablelist.c */

 
#include "symtable.h"

typedef struct Node { 
        char *key;                                                              
        void *data;
        struct Node *next;
        }Node_S,*Node_T;
         
struct SymTable {
        unsigned int num_of_bindings;                                                                               
        Node_T head;              
        };                             

SymTable_T SymTable_new(void)
{
  SymTable_T symtable;                           
  symtable=(SymTable_T )malloc(sizeof(SymTable_T));
  assert(symtable != NULL);
  symtable->num_of_bindings=0U;
  Node_T newnode=(Node_S *)malloc(sizeof(Node_S));
  assert(newnode!= NULL);
  newnode->key=NULL;
  newnode->data=NULL;
  newnode->next=NULL;
  symtable->head=newnode;
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
    Node_T i=oSymTable->head;
    if(i->key == NULL)
    {
      i->key=malloc((strlen(pcKey) + 1)*sizeof(char));
      assert(i->key != NULL);
      strcpy(i->key,pcKey);
      i->data=(void *) pvValue;
      oSymTable->num_of_bindings++;
      return 1;
    }
    while(1)
    {
    if(strcmp(i->key, pcKey) == 0)
    return 0;
    if(i->next == NULL)
    break;
    i=i->next;
    }
    Node_T newnode=(Node_S *)malloc(sizeof(Node_S));
    assert(newnode != NULL);
    newnode->key=malloc((strlen(pcKey) + 1)*sizeof(char));
    strcpy(newnode->key,pcKey);
    newnode->data=(void *) pvValue;
    newnode->next=NULL;
    i->next=newnode;
    oSymTable->num_of_bindings++;
    return 1;
  }
             
int SymTable_remove(SymTable_T oSymTable, const char *pcKey)
{
  assert(oSymTable != NULL);
  assert(pcKey != NULL);
  Node_T i=oSymTable->head;
  if(i->key == NULL)
    return 0;
  if(strcmp(i->key, pcKey) == 0)
  {
    free(oSymTable->head);                        
    oSymTable->head=oSymTable->head->next;
    oSymTable->num_of_bindings--;
    return 1;
    }
    while(1)
    {
      if(i->next==NULL)
      return 0;
      if(strcmp(i->next->key, pcKey) == 0)
      {

        free(i->next); 
        i->next=i->next->next;                   
        oSymTable->num_of_bindings--;
        return 1;                         
      }
      i=i->next;
    }                          
  }
             
int SymTable_contains(SymTable_T oSymTable, const char *pcKey)
{
  assert(oSymTable != NULL);
  assert(pcKey != NULL);
  Node_T i=oSymTable->head;
  //Empty List.
  if(i->key == NULL)
    return 0;
  while(1)
  { 
    if(strcmp(i->key, pcKey) == 0)
      return 1;
    if(i->next == NULL)
      return 0;
    i=i->next;
  }
}             
             
void* SymTable_get(SymTable_T oSymTable, const char *pcKey)
{
  assert(oSymTable != NULL);
  assert(pcKey != NULL);
  Node_T i=oSymTable->head;
  if(i->key == NULL) return 0;
      while(1)
      {
        if(strcmp(i->key, pcKey) == 0) return i->data;
        
        if(i->next == NULL) return NULL;
        i=i->next;
      }
      } 

void SymTable_map(SymTable_T oSymTable,void (*pfApply)
                  (const char *pcKey, void *pvValue, void *pvExtra),const void *pvExtra)
{
  assert(oSymTable != NULL);
  assert(pfApply != NULL);
  Node_T i=oSymTable->head;
  if(i->key == NULL) return; 
  while(1)
      {

        pfApply(i->key, i->data,(void *) pvExtra);
        if(i->next == NULL) return;
        i=i->next;
      }        
}    
             
             
             
             
             
             
             
             
             
             
             
             
