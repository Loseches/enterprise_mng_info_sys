#include <stdio.h>

int main(int argc,const char* argv[])
{
	int m = 0,n;
	scanf("%d%d",&m,&n);
	int arr[31],num = 0;
	do{
		arr[num++] = m % n;
		m /= n;
	}while(m != 0);
	for(int i = num - 1;i >= 0; i--)
	       if(num<10){
		    {
	        	printf("%d",arr[i]);
            	}
	    	}
	       else
        	{
	        	printf("%c",'A'+num[i]-10);
        	}
	return 0;
}
