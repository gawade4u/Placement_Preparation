#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
int main()
{
	int n,choice,w,c,l,i=0;
	FILE *fp;
	struct dirent *de;
	DIR *dr;
	char input[50],cmd[10],args[5],fname[10],line[50];
	system("clear");
	while(1)
	{
		printf("\n18111$");
		gets(input);
		n=sscanf(input,"%s%s%s",cmd,args,fname);
		switch(cmd[0])
		{
			case 'c'://count
				if(!strcmp(cmd,"count")==0)
				{	
					printf("wrong command");
					break;
				}
				fp=fopen(fname,"r");
				if(!fp)
					printf("file not found\n");	
				else
				{
					l=c=w=0;
					while(!feof(fp))
					{
						
						fgets(line,50,fp);
						if(!feof(fp))
						{
							//puts(line);
							l++;	
							i=0;
							while(line[i])
							{
								if(line[i]==' ' || line[i]=='\n')
								{	
									w++;
									c++;
								}
								else
									c++;
								i++;
							}
						}
					}
					if(strstr(args,"c"))
						printf("chracters:%d\n",c);
					if(strstr(args,"w"))
						printf("words:%d\n",w);
					if(strstr(args,"l"))
						printf("lines:%d\n",l);
				}
				break;
			case 't'://typeline
				if(!strcmp(cmd,"typeline")==0)
				{	
					printf("wrong command");
					break;
				}
				fp=fopen(fname,"r");
				if(!fp)
					printf("file not found\n");	
				else
				{
					if(strstr(args,"a"))
						choice=1;
					if(strstr(args,"+"))
						choice=2;
					if(strstr(args,"-"))
						choice=3;
					switch(choice)
					{
						case 1:	
							while(!feof(fp))
							{
								fgets(line,50,fp);
								if((!feof(fp)))
								{
									puts(line);
								}
							}
							break;
						case 2:i=0;
							while(!feof(fp) && i++<atoi(args))
							{
								fgets(line,50,fp);
								if((!feof(fp)))
								{
									puts(line);
								}
							}
							break;
						case 3:l=0;
							while(!feof(fp))
							{
								fgets(line,50,fp);
								if((!feof(fp)))
								{
									l++;
								}
							}
							fseek(fp,0,0);	
							l=l+atoi(args);
							i=0;
							while(!feof(fp) && i++<l)
								fgets(line,50,fp);
							while(!feof(fp))
							{
								fgets(line,50,fp);
								if(!feof(fp))
								{
									puts(line);
								}
							}
							break;
					}	
				}
				break;
			case 'l'://list
				if(strstr(args,"f"))
					choice=1;
				if(strstr(args,"n"))
					choice=2;
				if(strstr(args,"i"))
					choice=3;
				switch(choice)
				{
					case 1:system(".");
						dr=opendir(".");
						if(!dr)
							printf("directory not found....\n");
						else
						{
							printf("name\n");
							while((de=readdir(dr))!=NULL)
								printf("%s\n",de->d_name);
							closedir(dr);
						}
						break;
					case 2:dr=opendir(".");
						if(!dr)
							printf("directory not found....\n");
						else
						{
							printf("Inode no\n");
							while((de=readdir(dr))!=NULL)
								printf("%ld\n",de->d_ino);
							closedir(dr);
						}
						break;
					case 3:	dr=opendir(".");
						if(!dr)
							printf("directory not found....\n");
						else
						{
							printf("Inode no\tname\n");
							while((de=readdir(dr))!=NULL)
								printf("%ld\t\t%s\n",de->d_ino,de->d_name);
							closedir(dr);
						}
						break;
				}
				break;
			default:printf("wrong command\ntry again...");
				break;
		}
	}
	return 0;
}
