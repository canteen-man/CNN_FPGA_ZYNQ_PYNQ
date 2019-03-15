#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

char* filename_to_bin(char *filename_i)
{
	int filename_length=0;
	while(filename_i[filename_length]!='\0') filename_length++;
	//printf("filename length=%d\n",filename_length);
	char *filename_bin=(char *)malloc(filename_length+1);
	int i=0;
	while(!(filename_i[i]=='.' && filename_i[i+1]=='d'&& filename_i[i+2]=='a' && filename_i[i+3]=='t' && filename_i[i+4]=='\0'))//not '.dat\0'
	{
		if(i==filename_length-1)
		{
			free(filename_bin);
			filename_bin=NULL;
			return filename_bin;
		}
		filename_bin[i]=filename_i[i];
		i++;
	}
	filename_bin[i]='.';filename_bin[i+1]='b';filename_bin[i+2]='i';filename_bin[i+3]='n';
	filename_bin[i+4]='\0';
	return filename_bin;
}

int main(int argc, char *argv[])
{
	for(int i=1;i<argc;i++)
	{
		char *filename_i=argv[i];
		char *filename_bin=filename_to_bin(filename_i);
		if(filename_bin==NULL)
		{
			printf("%s is not a dat file\n",filename_i);
			break;
		}

		FILE *fp_IN;
		if((fp_IN=fopen(filename_i,"r"))==NULL) 
		{  
			printf("File %s cannot be opened/n",filename_i);   
			break;   
		}

		FILE* fp_OUT = fopen(filename_bin,"wb");
		if (fp_OUT == NULL) 
		{
			printf("File %s cannot be created/n",filename_bin);  
			break;
		}

		char str[20];
		while(fgets(str,20,fp_IN))
		{
			//printf("%s=%f\n",str,atof(str));
			float tp=atof(str);
			fwrite(&tp,sizeof(float),1,fp_OUT);
		};

		fclose(fp_IN);
		fflush(fp_OUT);
		fclose(fp_OUT);
		free(filename_bin);
	}
	return 0;
}
