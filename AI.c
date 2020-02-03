#include <stdlib.h>
#include <stdio.h>

int jmlk, sdk, sdg, byk;
int rrk, plan, nrml, cpat;
int ptr[9], nilaitengah[9];
int jml_nilai, jml_nilaitengah, nlh;

int main(void)
{
	system("cls");
	printf("\t\tNama : Muhd Aiman Bin Abd Azis\n\n");
	printf("\t\tJudul: Traffic Light\n\n");
	printf("\t''Atur Input Jumlah Kenderaan dan Rata-rata Kecepatan''\n");
	printf("\t 1. Masukkan Jumlah Kenderaan (0-30) : ");
	scanf("%d",&jmlk);
	printf("\n\t 2. Rata-rata Kecepatan (0-60) : ");
	scanf("%d",&rrk);

	system("cls");
	printf("Jumlah Kenderaan adalah %d unit\n",jmlk);
	printf("Rata-rata Kecepatan adalah %d km/h\n",rrk);

	//fuzzyfikasi jumlah kenderaan
	if(jmlk<=7)                //sigm=jumlah kenderaan
	{
		sdk=100;         //sdk=sedikit
		sdg=0;             //sdg=sedang
		byk=0;                     //byk=banyak
		printf("\nSedikit Kenderaan adalah %d%%",sdk);
	}
else if(jmlk>7 && jmlk<=13)
	{
		sdk=100-((jmlk-7)*10);
		sdg=((jmlk-7)*10);
		byk=0;
		printf("\nSedikit Kenderaan adalah %d%%",sdk);
		printf("\nSedang Kenderaan adalah %d%%",sdg);
	}
else if(jmlk>13 && jmlk<=17)
	{
		sdk=0;
		sdg=100;
		byk=0;
		printf("\nSedang Kenderaan adalah %d%%",sdg);
	}
else if(jmlk>17 && jmlk<=23)
	{
		sdk=0;
		sdg=100-((jmlk-17)*10);
		byk=((jmlk-17)*10);
		printf("\nSedang Kenderaan adalah %d%%",sdg);
		printf("\nBanyak Kenderaan adalah %d%%",byk);
	}
else
	{
		sdk=0;
		sdg=0;
		byk=100;
		printf("\nBanyak Kenderaan adalah %d%%",byk);
	}

//fuzzyfikasi Rata-rata Kecepatan
	if(rrk<=15)                //tmp=temperatur terukur
	{
		plan=100;               //plan=perlahan
		nrml=0;                  //nrml=normal
		cpat=0;                 //cpat=cepat
		printf("\nPerlahan adalah %d%%",plan);
	}
else if(rrk>15 && rrk<=25)
	{
		plan=100-((rrk-15)*10);
		nrml=((rrk-15)*10);
		cpat=0;
		printf("\nPerlahan adalah %d%%",plan);
		printf("\nNormal adalah %d%%",nrml);
	}
else if(rrk>25 && rrk<=35)
	{
		plan=0;
		nrml=100;
		cpat=0;
		printf("\nNormal adalah %d%%",nrml);
	}
else if(rrk>35 && rrk<=45)
	{
		plan=0;
		nrml=100-((rrk-35)*10);
		cpat=((rrk-35)*10);
		printf("\nNormal adalah %d%%",nrml);
		printf("\nCepat adalah %d%%",cpat);
	}
else
 {
  plan=0;
  nrml=0;
  cpat=100;
  printf("\nCepat adalah %d%%",cpat);
 }

	//proses inferensi
printf("\n----------------Evaluasi Rule---------------\n");
printf("|Jml|Rrk  |  Perlahan  |  Normal  |  Cepat |\n");
printf("|Kenderaan|----------------------------------\n");
printf("| Sedikit |     S      |     S    |    S   |\n");
printf("| Sedang  |     M      |     M    |    M   |\n");
printf("| Banyak  |     L      |     L    |    L   |\n");
printf("--------------------------------------------\n");
printf("------ S = Short, M = Medium, L = Long ------\n");

//rule based
if(sdk<plan)
 {ptr[0]=sdk;nilaitengah[0]=30;}
else
 {ptr[0]=plan;nilaitengah[0]=30;}

if(sdk<nrml)
 {ptr[1]=sdk;nilaitengah[1]=30;}
else
 {ptr[1]=nrml;nilaitengah[1]=30;}

if(sdk<cpat)
 {ptr[2]=sdk;nilaitengah[2]=30;}
else
 {ptr[2]=cpat;nilaitengah[2]=30;}
 
if(sdg<plan)
 {ptr[3]=sdg;nilaitengah[3]=60;}
else
 {ptr[3]=plan;nilaitengah[3]=60;}

if(sdg<nrml)
 {ptr[4]=sdg;nilaitengah[4]=60;}
else
 {ptr[4]=nrml;nilaitengah[4]=60;}

if(sdg<cpat)
 {ptr[5]=sdg;nilaitengah[5]=60;}
else
 {ptr[5]=cpat;nilaitengah[5]=60;}

if(byk<plan)
 {ptr[6]=byk;nilaitengah[6]=90;}
else
 {ptr[6]=plan;nilaitengah[6]=90;}

if(byk<nrml)
 {ptr[7]=byk;nilaitengah[7]=90;}
else
 {ptr[7]=nrml;nilaitengah[7]=90;}

if(byk<cpat)
 {ptr[8]=byk;nilaitengah[8]=90;}
else
 {ptr[8]=cpat;nilaitengah[8]=90;}

//inferensi derajat keanggotaan
jml_nilai=ptr[0]+ptr[1]+ptr[2]+ptr[3]+ptr[4]+ptr[5]+ptr[6]+ptr[7]+ptr[8];
jml_nilaitengah=(ptr[0]*nilaitengah[0])+(ptr[1]*nilaitengah[1])+(ptr[2]*nilaitengah[2])+(ptr[3]*nilaitengah[3])+(ptr[4]*nilaitengah[4])+(ptr[5]*nilaitengah[5])+(ptr[6]*nilaitengah[6])+(ptr[7]*nilaitengah[7])+(ptr[8]*nilaitengah[8]);


//defuzzyfikasi
if(jml_nilai==0)
 {
  nlh=0;
  printf("\nNyala Lampu Hijau adalah %d Seconds\n",nlh);
 }
else
 {
  nlh=jml_nilaitengah/jml_nilai;
  printf("\nKlasifikasi Seconds");
  printf("\n1. Short    = 30 Seconds");
  printf("\n2. Medium   = 60 Seconds");
  printf("\n3. Long     = 90 Seconds");
  printf("\nDan Nyala Lampu Hijau adalah %d Seconds\n\n",nlh);
 }
	
	system("pause");
	return(0);

}