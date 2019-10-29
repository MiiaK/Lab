#include<stdio.h>
#include"nod.h"

int main()
{
  float fnumber;
  printf("Give your first node data! \n");
  if (scanf("%f",&fnumber)==1)
  {
    printf("Your first data value is: %.3f \n", fnumber);
  }
  else
  {
  printf("Bad input! The data will be 0 instead. \n");
  fnumber=0;
  }
  struct node rot={fnumber, NULL, NULL};
  struct node *pointer = &rot;

  /*Loop beginning for options */
  int i=0;
  int leave=0;
  while(leave==0)
  {
    switch (i) {
      case 1:
        printf("How many steps do you want to move? Use +/- integer value!\n");
        if (scanf("%d",&i )==1)
        {
          pointer=move(pointer,i);
        }
        else
        {
        printf("Bad input! \n");
        }
        break;
      case 2:
        printf("Write data! \n");
        if (scanf("%f",&fnumber)==1)
        {
          setdata(pointer, fnumber);
        }
        else
        {
          printf("Bad input! \n");
        }
        break;
      case 3:
        printf("Do you want to add a node to the 1. left or the 2. right of current node? any other int to return\n");
        if (scanf("%d",&i)==1)
        {
          switch (i) {
            case 1:
            insertleftnode(pointer);
            break;
            case 2:
            insertrightnode(pointer);
            break;
            default:
            break;
          }
        }
        else
        {
          printf("Bad input! \n");
        }
        break;
      case 5:
        if (pointer->next==NULL&&pointer->previous==NULL) {
          printf("This is the last node! Returning to main. \n");
        }
        else if (pointer->next==NULL)
        {
          printf("Removing pointer and moving to the left. \n");
          pointer=pointer->previous;
          del(pointer->next);
        }
        else
        {
          printf("Removing pointer and moving to the right. \n");
          pointer=pointer->next;
          del(pointer->previous);
        }
        break;
      case 7:
      leave=1;
      break;
      default:
      i=0;
      break;

    }
    if (leave!=1){
      printf("The current data value is %.3f \nOptions: \n", getdata(pointer));
      printf("1. Move \n");
      printf("2. Change data for current node \n");
      printf("3. Add new node! \n");
      printf("5. Remove current node \n");
      printf("7. Quit program \n");
      while(scanf("%d",&i)!=1){
        printf("Bad input! Here 1\n");
      }
    }
  }


  return 0;
}
