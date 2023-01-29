#include <stddef.h>
#include "ll_cycle.h"
#include <stdbool.h>

int ll_has_cycle(node *head) {
    /* your code here */
       	if (head == NULL) {
		return 0;
	}

       	node *tortoise = head;
    	node *hare = head;
       
	while (true) {
		hare = hare->next;
		if (hare == NULL) {
		       	break;
		}
		if(hare == tortoise) {
		       	return 1;
		}
		
		hare = hare->next;
		if (hare == NULL) {
			break;
		}
		if (hare == tortoise) {
			return 1;
		}
		
		tortoise = tortoise->next;
		if (hare == tortoise) {
			return 1;
		}
	}
	
	return 0;
}
