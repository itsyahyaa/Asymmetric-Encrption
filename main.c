#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int x, y, n, t, i, flag_check;
long int e[70], d[70], temp[70], j, m[70], en[70];
char msg[700];
int prime(long int);
void encryption_key();
long int cd(long int);
void encrypt();
void decrypt();

int main()
{
  printf("\n Enter first Prime Number \n");
  scanf("%d", &x);
  flag_check = prime(x);
  if(flag_check == 0)
  {
    printf("\n Wrong Input try again \n");
    exit(0);
  }
  printf("\n Enter Second Prime Number \n");
  scanf("%d", &y);
  flag_check = prime(y);
  if(flag_check == 0 || x == y)
  {
    printf(" Wrong Input try again\n");
    exit(0);
  }
  printf("\n Enter Message to encrypt : \n");

  scanf("%s",msg);
  for(i = 0; msg[i] != NULL; i++)
    m[i] = msg[i];
  n = x * y;
  t = (x-1) * (y-1);
  encryption_key();
  printf("\n Possible Values of e and d \n");
  for(i = 0; i < j-1; i++)
    printf("\n %ld \t %ld ", e[i], d[i]);
  encrypt();
  decrypt();
  return 0;
}
int prime(long int pr)
{
  int i;
  j = sqrt(pr);
  for(i = 2; i <= j; i++)
  {
   if(pr % i == 0)
     return 0;
  }
  return 1;
 }

//function to generate encryption key
void encryption_key()
{
  int k;
  k = 0;
  for(i = 2; i < t; i++)
  {
    if(t % i == 0)
     continue;
    flag_check = prime(i);
    if(flag_check == 1 && i != x && i != y)
    {
     e[k] = i;
     flag_check = cd(e[k]);
    if(flag_check > 0)
    {
     d[k] = flag_check;
     k++;
    }
   if(k == 99)
    break;
   }
 }
}
long int cd(long int a)
{
  long int k = 1;
  while(1)
  {
    k = k + t;
    if(k % a == 0)
     return(k / a);
  }
}

//function to encrypt the message
void encrypt()
{
  long int pt, ct, key = e[0], k, len;
  i = 0;
  len = strlen(msg);
  while(i != len)
  {
    pt = m[i];
    pt = pt - 96;
    k = 1;
    for(j = 0; j < key; j++)
    {
     k = k * pt;
     k = k % n;
    }
   temp[i] = k;
   ct = k + 96;
   en[i] = ct;
   i++;
  }
  en[i] = -1;
  printf("\n The ciphertext is : \n");
  for(i = 0; en[i] != -1; i++)
    printf("%c", en[i]);
}

//function to decrypt the message
void decrypt()
{
  long int pt, ct, key = d[0], k;
  i = 0;
  while(en[i] != -1)
  {
    ct = temp[i];
    k = 1;
    for(j = 0; j < key; j++)
    {
      k = k * ct;
      k = k % n;
    }
   pt = k + 96;
   m[i] = pt;
   i++;
  }
  m[i] = -1;
  printf("\n Decrpted Message is : \n");
  for(i = 0; m[i] != -1; i++)
   printf("%c", m[i]);
  printf("\n");
}