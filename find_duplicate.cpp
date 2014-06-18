//
//  David Wells
//  Find duplicate entry in an array of integers between 1 and 1,000,000
//

#include <iostream>
#include <unordered_map>

using namespace std;

//  For readibility set the unordered multimap type name to hash_table
typedef unordered_multimap<int, int> hash_table;

//  Function Declarations:
int find_duplicates( int *array, int array_size );
bool unit_test(int expected_result, int actual_result);



int main(int argc, char *argv[]) {
	
    int array_size = 1000000;
    int *array = new int[array_size];
    
    srand(int(time(NULL)));
    int dummy_duplicate = rand() % 1000000;
    int expected_result = dummy_duplicate;
    
    //  Build array of "array_size" elements
	for(int i = 0; i < array_size; i++){
        array[i] = i;
	}
    
    //  Add a duplicate to the array just for testing purposes
    array[99999] = dummy_duplicate;
    

    int duplicate = find_duplicates(array, array_size);
    if (duplicate == -1) {
        cout <<"No duplicate found" << endl;
        return 0;
    }
	cout << "Duplicate: " << duplicate << endl;
    
    
    //Run Unit Test
    if (unit_test(expected_result, duplicate)) {
        cout << "Passed unit test"<< endl;
    }
	
	return 0;
	
}


//  Function definitions:

int find_duplicates( int *array, int array_size ) {
    hash_table myTable(array_size);
    
    for (int i = 0; i < array_size; i++) {
        int num = array[i];
        
        myTable.insert(hash_table::value_type(array[i], i));
        
        //  If the count of any particular value is more than 1 then we've found a duplicate
        if (myTable.count(num)>1) {
            return num;
        }
    }
    return -1;
}


bool unit_test(int expected_result, int actual_result) {
    
    if (actual_result == expected_result) {
        return true;
    }
    else return false;
    
}
