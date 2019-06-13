//in brief: it uses a structure which has 3 fields-> size of each directory, file_count in that directory, rank of that directory

//here we are keeping a sorted array of these directories based upon the size and file_count
//means here we're using multiple key sorting.



#include <iostream>     
#include <algorithm> 
using namespace std;

struct Directory{
	int size;
	int file_count;
	int rank;
	
};

bool compareTwoDirectories(Directory a, Directory b){
	//if size of two directories is not same
	if(a.size != b.size)
		return a.size < b.size;
	
	//if size is same then we return the file_count status
	return a.file_count<b.file_count;
}

void computeRank(Directory a[], int n){
	//sorting using the function 
	sort(a, a+5, compareTwoDirectories);
	
	//assign rank after sorting
	for(int i=0;i<n;i++){
		a[i].rank = i+1;
	}
}

int main(){
	
	int n =5;
	Directory a[n];
	
	//initilize every directory with zero as size and file_count
	for(int i=0;i<n;i++){
		a[i].size=0;
		a[i].file_count=0;
	}
	
	cout<<"enter no of files you want to store"<<endl;
	int file_count;
	cin>>file_count;
	
	while(file_count--){
		cout<<"enter the file size"<<endl;
		int temp;
		cin>> temp;
		
		
		a[0].size += temp;
		a[0].file_count++;
		
		computeRank(a,n);
		
		//printing the file size and file_count of each directory one by one
		for (int i=0;i<n;i++){
			cout<<a[i].rank<<"  ";
			cout<<a[i].size<<"  ";
			cout<<a[i].file_count<<endl;
		}
	}
	
	
	
	 
	
	
	return 0;
}
