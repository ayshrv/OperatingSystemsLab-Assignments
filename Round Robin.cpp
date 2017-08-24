/*input
5
5 3 2 1 4
1
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int burst[n];
    int temp[n];
    int turnAround[n];
    int waiting[n];
    for(int i=0;i<n;i++){
        cin >> burst[i];
        temp[i]=burst[i];
    }
    int TQ;
    cin >> TQ;
    int curr_time=0;
    int count=0;
    while(count<n){
        for(int i=0;i<n;i++){
            if(temp[i]!=0){
                if(temp[i]>TQ){
                    temp[i]-=TQ;
                    curr_time+=TQ;
                }
                else{
                    curr_time+=temp[i];
                    temp[i]=0;
                    turnAround[i]=curr_time;
                    count++;
                }
            }
        }
    }
    double totalTurnAround=0;
    double totalWaiting=0;
    double avgTurnAround,avgWaiting;
    for(int i=0;i<n;i++){
        totalTurnAround+=turnAround[i];
    }
    for(int i=0;i<n;i++){
        waiting[i]=turnAround[i]-burst[i];
        totalWaiting+=waiting[i];                                                                                                                                                                                                                                                                                                                                                                               
    }
    avgTurnAround=totalTurnAround/n;
    avgWaiting=totalWaiting/n;
    for(int i=0;i<n;i++){
        cout << "Waiting time-" << waiting[i] << "  TurnAroundTime-" << turnAround[i] << endl;
    }
    cout << "Average waiting time is:" << avgWaiting << endl;
    cout << "Average TurnAround Time is:" << avgTurnAround << endl;
	return 0;
}
