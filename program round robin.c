#include<stdio.h>
int main()
{
      int i, limit, total = 0, x, counter = 0, waktu_kuantum;
      int waktu_tunggu = 0, waktu_tunggu_dan_proses = 0, waktu_kedatangan[10], waktu_eksekusi[10], temp[10];
      printf("\nMasukkan banyaknya proses:\t");
      scanf("%d", &limit);
      x = limit;
      for(i = 0; i < limit; i++)
      {
            printf("\nMasukkan detail proses[%d]\n", i );
            printf("Waktu Kedatangan:\t");
            scanf("%d", &waktu_kedatangan[i]);
            printf("Waktu Eksekusi:\t");
            scanf("%d", &waktu_eksekusi[i]);
            temp[i] = waktu_eksekusi[i];
      }
      printf("\nMasukkan waktu kuantum:\t");
      scanf("%d", &waktu_kuantum);
      printf("\nProcess ID\t\tWaktu Eksekusi\t Waktu Tunggu dan Proses\t Waktu Tunggu\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= waktu_kuantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - waktu_kuantum;
                  total = total + waktu_kuantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t\t %d", i , waktu_eksekusi[i], total - waktu_kedatangan[i], total - waktu_kedatangan[i] - waktu_eksekusi[i]);
                  waktu_tunggu = waktu_tunggu + total - waktu_kedatangan[i] - waktu_eksekusi[i];
                  waktu_tunggu_dan_proses = waktu_tunggu_dan_proses + total - waktu_kedatangan[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(waktu_kedatangan[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }

}
