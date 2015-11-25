#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
struct operationCode
{
char mnemonic[7];
char opcode[2];
};
struct symbolTable
{
    char symbol[6];
    char address[4];
    struct symbolTable *next;
} ;
struct operationCode optab[60];

struct symbolTable *symtab=NULL;


void insert_optab()//to insert the opcodes of mnemonics
{
strcpy(optab[1].mnemonic,"Add");strcpy(optab[1].opcode,"18");
strcpy(optab[2].mnemonic,"Addf");strcpy(optab[2].opcode,"58");
strcpy(optab[3].mnemonic,"Addr");strcpy(optab[3].opcode,"90");
strcpy(optab[4].mnemonic,"And");strcpy(optab[4].opcode,"40");
strcpy(optab[5].mnemonic,"Clear");strcpy(optab[5].opcode,"B4");
strcpy(optab[6].mnemonic,"Comp");strcpy(optab[6].opcode,"28");
strcpy(optab[7].mnemonic,"Compf");strcpy(optab[7].opcode,"88");
strcpy(optab[8].mnemonic,"Compr");strcpy(optab[8].opcode,"A0");
strcpy(optab[9].mnemonic,"Div");strcpy(optab[9].opcode,"24");
strcpy(optab[10].mnemonic,"Divf");strcpy(optab[10].opcode,"64");
strcpy(optab[11].mnemonic,"Divr");strcpy(optab[11].opcode,"9C");
strcpy(optab[12].mnemonic,"Fix");strcpy(optab[12].opcode,"C4");
strcpy(optab[13].mnemonic,"Float");strcpy(optab[13].opcode,"C0");
strcpy(optab[14].mnemonic,"Hio");strcpy(optab[14].opcode,"F4");
strcpy(optab[15].mnemonic,"j");strcpy(optab[15].opcode,"3C");
strcpy(optab[16].mnemonic,"Jeq");strcpy(optab[16].opcode,"30");
strcpy(optab[17].mnemonic,"Jgt");strcpy(optab[17].opcode,"34");
strcpy(optab[18].mnemonic,"Jlt");strcpy(optab[18].opcode,"38");
strcpy(optab[19].mnemonic,"Jsub");strcpy(optab[19].opcode,"48");
strcpy(optab[20].mnemonic,"Lda");strcpy(optab[20].opcode,"00");
strcpy(optab[21].mnemonic,"Ldb");strcpy(optab[21].opcode,"68");
strcpy(optab[22].mnemonic,"Ldch");strcpy(optab[22].opcode,"50");
strcpy(optab[23].mnemonic,"Ldf");strcpy(optab[23].opcode,"70");
strcpy(optab[24].mnemonic,"Ldl");strcpy(optab[24].opcode,"08");
strcpy(optab[25].mnemonic,"Lds");strcpy(optab[25].opcode,"6C");
strcpy(optab[26].mnemonic,"Ldt");strcpy(optab[26].opcode,"74");
strcpy(optab[27].mnemonic,"Ldx");strcpy(optab[27].opcode,"04");
strcpy(optab[28].mnemonic,"Lps");strcpy(optab[28].opcode,"D0");
strcpy(optab[29].mnemonic,"Mul");strcpy(optab[29].opcode,"20");
strcpy(optab[30].mnemonic,"Mulf");strcpy(optab[30].opcode,"60");
strcpy(optab[31].mnemonic,"Mulr");strcpy(optab[31].opcode,"98");
strcpy(optab[32].mnemonic,"Norm");strcpy(optab[32].opcode,"C8");
strcpy(optab[33].mnemonic,"Or");strcpy(optab[33].opcode,"44");
strcpy(optab[34].mnemonic,"Rd");strcpy(optab[34].opcode,"D8");
strcpy(optab[35].mnemonic,"Rmo");strcpy(optab[35].opcode,"AC");
strcpy(optab[36].mnemonic,"Rsub");strcpy(optab[36].opcode,"4C");
strcpy(optab[37].mnemonic,"Shiftl");strcpy(optab[37].opcode,"A4");
strcpy(optab[38].mnemonic,"Shiftr");strcpy(optab[38].opcode,"A8");
strcpy(optab[39].mnemonic,"Sio");strcpy(optab[39].opcode,"F0");
strcpy(optab[40].mnemonic,"Ssk");strcpy(optab[40].opcode,"EC");
strcpy(optab[41].mnemonic,"Sta");strcpy(optab[41].opcode,"0C");
strcpy(optab[42].mnemonic,"Stb");strcpy(optab[42].opcode,"78");
strcpy(optab[43].mnemonic,"Stch");strcpy(optab[43].opcode,"54");
strcpy(optab[44].mnemonic,"Stf");strcpy(optab[44].opcode,"80");
strcpy(optab[45].mnemonic,"Sti");strcpy(optab[45].opcode,"D4");
strcpy(optab[46].mnemonic,"Stl");strcpy(optab[46].opcode,"14");
strcpy(optab[47].mnemonic,"Sts");strcpy(optab[47].opcode,"7C");
strcpy(optab[48].mnemonic,"Stsw");strcpy(optab[48].opcode,"E8");
strcpy(optab[49].mnemonic,"Stt");strcpy(optab[49].opcode,"84");
strcpy(optab[50].mnemonic,"Stx");strcpy(optab[50].opcode,"10");
strcpy(optab[51].mnemonic,"Sub");strcpy(optab[51].opcode,"1C");
strcpy(optab[52].mnemonic,"Subf");strcpy(optab[52].opcode,"5C");
strcpy(optab[53].mnemonic,"Subr");strcpy(optab[53].opcode,"94");
strcpy(optab[54].mnemonic,"Svc");strcpy(optab[54].opcode,"B0");
strcpy(optab[55].mnemonic,"Td");strcpy(optab[55].opcode,"E0");
strcpy(optab[56].mnemonic,"Tio");strcpy(optab[56].opcode,"F8");
strcpy(optab[57].mnemonic,"Tix");strcpy(optab[57].opcode,"2C");
strcpy(optab[58].mnemonic,"Tixr");strcpy(optab[58].opcode,"B8");
strcpy(optab[59].mnemonic,"Wd");strcpy(optab[59].opcode,"DC");
}


