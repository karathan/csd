#include <stdio.h>
#define MAXN 200

int main (int argc, char *argv[])
{	
	int N,i,j,k,rowsum,columnsum,diag1sum=0,diag2sum=0,MagicCount=0,unique=0;
	int box[MAXN][MAXN],a,i1,j1;
	
	if(argc < 3)
	{
		scanf("%d",&N);
   
		for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				scanf("%d",&box[i][j]);
			}
		
		}
		if(N==1)
		{
			if(box[0][0]>N*N)
			{
				printf("ROW %d NO\nCOLUMN %d NO\nDIAG1 NO\nDIAG2 NO\nUNIQUE NO\nMAGIC NO\n", N, N);
			}
			else
			{
				printf("ROW %d YES\nCOLUMN %d YES\nDIAG1 YES\nDIAG2 YES\nUNIQUE YES\nMAGIC YES\n", N, N);
			}		
			return 0;
		}
		
		for (i=0; i<N; i++)
		{
			rowsum=0;
			for (j=0; j<N; j++)
			{
				rowsum=rowsum+box[i][j];
			}
				if(rowsum==((((N*N)+1)*N)/2))
				{
					printf("ROW %d YES\n", i+1);
					}
					else
					{
						printf("ROW %d NO\n", i+1);
						MagicCount ++;
					}
						
		}
		
		for (j=0; j<N; j++)
		{
			columnsum=0;
			for (i=0; i<N; i++)
			{
				columnsum=columnsum+box[i][j];
			}
				if(columnsum==((((N*N)+1)*N)/2))
				{
					printf("COLUMN %d YES\n", j+1);
					}
					else
					{
						printf("COLUMN %d NO\n", j+1);
						MagicCount ++;
					}
						
		}
		
		for (i=0; i<N; i++)
		{
				diag1sum=diag1sum+box[i][i];
		}
			if (diag1sum== ((((N*N)+1)*N)/2))
			{
				printf("DIAG1 YES\n");
				}
				else
				{
					printf("DIAG1 NO\n");
					MagicCount ++;
				}
			
		
		for(i=0; i<N; i++)
		{
			diag2sum=diag2sum+box[i][N-i-1];
		}
			if (diag2sum== ((((N*N)+1)*N)/2))
			{
				printf("DIAG2 YES\n");
			}
			else
			{
				printf("DIAG2 NO\n");
				MagicCount ++;
			}
			for(i=0; i<N; i++)
			{
				for(j=0; j<N; j++)
				{
					a=box[i][j];
					for(i1=0; i1<N; i1++)
					{
						for(j1=0; j1<N; j1++)
						{
							if (a==box[i1][j1] && (i1!=i || j1!=j)) 
							{
								unique ++;
							}
						}
						
					}
					
				}
				
			}
			if (unique==0)
			{
				printf("UNIQUE YES\n");
			}
			else
			{
				printf("UNIQUE NO\n");
			}

			if (MagicCount==0)
			{
				printf("MAGIC YES\n");
			}
			else
			{
				printf("MAGIC NO\n");
			}

}
else
{
	N = atoi(argv[argc-1]);
	i=N-1;
  	j=(N-1)/2;


  	for(k=1; k<=(N*N); k++){
     box[i][j]=k;
     i++;
     j++;
     if(i==N){
       i=0;
     }
     if(j==N){
       j=0;
     }
     if(box[i][j]!=0){
       i--;
       j--;
       if(i<0){
         i=(N-1);
       }
       if(j<0){
         j=(N-1);
       }
       if(box[i][j]!=0){
         i--;
       }
    }
  }
	printf("%d\n", N);
  	for(i=0; i<N; i++)
  	{
     for(j=0; j<N; j++)
     {
        printf("%d ", box[i][j]);
     }
     printf("\n");
  }
}				
return 0;
}
