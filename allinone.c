#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>

int calculateSquareEquality(int a, int b, int c, float *x1, float *x2){
    //for solving a*x^2 + b*x + c = 0
    float D = 0;

    if((a==0)&&(b!=0)){
        *x1=-c/(b);
        return 0;
    }
    else if (a!=0){
            D = b*b-4*a*c;
            if(D>0){
                *x1 = (-1*b+sqrt(D))/(2*a);
                *x2 = (-1*b-sqrt(D))/(2*a);
                return 1;
            }
            if(D==0){
                *x1 = (-1*b)/(2*a);
                return 0;
            }
            if(D<0)
                return -1;
        } else
            if (c!=0)
                return -5; //error code
}



int ex1() //Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.
{
    float I=0, m=0, h=0;
    printf("Input your weight in kg: ");
    scanf("%f", &m);
    printf("Input your height in meters: ");
    scanf("%f", &h);
    I=m/(h*h);
    printf("Your BMI = %.2f\n", I);
    return 0;
}

int ex2() //Написать программу обмена значениями двух целочисленных переменных:

{
    int a=0,b=0,buf=0;
    printf("Input integer A: ");
    scanf("%i", &a);
    printf("Input integer B: ");
    scanf("%i", &b);
    printf("Your A = %i, and your B = %i\n", a, b);

    //a. с использованием третьей переменной
    /*buf=a;
    a=b;
    b=buf;*/

    //b. *без использования третьей переменной
    b=b+a;
    a=b-a;
    b=b-a;

    printf("Now your A = %i, and your B = %i\n", a, b);
    //c. вариант "сдавать надо уже вчера" без использования третьей переменной
    //printf("Now your A = %i, and your B = %i\n", b, a);
    return 0;
}

int ex3() //Написать программу нахождения корней заданного квадратного уравнения
{
    int var_a = 0,var_b = 0, var_c = 0;
    float var_x1 = 0, var_x2 = 0;
    float* p_x1 = &var_x1; float* p_x2 = &var_x2;

    printf("Hello!\nThis programm will solve square equality (a*x^2 + b*x + c = 0)\nPlease, input integer 'a':");
    scanf("%i", &var_a);
    printf("\nPlease, input integer 'b':");
    scanf("%i", &var_b);
    printf("\nPlease, input integer 'c':");
    scanf("%i", &var_c);

    switch (calculateSquareEquality(var_a, var_b, var_c, p_x1, p_x2)) {
    case 1:
        printf("Equation has two solutions: %.3f, %.3f\n", var_x1, var_x2);
        break;
    case 0:
        printf("Equation has one solution: %.3f\n", var_x1);
        break;
    case -1:
        printf("Equation has no real solutions\n");
        break;
    case -5:
        printf("Equation is not equation\n");
        break;
    default:
        break;
    }
    return 0;
}

int ex4() //С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
{
    int month=0;
    printf("Input number of month: ");
    scanf("%i", &month);
    if ((month<1)||(month>12))
        printf("This month does not exist\nBye\n");
    else if((month==12)||(month<=2))
        printf("This is winter\n");
    else if((month>=3)&&(month<=5))
        printf("This is spring\n");
    else if((month>=6)&&(month<=8))
        printf("This is summer\n");
    else if((month>=9)&&(month<=11))
        printf("This is autumn\n");
    return 0;
}

int ex5() // Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
{
    int age=0, number=0;
    printf("Input integer age (0-150): ");
    scanf("%i", &age);
    if ((age<0)||(age>150))
        printf("Ludi stolko ne jivut\nChao-kakao\n");
    else {
        number=age%10;
        if (((number>=5)&&(number<=9))||(number==0)||((age>=11)&&(age<=19)))
            printf("Vozrast: %i let\n", age);
        else if (number==1)
            printf("Vozrast: %i god\n", age);
        else if ((number>1)&&(number<5))
            printf("Vozrast: %i goda\n", age);
    }
    return 0;
}

int ex11()//В тексте программы, написанной на уроке избавиться от условия в цикле.
{
    int counter = 0;
    float sum = 0;
    int in=0;

    printf("\nInput some numbers (-1 to cancel): ");
    do{

        scanf("&d", &in);//
       if (in == -1) //ubrat
           break;
       sum +=in;//
       counter++;//


    } while(in != -1);//

    if (counter!=0)
        printf("mean = %.2f\n", (float)(sum/counter));
    else printf("No input\n");

    return 0;
}

int main(int argc, char *argv[])
{
    int command_c;
    char pause;
    char str_menu[1000] = "\nMENU\nInput number to select exersice or to exit program\n"
                         "1 - exercise 1 (Body mass index)\n"
                         "2 - exercise 2 (Change numbers)\n"
                         "3 - exercise 3 (Square equality)\n"
                         "4 - exercise 4 (Seasons)\n"
                         "5 - exercise 5 (Age)\n"
                         "11 - exercise 11 (Average with flag)\n"
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
        case 5:
            ex5();
            break;
        case 11:
            ex11();
            break;

        default:
            printf("\nWRONG COMMAND\nTry one more time\n\n");
            scanf("%c", &pause);
            break;
        }
    }
    return 0;
}