void hexaValue_to_CharArray(int x,char arr[4])// write hexadecimal value to character array
{
 int i=3,r;
while(i>=0)
{
    r=x%0x10;
     switch(r)
    {
    case 0xa:
        arr[i]='a';
        break;
	case 0xb:
	    arr[i]='b';
		break;
	case 0xc:
	    arr[i]='c';
        break;
	 case 0xd :
	     arr[i]='d';
        break;
	 case 0xe:
	     arr[i]='e';
        break;
	 case 0xf:
	     arr[i]='f';
        break;
     default :
        arr[i]=r+0x30;
	}
    x=x/0x10;
    i--;
}
}


int character_to_hexa(char *a)// convert character operand to hexadecimal
{
  int x=0x0,i=0;
while(a[i]!=NULL)
{
    switch(a[i])
    {
    case 'A':
        x=x*0x10+10;
        break;
    case 'B':
        x=x*0x10+11;
        break;
    case 'C':
        x=x*0x10+12;
        break;
    case 'D':
        x=x*0x10+13;
        break;
    case 'E':
        x=x*0x10+14;
        break;
    case 'F':
        x=x*0x10+15;
        break;
    default:
        x=x*0x10+(a[i]-0x30);

    }
    i++;
}
return x;
}


int search_opcode(char t[])//search for operation code of mnemonics
{
    int k;
    for(k=1;k<60;k++)
    {
        if(strcmp(optab[k].mnemonic,t)==0)
            return k;
    }
 return -1;
}

int search_symtab(char L[7],int loc)//search for symbol and insert if it is not found(pass1)
 {
     int k;
     char s[4];
     struct symbolTable *str=symtab,*ptr=symtab;
     while(ptr!=NULL)
	 {
		if(strcmp(ptr->symbol,L)==0)
		   return 0;
	    ptr=ptr->next;
     }
     ptr=(struct symbolTable*)malloc(sizeof(struct symbolTable));
    hexaValue_to_CharArray(loc,s);
    strcpy(ptr->symbol,L);
    fflush(stdin);
    strcpy(ptr->address,s);
    fflush(stdin);
    ptr->next=NULL;
    if(symtab==NULL)
        symtab=ptr;
    else
    {
        while(str->next!=NULL)
        str=str->next;
    str->next=ptr;
    }
    return 1;
 }

