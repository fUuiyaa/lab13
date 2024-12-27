#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double num[],int howmany,double ans[]){
    double ans2=0;
    ans[0]=0;
    ans[2]=0;
    double sum=1;
    double sum2=0;
    for(int i=0;i<howmany;i++){
        ans[0]+=num[i];
        ans2 += pow(num[i],2);
    }

    ans[0]/=howmany;
    ans[1]= sqrt((ans2/howmany)-pow(ans[0],2));

    for(int j=0;j<howmany;j++){
        sum*= num[j];
        
    }
    ans[2]= pow(sum,1.0/howmany);

    for(int k=0; k<howmany; k++){
        sum2 += 1.0/num[k];
    }
    ans[3]=howmany/sum2;

    ans[4]=num[0];
    ans[5]=num[0];
    for(int l=1; l<howmany; l++){
        if(ans[4]<num[l]) ans[4] = num[l];
        if(ans[5]>num[l]) ans[5] = num[l];
    }
}