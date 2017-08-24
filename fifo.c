/*input
4
1 2 3 4
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("%d\n",n);
	int burstTime[n+1];
	int waitTime[n+1];
	int turnTime[n+1];
	int i;
	for(i=0;i<=n;i++){
		waitTime[i]=0;
		turnTime[i]=0;
	}
	burstTime[0]=0;
	double avgWait=0,avgTurn=0;

	printf("Enter execution Time for each process:\n");
	for(i=1;i<=n;i++){
		scanf("%d",&burstTime[i]);
	}	printf("Enter the number of processes: ");

	for(i=1;i<=n;i++){
		waitTime[i]=waitTime[i-1]+burstTime[i-1];
		turnTime[i]=turnTime[i-1]+burstTime[i];
		avgWait+=waitTime[i];
		avgTurn+=turnTime[i];
	}

	avgWait=avgWait/n;
	avgTurn=avgTurn/n;

	for(i=1;i<=n;i++){
		printf("Process No.%d  Waiting Time: %d Turn Around Time: %d \n",i,waitTime[i],turnTime[i]);
	}
	printf("Average wait time = %lf   Average TurnAround Time = %lf",avgWait,avgTurn);
	return EXIT_SUCCESS;
}
