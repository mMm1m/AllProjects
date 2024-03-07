#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main()
{
   int K1,M,K2,P2,N2;
   scanf("%d ", &K1);
   scanf("%d ", &M);
   scanf("%d ", &K2);
   scanf("%d", &P2);
   scanf("%d", &N2);
   int P1 = -1 , N1 = -1;
   if(M < N2 || M*(P2-1)+N2 > K2)
   {
      P1 = -1; N1 = -1;
   }
   else if (N2 == 1 && P2 == 1) {
   if (K1 <= K2) {
      P1 = 1;
      N1 = 1;
  } else if (K1 <= M) {
   P1 = 1;
   N1 = 0;
   if (M == 1) {
    N1 = 1;
   }
  } else {
   P1 = 0;
   N1 = 0;
   if (M == 1) {
    N1 = 1;
   }
  }
 }
 else {
  int x1 = (int)(ceil((float)K2 / (float)(N2+M*(P2-1))));
  int x2 = (float)K2 / (float)(N2-1+M*(P2-1));
  if ((float)x1 < x2) {
   if (x2 == (float)((int)(x2))) {
    x2 -= 1;
   } else {
    x2 = floor(x2);
   }

   P1 = (int)(ceil((float)K1 / ((float)x1 * (float)M)));
   N1 = (int)(ceil(((float)K1 - (float)x1*(float)M*((float)P1-1)) / (float)x1));
   int checkP = 1;
   int checkN = 1;
   for (int x = (int)x1 + 1; x <= (int)(x2); x++) {
    int P = (int)(ceil((float)K1 / ((float)x * (float)M)));
    int N = (int)(ceil(((float)K1 - (float)x*(float)M*((float)P-1)) / (float)x));
    if (checkP == 1 && P != P1) {
     P1 = 0;
     checkP = 0;
    }
    if (checkP==1) {
     P1 = P;
    }

    if (checkN == 1 && N != N1) {
     N1 = 0;
     if (M == 1) {
      N1 = 1;
     }
     checkN = 0;
    }
    if (checkN == 1) {
     N1 = N;
    }
   }
  }
 }

}
