#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "function.h"
#include <unistd.h>

int insert(int number, int id, int day, int month, int year);
void deletes(int number, int d, int m, int y);
void display(void);
int datetoday(int d, int m, int y); //เปลี่ยนวันที่ให้เป็นหน่วยวัน
int checkdate(int d, int m, int y); //ดูว่าวันที่ถูกต้องไหม
int sort(void); // sort per ของจักรยาน
int selection(int x[], int y[], int n);
void swap(int *, int *);
void return_menu(void); //กดยืนยันเพื่อกลับไปหน้าเมนู
void assignuse();

int main(void) {
  system("clear"); //clear screen
  head = NULL;
  int menu, stdid, bikeid, day, month, year;
  int i;   // count
  int tem=0; // ไว้รับค่า เลขจักรยานที่ได้จาก sort() , default int tem

  assignuse();
  while (1) 
  {
    printf("\nWelcome to JakkaCenter :P \n");
    printf("=======================\n");
    printf("1. Rent a bike \n");         // Insert
    printf("2. Return a bike\n"); // Delete
    printf("3. Display \n");
    printf("4. Exit \n");
    printf("========================\n");

    printf("\nEnter the choice : ");
    scanf("%d", &menu);
    printf("\n");

    switch (menu) {
    case 1:
      tem = sort();
      if(tem == 0)
      {
        printf("\n========================");
        printf("\nThe bike has been booked out.\n");
        printf("========================\n");
      }
      else{
      printf("Put your studentID : ");
      scanf("%d", &stdid);
      printf("Your bike number is %d\n",tem);
      printf("Put date(dd/mm/yyyy) : ");
      i = 0;
      while (i == 0) {
        scanf("%d/%d/%d", &day, &month, &year);
        if (checkdate(day, month, year) == 0) {
          printf("Please enter a valid date Ex.(12/12/2022) : ");
        } else
          i = 1;
      }
      if (insert(stdid, tem , day, month, year) == 0) {
        printf("\n========================");
        printf("\nYou already booked.\n");
        printf("========================\n");
      } else {
        printf("\n========================");
        printf("\nSuccessfully booked\n");
        printf("========================\n");
      }
        }
      return_menu();
      break;
    case 2:
      if (head == NULL) {
        printf("\n========================");
        printf("\nNot have any booking yet.\n");
        printf("========================\n");
        return_menu();
        break;
      }
      printf("Put your studentID : ");
      scanf("%d", &stdid);
      printf("Put date(dd/mm/yyyy) : ");
      i = 0;
      while (i == 0) {
        scanf("%d/%d/%d", &day, &month, &year);
        if (checkdate(day, month, year) == 0) {
          printf("Please enter a valid date(dd/mm/yyyy) : ");
        } else
          i = 1;
      }
      deletes(stdid, day, month, year);
      return_menu();
      break;
    case 3:
      display();
      return_menu();
      break;
    case 4: // free all node
        printf("\n========================\n");
        printf("Thank you for using the service.\n");
        printf("========================\n");
      return 0;
      break;
    default:
      printf("Invalid choice \n");
      return_menu();
    }
  }
  return 0;
}
