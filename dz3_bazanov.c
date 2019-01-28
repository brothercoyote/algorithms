//Bazanov

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define ARR_SIZE 10
#define ARR_SIZE2 1000


void swap(int* a, int* b){ //из первого дз
    *a^=*b;
    *b^=*a;
    *a^=*b;
}

int simple_bubble(int *arr[0], int size){
    int i=0,j=0, count=0;
    for(i=0;i<size;i++){
        for(j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);  //вероятно, тут что-то не очень правильно, но работает
            }
            count++;
        }
    }
    return count;
}

int optimized_bubble(int *arr[0], int size){
    int i=0,j=0, count=0, num_of_swaps=0;

    for(i=0;i<size;i++){
        num_of_swaps=0;
        for(j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);  //вероятно, тут что-то не очень правильно, но работает
                num_of_swaps++;
            }
            count++;
        }
        if(num_of_swaps==0) //если во внутреннем цикле не было перестановок, значит, массив отсортирован и можно брякнуть внешний цикл
            break;
    }
    return count;
}


int bin_search(int *arr[0], int size, int val){
    int L=0, R=size-1;
    int ind = L+((R-L)/2);
    while((L<=R)&&(arr[ind]!=val)){
        (arr[ind]<val)?(L=ind+1):(R =ind-1);
        ind = L+((R-L)/2);
    }
    if(arr[ind]==val)
        return ind;
    else return -1;
}

int ex1() //Оптимизировать пузырьковую сортировку.
//Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
//Написать функции сортировки, которые возвращают количество операций.
{
    int arr1[ARR_SIZE], arr2[ARR_SIZE];
    int i=0;

    for(i=0;i<ARR_SIZE;i++)
        printf("%i ", arr1[i]=arr2[i]=rand()/100);
    printf("\n");

    printf("Bubble sort ops = %i \n",simple_bubble(&arr1[0], ARR_SIZE));
    for(i=0;i<ARR_SIZE;i++)
        printf("%i ", arr1[i]);

    printf("\n\n");

    printf("Optimized bubble sort ops = %i \n",optimized_bubble(&arr2[0], ARR_SIZE));
    for(i=0;i<ARR_SIZE;i++)
        printf("%i ", arr2[i]);


    return 0;
}

int ex2() // *Реализовать шейкерную сортировку.

{

    return 0;
}

int ex3() //Реализовать бинарный алгоритм поиска в виде функции,
//которой передается отсортированный массив.
//Функция возвращает индекс найденного элемента или -1, если элемент не найден.
{
    int arr1[ARR_SIZE2];
    int i=0;

    for(i=0;i<ARR_SIZE2;i++)
        arr1[i]=rand()/100;

    optimized_bubble(&arr1[0], ARR_SIZE2);
    printf("\n%i", bin_search(&arr1[0], ARR_SIZE2, 42));
    return 0;
}

int ex4() //*Подсчитать количество операций для каждой из сортировок
//и сравнить его с асимптотической сложностью алгоритма.
{

    return 0;
}




int main(int argc, char *argv[])
{
    int command_c;
    char pause;
    char str_menu[1000] = "\nMENU\nInput number to select exersice or to exit program\n"
                         "1 - exercise 1\n"
                         "2 - exercise 2\n"
                         "3 - exercise 3\n"
                         "4 - exercise 4\n"
                         "0 - exit\n";

    printf("Hello!\nThis is a program with all exercises in one c-file\nPlease, input any symbol to continue: ");
    scanf("%c", &pause);

    for( ; ; ){
        printf(str_menu);
        printf("Input number: ");
        scanf("%i", &command_c);

        switch (command_c){
        case 0:
            exit(0);
            break; //пусть всё равно будет
        case 1:
            ex1();
            break;
        case 2:
            ex2();
            break;
        case 3:
            ex3();
            break;
        case 4:
            ex4();
            break;       
        default:
            printf("\nWRONG COMMAND\nTry one more time\n\n");
            scanf("%c", &pause);
            break;
        }
    }
    return 0;
}


