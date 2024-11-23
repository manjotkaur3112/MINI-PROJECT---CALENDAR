#include <stdio.h>
#include <stdlib.h>

int enetr_leap_year(year)
{
  int d;
  d = (((year - 1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
  return d;
}

int main()
{
    int year,month,day,daysInMonth,weekDay=0,startingDay;
    printf("Enter year \n");
    scanf("%d",&year);
    printf("Entered year : %d\n",year);
    printf("%d is a leap year.\n",year);
    printf("\n***********Display %d Calendar***********",year);
    
    
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if((year%4==0 && year%100!=0)||year%400==0)
    monthDay[1] = 29;
    
    startingDay = enetr_leap_year(year);
    
    for(month=0; month<12; month++)
    {
      daysInMonth = monthDay[month];
      
      printf("\n\n  ---------------- %s ---------------\n",months[month]);
      printf("   SUN   MON   TUE   WED   THU   FRI   SAT\n");
      printf("  -----------------------------------------\n");
      
      for(weekDay=0; weekDay<startingDay; weekDay++)
      printf("      ");
      
      for(day=1; day<=daysInMonth; day++)
      {
        printf("%6d",day);
         
        if(++weekDay>6){
          weekDay=0;           
          printf("\n");
        }
        startingDay = weekDay;
      }
    }
    return 0;
}