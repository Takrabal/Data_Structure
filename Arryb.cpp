#include<iostream>
#include<string>
using  namespace std;

class list{
private:
	int p[5];
	int max,len,*current,*temp;
public:

	list(){
		len = 0;
		max=5;
		current=p;
		temp=p;
	}


	list(list & othrList){
	max = othrList.max;
	len = othrList.len;
	
	for(int i=0;i<max;i++){
	p[i] = othrList.p[i];

	}
	
	}


	void clear(){
	
		temp=p;

		for(int i=0;i<len;i++){
		*temp=0;
		temp++;
		}

	len=0;
	}



	void insert(int value,int pos){
	
		cout<<"position is :"<<pos<<endl;
		cout<<"length is: "<<len<<endl;

		if(pos > max || pos <= 0){
			cout<<"index/position out of bounds"<<endl;
			return;
		}
		if((len == 0 && pos != 1) || (len != 0 && pos > len+1)){
			
			cout<<"Invalid position!!!!";
		
		}

		else
		{
			current=p;
		
			
			for(int i=1;i<pos;i++){
			current++;
			}
			
			if(pos ==  len+1){
				*current=value;
				len++;
				return;
			}

			for(int i=1;i<len;i++){
			temp++;
			}

			while(temp>=current){
			*(temp+1)=*temp;
			temp--;
			}

			*current=value;
			len++;
		}

	}


	void remove(int pos){
	
	current=p;

	for(int i=1;i<pos;i++){
	
	current++;
	}

	temp=current;

	for(int i=pos-1;i<len;i++){
	*temp=*(temp+1);
	temp++;
	}

	len--;
	}




	int get(int pos){
	temp=p;
	
	for(int i=1;i<pos;i++){
	temp++;
	}
	return *temp;
	}


	void update(int value,int pos){
	current=p;

	for(int i=1;i<pos;i++){
	
	current++;
	}
	
	*current=value;

	}



	bool find(int value){
	
	bool chk=0;
	temp=p;


	for(int i=0;i<len;i++){
	if(*temp==value){
		chk=1;
	}
	}

	return chk;
	}



	int length(){
	return len;
	}



	void start(){
	current=p;
	}

	void end(){
	
	current=p;
	for(int i=1;i<len;i++){
	
	current++;
	}
	}

	void next(){
		if(current<(p+(len-1))){
		current++;
		}

		else{
		cout<<"Standing on last element"<<endl;
		}
	
	}


	void back(){
		if(current>p){
		current--;
		}
		else{
		cout<<"Standing on first element"<<endl;
		}
	}

	void Add(int value){
	current=p;
	while(current<=(p+len-1)){
	current++;
	}
	*current=value;
	}

};

int main(){

	list l1;
	
	l1.insert(2,6);

	for(int i =0; i< 5; i++){

		int x= 0;
		cin>>x;

		l1.insert(x,i+1);
	}


	
 

	for(int i =0; i< 5; i++){

		cout<<l1.get(i+1);
	}



	system("pause");
	return 0;
}    
