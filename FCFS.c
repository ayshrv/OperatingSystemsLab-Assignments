#include<stdio.h>

int main(){
    int n,wt=0,tat=0;
    float awt,atat,_awt=0,_atat=0;
    printf("Enter number of processes :");
    scanf("%d",&n);
    int exet[n];
    int i;
    for(i=0;i<n;i++){
        printf("Enter execution time of process %d:",i+1);
        scanf("%d",&exet[i]);
    }
    printf("Process \t Time \t Wait Time \t TurnAround");
    for(i=0;i<n;i++){
        tat = exet[i] + wt;
        printf("\n%d \t\t %d \t %d \t\t %d",i+1,exet[i],wt,tat);
        _awt += wt;
        _atat += tat;
        wt += exet[i];
    }
    awt = _awt/n;
    atat = _atat/n;
    printf("\nAverage waiting time=%.2f",awt);
    printf("\nAverage turn around time=%.2f\n",atat);

return 0;
}