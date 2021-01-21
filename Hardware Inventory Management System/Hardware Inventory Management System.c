//Hadware Inventory Management System. (input, display, delete, update)
// delete function not working properly isse dekhna hai mujhe. return h masla krrha hai, file me sahi store bh nahi horaha.
#include<stdio.h>
#include<conio.h>
#include<windows.h>

struct hardware {
  int RecNum;
  char toolname[20];
  int quantity;
  float cost;
};

// Declaring all the functions
int front(void);
struct hardware * input_records(FILE * );
void display_records(struct hardware * , FILE * );
struct hardware* delete_records(struct hardware * );
void update_records(struct hardware * );

// main function
int main() {
  FILE * fp;
  struct hardware * ptr, *hs;
  int ch;
  system("COLOR 3E");

  ch = front();
  while (1) {
    switch (ch) {
    case 1:
      ptr = input_records(fp);
      break;
    case 2:
      display_records(ptr, fp);
      break;
    case 3:
      hs=delete_records(ptr);
      break;
    case 4:
      update_records(ptr);
      break;
    case 5:
      exit(0);
    default:
      printf("\n\n\t\t\t Invalid choice.");
      break;
    }
    printf("\n\nPress any key to go back to main menu...");
    getch();
    ch = front();
  }

  getch();
  return 0;
}
int front() {
  int ch;
  system("cls");
  printf("\n\n\t\t\t HARDWARE INVENTORY MANAGEMENT SYSTEM");
  printf("\n\n\n\t\t\t 1. Input Tools");
  printf("\n\t\t\t 2. Display Tools");
  printf("\n\t\t\t 3. Delete Tools");
  printf("\n\t\t\t 4. Update Tools");
  printf("\n\t\t\t 5. Exit Program");
  printf("\n\n\t\t\t Enter your choice\t");
  scanf("%d", & ch);
  return ch;
}
struct hardware * input_records(FILE * fp) {
  int i;
  static struct hardware h[5];

  system("cls");
  fp = fopen("hardware.dat", "w");
  if (fp == NULL) {
    printf("\n File not found");
  } else {
    for (i = 0; i < 5; i++) {
      printf("\nEnter Record Number, Tool Name, Quantity and Cost for Tool %d :\n", i + 1);
      scanf("%d", & h[i].RecNum);
      fflush(stdin);
      gets(h[i].toolname);
      scanf("%d%f", & h[i].quantity, & h[i].cost);
    }
    fwrite( & h, sizeof(h), 5, fp);
    fclose(fp);
  }
  return h;
}

void display_records(struct hardware * ptr, FILE * fp) {
  int i;
  system("cls");
  fp = fopen("hardware.dat", "r");
  if (fp == NULL)
    printf("\n Can't open file");
  else {
    printf("\n\n\t\t DISPLAYTING RECORDS \n");
    for (i = 0; i < 5; i++) {
      printf("\n\n Record Number \t : %d\n Tool Name\t : %s\n Quantity \t : %d\n Cost of tool \t : %.2f", ptr->RecNum, ptr->toolname, ptr->quantity, ptr->cost);
      ptr++;
    }
  }
}

struct hardware* delete_records(struct hardware * ptr) {
  struct hardware h[5];
  int i, num, j = 0;
  system("cls");

  printf("\n\nDisplaying Records For User Help.\n");
  printf("Rec_Num\tTool Name\n");

  for (i = 0; i < 5; i++) {
    printf("%d\t%s\n", ptr->RecNum, ptr-> toolname);
    ptr++;
  }
  ptr -= 5; // bringing pointer to its orignal position
  
  printf("\n\n Enter the Record Number that you want to delete\t");
  scanf("%d", & num);

  for (i = 0 ; i < 5; i++, ptr++) {
    if (ptr-> RecNum == num)
    	continue;  
    else {
          	h[j].RecNum=ptr->RecNum;
          	strcpy(h[j].toolname,ptr->toolname);
          	h[j].quantity=ptr->quantity;
       		h[j].cost=ptr->cost;
       		j++;
    }
  }
  printf("\nRecord Successfuly deleted.");
  
  FILE * fp = fopen("hardware.dat", "w");
   if (fp == NULL)
    printf("\n Can't open file");
   else{
   	fwrite(&h,sizeof(h),j,fp);
   }
   fclose(fp);
   return h;
   
}
void update_records(struct hardware * ptr) {
  int num, choice, a, i, c = 0;
  float b;
  char ch, name[20];

  system("cls");
  printf("\n\nDisplaying Records For User Help.\n");
  printf("Rec_Num\tTool Name\t\tQuant\tCost\n");
  for (i = 0; i < 5; i++, ptr++)
    printf("%d\t%s\t\t%d\t%.2f\n", ptr-> RecNum, ptr-> toolname, ptr-> quantity, ptr-> cost);
  ptr -= 5; // bringing pointer to its orignal position

  do {
    c = 0;
    printf("\n\nEnter the Record Num that you want to update?\t");
    fflush(stdin);
    scanf("%d", & num);
    for (i = 0; i < 5; i++, ptr++) {
      if (ptr -> RecNum == num) {
        printf("\nWhat do you want to update? \n 1. Rec num.\n 2. Tool Name \n 3. Quantity \n 4. Cost \t\t");
        scanf("%d", & choice);
        
        if (choice == 1) {
          printf("\nEnter new record number : \t");
          scanf("%d", & a);
          ptr -> RecNum = a;
        } 
		else if (choice == 2) {
          printf("\nEnter new tool name : \t");
          fflush(stdin);
          gets(name);
          strcpy(ptr -> toolname, name);
        } 
		else if (choice == 3) {
          printf("\nEnter new quantity : \t");
          scanf("%d", & a);
          ptr -> quantity = a;
        } 
		else if (choice == 4) {
          printf("\nEnter new cost : \t");
          scanf("%f", & b);
          ptr -> cost = b;
        }
        c++;
      }
    }
    ptr -= 5; // bringing pointer to its orignal position
    if (c == 0)
      printf("\nNo Records dound");
    printf("\nDo you want to update any other record ? (y/n)\t");
    ch = getche();
  } while (ch == 'y');
}
