# include<stdio.h>
# include<stdlib.h>
# include<string.h>
typedef struct NODE NODE;
struct NODE
{
    int x, y;
};
int main()
{
    int p_list[5] = { 0, 1, 2, 3, 4 };
    int* p = p_list;
    for (int i = 0;i < 5;i++)
    {
        printf("%d\n%d\n", p[i], i[p]);
        printf("%p\n%p\n", p[i], i[p]);
    }
    int i = 100;
    int *p1 = &i;
    printf("-------%d\n", i);
    printf("-------%d\n", p1);
    printf("-------%p\n", p1);
    printf("%d\n", (0x4200 - 0x2600) / 32);
    // NODE* node = (NODE*)malloc(sizeof(NODE));
    // for (i = 0;i < 10;i++)
    // {
    //     printf("%p\n", node + i);
    // }
    char str[10] = "hello";
    char* str1 = NULL;
    strncpy(str1, str, 5);
    printf("%s\n", str);
    printf("%s\n", str1);

}