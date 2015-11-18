#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
struct operationCode
{
char *mnemonic;
char *opcode;
};
struct symbolTable
{
    char symbol[6];
    int address;
    struct symbolTable *next;
} ;
struct operationCode optab[60];

struct symbolTable *symtab;
void insert_optab()
{
optab[1].mnemonic="Add";optab[1].opcode="18";
optab[2].mnemonic="Addf";optab[2].opcode="58";
optab[3].mnemonic="Addr";optab[3].opcode="90";
optab[4].mnemonic="And";optab[4].opcode="40";
optab[5].mnemonic="Clear";optab[5].opcode="B4";
optab[6].mnemonic="Comp";optab[6].opcode="28";
optab[7].mnemonic="Compf";optab[7].opcode="88";
optab[8].mnemonic="Compr";optab[8].opcode="A0";
optab[9].mnemonic="Div";optab[9].opcode="24";
optab[10].mnemonic="Divf";optab[10].opcode="64";
optab[11].mnemonic="Divr";optab[11].opcode="9C";
optab[12].mnemonic="Fix";optab[12].opcode="C4";
optab[13].mnemonic="Float";optab[13].opcode="C0";
optab[14].mnemonic="Hio";optab[14].opcode="F4";
optab[15].mnemonic="j";optab[15].opcode="3C";
optab[16].mnemonic="Jeq";optab[16].opcode="30";
optab[17].mnemonic="Jgt";optab[17].opcode="34";
optab[18].mnemonic="Jlt";optab[18].opcode="38";
optab[19].mnemonic="Jsub";optab[19].opcode="48";
optab[20].mnemonic="Lda";optab[20].opcode="00";
optab[21].mnemonic="Ldb";optab[21].opcode="68";
optab[22].mnemonic="Ldch";optab[22].opcode="50";
optab[23].mnemonic="Ldf";optab[23].opcode="70";
optab[24].mnemonic="Ldl";optab[24].opcode="08";
optab[25].mnemonic="Lds";optab[25].opcode="6C";
optab[26].mnemonic="Ldt";optab[26].opcode="74";
optab[27].mnemonic="Ldx";optab[27].opcode="04";
optab[28].mnemonic="Lps";optab[28].opcode="D0";
optab[29].mnemonic="Mul";optab[29].opcode="20";
optab[30].mnemonic="Mulf";optab[30].opcode="60";
optab[31].mnemonic="Mulr";optab[31].opcode="98";
optab[32].mnemonic="Norm";optab[32].opcode="C8";
optab[33].mnemonic="Or";optab[33].opcode="44";
optab[34].mnemonic="Rd";optab[34].opcode="D8";
optab[35].mnemonic="Rmo";optab[35].opcode="AC";
optab[36].mnemonic="Rsub";optab[36].opcode="4C";
optab[37].mnemonic="Shiftl";optab[37].opcode="A4";
optab[38].mnemonic="Shiftr";optab[38].opcode="A8";
optab[39].mnemonic="Sio";optab[39].opcode="F0";
optab[40].mnemonic="Ssk";optab[40].opcode="EC";
optab[41].mnemonic="Sta";optab[41].opcode="0C";
optab[42].mnemonic="Stb";optab[42].opcode="78";
optab[43].mnemonic="Stch";optab[43].opcode="54";
optab[44].mnemonic="Stf";optab[44].opcode="80";
optab[45].mnemonic="Sti";optab[45].opcode="D4";
optab[46].mnemonic="Stl";optab[46].opcode="14";
optab[47].mnemonic="Sts";optab[47].opcode="7C";
optab[48].mnemonic="Stsw";optab[48].opcode="E8";
optab[49].mnemonic="Stt";optab[49].opcode="84";
optab[50].mnemonic="Stx";optab[50].opcode="10";
optab[51].mnemonic="Sub";optab[51].opcode="1C";
optab[52].mnemonic="Subf";optab[52].opcode="5C";
optab[53].mnemonic="Subr";optab[53].opcode="94";
optab[54].mnemonic="Svc";optab[54].opcode="B0";
optab[55].mnemonic="Td";optab[55].opcode="E0";
optab[56].mnemonic="Tio";optab[56].opcode="F8";
optab[57].mnemonic="Tix";optab[57].opcode="2C";
optab[58].mnemonic="Tixr";optab[58].opcode="B8";
optab[59].mnemonic="Wd";optab[59].opcode="DC";
}


//---------------------
void c_to_hexa(int x,char arr[5])// convert decimal to hexa
{
    int i=0,y;
  while(x>=0)
  {
     y=x%16;
    switch(y)
    { case '10' :arr[i]='A';
				  break;
	case '11' :arr[i]='B';
				  break;
	case '12' :arr[i]='C';
				  break;
	 case '13' :arr[i]='D';
				  break;
	 case '14' :arr[i]='E';
				  break;
	 case '15' :arr[i]='F';
				 break;
	default :arr[i]=y;
	}
  i++;x=x/16;
   printf("hello");
 }
}

