#include<stdio.h>

struct process			            // process structure
{
	int pid;
	int Arrival_time;
	int burst_time;
	int completion_time;
	int remaining_burst_time;
} faculty[100], student[100], m[100];     // Queues for Faculty and Students.......


void input();                             // for taking inputs from user...
void job_scheduler();                    // for scheduling according to priority..
void Round_Robin();                      //  round_robin algorithm implmentation
void result();	        	        //   for displaying results....

int a, fac=0, stu=0, mc=0;              // Global variables
int time_quanta;


void input()                           // function taking inputs from user...
{
	int map,  i, j;
	printf("Enter Total number of Queries: "); 
	scanf("%d", &a);
	
	if(a==0)
	{ 
		printf("\n No queries\n"); 
	}
	
	else
	{
			printf("\nEnter Time_Quanta for each Process: "); 
			scanf("%d", &time_quanta);
				
			int qno = 1 ;
			for(i=0; i<a; i++)
			{
				
				printf("\nQuery:%d",qno);
				printf("\nEnter 1 for faculty and 2 for student  process Type (1 or 2): "); 
				scanf("%d", &map);
				if(map==1)
				{
					printf("\nprocess Id: "); 
					scanf("%d", &faculty[fac].pid);
					printf("Arrival Time (Enter in \"1000\" format) (1000 - 1200) : ");
					scanf("%d", &j);
				
					if(j<1000 || j>1200)
					{
						system("cls");
						printf("\nPlease Enter Correct time\n\n");
						input();
					}
					
					else
					{
						faculty[fac].Arrival_time= j-1000;
					}
					printf("Burst Time: "); 
					scanf("%d", &faculty[fac].burst_time);	 
					faculty[fac].remaining_burst_time= faculty[fac].burst_time; 
					fac++;
					}
				 	else
					{
						printf("Process Id: "); 
						scanf("%d", &student[stu].pid);
						printf("Arrival Time (Enter in \"1000\" format) (1000 - 1200) :"); 
						scanf("%d", &j); 
						if(j<1000 || j>1200)
						{
							system("cls");
							printf("\nPlease Enter Correct time\n\n");
							input();
						}
					else 
					{
						student[stu].Arrival_time= j-1000; 
					}
						printf("Burst Time: "); 
						scanf("%d", &student[stu].burst_time);	 
						student[stu].remaining_burst_time= student[stu].burst_time;
						stu++;
					}
			qno++;
			}
	}
	
}

void Round_Robin()                     // Applying Round-Robin Algorithm....
{
	int time= m[0].Arrival_time, mark=0, cc=0, i, rc;
	while(time!=120 && cc!=mc)
	{
		for(i=0; i<=mark; i++)
		{
			if(m[i].remaining_burst_time > time_quanta)
			{
				time += time_quanta;
				m[i].remaining_burst_time -= time_quanta;
			}
			else if(m[i].remaining_burst_time <=time_quanta && m[i].remaining_burst_time !=0)
			{
				time += m[i].remaining_burst_time;
				m[i].remaining_burst_time =0;
				m[i].completion_time = time;
				cc++;
			}
			
		}
		int start = mark+1;
		for(rc= start; rc<mc; rc++)
		{
			if(m[rc].Arrival_time <= time)
			{
				mark++;
			}
		}
	}	
}


int main()
 {
 		
 		printf("\t\t ONLINE QUERY HANDLER \t\t\n ");
	 	printf("\nWelcome,\nplease follow given instruction in the program\n\n");
	 	
	 	input();
		job_scheduler();
		Round_Robin();
		result();
		
		return(0);
}


