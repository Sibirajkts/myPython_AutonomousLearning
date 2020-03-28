#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display_menu();
void handle_print(const vector<int> &);
void handle_add(vector<int> &);
void handle_mean(const vector<int> &);
void handle_smallest(const vector<int> &);
void handle_largest(const vector<int> &);
void handle_find(const vector<int> &);
char get_selection();
void display_list(const vector<int> &);
int get_number_to_add();
double calculate_mean(const vector<int> &);

int main()
{
	vector<int> numbers;
	char selection_char {};
	do{
		display_menu();
		selection_char = get_selection();
		switch(selection_char)
		{
			case 'P':
				handle_print(numbers);
				break;
			case 'A':
				handle_add(numbers);
				break;
			case 'M':
				handle_mean(numbers);
				break;
			case 'S':
				handle_smallest(numbers);
				break;
			case 'L':
				handle_largest(numbers);
				break;
			case 'F':
				handle_find(numbers);
				break;
			default:
				break;
		}
	}while(selection_char != 'Q');
}

void display_menu()
{
	cout<<"\nP-Print numbers"<<endl;
	cout<<"A-Add a number"<<endl;
	cout<<"M-display mean of the numbers"<<endl;
	cout<<"S-Display the smallest number"<<endl;
	cout<<"L-Display the largest number"<<endl;
	cout<<"F-find a number in list"<<endl;
	cout<<"Q-Quit"<<endl;
	cout<<"\n Enter your choice: ";
}

char get_selection()
{
	char choice {};
	cin>>choice;
	return toupper(choice);
}

void handle_print(const vector<int> &v)
{
	if(v.size() == 0)
		cout<<"[] - the list is empty"<<endl;
	else
		display_list(v);
}

void display_list(const vector<int> &v)
{
	cout<<"[ ";
	for(auto i:v)
		cout<<i<<" ";
	cout<<"]"<<endl;
}

void handle_add(vector<int> &v)
{
	int num_to_add {get_number_to_add()};
	v.push_back(num_to_add);
	cout<<num_to_add<<" added"<<" size of list is: " << v.size()<<endl;
}

int get_number_to_add()
{
	int number;
	cout<<"Enter num to add: ";
	cin>>number;
	return number;
}

void handle_mean(const vector<int> &v)
{
	if(v.size() == 0)
		cout<<"Cannot Calculate Mean, Vector is empty" << endl;
	else
		cout<<"The mean is "<<calculate_mean(v)<<endl;
}

double calculate_mean(const vector<int> &v)
{
	double mean {};
	int total {};
	for (auto i: v)
		total+= i;
	mean = (static_cast<double> (total))/v.size();
	return mean;
}

void handle_smallest(const vector<int> &v)
{
	int smallest {v.at(0)};
	for(auto i:v)
	{
		if(i < smallest)
			smallest = i;
	}
	cout<<"The Smallest is: "<<smallest<<endl;
}

void handle_largest(const vector<int> &v)
{
	int largest {v.at(0)};
	for(auto i:v)
	{
		if(i > largest)
			largest = i;
	}
	cout<<"The largest is: "<<largest<<endl;
}

void handle_find(const vector<int> &v)
{
	int target {};
	cout<<"Enter number to find: "<<endl;
	cin>>target;
	if(v.end() != find(v.begin(),v.end(),target))
		cout<<target<<" was found"<<endl;
	else
		cout<<target<<" was not found"<<endl;
}


