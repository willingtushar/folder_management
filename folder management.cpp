#include<iostream>

using namespace std;

struct node{
	int size;
	int file_count;
	struct node* next;
};

//function which adds nodes to the end of list
void add(struct node* head){
	struct node* temp = new node();

	temp->file_count = 0;
	temp->size=0;
	
	struct node* temp2=head;
	
	while(temp2->next){
		temp2 = temp2->next;
	}
	
	temp2->next = temp;
	temp->next = NULL;
	
}

//function that print the linked list
void print(struct node* temp){
	while(temp){
		cout<<temp->size<<"-"<<temp->file_count<<endl;
		temp= temp->next;
	}
	cout<<endl;
}

//function that returns the pivot, which points to the node after which the node should be placed
node* getPivot(node* temp, node* pivot){
	if(pivot != NULL){
		if(pivot->size<temp->size){
			getPivot(temp, pivot->next);
		}else if(pivot->size == temp->size){
			if(pivot->file_count >= temp->file_count)
				return pivot;
			else
				getPivot(temp, pivot->next);
		}else
			return pivot;
	}else
		return pivot;
}
int main(){
	
	cout<<"enter the no. of folders/Directories"<<endl;
	int directories;
	cin>>directories;
	
	struct node* head = new node();
	head->file_count =0;
	head->size=0;
	head->next = NULL;
	
	//add nodes equal to directories-1
	for(int i=0;i<directories-1;i++){
		add(head);
	}
	//asking no of files
	cout<<"enter no of files"<<endl;
	int fileCount;
	cin>>fileCount;
	
	while(fileCount--){
	
		//asking for the folder size
		cout<<"enter size"<<endl;
		int size;
		cin>>size;
		
		//adding the size to the first node and increasing it's count
		head->size += size;
		head->file_count += 1;
		
		//getting the pivot after which the first node should be added
		node* first_node = head;
		head = head->next;
		node* pivot = getPivot(first_node, head);
		
		//now making the new sorted list after adding the first node after pivot
		if(pivot == NULL){
			//adding the first_node at the end of list
			node* temp = head;
			while(temp->next){
				temp = temp->next;
			}
			temp->next = first_node;
			first_node->next = NULL;
		}else{
			first_node->next = pivot->next;
			pivot->next = first_node;
		}
		
		
		//printing the linked list
		print(head);
	
    }
	return 0;
}
