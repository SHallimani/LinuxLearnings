#include <stdio.h>

int pointer_check() {
        char msg = 'H';

        // here the data is constant, pointer can point to any other pointer
        const char *ms = &msg;
        char const *m = &msg;
        *ms = 'L';
        *m = 'L';

        // here the pointer is constant, data can be modified
        char *const ptr = &msg;

        *ptr = 'E';
        return 0;
}

/*
 We can create an array of pointers of size r. Note that from C99, C language allows variable sized arrays.
 After creating an array of pointers, we can dynamically allocate memory for every row.
 */
int array_of_pointers()
{
    int r = 3, c = 4, i, j, count;

    int *arr[r];
    for (i=0; i<r; i++)
         arr[i] = (int *)malloc(c * sizeof(int));

    // Note that arr[i][j] is same as *(*(arr+i)+j)
    count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         arr[i][j] = ++count; // Or *(*(arr+i)+j) = ++count

    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", arr[i][j]);

    /* Code for further processing and free the 
      dynamically allocated memory */
    for (i=0; i<r; i++)
         free(arr[i]);

   return 0;
}

/*
 We can create an array of pointers also dynamically using a double pointer. Once we have an array pointers allocated dynamically, we can dynamically allocate memory and for every row like method 2.
 */
int pointer_to_pointer()
{
    int r = 3, c = 4, i, j, count;

    int **arr = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
         arr[i] = (int *)malloc(c * sizeof(int));

    // Note that arr[i][j] is same as *(*(arr+i)+j)
    count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         arr[i][j] = ++count;  // OR *(*(arr+i)+j) = ++count

    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", arr[i][j]);

   /* Code for further processing and free the 
      dynamically allocated memory */
    for (i=0; i<r; i++)
         free(arr[i]);
    free(arr);

   return 0;
}

int main() {
        printf("%d. %d \n", sizeof(char *), sizeof(int *), sizeof(*));
        array_of_pointers();
        printf("\n");
        pointer_to_pointer();
        printf("\n");
        return 0;
}
