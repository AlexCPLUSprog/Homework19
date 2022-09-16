#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ������� 1
int ret(int num1, int num2) {    
        int o, max = 0;
        if (num1 < num2)
            o = num1;
        else
            o = num2;
        for (int i = 1; i <= o; i++)
            if (num1 % i == 0 && num2 % i == 0)
                max = i;
        return max;
}

// ������� 2
int mirror_number(int num) {
    int res = 0;
    while (num) {
        res *= 10;
        res += num % 10;
        num /= 10;
    }
    return res;
}

// ����� �������
template <typename T>
void show_arr(T arr[], const int lenght) {
    cout << "[";
    for (int i = 0; i < lenght; i++)
        cout << arr[i] << ", ";
    cout << "\b\b]\n";
}

// ������� 3
template <typename T>
int ret_arr(T arr[], int const lenght, T n) {   
    for (int i = 0; i < lenght; i++)
        if (arr[i] == n)             
            return i;
    return -1;    
}

/*template <typename T>
void sort_arr(T arr[], int const lenght, T n) {
    cout << "[";
    for (int i = lenght - 1; i > 0; i--) { 
        if (arr[i] == n)                                // �� ������� ��� ������, ��� ������� ���������� ����� N � �������� �� � ������� ret_arr
            arr[i] = n;
        for (int j = 0; j < n; j++)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
        cout << arr[i] << ", ";
    }
    cout << "\b\b]\n";
    
}*/

// ������� 4
void randArr(int arr[], const int lenght, int A, int B) {
    srand(time(0));
    cout << "[";
    for (int i = 0; i < lenght; i++) {
        arr[i] = rand() % (B - A) + A;
        cout << arr[i] << ", ";
    }
    cout << "\b\b]\n";
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// ������� 1
	cout << "������� 1.\n������� ��� �����: ";
	cin >> n >> m;
    cout << "���������� ����� �������� = " << ret(n, m) << "\n\n";

    // ������� 2
    cout << "������� 2.\n������� �����: ";
    cin >> n;
    cout << "���������� �����: " << mirror_number(n) << "\n\n";

    // ������� 3
    cout << "������� 3.\n";
    srand(time(0));
    const int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 20 + 1;
    cout << "������:\n";
    show_arr(arr, size);
    cout << "������� �����: ";
    cin >> n;
    cout << "������ ������� ����� " << n << " ��������� ��� �������� " << ret_arr(arr, size, n) << "\n\n";
    //sort_arr(arr, size,n);
   
   // ������� 4
    cout << "������� 4.\n������� ������ ���������: ";
    cin >> n;
    cout << "������� ����� ���������: ";
    cin >> m;
    const int size2 = 20;
    int arr2[size2]{};
    randArr(arr2, size2, n, m);

	return 0;
}