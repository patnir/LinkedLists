#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct _lnode {
	char *str;
	struct _lnode *next;
	
}lnode;

lnode *construct (char *str) 
{
	lnode *ret_node = (lnode*) malloc (sizeof (lnode));;
	ret_node->str = str;
	ret_node->next = NULL;
	return ret_node;
}

lnode *insert(lnode ** list, char *str)
{
	lnode* new_node = construct(str);
	new_node->next = *list;
	*list = new_node;
	return new_node;
}

lnode *lnode_remove(lnode **list) 
{
	lnode *ret_node = *list;
	*list = ret_node->next;
	ret_node->next = NULL;
	return ret_node;
}

void destroy (lnode *list) 
{
	while(list != NULL) {
		lnode *tmp = list->next;
		free(list->next);
		free(list);
		list = tmp;
	}
	return;
}

lnode *dequeue (lnode **list)
{
	lnode* ret_node = lnode_remove(list);
	return ret_node;
}

lnode *enqueue (lnode **list, char *str) 
{
	lnode *new_node = construct (str); // need to insert this
	lnode dummy;
	lnode dummy->next = *list;
	lnode *current = *list;
	lnode *prev = &dummy;
	while (current != NULL) {
		if (strcmp(current->str, str) >= 0) {
			/*lnode *middle_node = construct(str);	
			prev->next = middle_node;
			middle_node->next = current;*/
			break;
		}
		prev = curr;
		current = current->next;
	}
	lnode *middle = construct(str);
	prev->next = middle;
	
	

}
int main (int argc, char ** argv)
{
	lnode *head = NULL;
	
	char *new_string = (char *) malloc (sizeof(char) * (strlen ("abcd") + 1));
	strcpy(new_string, "abcd");
	lnode* new_node = insert(&head, new_string);
	
	new_string = (char *) malloc (sizeof(char) * (strlen ("abcd") + 1));
	strcpy(new_string, "efgh");
	new_node = insert(&head, new_string);
	
	new_string = (char *) malloc (sizeof(char) * (strlen ("abcd") + 1));
	strcpy(new_string, "wxyz");
	new_node = insert(&head, new_string);
	
	new_node = head;
	printf("Reach1\n");	
	while (new_node != NULL) {
		printf("%s->", new_node->str);
		new_node = new_node->next;
	}
	printf("NULL\n");
	while(head != NULL) {
		lnode *removed_node = dequeue(&head);
		printf("%s->", removed_node->str);
		destroy(removed_node);
	}
	printf("NULL\n");
	destroy(head);
	return EXIT_SUCCESS;
}
