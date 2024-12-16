#include<iostream>
using namespace std;
struct Node {
    int value;
    Node * next;
};

Node* start = NULL ;

//Add an element in the list
void add (int value){
    Node* newnode = new Node();
    newnode->value=value;
    newnode->next=NULL;
    if(start == NULL){
        start = newnode;
    }
    else {
        Node* temp = start;
        while((temp->next)!=NULL){
            temp=temp->next;
        }
        temp->next= newnode;
    }
    cout<<"node added sucssesfully"<<endl;
}

//delete the last element of the list
void popback(){
    Node* temp = start;
    if(temp==NULL){
        cout<<"empty list";
    }
    else if(temp->next==NULL){
       free(temp->next);
       start=NULL;
       cout<<"deleted successfully"<<endl;
    }
    else{
    while((temp->next)->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    cout<<"deleted successfully"<<endl;
    }
}

//check if an element exist in the list or not
bool existornot (int val){
    Node* temp = start;
    if(temp==NULL){
        return 0;
    }
    else{
    while(temp->next!=NULL){
        if(temp->value == val){
            return 1;
        }
        temp=temp->next;
    }}

    if(temp->value==val){
        return 1;
    }
    else{
        return 0 ;
    }
}

//enter an element and it will be deleted if it exists in the list
void popelement(int val){
if((start->value==val)){
    popback();
}
else{
    if(!existornot(val)){
        cout<<"this value doesnt exist in the list !"<<endl;
    }
    else{
        Node* temp1 = start;
        while((temp1->next)->next != NULL){
            if((temp1->next)->value == val){
                Node* temp2;
                temp2=(temp1->next)->next;
                free(temp1->next);
                temp1->next = temp2;
                break;
            }
            else{
                temp1=temp1->next;
            }

        }
        cout<<"deleted successfully"<<endl;
    }
}
}

//print the list
void printlist (){
    Node* temp = start;
    if(temp==NULL){
        cout<<"empty list!!"<<endl;
    }
    else{
    while(temp->next!=NULL){
        cout<<temp->value<<" ";
        temp = (temp->next);
    }
    cout<<temp->value<<endl;}
}