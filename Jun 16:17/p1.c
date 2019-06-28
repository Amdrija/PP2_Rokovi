#include <stdio.h> 
#define ADD(x, y) x+y 
#define MUL(x, y) x*y 


int main() 
{
   int arr[6] = { 012, -2, 7 - 011, 0x1F, 3 }, res = 0;
   int n = sizeof(arr) / sizeof(int), i, j;
   for (i = -1, j = n; i <= n / 2;) 
   {
        switch (--j, ++i) 
        {     
            case 0: res += MUL(arr[i], arr[j]);     
            case 1: res += ADD(arr[i], arr[j]); break;     
            case 4: 
                    printf("%d %d %d %d \n",arr[i+1],res,arr[i],arr[j]);
                    printf("%d %d\n",ADD(arr[i],arr[j]),ADD(arr[i+1],res));
                    printf("%d\n",MUL(ADD(arr[i], arr[j]), ADD(arr[i+1], res)));
                    res += MUL(ADD(arr[i], arr[j]), ADD(arr[i + 1], res));    
                    printf("%d\n",res); 
            default: res++; break;     
        }  
    }   
    printf("%d", res);
    return 0;
}