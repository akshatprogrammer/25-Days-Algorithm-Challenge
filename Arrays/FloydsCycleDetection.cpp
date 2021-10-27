#include<iostream>
using namespace std;
bool floydCycleDetection(Node* root){
    // we will create two pointers.
    Node *slow=Node* fast = root;
    while(slow and fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
        return false;
    }
}
void main(){
  cout <<  floydCycleDetection();
}