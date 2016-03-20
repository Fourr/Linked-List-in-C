#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include"second.h"
/*struct node

{

	int num;

	struct node *next;

};

typedef struct node node;
*/node *root = NULL;

node *createNode(int n)

{

	node *bust  = (node *) malloc(sizeof(node) );

	bust->num = n;

	bust->next = NULL;
	return bust;
}

void insertNode(node *ptr)


{

	if(root == NULL)

	{ root = ptr;
		return;

	} else
	{
		node *temp;

		if( ptr->num <= root->num)
		{
			if( ptr->num == root->num){
				return;
			}

			ptr->next = root;
			root = ptr;
			return;

		}
		for(temp = root; temp->next!=NULL; temp=temp->next)
		{
			if (ptr->num <= temp->next->num)
			{ 
				if (ptr->num == temp->next->num){
					return;
				}
				ptr->next = temp->next;
				temp->next =ptr;
				return;

			}				

		}
		if(ptr->num > temp->num)
		{	temp->next = ptr;			
			return;
		}
	}
}
void deleteNode(int g)
{	node *target;
	if(root ==NULL){
		return;

	}

	if(root->num == g)
	{	target = root;
		root=root->next;
		free(target);	
		return;
	}
	node *temp;
	for(temp =root; temp->next !=NULL; temp =temp->next)
	{
		if(temp->next->num == g)
		{
			target = temp->next;			
			temp->next = temp->next->next;
			free(target);
			return;	
		}
		if(temp->next->next == NULL){
			if(temp->next->num == g){
				target = temp->next;
				temp->next = NULL;
				free(target); 
				return;
			}
		}

	}
}





void print()
{
	node *temp;

	for(temp = root; temp!=NULL; temp = temp->next)
	{
		printf("%d\t", temp->num);



	}
	return;

}


//insert method                                                                                                                          

// in this method if root =null, then root equals the thing i passed in                                           

int main(int argc, char** argv)

{

	FILE *fp;

	char data[1024];

	fp = fopen(argv[1], "r");

	int i;

	int n;

	node *ptr;



	if (fp == NULL)

	{

		printf("error\n");

		return 0;

	} else {
		do{

			i = fscanf(fp, "%s",data );
			if (i == -1){
				break;
			}

			if(strcmp(data, "i") !=0 && strcmp(data, "d")!=0){

				printf("error\n");
				return 0;	}			
			if (strcmp(data, "i") == 0)
			{	

				fscanf(fp,"%s", data);
				n = atoi(data);
				if(isdigit(n) != -1){
					ptr = createNode(n);
					insertNode(ptr);
				}
				else{
					printf("error1\n");
					return 0;
				}

			}

			if (strcmp(data,"d") ==0)
			{
				fscanf(fp,"%s",data);
				n = atoi(data);
				if(isdigit(n) != -1){

					deleteNode(n);

				}
				else{
					printf("error\n");
					return 0;
				}
			}


		}while(i!=EOF);
	}

	print();
	fclose(fp);
	free(root);
	return 0;
}

