#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
      int data;
      char reg_no[20];
      struct node *prev, *next;
};

struct node *lane_head[5],*lane_tail[5];
int lane_count[5]={0};
int car_count=0;

struct node * createNode(int data,char *reg_no) {
      struct node *newnode = (struct node *)malloc(sizeof (struct node));
      newnode->data = data;
      char a[20];        
      strcpy(newnode->reg_no,reg_no);
      newnode->next = newnode->prev = NULL;
      return (newnode);
}

void createSentinels(int lane) {
      lane_head[lane] = createNode(0,"");
      lane_tail[lane] = createNode(0,"");
      lane_head[lane]->next = lane_tail[lane];
      lane_tail[lane]->prev = lane_head[lane];
}

/* insertion at the front of the queue */
void enqueueAtFront(int data,char *reg_no,int lane) {
      struct node *newnode, *temp;
      newnode = createNode(data,reg_no);
      temp = lane_head[lane]->next;
      lane_head[lane]->next = newnode;
      newnode->prev = lane_head[lane];
      newnode->next = temp;
      temp->prev = newnode;
}

void initialize(){
      int i=0;
      for(i=0;i<5;i++){
            lane_head[i]=NULL;
            lane_tail[i]=NULL;
            createSentinels(i);
      }
}

void car_insert(int time,char reg[],int lane) {
      if(car_count<=25)
            enqueueAtFront(time,reg,lane);
      else 
            printf("!**Total Capacity Full**!\n");
}

/*insertion at the rear of the queue */
void enqueueAtRear(int data,char *reg_no,int lane) {
      struct node *newnode, *temp;
      newnode = createNode(data,reg_no);
      temp = lane_tail[lane]->prev;
      lane_tail[lane]->prev = newnode;
      newnode->next = lane_tail[lane];
      newnode->prev = temp;
      temp->next = newnode;
}

/* deletion at the front of the queue */
void dequeueAtFront(int lane) {
      struct node *temp;
      if (lane_head[lane]->next == lane_tail[lane]) {
            printf("Queue is empty\n");
      } else {
            temp = lane_head[lane]->next;
            lane_head[lane]->next = temp->next;
            temp->next->prev = lane_head[lane];
            free(temp);
      }
      return;
}


/* deletion at the rear of the queue */

void dequeueAtRear(int lane)  {
      struct node *temp;
      if (lane_tail[lane]->prev == lane_head[lane]) {
            printf("Queue is empty\n");
      } else {
            temp = lane_tail[lane]->prev;
            lane_tail[lane]->prev = temp->prev;
            temp->prev->next = lane_tail[lane];
            free(temp);
      }
      return;
}

/* display elements present in the queue */
void display(int lane) {
      struct node *temp;
      printf("Lane_%d: ",lane+1);
      if (lane_head[lane]->next == lane_tail[lane]) {
            printf("Lane_%d is empty\n",lane);
            return;
      }
      
      temp = lane_tail[lane]->prev;
      while(temp!=lane_head[lane]) {
            printf("((%s|]\t ", temp->reg_no);
            temp= temp->prev;
      }
      printf("\n");
}

void search(char reg[]) {
      
}

void show_parking() {
      int i=0;
      printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
      for(i=0;i<5;i++) {
            display(i);
      }
      printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
}

int menu() {
      int choice;
      printf("\nPress 0 For Exit\n");
      printf("Enter Your Choice\n");
      printf("1. Show Parking Lanes\n");
      printf("2. Show Specific Lane\n");
      printf("3. Add a New Car\n");
      printf("4. Remove a Car\n");
      printf("5. Search a Car\n");
      scanf("%d",&choice);
      return choice;
}


int main() {
      FILE *fp;
      char a[20];
      char temp[20];
      char reg_no[20];
      int tim,time_unit=0,i;
      initialize();
//   printf("Enter name of file to read from\n");
//   scanf("%s",a);
      strcpy(a,"parking_data.txt");
      fp = fopen(a,"r");
      if(fp) {
            do {
                  fscanf(fp,"%s",reg_no);
                  fscanf(fp,"%s",temp); 
                  tim=atoi(temp);           
                  if(time_unit==tim) {                  
                        time_unit=tim;
                        //printf("%s %d\n", reg_no,tim);
                        car_count++;
                        car_insert(tim,reg_no,(car_count-1)%5);
                  } else if(time_unit<tim) {
                        time_unit=tim;
                        //printf("%s %d\n", reg_no,tim);
                        car_count++;                  
                        car_insert(tim,reg_no,(car_count-1)%5);
                  }       
            }while(!feof(fp));
      }     
      int choice;                     
      while(choice = menu()) {
            switch(choice){
                  case 1: show_parking();break;
                  case 2: printf("Input Lane no: \n");scanf("%d",&choice);display(choice-1);break;
                  default: printf("wrong choice\n");
            }
      }
}