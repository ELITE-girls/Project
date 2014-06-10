#include <dirent.h>
#include <stdio.h>
#include<string.h>
//#include<unistd.h>
#include<conio.h>

int search(char filename[30]);
void work(struct dirent *dir);

int main(void)
{
  int m;
  char filename[30];

  DIR           *d;
  struct dirent *dir;
  d = opendir(".");
  if (d)
  {
		while ((dir = readdir(d)) != NULL)
	{
	  strcpy(filename,dir->d_name);
	  m=search(filename);
	  if(m==0)
      {
	getch();
	printf("%s\n", dir->d_name);
      }
      else
	  {
	work(dir);
	return 0;
      }

    }

    closedir(d);
  }
  getch();
  return(0);
}

int search(char filename[30])
{

	int cnt=0;
	DIR           *d1;
	struct dirent *dir1;
	d1=opendir(".");
	if(d1)
	{
		while((dir1 =readdir(d1)) !=NULL)
		{
			if(strcmp(dir1->d_name,filename)==0)
				cnt++;
				//return 1;
		}
	}
	if(cnt==1)
		return 0;
	//if count is 1 then fine if more then 1 hence file name is duplucate
	//for 1 count(1 match) it is fine because directory opened again.
	else
		return 1;
}

void work(struct dirent *dir)
{
	int ch,d;
	char newname[30];
	printf("\n%s\n file name is duplicate.",dir->d_name);
	getch();
	printf("\n\n\t Want to delete or rename the file:: ");
	printf("\n\t 1]RENAME \n\t 2]DELETE\n");
	printf("\n\n\t Enter choice:: ");
	scanf("%d",&ch);
	do{
	switch(ch)
	{
		case 1: printf("\n\n\t Enter the new name:: ");
			scanf("%s",newname);
			strcpy(dir->d_name,newname);
			break;

		case 2:
			//delete file name
			d=unlink(dir->d_name);
			if(d==0)
				printf("\n\n\t File deleted Successfully.");
			break;

		case 3:exit(0);
	}
	}while(ch!=3);
	getch();
}