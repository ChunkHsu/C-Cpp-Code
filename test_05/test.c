
#include<stdio.h>
#include<pthread.h>
static int tmp;
void swap(int *a, int *b)
{
    tmp = *a;
    *a=*b;
    *b=tmp;
}
void * t_fun(void * arg)
{
    int ** ptr = (int**)arg;
    int *a=ptr[0];
    int *b=ptr[1];
    swap(a,b);
}
int main()
{
    int a=1,b=2,c=3;
    pthread_t thread1, thread2;
    int *ptr_a = &a;
    int *ptr_b = &b;
    int *ptr_c = &c;
    int *ptr[2] = {ptr_a, ptr_b};
    int *ptr2[2] = {ptr_b, ptr_c};
    
    printf("a= %d, b= %d\n",a,b);
    pthread_create(&thread1, NULL, t_fun,(void*)ptr);
    printf("a= %d, b= %d\n",a,b);

    printf("b= %d, c= %d\n",b,c);
    pthread_create(&thread2, NULL, t_fun,(void*)ptr2);
    printf("b= %d, c= %d\n",b,c);

}