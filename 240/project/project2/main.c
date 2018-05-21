/************************************************************//**
 * @file   main.c                                      		*
 * @author Nikolaos Batsaras <batsaras@csd.uoc.gr>  		*
 *                                                    		*
 * @brief Main function for the needs of cs-240b project 2017   *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "troy.h"

#define BUFFER_SIZE 1024  /**< Maximum length of a line in input file */

/* Uncomment the following line to enable debugging prints 
 * or comment to disable it */
#define DEBUG

#ifdef DEBUG
#define DPRINT(...) fprintf(stderr, __VA_ARGS__);
#else  /* DEBUG */
#define DPRINT(...)
#endif /* DEBUG */

typedef struct c_soldier c_soldier;
typedef struct general general;
typedef struct TREE_soldier TREE_soldier;
typedef struct soldier soldier;
typedef struct combat combat;

int cntAxilleas = 0;
int cntPatroklos = 0;


//print TREE
void InOrder(TREE_soldier *root){ 

    if(root == NULL) return;

    InOrder(root->lc);
    if (root->sid != -1) {printf("<%d>, ", root->sid);}
    InOrder(root->rc);
}

void InOrderArrayPatroklos(TREE_soldier *root, int *array){

    if(root==NULL) return;

    InOrderArrayPatroklos(root->lc, array);
    if (root->sid != -1) {
        array[cntPatroklos++] = root->sid;
    }
    InOrderArrayPatroklos(root->rc, array);
}

void InOrderArrayAxilleas(TREE_soldier *root, int *array){

    if(root==NULL) return;

    InOrderArrayAxilleas(root->lc, array);
    if (root->sid != -1) {
        array[cntAxilleas++] = root->sid;
    }
    InOrderArrayAxilleas(root->rc, array);
}


TREE_soldier *minValue(TREE_soldier *node){

    TREE_soldier *curr = node;

    while(curr->lc->sid != -1){
        curr = curr->lc;
    }
    return curr;
}

TREE_soldier *maxValue(TREE_soldier *node){

    TREE_soldier *curr = node;
    while(curr->rc->sid != -1)
        curr = curr->rc;

    return curr;
}

TREE_soldier *inorderSuccessor(TREE_soldier *root, TREE_soldier *node){

    TREE_soldier *p;

    switch(node->rc->sid){

        case (-1):

        p = node->p;

        while(p!=NULL && node == p->rc){
            node = p;
            p = p->p;
        }
        return p;

        default:

        return minValue(node->rc);
    }
}

TREE_soldier *inorderPredeccesor(TREE_soldier *root, TREE_soldier *node){

    TREE_soldier *p;

    switch(node->lc->sid){

        case (-1):

        p = node->p;

        while(p!=NULL && node == p->lc){
            node = p;
            p = p->p;
        }
        return p;

        default:

        return maxValue(node->lc);
    }
}


void InOrderPrintCombat(c_soldier *root){

    if(root==NULL) return;

    InOrderPrintCombat(root->lc);
    printf("<%d>, ", root->sid );
    InOrderPrintCombat(root->rc);
}

int findNextPrime(){

    int number = max_soldiers_g/5;
    int found = 0;

    while(!found){
        number++;
        if(isPrime(number))
            found = 1;
    }
    return number;
}

int isPrime(int number){

    int i;

    for(i=2; i<=number/2; i++){
        if(number%i==0)
            return 0;
    }
    return 1;
}

int hashCode(int key){

    return (key % findNextPrime());
}

void htCreate(){

    int size = findNextPrime();
    int i;
    if(size<1) return;

    registration_hashtable = (soldier**) malloc(sizeof(soldier*) * size);

    for(i=0; i<size; i++){
        registration_hashtable[i] = NULL;
    }
}


void insertToCombat(c_soldier *root, int sid, int gid){

    c_soldier *TEMP = root;

    c_soldier* newnode = (c_soldier*) malloc(sizeof(c_soldier));

    newnode->sid = sid;
    newnode->gid = gid;
    newnode->alive = 1;
    newnode->lc = NULL;
    newnode->rc = NULL;
    newnode->left_cnt = 0;

    while(1){

        if(sid<TEMP->sid && TEMP->lc == NULL){
            TEMP->left_cnt++;
            TEMP->lc = newnode;
            break;
        }
        else if(sid>TEMP->sid && TEMP->rc == NULL){
            TEMP->rc = newnode;
            break;
        }
        else if(sid<TEMP->sid && TEMP->lc != NULL){
            TEMP = TEMP->lc;
        }
        else if(sid>TEMP->sid && TEMP->rc != NULL){
            TEMP = TEMP->rc;
        }
    }

    my_combat.soldier_cnt++;
    return;
}


