/************************************************************//**
 * @file   main.c                                      			*
 * @author Antonis Papaioannou <papaioan@csd.uoc.gr>  			*
 *                                                    			*
 * @brief Header function for the needs of cs-240a project 2017 *
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

typedef struct soldier soldier;
typedef struct DDL_soldier DDL_soldier;
typedef struct general general;
typedef struct c_soldier c_soldier;
typedef struct combat combat;

void printCombat(){

	int i;
	c_soldier *temp = my_combat.combat_s;

	printf("\tCombat soldiers: ");
	for(i=0; i<my_combat.soldier_cnt; i++){
		if(temp->alive == 1){
			printf("<%d:alive>, ", temp->sid);
		}
		else{
			printf("<%d:dead>, ", temp->sid);
		}
		temp = temp->next;
	}
	printf("\n");
}

void print_gSid(){

	general *tempGeneral = generals_list;
	DDL_soldier *temp1 = tempGeneral->soldiers_head;

	printf("\tGENERALS:\n\t");
	while(tempGeneral != general_sentinel){
		if(temp1 != NULL){
			printf("%d: ", tempGeneral->gid );
			while(temp1 != tempGeneral->soldiers_tail){

				printf("%d ", temp1->sid);

				temp1 = temp1->next;
			}
			printf("%d ", temp1->sid);
			printf("\n\t");
		}
		tempGeneral = tempGeneral->next;
		temp1 = tempGeneral->soldiers_head;
	}
	printf("DONE\n");
}

struct DDL_soldier *resign(int sid, struct general* Patroklos, struct DDL_soldier* tempPatroklosHead){
	int c;

	DDL_soldier *newnode = (DDL_soldier*) malloc(sizeof(DDL_soldier));


	while(tempPatroklosHead->sid < sid && tempPatroklosHead->next != NULL){
		tempPatroklosHead = tempPatroklosHead->next;
	}

	if(tempPatroklosHead->next != NULL){
		newnode->sid = sid;
		newnode->next = tempPatroklosHead;
		newnode->prev = tempPatroklosHead->prev;
		tempPatroklosHead->prev->next = newnode;
		tempPatroklosHead->prev = newnode;
	}else{
		if(tempPatroklosHead->sid < sid){
			newnode->sid = sid;
			newnode->next = NULL;
			tempPatroklosHead->next = newnode;
			Patroklos->soldiers_tail = newnode;
		}
		else{
			newnode->sid = sid;
			newnode->next = tempPatroklosHead;
			tempPatroklosHead->prev->next = newnode;
			tempPatroklosHead->prev = newnode;
		}
	}

	tempPatroklosHead = newnode;

	return tempPatroklosHead;

}

struct DDL_soldier *deleteFromDouble(struct DDL_soldier* node, struct general* currGeneral, int whereTo, int sid){

	switch(whereTo){

		case 1:

		while(node->sid != sid){ 
			node = node->prev;
		}
		if(node->next==NULL){
			currGeneral->soldiers_tail = currGeneral->soldiers_tail->prev;
			currGeneral->soldiers_tail->next = NULL;
		}else{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		return node->prev;

		case 0:

		while(node->sid != sid){
			node = node->next;
		}
		if(node->prev==NULL){
			currGeneral->soldiers_head = currGeneral->soldiers_head->next;
			currGeneral->soldiers_head->prev = NULL;
		}else{
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		return node->next;
	}

}

void insertToDoublyLinkedSorted(struct general* tempGeneral, int sid ){

	DDL_soldier *newnode = (DDL_soldier*) malloc(sizeof(DDL_soldier));
	newnode->sid = sid;

	//Otan den exei kanenan soldier o general
	if(tempGeneral->soldiers_head == NULL){
		tempGeneral->soldiers_head = newnode;
		tempGeneral->soldiers_tail = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;



	}

	//otan prepei na mpei o soldier stin arxi tis listas
	else if(sid < tempGeneral->soldiers_head->sid){
		newnode->next = tempGeneral->soldiers_head;
		tempGeneral->soldiers_head->prev = newnode;
		newnode->prev = NULL;
		tempGeneral->soldiers_head = newnode;

	}

	//otan prepei na mpei o soldier sto telos tis listas
	else if(sid > tempGeneral->soldiers_tail->sid){
		newnode->next = NULL;
		newnode->prev = tempGeneral->soldiers_tail;
		tempGeneral->soldiers_tail->next = newnode;
		tempGeneral->soldiers_tail = newnode;


	}

	//otan prepei na mpei anamesa
	else{
		DDL_soldier *curr = tempGeneral->soldiers_head;	
		DDL_soldier *prev = tempGeneral->soldiers_head;
		while(curr->sid < sid){
			prev = curr;
			curr = curr->next;
		}
		newnode->prev = prev;
		newnode->next = curr;
		prev->next = newnode;
		curr->prev = newnode;
	}
}





	/**
	* @brief Optional function to initialize data structures that 
	* need initialization
	*
	* @return 1 on success
	*         0 on failure
	*/
