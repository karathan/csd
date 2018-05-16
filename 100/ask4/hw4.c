#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N,i,j,max=0,pos=0;
	char **array;
	int *freq;	
	
	scanf("%d", &N);
	
	array = (char **) malloc (N*sizeof(char*));
	for(i=0;i<N;i++){
		array[i] = (char *) malloc (50*sizeof(char));
	}

	freq = (int *) malloc (N*sizeof(int));	
	for(i=0;i<N;i++){
		freq[i] = 1;
		scanf("%s", array[i]);
	}

	for(i=0;i<N;i++){
		if(!strcmp(array[i],"")) continue;
		for(j=i+1;j<N;j++){
			if(!strcmp(array[i],array[j])){
				freq[i]++;
				strcpy(array[j],"");	
			}
		}
	}	
	

	for(i=0;i<N;i++){
		if(!strcmp(array[i],"")){ 
			continue;
		}else{
			if(max < freq[i]){ 
				max = freq[i];
				pos = i;
			}
		}
	}		
	
	printf("%s %d\n",array[pos],freq[pos]);

	 for(i=0; i<N; i++) { 
        free(array[i]);
    }
    
    free(array);
    free(freq);
	return 0;
}