#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//self referential structure
struct LinList//
{
	
	int ID1;
	char cusname[20];
	struct LinList *nod1;
	
};
struct Queeue//
{
	int Qid1;
	char CusQnam[20];
	char QUname[20];
	struct Queeue *nod2;
	
};
struct Stak
{
	int stackID;
	char csname[20];
	char sname[20];
	struct Stak *nod3;	
};
//declare variables
int a,i=1,ID1,cou1 = 1,cdID;

struct LinList *NodeX,*Strt=NULL,*Pr_ev,*tm,*T,*curr;

	struct Queeue *SrtQ=NULL,*Qnode,*T_3;

	struct Stak* Stts = NULL,*Nodes,*T7,*T2;

char add[20],Qdd[20],cQdd[20],nameofcus[20],MOname[20],ot[20]; 

//function
void UpdteF()
{

    FILE *fptr;
	
		fptr = fopen("mobiles.txt", "w");
	struct LinList *  t = Strt; 
	
	while (t != NULL) 
	{ 
			fprintf(fptr, "%d\t%s\n",t->ID1,t->cusname);
		t = t-> nod1;
	}
	printf("wrote the file successfully.\n");
	
}

//delete the last order
void CancLast()
{
	struct Stak *toDelete;
	
	if(Stts !=NULL)
	{
		NodeX=(struct LinList*)malloc(sizeof(struct LinList));
		
		strcpy(NodeX->cusname,Stts->sname);
		
		if(Strt==NULL || strcmp(Strt->cusname,NodeX->cusname)>=0 )
		{
			
			NodeX->nod1=Strt;
			
			
				Strt = NodeX;
		}
		else
		{
			
			curr=Strt;
			while(curr->nod1 !=NULL && strcmp(curr->nod1->cusname,NodeX->cusname)<0)
			{
				
				curr = curr->nod1;
			}
			
			
			NodeX->nod1 = curr->nod1; 
			
			curr->nod1 =NodeX;  
		}
		
		toDelete = Stts;
		
		Stts = Stts->nod3;
		
		free(toDelete);

		printf("Cancel the order\n");
	
	//error messege
	}else
	{
		
		printf("No order to Cancel \n");
	}
}

//disply last 
void DisInfoLast()
{
	
	if(Stts !=NULL)
	{
		
		printf("%s \n",Stts->csname);
		
		printf("%s \n",Stts->sname);
		
		
	}else
	{
		printf("There is no orders to processed. \n");
	}
	
	
}

//create a stck which is empty
void emptycreatestack()

{
	
  Nodes=malloc(sizeof(struct Stak));
  
  strcpy(Nodes->csname,nameofcus);
  
  strcpy(Nodes->sname,MOname);
	Nodes->stackID=ID1;
   Stts=Nodes;
      T7=Nodes;
	Nodes->nod3=NULL;
	
	
}
//create normal stack
void normalcreatestack()

{
  Nodes=malloc(sizeof(struct Stak));
  
  strcpy(Nodes->csname,nameofcus);
  
  strcpy(Nodes->sname,MOname);
  
		Nodes->stackID=ID1;
  
	Stts=Nodes;
	Nodes->nod3=T7;
	
  T7=Nodes;
  
  
}

//process nxt order
void ProsNext()
{

	while(1)
	{
		tm =Strt,Pr_ev;
		
		if(tm !=NULL && strcmp(tm->cusname,SrtQ->QUname)==1)
		{
			
			strcpy(MOname,SrtQ->QUname);
			
			strcpy(nameofcus,SrtQ->CusQnam);
			
				ID1=SrtQ->Qid1;
			
				struct Queeue* w=SrtQ;
			
				SrtQ=SrtQ->nod2;
			
			free(w);
				Strt=tm->nod1;
			free(tm);
			if(Stts==NULL)
			{
			emptycreatestack();
			}else
			{
			normalcreatestack();
			}
				cou1=0;
				
			break;
			
		}
		
		while(tm !=NULL && strcmp(tm->cusname,SrtQ->QUname) !=1)
		
		{
			Pr_ev=tm;
			
			tm =tm->nod1;
			
		}
		
		if(tm==NULL)
		{
			printf("Game is not in the stock \n");
			
			struct Queeue* w=SrtQ;
			
			SrtQ=SrtQ->nod2;
			
			free(w);break;
		}
		
		strcpy(MOname,SrtQ->QUname);
		
			strcpy(nameofcus,SrtQ->CusQnam);
		
		ID1=SrtQ->Qid1;
		
		struct Queeue* w=SrtQ;
		
			SrtQ=SrtQ->nod2;
		
		free(w);
		
		 Pr_ev->nod1=tm->nod1;
		  free(tm);
		if(Stts==NULL)
		
		{
			
				emptycreatestack();
		}else
		{
			normalcreatestack();
		}
		
		cou1=0;
		
		break;
		
	}
	
	if(cou1==0)
	{
		
		printf("processed success.\n");
	}
	
	
}

//function that can print next order
void DisNextOrder()
{			

	if(SrtQ !=NULL)
	
	{
		struct Queeue *  t = SrtQ; 
		
			while (t != NULL) { 
				printf("|%d         |%s               |%s          |\n",SrtQ->Qid1,SrtQ	->CusQnam,SrtQ->QUname);
				t = t->nod2; 
		}			
	
	}else
	
	{
		
		printf("There are no orders \n");
	}

}