int search_symtab2(char l[6],char t[][6],int p)//searching of the symbols in pass2
 {
     int r,i=check_indexing(l);
        struct symbolTable *ptr=symtab;
        while(ptr!=NULL)
        {
            if(strcmp(ptr->symbol,l)==0)
            {
                r=0;
                for(i=2;i<6;i++)
               {
                t[p][i]=ptr->address[r];r++;
               }
               if(i==1)
                t[p][3]+=0x8;
               return 1;
            }
            ptr=ptr->next;
        }
        return -1;
 }

int  check_indexing(char s[6])//to check whether indexed addressing
{
int i=0,y=strlen(s);
while(i<y)
{
if(s[i]!=',')
 i++;
else
{
if(s[i+1]=='x')
	 {
	     s[i]=NULL;
	     return 1;
	 }
}
}
return 0;
}

//WORKING OF PASS1
int PASS1()
{
int i,r,currentLength=0x0,locctr,j,startingAddress,programLength;
char opcode[7],label[20],operand[20],programName[20];

FILE *input,*intermediate;
input=fopen("INPUT.dat","r");
intermediate=fopen("intermediate.dat","w");

//WORKING OF PASS1
fscanf(input,"%s %s %s",&label,&opcode,&operand);
if (strcmp(opcode,"Start")==0)
{
strcpy(programName,label);
r=character_to_hexa(operand);
startingAddress=locctr=currentLength=r;
fprintf(intermediate,"%x %s %s %s",locctr,programName,opcode,operand);
fscanf(input,"%s %s %s",&label,&opcode,&operand);
}//end if start
else
locctr=0x0;

while(strcmp(opcode,"End")!=0)
{
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
    {
        locctr=locctr+3;currentLength=3;
    }
    else if(strcmp(opcode,"Word")==0)
    {
     locctr+=3;
     currentLength=3;
    }
    else if(strcmp(opcode,"Resw")==0)
    {
       locctr+=currentLength=3*atoi(operand);
    }
    else if(strcmp(opcode,"Resb")==0)
    {
        locctr+=currentLength=atoi(operand);
    }
    else if(strcmp(opcode,"Byte")==0)
    {
        if(operand[0]=='C')
        {
            i=2;currentLength=0x0;
            while(operand[i]!=',')
            {
                locctr++;currentLength++;
                i++;
            }
        }
        else if(operand[0]=='X')
        {
            locctr+=1;currentLength=1;
        }
    }
    else
    {
        printf("\nOPCODE NOT FOUND\n");
        exit(1);
    }

    fprintf(intermediate,"\n%x %s %s %s",locctr-currentLength,label,opcode,operand);
    fscanf(input,"%s %s %s",&label,&opcode,&operand);
}
fprintf(intermediate,"\n%x - %s %s",locctr,opcode,operand);
programLength=locctr-startingAddress;
fclose(intermediate);
fclose(input);
return programLength;

}

