#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Contact {
  char name[100];
  char phone[100];
  struct Contact *next;
};

struct Contact *phonebook = NULL;

void add_contact()
{
  struct Contact *new_contact = malloc(sizeof(struct Contact));
  printf("\n\t\tEnter contact information:\n");
  printf("\t\tName: ");
  scanf("%s", new_contact->name);
  printf("\t\tPhone: ");
  scanf("%s", new_contact->phone);
  new_contact->next = phonebook;
  phonebook = new_contact;
  printf("\t\t----Added Successfully----\t\n");
}

void delete_contact()
{
  char name[100];
  if(phonebook==NULL){
		printf("\n\t\tNo contacts found to delete\n");
	}
	else{
  printf("\t\tEnter the name of the contact to delete: ");
  scanf("%s", name);

  struct Contact *curr = phonebook;
  struct Contact *prev = NULL;
  while (curr != NULL) {
    if (strcmp(curr->name, name) == 0) {
      break;
    }
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL) {
    printf("\t\tError: No contact with name '%s' found.\n", name);
    return;
  }

  if (prev == NULL) {
    phonebook = curr->next;
  } else {
    prev->next = curr->next;
  }

  free(curr);
printf("\t\t----Deletion Successfully----\t");
}
}

void update_contact()
{
  char name[100];
  printf("\n\t\tEnter the name of the contact to update: ");
  scanf("%s", name);

  struct Contact *curr = phonebook;
  while (curr != NULL) {
    if (strcmp(curr->name, name) == 0) {
      break;
    }
    curr = curr->next;
  }

  if (curr == NULL) {
    printf("\t\tError: No contact with name '%s' found.\n", name);
    return;
  }

  printf("\t\tEnter new contact information:\n");
  printf("\t\tName: %s\n", curr->name);
  printf("\t\tPhone: ");
  scanf("%s", curr->phone);
  printf("\t\t----Updation Successfully----\t");
}

void search_contact()
{
  struct Contact *curr = phonebook;
  char name[100];
  printf("\n\t\tEnter the name of the contact to search for: ");
  scanf("%s", name);
  while (curr != NULL && strcmp(curr->name, name) != 0) {
    curr = curr->next;
  }

  if (curr == NULL) {
    printf("\n\t\tError: No contact with name '%s' found.\n", name);
    return;
  }
  printf("\t\t----Element Found----\t\n");
  printf("\t\tName: %s\t\n", curr->name);
  printf("\t\tPhone: %s\t\n", curr->phone);
  printf("\t\t---------------------\t");
}

void display_contact(){
	struct Contact *ptr;
	int z;
	ptr = phonebook;
	if(ptr==NULL){
		printf("\n\t\tNo contacts found\n");
	}
	else{
	printf("\n\t\tALL CONTACTS\n\n\t\t ");	
    for(z=0;z<32;z++){
			printf("_");
	}
	printf("\n\t\t|NAME\t\tNUMBER \t\t|\n\t\t");
	for(z=0;z<33;z++){
			printf("-");
		}
	printf("\n");
	while(ptr!=NULL)
	{
		printf("\t\t %s\t\t",ptr->name);
		printf("%s\t\n",ptr->phone);
		ptr=ptr->next;
	}
		printf("\t\t");
		for(z=0;z<32;z++){
			printf("-");
		}
  }
}
int main()
{
	int opt=8,i,z;
	do{
		printf("\n\t\t");
		for(z=0;z<25;z++){
			printf("-");
		}
		printf("\n\t\t|\tMENU\t\t|");
		printf("\n\t\t");
		for(z=0;z<25;z++){
			printf("-");
		}
		printf("\n\t\t|1. ADD CONTACT\t\t|\n\t\t|2. UPDATE CONTACT\t|\n\t\t|3. SEARCH CONTACT\t|\n\t\t|4. DELETE CONTACT\t|\n\t\t|5. DISPLAY ALL CONTACTS|\t\n\t\t|0. EXIT\t\t|\n");
		printf("\t\t");
		for(z=0;z<25;z++)
		{
			printf("-");
		}
		printf("\n\t\tEnter your option :");		
		scanf("%d",&opt);
		switch(opt){
		case 1 : {
			add_contact();
			break;
		}
		case 2 : {
			update_contact();
			break;
		}
		case 3 : {
			search_contact();
			break;
		}
		case 4 : {
			delete_contact();
			break;
		}
		case 5 : {
			display_contact();
			break;
		}
		case 0 :{
			break;
		}
		default :{
			printf("Enter valid number\n");
			break;
		}
	}	
	}while(opt!=0);
    return 0;
}
