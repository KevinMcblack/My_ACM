#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char a[100000];
	int i;
	while(gets(a))
	{
		for(i=0;i<strlen(a);i++)
		{
			switch(a[i])
			{
				case 'W':a[i]='Q';
					break;
				case 'E':a[i]='W';
					break;
				case 'R':a[i]='E';
					break;
				case 'T':a[i]='R';
					break;
				case 'Y':a[i]='T';
					break;
				case 'U':a[i]='Y';
					break;
				case 'I':a[i]='U';
					break;
				case 'O':a[i]='I';
					break;
				case 'P':a[i]='O';
					break;
				case 'S':a[i]='A';
					break;
				case 'D':a[i]='S';
					break;
				case 'F':a[i]='D';
					break;
				case 'G':a[i]='F';
					break;
				case 'H':a[i]='G';
					break;
				case 'J':a[i]='H';
					break;
				case 'K':a[i]='J';
					break;
				case 'L':a[i]='K';
					break;
				case 'X':a[i]='Z';
					break;
				case 'C':a[i]='X';
					break;
				case 'V':a[i]='C';
					break;
				case 'B':a[i]='V';
					break;
				case 'N':a[i]='B';
					break;
				case 'M':a[i]='N';
					break;
				case ',':a[i]='M';
					break;
				case '.':a[i]=',';
					break;
				case '/':a[i]='.';
					break;
				case '[':a[i]='P';
					break;
				case ']':a[i]='[';
					break;
				case 92:a[i]=93;
					break;
				case '1':a[i]='`';
					break;
				case '2':a[i]='1';
					break;
				case '3':a[i]='2';
					break;
				case '4':a[i]='3';
					break;
				case '5':a[i]='4';
					break;
				case '6':a[i]='5';
					break;
				case '7':a[i]='6';
					break;
				case '8':a[i]='7';
					break;
				case '9':a[i]='8';
					break;
				case '0':a[i]='9';
					break;
				case '-':a[i]='0';
					break;
				case '=':a[i]='-';
					break;	
				case ';':a[i]='L';
					break;
				case 32:a[i]=32;
					break;
				case 39:a[i]=59;
					break;
				case '`':a[i]=32;
					break;			
			}	
		}
		printf("%s",a);
		printf("\n"); 
	}
	return 0;
}