//print previous order
void DisAll()

{			
	if(SrtQ !=NULL)
	{
		struct Queeue *  t = SrtQ; 
		
		while (t != NULL) 
		{ 
			printf("|%d         |%s               |%s          |\n",t->Qid1,t->CusQnam,t->QUname);
			
			t = t->nod2; 
			
		}			
	}
	else
	{
		
		printf("There are no orders \n");
	}
}

//add details to Queue
void AddtoQ()
{
	
	if(Strt !=NULL)
	{
		if(SrtQ==NULL)
		
		{
			Qnode=(struct Queeue*)malloc(sizeof(struct Queeue));
				Qnode->Qid1=i;
				strcpy(Qnode->CusQnam,cQdd);
				
			strcpy(Qnode->QUname,Qdd);
			
				SrtQ=Qnode;
				
				T_3=Qnode;
				Qnode->nod2=NULL;
				
			i++;
			
		}else
		{
			Qnode=(struct Queeue*)malloc(sizeof(struct Queeue));
			
			Qnode->Qid1=i;
					strcpy(Qnode->CusQnam,cQdd);
			strcpy(Qnode->QUname,Qdd);
					T_3->nod2=Qnode;
				T_3=Qnode;
			Qnode->nod2=NULL;	
			
			
			i++;
		}
		
		
	}else
	{
		
		
		printf("Stock is empty \n Cannot add Orders \n");
	}
	
}

//adding new stocks 1 by 1
void addNewstock(){
	NodeX=malloc(sizeof(struct LinList));
	strcpy(NodeX->cusname,add);
	NodeX->ID1=cdID;
	if(Strt==NULL || strcmp(Strt->cusname,NodeX->cusname)>=0 ){
		NodeX->nod1=Strt;
		Strt=NodeX;
	}
	else{
		curr=Strt;
		while(curr->nod1 !=NULL && strcmp(curr->nod1->cusname,NodeX->cusname)<0)
			curr = curr->nod1;
		NodeX->nod1 = curr->nod1; 
		curr->nod1 =NodeX; 
	}
}

//display the stock entered
void disstock(){
	if(Strt !=NULL){
		struct LinList *  t = Strt; 
		printf("--mobile Shop--\n");
		printf("---------------------------------\n");
		while (t != NULL) { 
			printf("%s\n",t->cusname);
			t = t->nod1; 
		}

	}else{
		printf("Stock is Empty at the moment \n");
	}
}

void readMobile()
{
	
	FILE *file =fopen("mobiles.txt","r");
	
	for(int i=0;fscanf(file,"%d\t%[^\n]\n",&a,ot) !=EOF;i++)
	
	{
		NodeX=malloc(sizeof(struct LinList));
		
		strcpy(NodeX->cusname,ot);
		
		NodeX->ID1=a;
		
		if(Strt==NULL || strcmp(Strt->cusname,NodeX->cusname)>=0 ){
			NodeX->nod1=Strt;
			
			Strt=NodeX;
			
		}
		
		
		else
		
		{
			curr=Strt;
			
			while(curr->nod1 !=NULL && strcmp(curr->nod1->cusname,NodeX->cusname)<0)
					curr = curr->nod1;
				NodeX->nod1 = curr->nod1; 
				
			curr->nod1 =NodeX; 
			
		}		
	}
	


}

//display menu
void menu(){
	printf("(1)  - Display the current stock \n");
	printf("(2)  - Add a New Mobile to stock \n");
	printf("(3)  - Display next order information \n");
	printf("(4)  - Display all orders \n");
	printf("(5)  - Add order to Queeue \n");
	printf("(6)  - Process the next order \n");
	printf("(7)  - Cancel last order \n");
	printf("(8)  - Display information   of last order \n");
	printf("(9)  - Update mobile file \n");
	printf("(10) - Quit program \n");
}

//taking option from user
int main()
{
	int like;
	readMobile();
	while(1)
	{
		
		printf("Please enter your option \n");
		
		menu();
		
		
		scanf("%d",&like);
		
		if(like==1)
		
		{
				disstock();
		}
		else if(like==2)
		{
				printf("Please enter the name of the mobile to insert  :");
				fflush(stdin);
				gets(add);
				printf("Enter the mobile code   :");
				scanf("%d",&cdID);
			addNewstock();
		}
		
		else if(like==3)
		{
			
			DisNextOrder();
		}
		else if(like==4)
		{
			
			
			DisAll();
		}
		else if(like==5)
		
		{
			printf("Please enter the name of a customer  :");
			
			fflush(stdin);
			gets(cQdd);
			
			printf("Please enter a name of the mobile to order  :");
			fflush(stdin);
			
			gets(Qdd);
			AddtoQ();
		}
		
		
		else if(like==6)
		{
			ProsNext();
			
			cou1=1;
		}
		else if(like==7)
		{
			CancLast();
			
			cou1=1;
		}
		else if(like==8)
		{
			
			DisInfoLast();
		}
		
		
		else if(like==9)
		{
			
			UpdteF();
		}
		else if(like==10)
		{
			
			exit(1);
		}
		else
		{
			
			printf("--You entered invalid option--\n");
			
		}		

	}

}