long int c_to_decimal(char *arr)// convert hexa to decimal
{
    int i=5,y;
    long int sum=0;
while(i>=0)
  {switch(arr[i])
	 {   case 'A'  :y=10;
					sum=sum+y*pow(16,i);
					break;
		  case 'B' :y=11;
					sum=sum+y*pow(16,i);
					break;
		  case 'C' :y=12;
					sum=sum+y*pow(16,i);
					break;
		  case 'D' :y=13;
					sum=sum+y*pow(16,i);
					break;
		  case 'E' :y=14;
					sum=sum+y*pow(16,i);
					break;
		  case 'F' :y=15;
					sum=sum+y*pow(16,i);
					break;
		  default :y=(int)(arr[i])-(int)(0);
							sum=sum+y*pow(16,i);
	  }
	i--;
  }
return sum;
}


int search_opcode(char s[5])//search for operation code
{
    int k;
    for(k=0;k<60;k++)
    {
     if(strcmp(optab[k].opcode,s)==0)
	  return k;
    }
 return -1;
}


int stringlen(char  s[20])
{int j=2,len=0;
while((int)(s[j])!= 27)   //	ASCII Code for '
	{ len++;
	  j++;
	 }
if((int )(s[0])==58)		//ASCII Code for X
  return (len/2);
else
 return len;
 }

int search_symtab(char L[6],int loc)//search for symbol and insert it if it is not found(pass1)
 {
     int k;
     char s[5];
     struct symbolTable *ptr=symtab;
     while(ptr!=NULL)
	 {
		if(strcmp(ptr->symbol,L)==0)
		return 0;
		ptr=ptr->next;
     }
    // printf("hello");
     ptr=(struct symbolTable*)malloc(sizeof(struct symbolTable));
     printf("hello");
    c_to_hexa(loc,s);
     printf("hello");
    strcpy(ptr->symbol,L);
    strcpy(ptr->address,s);
    ptr->next=NULL;
    symtab->next=ptr;
    return 1;
 }
int main()
{
int i,k,locctr,startingAddress,programLength;
int r;
char line[100],opcode[5],label[6],operand[20],programName[20];

FILE *input,*intermediate,*output;
input=fopen("INPUT.dat","r");
intermediate=fopen("intermediate.dat","w");
insert_optab();
printf("\nmnemonics \t opcode ");
for(i=1;i<60;i++)
printf("\n %s \t %s",optab[i].mnemonic,optab[i].opcode);


//WORKING OF PASS1
fscanf(input,"%s %s %s",&label,&opcode,&operand);
printf("\n%s %s %s",label,opcode,operand);
if (strcmp(opcode,"Start")==0)
{
strcpy(programName,label);
r=c_to_decimal(operand);
printf("\n %d",r);
startingAddress=locctr=r;
//printf("\n %s %s",locctr,startingAddress);
fprintf(intermediate,"- %s %s %s",programName,opcode,operand);
fscanf(input,"%s %s %s",&label,&opcode,&operand);
printf("\n%s %s %s",label,opcode,operand);
}//end if start
else
locctr="0";

while(strcmp(opcode,"End")!=0)
{
    //printf("helo");
    if(strcmp(label,"-")!=0)
    {
     r=search_symtab(label,locctr);
     if(r==0)
     {
        printf("\nDUPLICATE SYMBOL");
        exit(1);
     }
    }
    r=search_opcode(opcode);
    if(r>=0)
        locctr=locctr+3;
    else if(strcmp(opcode,"Word")==0)
     locctr+=3;
    else if(strcmp(opcode,"RESW")==0)
	    locctr+=3*atoi(operand);
    else if(strcmp(opcode,"RESB")==0)
        locctr+=atoi(operand);
    else if(strcmp(opcode,"BYTE")==0)
        locctr+=stringlen(operand);
    else
        printf("\nOPCODE NOT FOUND\n");
        exit(1);

fprintf(intermediate,"%d %s %s %s",locctr,label,opcode,operand);
fscanf(input,"%s %s %s",&label,&opcode,&operand);
printf("\n%s %s %s",label,opcode,operand);
}
fprintf(intermediate,"- - %s %s",opcode,operand);
programLength=locctr-startingAddress;
fclose(intermediate);
fclose(input);
//working of pass2

return 0;
}


void PASS2()
{
FILE *intermediate,*output;
intermediate=fopen("intermediate.dat","r");
output=fopen("OUTPUT.dat","w");


}
