#include<stdio.h>
#include<conio.h>
struct mneumonics
{
char *mnemonic;
char *opcode;
};
int main()
{
int i;
struct mneumonics optab[100];
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

printf("\nmnemonics \t opcode ");
for(i=1;i<60;i++)
printf("\n %s \t %s",optab[i].mnemonic,optab[i].opcode);

return 0;
}
