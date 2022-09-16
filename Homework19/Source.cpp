#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Задание 1
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

// Задание 2
int mirror_number(int num) {
    int res = 0;
    while (num) {
        res *= 10;
        res += num % 10;
        num /= 10;
    }
    return res;
}

// Показ массива
template <typename T>
void show_arr(T arr[], const int lenght) {
    cout << "[";
    for (int i = 0; i < lenght; i++)
        cout << arr[i] << ", ";
    cout << "\b\b]\n";
}

// Задание 3
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
        if (arr[i] == n)                                // Не хватает ума понять, как сделать сортировку после N и вставить ее в функцию ret_arr
            arr[i] = n;
        for (int j = 0; j < n; j++)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
        cout << arr[i] << ", ";
    }
    cout << "\b\b]\n";
    
}*/

// Задание 4
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

	// Задание 1
	cout << "Задание 1.\nВведите два числа: ";
	cin >> n >> m;
    cout << "Наибольший общий делитель = " << ret(n, m) << "\n\n";

    // Задание 2
    cout << "Задание 2.\nВведите число: ";
    cin >> n;
    cout << "Зеркальное число: " << mirror_number(n) << "\n\n";

    // Задание 3
    cout << "Задание 3.\n";
    srand(time(0));
    const int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 20 + 1;
    cout << "Массив:\n";
    show_arr(arr, size);
    cout << "Введите число: ";
    cin >> n;
    cout << "Первая позиция числа " << n << " находится под индексом " << ret_arr(arr, size, n) << "\n\n";
    //sort_arr(arr, size,n);
   
   // Задание 4
    cout << "Задание 4.\nВведите начало диапазона: ";
    cin >> n;
    cout << "Введите конец диапазона: ";
    cin >> m;
    const int size2 = 20;
    int arr2[size2]{};
    randArr(arr2, size2, n, m);

	return 0;
}