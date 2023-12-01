#include <iostream>
#include <cmath>

//сложность O(NloglogN); времы выполнения для 100000 элементов 8.00 секунд

void First() {
    int n, p;
    int* mass;
    bool flag; 
    printf("Input n: ");
    scanf_s("%d", &n);
    if (n >= 2)
    {
        n = n - 1;
        mass = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            mass[i] = i + 2;
        for (int i = 0; i < n; i++)
        {
            p = mass[i];
            flag = false;
            for (int j = i + 1; j < n; j++)
            {
                if (!(mass[j] % p))
                {
                    for (int k = j; k < n - 1; k++)
                        mass[k] = mass[k + 1];
                    flag = true;
                    n--; //уменьшаем, потому что чисел на одно стало меньше
                    j--; //уменьшаем, для того чтобы снова проверить на кратность j-е число. Оно же теперь стало другим
                }
            }
            if (flag == false) break;
        }
        for (int i = 0; i < n; i++)
            printf("%d ", mass[i]);
        free(mass);
    }
    else
        printf("Error. n must be >= 2\n");

}

void Second() {
    int n;
    int* a;
    printf("Input n: ");
    scanf_s("%d", &n);

    if (n >= 2)
    {
        n = n - 1;
        a = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            a[i] = i + 2;

        // инициализировать все числа как простые
        for (int i = 0; i <= n; i++) {
            a[i] = 1;
        }

        for (int i = 2; i <= sqrt(n); i++)
        {
            if (a[i] == 1)          // проверяет, является ли `i` простым числом
            {
                for (int j = 2; i * j <= n; j++) {
                    a[i * j] = 0;   // числа, кратные `i`, не являются простыми
                }
            }
        }

        for (int i = 2; i <= n; i++)
        {
            if (a[i] == 1) {
                std::cout << i << " ";   // печатает простые числа
            }
        }
    }
}

//сложность n^2 в лучшем случае и n в худшем 

void Third() {
    int n;
    /*std::cout << "n= ";
    std::cin >> n;*/
    printf("Input n: ");
    scanf_s("%d", &n);
    int simple[10000];
    int k = 0;
    int amount_of_numbers = 0;
    for (int i = 2; i < n + 1; i++)
    {
        k = 0;
        for (int j = 2; j < i; j++)
            if (i % j == 0)
            {
                k = 1;
                    break;
            }
        if (k == 0)
        {
            simple[amount_of_numbers] = i;
            amount_of_numbers++;
        }
    } for (int i = 0; i < amount_of_numbers; i++)
        std::cout << simple[i];
}
int main()
{
	int key;
	do {

		printf("Enter the number of algorithm: ");
		scanf_s("%d", &key);

	} while (key == 1 && key == 2 && key == 3);

	switch(key) {
		case 1:
			printf("The first algorithm:  \n");
			First();
            break;
        case 2:
            printf("The second algorithm:  \n");
            Second();
            break;
        case 3: 
            printf("The third algorithm:  \n");
            Third();
            break;
	}
}

