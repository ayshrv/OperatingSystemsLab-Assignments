/*input
5
0 5
2 3
3 1
4 6
5 3
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    int arrival;
    int burst;
};

bool fun(node edge1,node edge2){
    return (edge1.arrival<edge2.arrival);
}

bool fun2(node edge1,node edge2){
    return (edge1.burst<edge2.burst);

}

int main() {
    int n;
    cin >> n;
    node arrival_burst[n];
    int completion[n]={0};
    int waiting[n];
    int turnAround[n];
    int aux[n]={0};
    for(int i=0;i<n;i++){
        cin >> arrival_burst[i].arrival >> arrival_burst[i].burst;
    }
    sort(arrival_burst,arrival_burst+n,fun2);
    sort(arrival_burst,arrival_burst+n,fun);
    for(int i=0;i<n;i++){
        cout << arrival_burst[i].arrival <<" "<< arrival_burst[i].burst << endl;
    }
    int curr_time=0;
    int count=0;
    int i=0;
    int j=0;
    int complete;
    vector<int> vec;
    while(j<n){
        while(i<n && arrival_burst[i].arrival<=curr_time){
            vec.push_back(arrival_burst[i].burst);
            aux[i]=1;
            i++;
        }
        if(vec.size()==0){
            curr_time=arrival_burst[i].arrival;
        }
        else{
            sort(vec.begin(),vec.end());
            curr_time+=vec[0];
            int index=-1;
            for(int k=0;k<n;k++){
                if(aux[k]==1 && arrival_burst[k].burst==vec[0]){
                    aux[k]=2;
                    index=k;
                }
            }
            vec.erase(vec.begin());
            completion[index]=curr_time;
            j++;
        }
    }
    double totalTurnAround=0;
    double totalWaiting=0;
    double avgTurnAround,avgWaiting;
    for(int i=0;i<n;i++){
        turnAround[i]=completion[i]-arrival_burst[i].arrival;
        totalTurnAround+=turnAround[i];
    }
    for(int i=0;i<n;i++){
        waiting[i]=turnAround[i]-arrival_burst[i].burst;
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
