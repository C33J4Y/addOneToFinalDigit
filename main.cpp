#include <iostream>
#include <vector>

using namespace std;

/*
Using an array to store each digit of a number, add one to the final digit. 

example:
[3,4,5] =  345 -> [3,4,6] = 346
[9,9,9] = 999 -> [1,0,0,0] = 1000
 
*/

int main() {
  int arr[3] = {4,9,9};
  int carry = 1;
  int size = sizeof(arr)/(sizeof(arr[0]))-1;
  vector<int> v; // Vector declaration
  int sumHolder = 0; // variable to store sum

 //Start at last index of the array and add 1 from carry.
 for(int i = size; i >= 0; i--){
   sumHolder = arr[i] + carry; 
   if(sumHolder >= 10){  //if result is 10 or greater push_back() remainder
     v.push_back(sumHolder % 10);
     carry = 1; // set carry to 1
   }else{
     v.push_back(sumHolder); // otherwise push_back sumholder
     carry = 0;
   }
 }
 if(carry == 1){
   // in the case of 999, we will need a fourth digit. push_back 1 into vector
   //and set carry to 0.
   v.push_back(carry); 
   carry = 0;
 }

//print out vector from last index to the first index. 
for(int i = v.size()-1; i >= 0; i--){
  cout << v[i];
}
}