void insertNode(general *tempGeneral, int sid){

    int c;

    general *TEMP  = tempGeneral;
    TREE_soldier *newnode = (TREE_soldier*) malloc(sizeof(TREE_soldier));
    newnode->sid = sid;
    newnode->lc = TEMP->soldiers_S;
    newnode->rc = TEMP->soldiers_S;

    if(TEMP->soldiers_R == NULL){
        TEMP->soldiers_R = newnode;
        newnode->p = NULL;
        //InOrder(TEMP->soldiers_R);
    }
    else{

        TREE_soldier * node;
        node = TEMP->soldiers_R;
        
        while(1){

            if(sid<node->sid && node->lc == TEMP->soldiers_S){

                newnode->p = node;
                node->lc = newnode;

                break;
            }
            else if(sid>node->sid && node->rc == TEMP->soldiers_S ){
                newnode->p = node;
                node->rc = newnode;

                break;
            }
            else if(sid<node->sid && node->lc != TEMP->soldiers_S){
                node = node->lc;

            }
            else if(sid>node->sid && node->rc != TEMP->soldiers_S ){
                node = node->rc;

            }
        }
    }
    return;
}


void insertToGeneralTree(int sid, int gid){

    general *tempGeneral;
    tempGeneral = generals_list;

    while(tempGeneral->gid != gid){
        tempGeneral = tempGeneral->next;
    }
    tempGeneral->soldiers_no++;

    insertNode(tempGeneral, sid);

    return;
}





/**
 * @brief Optional function to initialize data structures that 
 * need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize() {
    htCreate();
    return 1;
}

/**
 * @brief Register soldier
 *
 * @param sid The soldier's id
 * @param gid The general's id who orders the soldier
 *
 * @return 1 on success
 *         0 on failure
 */
