/*
 *@author Hrishikesh . M, cssc2644
 *Copyright © 2020 hr. All rights reserved.
 *                */

#include"llist.h"

int main(int argc,char*  argv[]){
Link node,head,curNode;
 FILE * database;
    char buffer[30];
    int ch;
    int i=0;
    database = fopen(argv[1], "r");

    if (NULL == database)
    {
         perror("opening database");
         return (-1);
    }

    while (EOF != fscanf(database, "%[^\n]\n", buffer))
    {
         printf("> %s\n", buffer);
    }

    fclose(database);

/* it will get the head and pass on to print function to get it printed out */
head=strToList(buffer);
print(head);
printf("\n%d\n",size(head));

curNode=find('t',head);         /*it will search for the "t" characters in the linked list*/
if(curNode!=NULL){
   node=(Link)(malloc(sizeof(Link)));
       node->data='o';
       node->next=NULL;
    
   insert(curNode,curNode->next,node);  /* it will insert node to list */
}
    
print(head);
printf("\n%d\n\n",size(head));
    
/*deleting the last letter and so on... */
curNode=head;
curNode=curNode->next;
delete_(curNode,curNode->next);

/* deletes everything */
deleteList(head);

}


