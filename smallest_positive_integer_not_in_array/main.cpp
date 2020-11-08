#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
	cout << endl;
}

bool IsNotPositive (int i) { return (i<=0); }

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    sort(A.begin(), A.end()); // sort vector
    // print(A);
    int positive_counter = 1;
    // remove duplicate elements
    A.erase(std::unique(A.begin(), A.end()), A.end());
    // print(A);
    
    // remove negative elements
    A.erase(remove_if(A.begin(), A.end(), IsNotPositive), A.end()); // Investigate !!!
    // print(A);

    for (int element:A)
    {
        if (element == positive_counter) positive_counter = positive_counter + 1;
        else continue;
    }
    return positive_counter;
}

int main()
{
    cout<<"Hello World"<<endl;
    vector<int> A = {1, 3, 6, 4, 1, 2};
    vector<int> B = {1, 2, 3};
    vector<int> C = {-1, -3};
    
    cout << solution(A) << endl;
    cout << solution(B) << endl;
    cout << solution(C) << endl;
    return 0;
}

