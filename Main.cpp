#include<iostream>
using namespace std;

struct Node{
    int rollnum;
    int totalcls=0;
    int presentcls=0;
    Node* next;

    Node(int r){
        rollnum=r;
        next = NULL;
    }
};

Node* head = NULL;
Node* student(int roll){
    Node* node = new Node(roll);
    node->next = head;
    return node;
}

void calculation(){
    Node* curr= head;
    cout<<"Percentage: \n";

    while(curr!=NULL){
        int sum=curr->totalcls;
        int p= curr->presentcls;
        float percentage = (p*100)/sum;
        cout<<"Student "<<curr->rollnum<<" : "<<percentage<<"%\n";
        curr = curr->next;
    }
}

void below75(){
    Node* curr= head;
    cout<<"Less than 75%: ";
    while(curr!=NULL){
        int sum=curr->totalcls;
        int p= curr->presentcls;
        double percentage = (p*100)/sum;
        
        if(percentage<75){
            cout<<curr->rollnum<<", ";
        }   curr = curr->next;
    }   cout<<endl;
}

int main(){  
    int N = 3; // here i inputed the fixed number of student acording to ur instruction sir
    int M = 3; // i count 3 classes
    int a = 0;

    cout<<" Num of student(N): "<<N<<endl;
    cout<<" Num of classes(M): "<<M<<endl;
    cout<<" To insert attendence for present(1), for absent(0)\n";

// i use the linked list for the student here
    for(int i=1; i<=N;i++){
        head= student(i);
    }
    for(int i=1; i<=M;i++){
        Node* curr = head;
        while(curr!=NULL){
            int v;
            cout<<"Day-"<<i<<" Student "<<curr->rollnum<<" : ";
            cin>>v;

            curr->presentcls= curr->presentcls + v;
            curr->totalcls++;
            curr = curr->next;
        }
    }cout<<endl;

    calculation();
    below75();

    return 0;
}