#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool debug = false;

vector<string> addToRaffleVector(string name, int num, vector<string> raffleVector){
//Adds the specified person to the vector "num" times

    if(debug)
        cout<<"Filling with params: "<<name<<", "<<num<<endl;
        //Prints it out, debug only

    for(int i = 0; i<num; i++){
        raffleVector.push_back(name);
    }
    //Pushes the string to the vector "num" times, position does not matter
    return raffleVector;
}

vector<string> fillRaffleVector(){
    //Calls the addToRaffleVector with each person

    vector<string> raffleVector;

    string owner1 = "Zink";
    int owner1entries = 91;
    string owner2 = "Berger";
    int owner2entries = 1;
    string owner3 = "Owen";
    int owner3entries = 1;
    string owner4 = "Leonard";
    int owner4entries = 1;
    string owner5 = "Max";
    int owner5entries = 1;
    string owner6 = "Andrew";
    int owner6entries = 1;
    string owner7 = "Parker";
    int owner7entries = 1;
    string owner8 = "Jake";
    int owner8entries = 1;
    string owner9 = "Harold";
    int owner9entries = 1;
    string owner10 = "Sean";
    int owner10entries = 1;

    raffleVector = addToRaffleVector(owner1, owner1entries, raffleVector);
    raffleVector = addToRaffleVector(owner2, owner2entries, raffleVector);
    raffleVector = addToRaffleVector(owner3, owner3entries, raffleVector);
    raffleVector = addToRaffleVector(owner4, owner4entries, raffleVector);
    raffleVector = addToRaffleVector(owner5, owner5entries, raffleVector);
    raffleVector = addToRaffleVector(owner6, owner6entries, raffleVector);
    raffleVector = addToRaffleVector(owner7, owner7entries, raffleVector);
    raffleVector = addToRaffleVector(owner8, owner8entries, raffleVector);
    raffleVector = addToRaffleVector(owner9, owner9entries, raffleVector);
    raffleVector = addToRaffleVector(owner10, owner10entries, raffleVector);

    return raffleVector;
}

vector<string> deleteName(vector<string> raffleVector, string name){
//Deletes the person who was just selected by looping through from the end and deleting any
//string that matches the name value

    if(debug)
        cout<<"Deleting "<<name<<endl;

    for(int i=raffleVector.size()-1; i>=0; i--){
        if(raffleVector[i] == name){
            raffleVector.erase(raffleVector.begin() + i);
        }
    }
    return raffleVector;
}

void getPercentages(vector<string> raffleVector){
//Prints out the percentages for each member based on the order they were added to the vector

    double iTracker = 0;
    double percentTracker = 1;
    double percent;
    for(int i=1; i<raffleVector.size(); i++){
        if(raffleVector[i] == raffleVector[iTracker]){
            percentTracker++;
        }
        //If they match, increment
        else{
            percent = (percentTracker/raffleVector.size())*100;
            cout<<raffleVector[iTracker]<<": "<<percent<<"% chance"<<endl;
            iTracker = i;
            percentTracker = 1;
        }
        //If they don't match, calculate and print percentages, then set the tracker values to the current positions
    }
}

void printVector(vector<string> vecTemp){
//Just prints the vector, debug only
    for(int i = 0; i<vecTemp.size(); i++){
        cout<<vecTemp[i]<<endl;
    }
}

vector<string> getSelection(vector<string> raffleVector){
    int vectorSizeSubOne = raffleVector.size() - 1; //Used for random calculation

    int randVal = rand() % vectorSizeSubOne + 0; //Get the random value

    if(randVal > vectorSizeSubOne){ //So it can't go out of bounds
        randVal = vectorSizeSubOne;
    }

    cout<<"[The pick is "<<raffleVector[randVal]<<".]"<<endl;
    raffleVector = deleteName(raffleVector, raffleVector[randVal]);
    //Delete the selected pick
    return raffleVector;
}

int main(){

    vector<string> raffleVector;

    raffleVector = fillRaffleVector(); //Fill the vector

    srand (time(NULL)); //Set the random seed based on time

    cout<<"Welcome to the raffle process! Before every selection, the percentages will be displayed, and a selection will be made."<<endl;
    while(raffleVector.size() != 0){

        if(debug)
            printVector(raffleVector);

        system("pause");
        getPercentages(raffleVector);
        system("pause");
        raffleVector = getSelection(raffleVector);
        cout<<"-----------------------------------------------"<<endl;

    }

return 0;

}
