#include<stdio.h>


void input();     // for taking inputs from user...
void job_scheduler();    // for scheduling according to priority..
void Round_Robin();     //  round_robin algorithm implmentation
void result();			//   for displaying results....

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

