#include <stdio.h>
#include <stdlib.h>
int asalmi(int sayi){
    if(sayi==2)
        return 1;
        int sayac=0;
    for(int i=2;i<sayi;i++){
        if(sayi%i==0){
            return 0;
        }

    }
        if(sayac==0)
           return 1;


}
int main()
{
    int sayi,i,j;
    int tutucu;
    printf("Bir sayi giriniz:");
    scanf("%d",&sayi);
    if(sayi==0 || sayi==1){
        printf("Sayi en yakin asal sayiya yuvarlandi:2");
        exit(0);
    }
    if(asalmi(sayi)==1){
    printf("Sayi en yakin asal sayiya yuvarlandi:%d",sayi);
    exit(0);
    }
    else{
    int *saklayici=malloc(sizeof(int)*sayi);
    saklayici[0]=0;
    saklayici[1]=0;
    saklayici[2]=2;
    int index;
    int tutar1;
        for(i=2;i<sayi;i++){
            int sayac=0;
            for(j=2;j<i;j++){
                 if(i%j==0){
                    sayac++;
                    saklayici[i]=0;
                    break;
                }


            }
            if(sayac==0){
                 saklayici[i]=i;
                    index=i;
            }

        }
        tutar1=index;

        int fark=sayi-index;
        int t;
        tutucu=saklayici[index];



        saklayici=(int*)realloc(saklayici,sizeof(int)*(sayi+fark));

        int fark2=fark;
        int uyari=0;
        while(fark>0){

            for(t=i;t<i+(fark2)+1;t++){
                int sayac2=0;
                for(j=2;j<t;j++){
                    if(t%j==0){
                    sayac2++;
                    saklayici[t]=0;
                    break;
                }

                }
                if(sayac2==0){

                 saklayici[t]=t;
                    index=t;
                    uyari++;
                    break;
            }


            }
           fark--;
        }

        int yeni_fark;
        if(uyari!=0)
        yeni_fark=index-sayi;
        else
           yeni_fark=fark2+1;




        if(fark2<yeni_fark){
            printf("En Yakin Asal Sayiya Yuvarlandi........:%d\n",index);

        }
        else if(fark2>yeni_fark){

            printf("En Yakin Asal Sayiya Yuvarlandi:%d\n",index);

        }
        else if(fark2==yeni_fark)
            printf("Sayi en yakin iki asal sayiya da esit uzaklikta.%d ve %d ye yuvarlanabilir.",tutar1,index);
        free(saklayici);

}
}
