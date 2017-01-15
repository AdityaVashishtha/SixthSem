#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct node structure for car regno and time(data)*/
struct node {
      int data;
      char reg_no[20];
      struct node *prev, *next;
};

/*initialize array of pointer for 5 lanes and lane car counter for lane capacity*/
struct node *lane_head[5],*lane_tail[5];
int lane_count[5]={0};
int car_count=0;

/*createnode for every insertion*/
struct node * createNode(int data,char *reg_no) {
      struct node *newnode = (struct node *)malloc(sizeof (struct node));
      newnode->data = data;
      char a[20];        
      strcpy(newnode->reg_no,reg_no);
      newnode->next = newnode->prev = NULL;
      return (newnode);
}

/*initialize every head and tail pointer for insertions*/
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
/*Initialize every lane for insertion and deletion*/
void initialize(){
      int i=0;
      for(i=0;i<5;i++){
            lane_head[i]=NULL;
            lane_tail[i]=NULL;
            createSentinels(i);
      }
}

/*Car insert at front*/
void car_insert(int time,char reg[],int lane) {
      if((car_count<=25)) {
            if((lane_count[lane]<=5)){
                  enqueueAtFront(time,reg,lane);
                  lane_count[lane]++;
            } else {
                  enqueueAtFront(time,reg,(lane+1)%5);
            }         
      }
      else 
            printf("!**Total Capacity Full**!\n");
}

/* deletion at a special position*/
void dequeueAtSpecial(char reg[],int lane) {
      struct node *temp;
      printf("%d\n",lane);
      if (lane_head[lane]->next==lane_tail[lane]){
            printf("Queue is empty\n");
      } else {
          temp = lane_head[lane]->next;
          while((temp!=lane_tail[lane])) {
                if(strcmp(temp->reg_no,reg)==0){
                      temp->prev->next = temp->next;
                      temp->next->prev = temp->prev;
                      temp->next=NULL;
                      temp->prev=NULL;
                      free(temp);
                      car_count--;
                      lane_count[lane]--;
                      printf("Car DEPARTED\n");
                      break;
                }
                temp = temp->next;
          }
      }
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
            printf("((%s|] ~ ", temp->reg_no);
            temp= temp->prev;
      }
      printf("\n");
}

/*search a car in every lane sequentialy and then return lane no*/
int search(char reg[]) {
     struct node *temp;
     int i,flag=0,lane;
     for(i=0;i<5;i++) {
           lane=i;
           if (lane_head[lane]->next == lane_tail[lane]) {
                  //printf("Lane_%d is empty\n",lane);
                  return -1;
            }
            
            temp = lane_tail[lane]->prev;
            while(temp!=lane_head[lane]) {
                  if(strcmp(reg,temp->reg_no)==0) {
                        printf("%s Car is in %d Lane arrived at %d time \n",reg,i+1,temp->data);
                        flag=1;
                        break;
                  }
                  temp= temp->prev;
            } if(flag==1) {
                  break;
            }
     } if(flag==0) {
           printf("no vehical found\n");
           return -1;
     }
     return lane;
}

/*display current parking lanes*/
void show_parking() {
      int i=0;            
      for(i=0;i<5;i++) {
            display(i);
      }      
}

int menu() {
      int choice;
      printf("\ncontinue(1),exit(0)\n");      
      scanf("%d",&choice);
      if(choice==1) {
            printf("______________________________________________________\n");
            printf("\nPress 0 For Exit\n");
            printf("Enter Your Choice\n");
            printf("1. Show Parking Lanes\n");
            printf("2. Show Specific Lane\n");
            printf("3. Add a New Car\n");
            printf("4. Remove a Car\n");
            printf("5. Search a Car\n");
            printf("______________________________________________________\n");
            scanf("%d",&choice);      
      }      
      return choice;      
}

/*remove car first search than remove car*/
void remove_car(char reg[]) {
      int lane=search(reg);
      if(lane>=0){
            dequeueAtSpecial(reg,lane);
      }
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
                  case 3: printf("Enter reg_no: \n");
                        scanf("%s",reg_no);
                        printf("Enter time\n");
                        scanf("%d",&tim);
                        if(time_unit<=tim) {
                              time_unit=tim;
                              //printf("%s %d\n", reg_no,tim);
                              car_count++;
                              car_insert(tim,reg_no,(car_count-1)%5);  
                        } else {
                              printf("INVAILD TIME\n");
                        }
                        break;
                  case 4: printf("Enter the regestration num \n");scanf("%s",reg_no);remove_car(reg_no);break;
                  case 5: printf("Enter the regestration num \n");scanf("%s",reg_no);search(reg_no);break;
                  default: printf("wrong choice\n");
            }
      }
}