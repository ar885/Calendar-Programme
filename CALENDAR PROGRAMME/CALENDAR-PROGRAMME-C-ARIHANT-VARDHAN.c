                                              //gregorian calendar
#include <stdio.h>
#include <stdlib.h>

int yearlyCalendar(){	
            int year,month,day,daysInMonth,weekDay=0,firstDay;
	
	        int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
	        char *months[]={"January","Feburary","March","April","May","June","July","August","September","October","November","December"};	
	        
        	printf("\nEnter your desired year:(YYYY) ");
			scanf("%d",&year);
			if(year%4==0&&year%100!=0){
		      monthDay[1]=29;
	        }	
	        else if(year%400==0){
	          monthDay[1]=29;
			}	
	       else{
	          monthDay[1]=28;
          	}
			firstDay=get_First_weekday(year);
			for(month=0;month<12;month++){
				daysInMonth=monthDay[month];
				printf("\n\n--------------------%s----------------------",months[month]);
				printf("\n   SUN  MON  TUE  WED  THU  FRI  SAT\n");
				for(weekDay=0;weekDay<firstDay;weekDay++){
					printf("     ");
				}
				for(day=1;day<=daysInMonth;day++){
					
					printf("%5d",day);
					
					if(++weekDay>6){
						printf("\n");
						weekDay=0; //It is essential to again initialize it to zero otherwise it will only run ones 
					}
					firstDay=weekDay;
				}
			}
}

int monthlyCalendar(){
	            int year,month,day,daysInMonth,weekDay=0,firstDay;
	
	        int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
	        char *months[]={"January","Feburary","March","April","May","June","July","August","September","October","November","December"};	
	        
        	printf("\nEnter your desired year:(MM  YYYY)  ");
			scanf("%d%d",&month,&year);
			if(month<=12){
			if(year%4==0&&year%100!=0){
		      monthDay[1]=29;
	        }	
	        else if(year%400==0){
	          monthDay[1]=29;
			}	
	       else{
	          monthDay[1]=28;
          	}
          	firstDay=dayOfWeek(month,year);
          	month=month-1;
				daysInMonth=monthDay[month];
				printf("\n\n--------------------%s----------------------",months[month]);
				printf("\n   SUN  MON  TUE  WED  THU  FRI  SAT\n");
				printf("\n");
				for(weekDay=0;weekDay<firstDay;weekDay++){
					printf("     ");
				}
				for(day=1;day<=daysInMonth;day++){
					
					printf("%5d",day);
					
					if(++weekDay>6){
						printf("\n");
						weekDay=0; //It is essential to again initialize it to zero otherwise it will only run ones 
					}
					firstDay=weekDay;
				}
			}
			else{
				printf("Month cannot be greater than 12");
			}
}

int dayOfWeek(int m,int y){
	int d=1;
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if(m<3)
	 {y=y-1;
	 }
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

int get_First_weekday(int year){
	int day;
	day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7; // this algo will return 0 for Sunday and 6 for Saturday only works for january
	return day;
}

int main()
{
	system("Color 0F"); //System fn is called here to add back ground color 0= black and text color F= white
	int choice;
	do{
	printf("\n\n------------------------------------\n");
	printf("PRESS :\n 1.Show calendar for whole year\n 2.show monthly calendar\n 3.EXIT" );
	printf("\n------------------------------------\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			yearlyCalendar();
			break;
		case 2:
			monthlyCalendar();
			break;
		case 3:
			printf("\nExiting program\n");
			break;
		default:
			printf("\nEntered choice doesn't exist ... please enter correct value\n ");
	}
}while(choice!=3);
return 0;
}