int register_soldier(int sid, int gid) {

    int value;
    value = hashCode(sid);
    soldier *temp;
    
    soldier *newnode = (soldier*) malloc(sizeof(soldier));
    newnode->sid = sid;
    newnode->gid = gid;
    newnode->next = NULL;
    if(registration_hashtable[value] == NULL){
        registration_hashtable[value] = newnode;
    }
    else{
        temp = registration_hashtable[value];
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return 1;
}

/**
 * @brief General or King joins the battlefield
 *
 * @param gid The general's id
 *
 * @return 1 on success
 *         0 on failure
 */
int add_general(int gid) {

    TREE_soldier *newnodeTree = (TREE_soldier*) malloc(sizeof(TREE_soldier));
    newnodeTree->sid = -1;
    newnodeTree->p = NULL;
    newnodeTree->rc = NULL;
    newnodeTree->lc = NULL;

    general *newnode = (general*) malloc(sizeof(general));    newnode->gid = gid;
    newnode->combats_no = 0;
    newnode->soldiers_no = 0;
    newnode->soldiers_R = NULL;
    newnode->soldiers_S = newnodeTree;

    if(generals_list == NULL){
        generals_list = newnode;
        newnode->next = NULL;
    }
    else{
        newnode->next = generals_list;
        generals_list = newnode;
    }
    return 1;
}


/**
 * @brief Distribute soldiers to the camps
 * 
 * @return 1 on success
 *         0 on failure
 */
int distribute() {

    soldier *temp;
    general *tempGeneral;

    int i,c;
    int size = findNextPrime();

    for(i=0; i<size; i++){
        temp = registration_hashtable[i];

        while(temp!=NULL){

            insertToGeneralTree(temp->sid, temp->gid);
            temp = temp->next;
        }
    }

    tempGeneral = generals_list;
    printf("\n\tGENERALS:");
    while(tempGeneral != NULL){
        printf("\n\t<%d>: ", tempGeneral->gid );
        InOrder(tempGeneral->soldiers_R);
        tempGeneral = tempGeneral->next;
    }
    return 1;
}

/**
 * @brief General resigns from battlefield
 *
 * @param gid1 The id of general that resigns
 * @param gid2 The id of the general that will  
 * 
 * @return 1 on success
 *         0 on failure
 */
int general_resign(int gid1, int gid2) {

    general *tempAXILLEAS = generals_list;
    general *tempPATROKLOS = generals_list;
    general *tempGeneral;

    int patroklosArray[tempPATROKLOS->soldiers_no];
    int axilleasArray[tempAXILLEAS->soldiers_no];

    int i, j, k, c;
    int size3 = tempAXILLEAS->soldiers_no + tempPATROKLOS->soldiers_no;

    int array3[size3];

    while(tempAXILLEAS->gid != gid1){
        tempAXILLEAS = tempAXILLEAS->next;
    }
    while(tempPATROKLOS->gid != gid2){
        tempPATROKLOS = tempPATROKLOS->next;
    }

    TREE_soldier *axilleasRoot = tempAXILLEAS->soldiers_R;
    TREE_soldier *patroklosRoot = tempPATROKLOS->soldiers_R;


    InOrderArrayAxilleas(axilleasRoot, axilleasArray);
    InOrderArrayPatroklos(patroklosRoot, patroklosArray);

    i=0;
    j=0;
    k=0;

    while(i<tempAXILLEAS->soldiers_no && j<tempPATROKLOS->soldiers_no){
        if(axilleasArray[i] < patroklosArray[j]){
            array3[k] = axilleasArray[i];
            i++;
        }
        else{
            array3[k] = patroklosArray[j];
            j++;
        }
        k++;
    }

    if(i>=tempAXILLEAS->soldiers_no){
        while(j<tempPATROKLOS->soldiers_no){
            array3[k] = patroklosArray[j];
            j++;
            k++;
        }
    }


    if(j>=tempPATROKLOS->soldiers_no){
        while(i<tempAXILLEAS->soldiers_no){
            array3[k] = axilleasArray[i];
            i++;
            k++;
        }
    }


    tempAXILLEAS->soldiers_R = NULL;
    tempPATROKLOS->soldiers_R = NULL;


    for(i=0; i<size3; i++){
        insertNode(tempPATROKLOS, array3[i]);
    }

    tempGeneral = generals_list;
    printf("\n\tGENERALS:");
    while(tempGeneral != NULL){
        printf("\n\t<%d>: ", tempGeneral->gid );
        InOrder(tempGeneral->soldiers_R);
        tempGeneral = tempGeneral->next;
    }
    printf("\n");

    return 1;
}

/**
 * @brief Prepare for battle
 * 
 * @param gid1 The id of the first general
 * @param gid2 The id of the second general
 * 
 * @return 1 on success
 *         0 on failure
 */
int prepare_battle(int gid1, int gid2) {

    general *tempGeneral1 = generals_list;
    general *tempGeneral2 = generals_list;
    TREE_soldier *tempTree1;
    TREE_soldier *tempTree2;

    c_soldier *tempPrint;


    int s1, s2, c, i;

    int flag = 1;

    while(tempGeneral1->gid != gid1){
        tempGeneral1 = tempGeneral1->next;
    }
    while(tempGeneral2->gid != gid2){
        tempGeneral2 = tempGeneral2->next;
    }

    tempGeneral1->combats_no++;
    tempGeneral2->combats_no++;

    tempTree1 = tempGeneral1->soldiers_R;
    tempTree2 = tempGeneral2->soldiers_R;

    //mikroteros toy gid1
    while(tempTree1->lc->sid != -1){
        tempTree1 = tempTree1->lc;
    }

    //megalyteros toy gid2
    while(tempTree2->rc->sid != -1){
        tempTree2 = tempTree2->rc;
    }

    s1 = tempGeneral1->soldiers_no;
    s2 = tempGeneral2->soldiers_no;
    s1--;

    
    c_soldier* newnode = (c_soldier*) malloc(sizeof(c_soldier));

    newnode->sid = tempTree1->sid;
    newnode->gid = tempGeneral1->gid;
    newnode->alive = 1;
    newnode->left_cnt = 0;
    newnode->lc = NULL;
    newnode->rc = NULL;

    my_combat.soldier_cnt = 1;
    my_combat.combat_s = newnode;

    while(s1 != 0 || s2 != 0){

        switch(flag){

            case(0):

            if (s1 <= 0) {
                flag = 1;
                break;
            }

            tempTree1 = inorderSuccessor(tempGeneral1->soldiers_R, tempTree1);
            insertToCombat(my_combat.combat_s, tempTree1->sid, gid1);

            s1--;
            flag = 1;


            case(1):

            if (s2 <= 0) {
                flag = 0;
                break;
            }

            insertToCombat(my_combat.combat_s, tempTree2->sid, gid2);
            tempTree2 = inorderPredeccesor(tempGeneral2->soldiers_R, tempTree2);

            s2--;
            flag = 0;
        }
    }

    tempPrint = my_combat.combat_s;

    printf("\n\tCombat soldiers: ");
    InOrderPrintCombat(tempPrint);
    printf("\n");
    return 1;
}

/**
 * @brief Battle
 * 
 * @param god_favor
 * @param bit_stream A sequence of bits
 * @param bitsno The number of bits in the sequence
 *
 * @return 1 on success
 *         0 on failure
 */
int battle(int god_favor, char *bit_stream, int bitsno) {

/*    int dead;
    c_soldier *temp, *prev;
    int flag;

    switch(god_favor){

        case(0):
        dead = (int) my_combat.soldier_cnt * 0.4;
        temp = my_combat.combat_s;

        while(dead > 0){

            while(1){
                
                if(temp->rc == NULL && temp->lc == NULL){
                    if(flag){
                        prev->lc == NULL;
                        break;
                    }
                    else{
                        prev->rc == NULL;
                        break;
                    }
                }
                
                if(temp->rc != NULL && temp->lc != NULL){
                    prev = temp;
                    temp = temp->rc;
                    flag = 0;
                }
                
                if(temp->rc == NULL){
                    prev = temp;
                    temp = temp->lc;
                    flag = 1;
                }
                
                if(temp->lc == NULL){
                    prev = temp;
                    temp = temp->rc;
                    flag = 0;
                }
            }

            dead--;
            temp = my_combat.combat_s;
        }

        my_combat.combat_s = temp;

        InOrderPrintCombat(my_combat.combat_s);


        case(1):

        break;


    }*/
    return 1;
}

/**
 * @brief Cease fire
 * 
 * @return 1 on success
 *         0 on failure
 */
int cease_fire() {
    return 1;
}

/**
 * @brief Print general's soldiers
 *
 * @param gid The id of the general
 *
 * @return 1 on success
 *         0 on failure
 */


int print_generals_soldiers(int gid) {

    general *tempGeneral;
    tempGeneral = generals_list;

    printf("\n\tSoldier tree = ");
    while(tempGeneral->gid!=gid){
        tempGeneral = tempGeneral->next;
    }

    InOrder(tempGeneral->soldiers_R);
    return 1;
}



/**
 * @brief Print generals
 *
 * @return 1 on success
 *         0 on failure
 */
int print_generals() {

    general *tempGeneral = generals_list;

    printf("\n\tGENERALS: \n");

    while(tempGeneral != NULL){
        printf("\t<%d>: ", tempGeneral->gid );
        InOrder(tempGeneral->soldiers_R);
        tempGeneral = tempGeneral->next;
        printf("\n");
    }

    printf("\nDONE\n");
    return 1;
}

/**
 * @brief Print registration hashtable
 *
 * @return 1 on success
 *         0 on failure
 */
int print_registration_hashtable() {

    int i;
    int size = findNextPrime();
    soldier *temp;

    printf("\n\tSoldiers Hash Table:\n\t");
    for(i=0; i<size; i++){
        temp = registration_hashtable[i];
        printf("%d = ", i  );
        while(temp!=NULL){
            printf("<%d:%d>, ", temp->sid, temp->gid);
            temp = temp->next;
        }
        printf("\n\t");
    }
    printf("DONE\n");
    return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */
int free_world() {
    return 1;
}


/**
 * @brief The main function
 *
 * @param argc Number of arguments
 * @param argv Argument vector
 *
 * @return 0 on success
 *         1 on failure
 */
int main(int argc, char** argv)
{
    FILE *fin = NULL;
    char buff[BUFFER_SIZE], event;

    /* Check command buff arguments */
    if ( argc != 2 ) {
        fprintf(stderr, "Usage: %s <input_file> \n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open input file */
    if (( fin = fopen(argv[1], "r") ) == NULL ) {
        fprintf(stderr, "\n Could not open file: %s\n", argv[1]);
        perror("Opening test file\n");
        return EXIT_FAILURE;
    }

    /* Read input file buff-by-buff and handle the events */
    while ( fgets(buff, BUFFER_SIZE, fin) ) {

        DPRINT("\n>>> Event: %s", buff);

        switch(buff[0]) {

            /* Comment */
            case '#':
            break;

                /* Maximum soldiers */
            case '0':
            {
                sscanf(buff, "%c %d", &event, &max_soldiers_g);
                DPRINT("%c %d\n", event, max_soldiers_g);

                initialize();

                break;
            }

                /* Register soldier
                 * R <sid> <gid> */
            case 'R':
            {
                int sid, gid;

                sscanf(buff, "%c %d %d", &event, &sid, &gid);
                DPRINT("%c %d %d\n", event, sid, gid);

                if ( register_soldier(sid, gid) ) {
                    DPRINT("R %d %d succeeded\n", sid, gid);
                } else {
                    fprintf(stderr, "R %d %d failed\n", sid, gid);
                }

                break;
            }

                /* General or king joins the battlefield
                 * G <gid> */
            case 'G':
            {
                int gid;

                sscanf(buff, "%c %d", &event, &gid);
                DPRINT("%c %d\n", event, gid);

                if ( add_general(gid) ) {
                    DPRINT("%c %d succeeded\n", event, gid);
                } else {
                    fprintf(stderr, "%c %d failed\n", event, gid);
                }

                break;
            }

                /* Distribute soldier
                 * D */
            case 'D':
            {
                sscanf(buff, "%c", &event);
                DPRINT("%c\n", event);

                if ( distribute() ) {
                    DPRINT("%c succeeded\n", event);
                } else {
                    fprintf(stderr, "%c failed\n", event);
                }

                break;
            }

                /* General resigns from battle
                 * M <gid1> <gid2> */
            case 'M':
            {
                int gid1, gid2;

                sscanf(buff, "%c %d %d", &event, &gid1, &gid2);
                DPRINT("%c %d %d\n", event, gid1, gid2);

                if ( general_resign(gid1, gid2) ) {
                    DPRINT("%c %d %d succeeded\n", event, gid1, gid2);
                } else {
                    fprintf(stderr, "%c %d %d failed\n", event, gid1, gid2);
                }

                break;
            }

                /* Prepare for battle
                 * P <gid1> <gid2> */
            case 'P':
            {
                int gid1, gid2;
                sscanf(buff, "%c %d %d", &event, &gid1, &gid2);
                DPRINT("%c %d %d\n", event, gid1, gid2);

                if ( prepare_battle(gid1, gid2) ) {
                    DPRINT("%c %d %d succeeded\n", event, gid1, gid2);
                } else {
                    fprintf(stderr, "%c %d %d failed\n", event, gid1, gid2);
                }

                break;
            }

                /* Battle
                 * B <god_favor> <bit_stream> */
            case 'B':
            {
                int god_favor;
                char bit_stream[9];

                sscanf(buff, "%c %d %s\n", &event, &god_favor, bit_stream);
                DPRINT("%c %d %s\n", event, god_favor, bit_stream);

                if ( battle(god_favor, bit_stream, 8) ) {
                    DPRINT("%c %d %s succeeded\n", event, god_favor, bit_stream);
                } else {
                    fprintf(stderr, "%c %d %s failed\n", event, god_favor, bit_stream);
                }

                break;
            }

                /* Cease fire
                 * U */
            case 'U':
            {
                sscanf(buff, "%c", &event);
                DPRINT("%c\n", event);

                if ( cease_fire() ) {
                    DPRINT("%c succeeded\n", event);
                } else {
                    fprintf(stderr, "%c failed\n", event);
                }

                break;
            }

                /* Print general's soldiers
                 * W <gid> */
            case 'W':
            {
                int gid;

                sscanf(buff, "%c %d", &event, &gid);
                DPRINT("%c %d\n", event, gid);

                if ( print_generals_soldiers(gid) ) {
                    DPRINT("%c %d succeeded\n", event, gid);
                } else {
                    fprintf(stderr, "%c %d failed\n", event, gid);
                }

                break;
            }

                /* Print generals
                 * X */
            case 'X':
            {
                sscanf(buff, "%c", &event);
                DPRINT("%c\n", event);

                if ( print_generals() ) {
                    DPRINT("%c succeeded\n", event);
                } else {
                    fprintf(stderr, "%c failed\n", event);
                }

                break;
            }

                /* Print registration hashtable
                 * Y */
            case 'Y':
            {
                sscanf(buff, "%c", &event);
                DPRINT("%c\n", event);

                if ( print_registration_hashtable() ) {
                    DPRINT("%c succeeded\n", event);
                } else {
                    fprintf(stderr, "%c failed\n", event);
                }

                break;
            }

                /* Empty line */
            case '\n':
            break;

                /* Ignore everything else */
            default:
            DPRINT("Ignoring buff: %s \n", buff);

            break;
        }
    }

    free_world();
    return (EXIT_SUCCESS);
}