int initialize() {

	//initialize registration sentinel
	soldier *newnode = (soldier*) malloc(sizeof(soldier));
	newnode->sid = -1;
	newnode->gid = -1;
	newnode->next = NULL;
	registration_list = newnode;		
	registration_sentinel = newnode;	

	//initialize generals sentinel
	general *newnode2 = (general*) malloc(sizeof(general));
	newnode2->gid = -1;
	newnode2->combats_no = -1;
	newnode2->soldiers_head = NULL;
	newnode2->soldiers_tail = NULL;
	newnode2->next = NULL;
	generals_list = newnode2;
	general_sentinel = newnode2;

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
int register_soldier (int sid, int gid) {

	if(registration_list == registration_sentinel){
		soldier *newnode = (soldier*) malloc(sizeof(soldier));
		newnode->sid = sid;
		newnode->gid = gid;
		newnode->next = registration_sentinel;
		registration_list = newnode;
	}
	else{
		soldier *newnode = (soldier*) malloc(sizeof(soldier));
		newnode->sid = sid;
		newnode->gid = gid;
		newnode->next = registration_list;
		registration_list = newnode;

	}
	return 1;
}

	/**
	 * @brief General or King joins the battlefield
	 *
     * @param gid The general's id
	 * @return 1 on success
	 *         0 on failure
	 */
int add_general(int gid) {

	if(generals_list == general_sentinel){
		general *newnode = (general*) malloc(sizeof(general));
		newnode->gid = gid;
		newnode->combats_no = 0;
		newnode->soldiers_head = NULL;
		newnode->soldiers_tail = NULL;
		newnode->next = general_sentinel;
		generals_list = newnode;
	}
	else{
		general *newnode2 = (general*) malloc(sizeof(general));
		newnode2->gid = gid;
		newnode2->combats_no = 0;
		newnode2->soldiers_head = NULL;
		newnode2->soldiers_tail = NULL;
		newnode2->next = generals_list;
		generals_list = newnode2;

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

	soldier *tempSoldier = registration_list;

	while(tempSoldier != registration_sentinel){
		general *tempGeneral = generals_list;
		while(tempGeneral->gid != tempSoldier->gid){
			tempGeneral = tempGeneral->next;
		}

		insertToDoublyLinkedSorted(tempGeneral , tempSoldier->sid);
		tempSoldier = tempSoldier->next;
	}

	print_gSid();
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

	//remove gid1 soldiers to gid2
	general *tempGeneral = generals_list;
	general *tempGeneral1 = NULL;
	general *tempGeneral2 = NULL;



	while(tempGeneral!=general_sentinel){
		if(tempGeneral->gid == gid1){
			tempGeneral1 = tempGeneral;
			tempGeneral = tempGeneral->next;
		}
		else if(tempGeneral->gid == gid2){
			tempGeneral2 = tempGeneral;
			tempGeneral = tempGeneral->next;
		}
		else{
			tempGeneral = tempGeneral->next;
		}
	}

	DDL_soldier *temp1 = tempGeneral1->soldiers_head;
	DDL_soldier *PatroklosHead = tempGeneral2->soldiers_head;


	while(temp1 != tempGeneral1->soldiers_tail){
		PatroklosHead = resign(temp1->sid, tempGeneral2, PatroklosHead);
		temp1 = temp1->next;
	}
	resign(temp1->sid, tempGeneral2, PatroklosHead);

	//allazw to registration list
	soldier *temp = registration_list;

	while(temp!=registration_sentinel){
		if(temp->gid==tempGeneral1->gid){
			temp->gid = tempGeneral2->gid;
			temp = temp->next;

		}else temp = temp->next;
	}

	//svinw ton komvo apo toys generals
	tempGeneral = generals_list;
	general *prev = NULL;
	while(tempGeneral!=general_sentinel){

		if(tempGeneral->gid == tempGeneral1->gid){
			if(tempGeneral == generals_list){
				generals_list = tempGeneral->next;
			}
			else if(tempGeneral->next == general_sentinel){
				prev->next = general_sentinel;
			}
			else {
				prev->next = tempGeneral->next;
			}
		}
		prev = tempGeneral;
		tempGeneral = tempGeneral->next;
	}


	print_gSid();
	return 1;
}


	/**
	 * @brief Prepare for battle
     * 
	 * @param gid1 The id of the first general
     * @param gid2 The id of the second general
     * @param gid3 The id of the third general
      * 
	 * @return 1 on success
	 *         0 on failure
	 */
int prepare_battle(int gid1, int gid2, int gid3) {

	general *tempGeneral = generals_list;
	general *tempGeneral1;
	general *tempGeneral2;
	general *tempGeneral3;

	while(tempGeneral != general_sentinel){
		if(tempGeneral->gid == gid1){
			tempGeneral1 = tempGeneral;
			tempGeneral1->combats_no++;
		}
		else if(tempGeneral->gid == gid2){
			tempGeneral2 = tempGeneral;
			tempGeneral2->combats_no++;
		}
		else if(tempGeneral->gid == gid3){
			tempGeneral3 = tempGeneral;
			tempGeneral3->combats_no++;
		}

		tempGeneral = tempGeneral->next;
	}


	my_combat.soldier_cnt = 0;

	int exitLoop1 = 0;
	int exitLoop2 = 0;
	int exitLoop3 = 0;
	int whereTo = 0;
	c_soldier* combatLoop = NULL;

	DDL_soldier *diasxisi_tempHead1 = tempGeneral1->soldiers_head;
	DDL_soldier *diasxisi_tempHead2 = tempGeneral2->soldiers_head;
	DDL_soldier *diasxisi_tempHead3 = tempGeneral3->soldiers_head;

	DDL_soldier *diasxisi_tempTail1 = tempGeneral1->soldiers_tail;
	DDL_soldier *diasxisi_tempTail2 = tempGeneral2->soldiers_tail;
	DDL_soldier *diasxisi_tempTail3 = tempGeneral3->soldiers_tail;

	while(exitLoop1 != 1 && exitLoop2 != 1 && exitLoop3  != 1){

		if(diasxisi_tempHead1 != NULL && diasxisi_tempHead1->sid!=diasxisi_tempTail1->sid && exitLoop1 != 1){

			c_soldier* newnode = (c_soldier*) malloc(sizeof(c_soldier));
			if(whereTo){
				newnode->sid = diasxisi_tempTail1->sid;
				diasxisi_tempTail1 = diasxisi_tempTail1->prev;
			}
			else{
				newnode->sid = diasxisi_tempHead1->sid;
				diasxisi_tempHead1 = diasxisi_tempHead1->next;
			}

			newnode->alive = 1;
			newnode->gid = tempGeneral1->gid;
			newnode->next = NULL;


			if(my_combat.combat_s == NULL){
				my_combat.combat_s = newnode;
				my_combat.soldier_cnt++;
			}else{
				combatLoop = my_combat.combat_s;
				while(combatLoop!=NULL){
					// printf("<<%d>>, ",combatLoop->sid );
					if(combatLoop->next == NULL){
						combatLoop->next = newnode;
						my_combat.soldier_cnt++;
						break;
					}
					combatLoop = combatLoop->next;
				}

			}
		}else{
			exitLoop1 = 1;
		}


		if(diasxisi_tempHead2 != NULL && diasxisi_tempHead2->sid!=diasxisi_tempTail2->sid && exitLoop2 != 1){

			c_soldier* newnode = (c_soldier*) malloc(sizeof(c_soldier));
			if(whereTo){
				newnode->sid = diasxisi_tempTail2->sid;
				diasxisi_tempTail2 = diasxisi_tempTail2->prev;
			}
			else{
				newnode->sid = diasxisi_tempHead2->sid;
				diasxisi_tempHead2 = diasxisi_tempHead2->next;
			}

			newnode->alive = 1;
			newnode->gid = tempGeneral2->gid;
			newnode->next = NULL;


			if(my_combat.combat_s == NULL){
				my_combat.combat_s = newnode;
				my_combat.soldier_cnt++;
			}else{
				combatLoop = my_combat.combat_s;
				while(combatLoop!=NULL){
					// printf("<<%d>>, ",combatLoop->sid );
					if(combatLoop->next == NULL){
						combatLoop->next = newnode;
						my_combat.soldier_cnt++;
						break;
					}
					combatLoop = combatLoop->next;
				}


			}
		}else{
			exitLoop2 = 1;
		}


		if(diasxisi_tempHead3 != NULL && diasxisi_tempHead3->sid!=diasxisi_tempTail3->sid && exitLoop3 != 1){

			c_soldier* newnode = (c_soldier*) malloc(sizeof(c_soldier));
			if(whereTo){
				newnode->sid = diasxisi_tempTail3->sid;
				diasxisi_tempTail3 = diasxisi_tempTail3->prev;
			}
			else{
				newnode->sid = diasxisi_tempHead3->sid;
				diasxisi_tempHead3 = diasxisi_tempHead3->next;
			}

			newnode->alive = 1;
			newnode->gid = tempGeneral3->gid;
			newnode->next = NULL;


			if(my_combat.combat_s == NULL){
				my_combat.combat_s = newnode;
				my_combat.soldier_cnt++;
			}else{
				combatLoop = my_combat.combat_s;
				while(combatLoop!=NULL){
					if(combatLoop->next == NULL){
						combatLoop->next = newnode;
						my_combat.soldier_cnt++;
						break;
					}
					combatLoop = combatLoop->next;
				}

			}
		}else{
			exitLoop3 = 1;
		}


		if(whereTo){
			whereTo = 0;	
		}
		else{
			whereTo = 1;
		}
	}

	combatLoop = my_combat.combat_s;
	printf("\tCombat soldiers: ");
	while(combatLoop!=NULL){
		printf("<%d>, ",combatLoop->sid );
		combatLoop = combatLoop->next;
	}
	printf("\nDONE\n");
	return 1;
}

	/**
	 * @brief Battle
     * 
     * @param god_favor 
     *
	 * @return 1 on success
	 *         0 on failure
	 */
int battle(int god_favor) {

	float loss;
	int i;
	int counter = 0;
	c_soldier *temp = my_combat.combat_s;


	switch(god_favor){

		case 0:
		loss = my_combat.soldier_cnt * 0.4;
		loss = (int) loss;

		for(i=0; i<loss; i++){
			temp->alive = 0;
			temp = temp->next;
		}

		printCombat();
		break;

		case 1:
		loss = my_combat.soldier_cnt * 0.1;
		loss = (int) loss;
		counter = loss;

		for(i=1; i<=my_combat.soldier_cnt; i++){
			if(i % 10 == 1){
				temp->alive = 0;
				if(--counter == 0) break;
			}
			temp = temp->next;
		}

		printCombat();
		break;
	}
	return 1;
}

	/**
	 * @brief Cease fire
     * 
	 * @return 1 on success
	 *         0 on failure
	 */
int cease_fire() {

	int i, gid1, gid2, gid3, c;
	int whereTo1 = 0;
	int whereTo2 = 0;
	int whereTo3 = 0;

	c_soldier *temp = my_combat.combat_s;
	general *tempGeneral = generals_list;
	general *tempGeneral1 = NULL;
	general *tempGeneral2 = NULL;
	general *tempGeneral3 = NULL;


	//Generals took place in combat are the first three in my_combat list
	gid1 = temp->gid;
	temp = temp->next;
	gid2 = temp->gid;
	temp = temp->next;
	gid3 = temp->gid;	

	while(tempGeneral != general_sentinel){
		if(tempGeneral->gid == gid1){
			tempGeneral1 = tempGeneral;
		}
		else if(tempGeneral->gid == gid2){
			tempGeneral2 = tempGeneral;
		}
		else if(tempGeneral->gid == gid3){
			tempGeneral3 = tempGeneral;
		}
		tempGeneral = tempGeneral->next;
	}

	DDL_soldier *g1Head = tempGeneral1->soldiers_head;
	DDL_soldier *g1Tail = tempGeneral1->soldiers_tail;
	DDL_soldier *g2Head = tempGeneral2->soldiers_head;
	DDL_soldier *g2Tail = tempGeneral2->soldiers_tail;
	DDL_soldier *g3Head = tempGeneral3->soldiers_head;
	DDL_soldier *g3Tail = tempGeneral3->soldiers_tail;
	temp = my_combat.combat_s;
	for(i=1; i<=my_combat.soldier_cnt; i++){
		if(temp->alive == 0){
			if(temp->gid == gid1){
				if(whereTo1){
					g1Tail = deleteFromDouble(g1Tail, tempGeneral1, whereTo1, temp->sid);

				}else{
					//scanf("%d",&c);
					g1Head = deleteFromDouble(g1Head, tempGeneral1, whereTo1, temp->sid);
					//scanf("%d",&c);

				}
				if(whereTo1){
					whereTo1 = 0;
				}
				else{
					whereTo1 = 1;
				}
			}

			else if(temp->gid == gid2){
				if(whereTo2){
					g2Tail = deleteFromDouble(g2Tail, tempGeneral2, whereTo2, temp->sid);

				}else{
					g2Head = deleteFromDouble(g2Head, tempGeneral2, whereTo2, temp->sid);

				}
				if(whereTo2){
					whereTo2 = 0;
				}
				else{
					whereTo2 = 1;
				}
			}

			else if(temp->gid == gid3){
				if(whereTo3){
					g3Tail = deleteFromDouble(g3Tail, tempGeneral3, whereTo3, temp->sid);

				}else{
					g3Head = deleteFromDouble(g3Head, tempGeneral3, whereTo3, temp->sid);

				}
				if(whereTo3){
					whereTo3 = 0;
				}
				else{
					whereTo3 = 1;
				}
			}

			temp = temp->next;

		}else{

			if(temp->gid == gid1){
				if(whereTo1){
					whereTo1 = 0;
				}
				else{
					whereTo1 = 1;
				}
			}
			else if(temp->gid == gid2){

				if(whereTo2){
					whereTo2 = 0;
				}
				else{
					whereTo2 = 1;
				}
			}
			else if(temp->gid == gid3){

				if(whereTo3){
					whereTo3 = 0;
				}
				else{
					whereTo3 = 1;
				}
			}

			temp = temp->next;
		}
	}
	print_gSid();
	my_combat.soldier_cnt = 0;
	my_combat.combat_s = NULL;
	return 1;

}

	/**
	 * @brief Trojan Horse
	 *
	 * @return 1 on success
	 *         0 on failure
	 */
int trojan_horse() {

	general *array[5] = {NULL,NULL,NULL,NULL,NULL};
	general *tempGeneral = generals_list;

	int counter = 0;
	int i, min, kl;
	while(tempGeneral!=general_sentinel){
		array[counter++] = tempGeneral;
		tempGeneral = tempGeneral->next;
		if (counter == 5) break;
	}

	while(tempGeneral!=general_sentinel){
		min = 0;
		for(i=1; i<5 && array[i] != NULL ; i++){
			if(array[min]->combats_no > array[i]->combats_no){
				min = i;
			}
		}

		if(tempGeneral->combats_no > array[min]->combats_no){
			array[min] = tempGeneral;
		}
		tempGeneral = tempGeneral->next;
	}

	printf("\tGeneral = ");

	for(i=0; i<5 && array[i] != NULL; i++){
		printf("<%d:%d>, ", array[i]->gid, array[i]->combats_no );
	}
	printf("\nDONE\n");

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
	DDL_soldier *temp1 = tempGeneral->soldiers_head;

	printf("\tGENERALS:\n\t");
	while(tempGeneral != general_sentinel){
		printf("%d: ", tempGeneral->gid );
		if(temp1 == NULL)
			printf("\n\t");
		if(temp1 != NULL){
			while(temp1 != tempGeneral->soldiers_tail){

				printf("%d ", temp1->sid);

				temp1 = temp1->next;
			}
			printf("%d ", temp1->sid);
			printf("\n\t");
		}
		tempGeneral = tempGeneral->next;
		temp1 = tempGeneral->soldiers_head;
	}
	printf("DONE\n");
	return 1;
}

	/**
	 * @brief Print registration list
	 *
	 * @return 1 on success
	 *         0 on failure
	 */
int print_registration_list() {

	soldier *temp = registration_list;

	printf("R\n\t");
	printf("Registration list = ");
	while(temp != registration_sentinel){
		printf("%d:", temp->sid );
		printf("%d, ", temp->gid );
		temp = temp->next;
	}

	printf("\nDONE \n");
	return 1;
}



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

	initialize();


	/* Read input file buff-by-buff and handle the events */
	while ( fgets(buff, BUFFER_SIZE, fin) ) {

		DPRINT("\n>>> Event: %s", buff);

		switch(buff[0]) {

		/* Comment */
			case '#':
			break;

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
		 * P <gid1> <gid2> <gid3> */
			case 'P':
			{
				int gid1, gid2, gid3;
				sscanf(buff, "%c %d %d %d", &event, &gid1, &gid2, &gid3);
				DPRINT("%c %d %d %d\n", event, gid1, gid2, gid3);

				if ( prepare_battle(gid1, gid2, gid3) ) {
					DPRINT("%c %d %d %d succeeded\n", event, gid1, gid2, gid3);
				} else {
					fprintf(stderr, "%c %d %d %d failed\n", event, gid1, gid2, gid3);
				}

				break;
			}

		/* Battle
		 * B <god_favor> */
			case 'B':
			{
				int god_favor;
				sscanf(buff, "%c %d\n", &event, &god_favor);
				DPRINT("%c %d\n", event, god_favor);

				if ( battle(god_favor) ) {
					DPRINT("%c %d succeeded\n", event, god_favor);
				} else {
					fprintf(stderr, "%c %d failed\n", event, god_favor);
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

		/* Trojan Horse
		 * T */
			case 'T':
			{
				sscanf(buff, "%c", &event);
				DPRINT("%c\n", event);

				if ( trojan_horse() ) {
					DPRINT("%c succeeded\n", event);
				} else {
					fprintf(stderr, "%c failed\n", event);
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

		/* Print registration list
		 * Y */
			case 'Y':
			{
				sscanf(buff, "%c", &event);
				DPRINT("%c\n", event);

				if ( print_registration_list() ) {
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