//WORKING OF PASS2
void PASS2(int programLength)
{
int i,k,f,p,m,currentLength=0x0,locctr,j,startingAddress;
int r,s=0;
char t[11][6],opcode[7],label[20],operand[20],tarr[4];

FILE *intermediate,*output;
intermediate=fopen("intermediate.dat","r");
output=fopen("OUTPUT.dat","w");
fscanf(intermediate,"%x %s %s %s",&locctr,&label,&opcode,&operand);
startingAddress=locctr;
if(strcmp(opcode,"Start")==0)
{
   hexaValue_to_CharArray(programLength,tarr);
		p=strlen(operand);
		fprintf(output,"H%s",label);
		 for(i=0;i<(6-p);i++)
            fprintf(output,"0");
		 fprintf(output,"%s",operand);
		 for(i=0;i<2;i++)
          fprintf(output,"0");
         for(i=0;i<4;i++)
		    fprintf(output,"%c",tarr[i]);
   fscanf(intermediate,"%x %s %s %s",&locctr,&label,&opcode,&operand);
}
m=0;p=0;s=0;f=0;
while(strcmp(opcode,"End")!=0)
{
    k=search_opcode(opcode);
    if(k>0)
    {
    t[p][0]=optab[k].opcode[0];
    t[p][1]=optab[k].opcode[1];
    if(strcmp(operand,"-")!=0)
    {
    i=check_indexing(operand);
    j=search_symtab2(operand,t,p);
    if(j<0)
    {
    printf("\nerror operand not found");
    exit(1);
    }
    }
    else
    {
         for(i=2;i<6;i++)
			  t[p][i]='0';
    }
    if(p==0)
        currentLength=locctr;
    m=m+3;p++;s=3;f=0;
    }
    else if(strcmp(opcode,"Word")==0)
    {
        r=atoi(operand);
        i=0;
        hexaValue_to_CharArray(r,operand);
        for(i=0;i<2;i++)
            t[p][i]='0';
            j=0;
        for(i=2;i<6;i++)
        {
            t[p][i]=operand[j];j++;
        }
    if(p==0)
        currentLength=locctr;
    m=m+3;p++;s=3;f=0;
    }
    else if(strcmp(opcode,"Byte")==0)
    {
     if(operand[0]=='C')
        {
            i=2;j=0;
            while(operand[i]!=',')
            {
                j++;i++;
            }

            m+=j;s=j;
            for(i=0;i<6-j;i++)
             {
                 t[p][i]='0';
             }
             j=2;
             while(operand[j]!=',')
             {
                 t[p][i]=operand[j];
                 i++;j++;
             }
             if(p==0)
        currentLength=locctr;
             p++;f=0;
        }
        else if(operand[0]=='X')
            {
                i=2;j=0;
              while(operand[i]!=',')
              {
                  j++;i++;
              }
              for(i=0;i<6-j;i++)
             {
                 t[p][i]='0';
             }
             j=2;
             while(operand[j]!=',')
             {
                 t[p][i]=operand[j];
                 i++;j++;
             }
             if(p==0)
        currentLength=locctr;
             m+=1;s=1;p++;f=0;
            }
    }

    if(m>30)
    {
    m=m-s;
    fprintf(output,"\nT00%x%x",currentLength,m);
    for(i=0;i<p-1;i++)
    {
        for(j=0;j<6;j++)
        fprintf(output,"%c",t[i][j]);
    }
        for(j=0;j<6;j++)
            t[0][j]=t[p-1][j];
            currentLength=locctr;
        p=1;
        m=s;
        if(m==0)
            f=1;
        else
        f=0;
    }
    else if(strcmp(opcode,"Resb")==0 || strcmp(opcode,"Resw")==0)
    {
        if(f==0)
        {
    fprintf(output,"\nT00%x%x",currentLength,m);
    for(i=0;i<p;i++)
    {
        for(j=0;j<6;j++)
        fprintf(output,"%c",t[i][j]);
    }

        p=0;
        m=0;
        f=1;
       }
     }
   fscanf(intermediate,"%x %s %s %s",&locctr,&label,&opcode,&operand);
}
if(f==0)
{
fprintf(output,"\nT00%x%x",currentLength,m);
    for(i=0;i<p;i++)
    {
        for(j=0;j<6;j++)
        fprintf(output,"%c",t[i][j]);
    }
}
fprintf(output,"\nE");
hexaValue_to_CharArray(startingAddress,operand);
p=strlen(operand);
			for(i=0;i<2;i++)
                    fprintf(output,"0");
			for(i=0;i<4;i++)
			     fprintf(output,"%c",operand[i]);

fclose(intermediate);
fclose(output);

}

int main()
{
int programLength;
insert_optab();
programLength=PASS1();//WORKING OF PASS1
void PASS2(programLength);//WORKING OF PASS2
printf("\nTHE OUTPUT.DAT FILE CONTAINS THE OBJECT PROGRAM\n");
return 0;
}
