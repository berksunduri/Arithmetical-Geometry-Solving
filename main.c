//Berk Sunduri 180201145
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
struct
{
    float x,y,z;
    int r,g,b;
} nokta[10000];




int main()
{

    FILE *veriler1;

    veriler1=fopen("C:\\veriler1.nkt","r");


    char line[10000];
    char lineb[1000];
    char line2[84578];

    if(veriler1==NULL)
    {
        printf("error opening file");
        exit(1);
    }




    for(int k=6; k<10005; k++) //veriler1in kontrol mekanizmasi
    {
        nokta[k].x=0.010;
        nokta[k].y=0.010;
        nokta[k].z=0.010;
        nokta[k].r=300;
        nokta[k].g=300;
        nokta[k].b=300;
    }


    int i = 0;
    int j=0;
    int index2=0;
    int index=0;
    while (fgets(line, sizeof(line), veriler1))//Verilerin x,y,z r,g,b ye atanmasi
    {
        i++;
        if(i > 4 )
        {
            fscanf(veriler1,"%f %f %f %d %d %d",&nokta[index].x,&nokta[index].y,&nokta[index].z,&nokta[index].r,&nokta[index].g,&nokta[index].b);//Noktalarin dosya1den okunup struct a kaydedilmesi
            //printf("%f %f %f %d %d %d\n",nokta[index].x,nokta[index].y,nokta[index].z,nokta[index].r,nokta[index].g,nokta[index].b);//Noktalari Yazdirma
            index++;
        }
    }

    float dist=0;
    float mini=FLT_MAX;
    float dist1=0;
    float mini1=FLT_MAX;
    int vericont;

int operasyon;
LOOP:

    printf("\n\nBir Islem seciniz:\n");
    printf("1) Dosyalarda ki verilerin tam olup olmadigini kontrol etmek.\n");
    printf("2) Birbirine en yakin noktalarin bilgileri ve ortalama uzakliklari (Veriler1)\n");

    printf("3) Tum noktalari icine alacak bir kupun kenar nokta bilgileri\n");
    printf("4) Bir kurenin icinde kalan noktalarin bilgileri ve nokta numaralari\n");
    printf("5) Cikis yap\n");
    printf("Bir islem seciniz:");
    scanf("%d",&operasyon);

        if(operasyon==1)
        {
            printf("Hangi veriler dosyasini kontrol etmek istersiniz?\n");
        printf("1) Veriler 1 dosyasi\n");

        printf("Bir dosya seciniz:");
        scanf("%d",&vericont);
        if(vericont==1)//veriler 1 in tam olup olmadigini kontrol etmek
        {
            for(int c=0; c<index-1; c++) //Verilerin tam olup olmadigini kontrol etmek
            {
                if(nokta[c].x==0.010 || nokta[c].y==0.010 || nokta[c].z==0.010 || nokta[c].r==300 || nokta[c].g==300 || nokta[c].b ==300)
                {
                    printf("Veriler 1 dosyasinda ki %d sirasinda ki deger tam degildir.\n",c);
                    break;
                }
                else
                    printf("Veriler 1 dosyasinda ki degerler tamdir\n");
                break;

            }

        }

        }




        if(operasyon==2)//en yakin veri kontrolu
        {
       float aver=0;
        int n=0;
        float ort;

        for(int u=0; u<index-1; u++) //distance control of veriler 1
            {

                for(int o=u+1; o<index-2; o++)
                {

                    dist = sqrt( pow((nokta[o].x- nokta[u].x),2) +
                                 pow((nokta[o].y - nokta[u].y),2)+
                                 pow((nokta[o].z-nokta[u].z),2)
                               );
                               n++;
                                aver=aver+dist;
                    if(dist<mini)
                    {
                        mini=dist;
                    }

                }

            }
            ort=aver/n;

            printf("En yakin uzaklik %f ve ortalama uzaklik: %f ",mini,ort);
        }

        if(operasyon==3)//Kup bilgileri

        {
            printf("Verilen verilerde ki Kup Kenarlarinin Bilgileri:\n");
             int locationX=0,locationRX,locationRY,locationRZ;
            int locationY=0,locationGX,locationGY,locationGZ;
            int locationZ=0,locationBX,locationBY,locationBZ;
            float maximumX=nokta[0].x;
            float maximumY=nokta[0].y;
            float maximumZ=nokta[0].z;
            printf("\nVeriler1 dosyasi icin:\n");
            for(int c=1;c<index;c++)
            {
                if(nokta[c].x>maximumX)
                {
                    maximumX=nokta[c].x;
                    locationRX=nokta[c].r;
                    locationGX=nokta[c].g;
                    locationBX=nokta[c].b;
                    locationX=c;
                }
            }
            printf("Nokta degeri(X:%f, Bulundugu sira:%d, Renk Verileri: %d %d %d\n",maximumX,locationX+6,locationRX,locationGX,locationBX);
            for(int c=1;c<index;c++)
            {
                if(nokta[c].y>maximumY)
                {
                    maximumY=nokta[c].y;
                    locationRY=nokta[c].r;
                    locationGY=nokta[c].g;
                    locationBY=nokta[c].b;
                    locationY=c;
                }
            }
            printf("Nokta degeri(Y):%f, Bulundugu sira:%d, Renk Verileri: %d %d %d\n",maximumY,locationY+6,locationRY,locationGY,locationBY);

            for(int c=1;c<index;c++)
            {
                if(nokta[c].z>maximumZ)
                {
                    maximumZ=nokta[c].z;
                    locationRZ=nokta[c].r;
                    locationGZ=nokta[c].g;
                    locationBZ=nokta[c].b;
                    locationZ=c;
                }
            }
            printf("Nokta degeri(Z):%f, Bulundugu sira:%d, Renk Verileri: %d %d %d\n",maximumZ,locationZ+6,locationRZ,locationGZ,locationBZ);

        }
        if(operasyon==4)
        {
            float cx,cy,cz;
            int r;
            float x1,y1,z1;
            float kure=0;
            int insideValue=0;
            printf("Merkezin 3 boyutlu koordinatini giriniz:(X Y Z)\n");
            scanf("%f %f %f",&cx,&cy,&cz);
            printf("Yaricapi giriniz(intvalue):\n");
            scanf("%d",&r);
            for(int z=0;z<index;z++)
            {
                x1=pow((nokta[z].x-cx),2);
                y1=pow((nokta[z].y-cy),2);
                z1=pow((nokta[z].z-cz),2);
            kure=sqrt(x1+y1+z1);
            if(kure<r)
            {
                printf("X:%f Y:%f Z:%f R:%d G:%d B:%d\n",nokta[z].x,nokta[z].y,nokta[z].z,nokta[z].r,nokta[z].g,nokta[z].b);
                insideValue++;
            }
            }

            printf("\nKurenin icinde %d tane deger vardir\n",insideValue);

        }
        if(operasyon==5)
        {
            exit(1);
        }







    goto LOOP;



    /*for(int j=0; j<9999; j++)//veriler 1noktalarin ayri dosyaya atanmasi
    {
        fprintf(noktalarme,"%f %f %f %d %d %d\n",nokta[j].x,nokta[j].y,nokta[j].z,nokta[j].r,nokta[j].g,nokta[j].b);// Noktalarin ayri dosyaya kaydedilmesi
    }*/
    //printf("%f",uzaklik(nokta.x,nokta2.x2,nokta.y,nokta2.y2 nokta.z,nokta2.z2));

    fclose(veriler1);

    return 0;
}
