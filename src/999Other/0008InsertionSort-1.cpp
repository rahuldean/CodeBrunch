#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> lst);
void display_lst(const vector<int>& lst);

int main()
{
	vector<int> lst;
	int lst_size, holder;
	cin >> lst_size;

	for (int i = 0; i < lst_size; i++){
		cin >> holder;
		lst.push_back(holder);
	}

	insertion_sort(lst);

	return 0;
}

void insertion_sort(vector<int> lst){
	// Case: 1 If it is the only element
	if (lst.size() <= 1){
		display_lst(lst);
		return;
	}

	// Case: 2 Atleast two elements are present.
	// start iterating from last
	int lst_size = lst.size(), unsorted_element;
	for (int i = lst_size - 1; i >= 0; i--){
		if (i == lst_size - 1){
			// since last element is an unsorted_element, extract it
			unsorted_element = lst[i];
			continue;
		}

		// start compare the current element
		if (lst[i] > unsorted_element){

			if (i == 0){
				lst[i + 1] = lst[i];
				lst[i] = unsorted_element;
				display_lst(lst);
			}
			else {
				// make a copy of current element into next
				lst[i + 1] = lst[i];
			}
			
			display_lst(lst);
			continue;
		}
		else {
			lst[i + 1] = unsorted_element;

			display_lst(lst);
			break;
		}
	}
	
}

void display_lst(const vector<int>& lst){
	for (vector<int>::const_iterator it = lst.begin(); it != lst.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}