/*
* Joshua Beaty
* 4883
* 09/02/2021
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  //create integer to hold incoming cycle data
  int inData = 0;
  cin >> inData;
  
  //loop as long as incoming cycle data is greater than 0
  while(inData){
    //create array of light cycles 'lightCycles' of size 110, 110 is enough to hold all cycle data
    int lightCycles[110];
    int count = 0;
    int shortestCycle = 999;
    //loop as long as incoming cycle data is greater than 0
    while(inData){
      //put cycle data in array 'lightCycles'
      lightCycles[count] = inData;
      //store shortest cycle data
      if(inData < shortestCycle)
        shortestCycle = inData;
      //grab next cycle data
      cin >> inData;
      //increase count for array filling purposes
      count++;
    }
    //create an int for current time in seconds
    //don't need to start at 0 data doesn't matter until shortest light turns green again.
    int currentSecond = (shortestCycle*2);
    //create a boolean for synchrony
    bool inSync = false;
    //while time is less than 18000 seconds or five hours
    while(currentSecond <= 18000 && !inSync){
      //boolean for synchrony, will turn false if orange/red light is found
      bool greenLights = true;
      //loop through light cycles for the current time
      for(int i = 0; i < count; i++){
        //figure out how many times to increment current light cycle based on current time
        int increment = currentSecond / lightCycles[i];
        //if increment is even then it's possible for it to be green, else break
        if(increment % 2){
          greenLights = false;
          break;
        }
        //figure out current cycle = incrementation + green light time
        int currentCycle = (lightCycles[i]*increment) + (lightCycles[i]-5);
        //find difference in time between now and current cycle, this is the remaining green time
        int timeDiff = currentCycle - currentSecond;
        //if timeDiff is greater than 0, we have a green light, check the next lightCycles[i]
        //else, break current time
        if(timeDiff <= 0){
          greenLights = false;
          break;
        }
      }
      //increase current time
      currentSecond++;
      //flip inSync if lights are all green
      if(greenLights)
        inSync = true;
    }
    //if inSync, print out timeframe, else print 5 hour failure message
    if(inSync){
      currentSecond--;
      int hr = currentSecond / 3600;
      currentSecond = currentSecond % 3600;
      int min = currentSecond / 60;
      currentSecond = currentSecond % 60;
      cout << setfill('0');
      cout << setw(2) << hr << ':';
      cout << setw(2) << min << ':';
      cout << setw(2) << currentSecond << '\n';
    }
    else{
      cout << "Signals fail to synchronise in 5 hours\n";
    }
    //current inData should be 0, if another is found, terminate program
    cin >> inData;
    if(!inData){
      //cout << "Multiple consecutive zeros found, terminating.\n\n";
      return 0;
    }
  }
}