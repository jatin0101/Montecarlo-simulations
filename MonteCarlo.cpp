#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
    int timesteps = 30;
    int volatility = 2;  //2 %
    int max_simulations = 5000;
    float starting_price = 600;
    float path[max_simulations][timesteps+1];
    // Timesteps + 1 is for the starting price at Day 0 to be at the start of every array 
    
    srand(time(0));
    for(int j=0;j<max_simulations;j++) path[j][0]=starting_price;
    for(int p=0;p<max_simulations;p++)
    {
        for(int i=1;i<=timesteps;i++)
        {
            float rand_rate=(float)(rand()-RAND_MAX/2)*volatility*2/RAND_MAX;
            path[p][i]=path[p][i-1]*(1+rand_rate/100);
        }
    }
   
    ofstream outputfile;
    outputfile.open("paths.txt");

    for(int i = 0; i<max_simulations; i++)
    {
        for(int j = 0; j<(timesteps+1); j++)
        {
            outputfile<<path[i][j]<<" ";
        }
        outputfile<<endl;
    }
    outputfile.close();


}