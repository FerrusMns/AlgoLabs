#include <iostream>
#include <stdlib.h>
#include <chrono>
using namespace std;
auto get_time()
{
	return std::chrono::high_resolution_clock::now();
}

void print_difference(std::chrono::high_resolution_clock::time_point t1,
	std::chrono::high_resolution_clock::time_point t2)
{
	unsigned nano = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
	unsigned micro = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	unsigned mili = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	unsigned sec = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();

	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << sec << " seconds" << std::endl;
	std::cout << mili << " miliseconds" << std::endl;
	std::cout << micro << " microseconds" << std::endl;
	std::cout << nano << " nanoseconds" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
}
int main()
{
	// Считываем размер массива,
	// который необходимо отсортировать
	int size;
	cin >> size;
	int countPairs = 0; 
	int countR = 0;
	// Динамически выделяем память под
	// хранение массива размера size
	int *a = new int[size];

	// Считываем массив
	for (int i = 0; i < size; i++) 
	{
		a[i]=rand();
	}


	auto start_time = get_time();
	int step = size / 2;//инициализируем шаг.
	while (step > 0)//пока шаг не 0
	{
		for (int i = 0; i < (size - step); i++) 
		{
			int j = i; //будем идти начиная с i-го элемента 
			while (j >= 0 && a[j] > a[j + step])
			//пока не пришли к началу массива
			//и пока рассматриваемый элемент больше
			//чем элемент находящийся на расстоянии шага
			{
				
				
				//меняем их местами
				int temp = a[j];
				a[j] = a[j + step];
				a[j + step] = temp;
				countR++;
				j--;
				 
			}
			countPairs++;
		}
		step = step / 2;//уменьшаем шаг
	}
	auto end_time = get_time();
	// Выводим отсортированный массив
	for (int i = 0; i < size; i++) { cout << a[i] << ' '; }
	cout << "Changes: "<<countR << "Comparsions: " << countPairs << endl;
	print_difference(start_time, end_time);

	return 0;
}
   
