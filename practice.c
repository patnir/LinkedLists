#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _lnode {
	char *str;
	struct _lnode *next;
}lnode;

lnode *lnode_construct(char *str)
{
	lnode *ret_node = (lnode *) malloc (sizeof (lnode));
	if (ret_node == NULL) {
		fprintf(stderr, "malloc fail!\n");
		return NULL;
	}
	ret_node->str = str;
	ret_node->next = NULL;
	return ret_node;
	
}

// insert in front of the list 

lnode *lnode_insert (lnode **list, char *str)
{
	if (str == NULL) {
		return NULL;
	}
	lnode *new_node = lnode_construct(str);
	if (new_node == NULL) {
		fprintf(stderr, "malloc fail!\n");
	}	
	new_node->next = *list;
	*list = new_node;
	return new_node;
}

int main (int argc, char **argv)
{
	lnode *head = NULL;
	char *new_string = (char *) malloc (sizeof(char) * (strlen("abcd") + 1));
	strcpy(new_string, "abcd");
	lnode *new_node = lnode_insert(&head, new_string);
	new_string = (char*) malloc  (sizeof(char) * (strlen("efgh") + 1));
	strcpy(new_string, "efgh");
	new_node = lnode_insert(&head, new_string);
	while(new_node != NULL) {
		printf("%s->", new_node->str);
		new_node = new_node->next;
	}
	printf("\n");
	return EXIT_SUCCESS;
	
}
