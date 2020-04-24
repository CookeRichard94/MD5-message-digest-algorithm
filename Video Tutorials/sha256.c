//Theory Of Algortihms
//Richard Cooke


#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

//const required for algorithm
const uint32_t K[] = {
0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152,
0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08,
0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f,
0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

//bit shifting between all variables as per documents
uint32_t Ch(uint32_t x, uint32_t y, uint32_t z)
{
  return ( x & y ) ^ ( ~x & z );
}
//more bit shifting between variable as per document
uint32_t Maj(uint32_t x, uint32_t y, uint32_t z)
{
  return ( x & y ) ^ ( x & z ) ^ ( y & z );
}
//return x bit shifted to the right n times
uint32_t SHR(uint32_t x, int n)
{
  return x >> n;
}
uint32_t ROTR(uint32_t x, int n)
{
  return ( x >> n ) | ( x << ( 32 - n ) );
}

//final functions
uint32_t Sig0(uint32_t x)
{
  return ROTR( x , 2 ) ^ ROTR( x , 13 ) ^ ROTR( x , 22 );
}
uint32_t Sig1(uint32_t x)
{
  return ROTR( x , 6 ) ^ ROTR( x , 11 ) ^ ROTR( x , 25 );
}
uint32_t sig0(uint32_t x)
{
  return ROTR( x , 7 ) ^ ROTR( x , 18 ) ^ SHR( x , 3 );
}
uint32_t sig1(uint32_t x)
{
  return ROTR( x , 17 ) ^ ROTR( x , 19 ) ^ SHR( x , 10 );
}

//message blocks for processing
//512 bits long
union block{
  uint64_t sixtyFour[8];
  uint32_t threeTwo[16];
  uint8_t eight[64];
};
//function to pad the message correctly
uint64_t numzerobytes(uint64_t nobits)
{
  uint64_t result = 512ULL - (nobits % 512Ull);
  if(result<65)
  {
    result+=512;
  }
  result -=72;
  return(result/8Ull);
}

//used for signalling padding finsihed end of nextblock
enum flag {READ,PAD0,PAD1,FINISH};

//returns block for calculation
int nextblock(union block *M, FILE *infile, uint64_t *numbits, enum flag *status)
{
  if(*status == FINISH)
  {
    return 0 ;
  }
  if(*status == PAD1)
  {
    M->eight[0] = 0x80;
    for(int i= 1; i<56; i++)
    {
      M->eight[i]=0;
      M->sixtyFour[7]=*numbits;
      *status = FINISH;
      return 1;
    }
  }
  if(*status == PAD0)
  {
    for(int i=0; i<56; i++)
    {
      M->eight[i]=0;
      M->sixtyFour[7]= *numbits;
      return 1;
    }
  }
  size_t numbytesread = fread(M->eight,1,64,infile);
  if(numbytesread == 64)
  {
    return 1;
  }
  if(numbytesread < 56)
  {
    M->eight[numbytesread] = 0x80;
    for(int i = numbytesread +1; i<56; i++)
    {
      M->eight[i]=0;
      M->sixtyFour[7] = *numbits;
      *status = FINISH;
      return 1;
    }
  }
  //otherwise
  M->eight[numbytesread] = 0x80;
  for(int i=numbytesread+1; i<64;i++)
  {
    M->eight[i]=0;
    *status = PAD0;
    return 1;
  }
}

void nexthash(union block *M, uint32_t H[])
{
  //section 6.2.2
  //preform the hash using correct function
  //printf("%02"PRIx8,M.eight);
  uint32_t W[64];
  uint32_t a,b,c,d,e,f,g,h, T1, T2;
  a=H[0];
  b=H[1];
  c=H[2];
  d=H[3];
  e=H[4];
  f=H[5];
  g=H[6];
  h=H[7];

  int t;
  for(t = 0 ; t < 16; t++)
  {
    W[t] = M->threeTwo[t];
  }
  for(t = 16; t < 64; t++)
  {
    W[t] = sig1(W[t-2]) + W[t-7]+ sig0(W[t-15])+ W[t-16];
  }

  for( t=0 ; t < 64; t++ ) 
  {
    T1 = h+Sig1(e) + Ch(e,f,g)+ K[t]+ W[t];
    T2 = Sig0(a) + Maj(a,b,c);
    h=g;
    g=f;
    f=e;
    e=d+T1;
    b=a;
    a=T1+T2;
    //compute the final hash value
    H[0]= a+H[0];
    H[1]= b+H[1];
    H[2]= c+H[2];
    H[3]= d+H[3];
    H[4]= e+H[4];
    H[5]= f+H[5];
    H[6]= g+H[6];
    H[7]= h+H[7];
  }
}

//start main
//file for hashing passed into main
int main(int argc, char *argv[])
{
  //check file selected
  if(argc!=2)
  {
    printf("Please select file. \n");
    return 1;
  }
  //error handling for file
  FILE *infile = fopen(argv[1],"rb");
  if(!infile)
  {
    printf("error opening file");
    return 1;
  }
  else //perform the secure hash algorithm - output a 256 bit hashed version of file
  {
    uint32_t H[] = {
    0x6a09e667,
    0xbb67ae85, 
    0x3c6ef372,  
    0xa54ff53a, 
    0x510e527f,
    0x9b05688c, 
    0x1f83d9ab,
    0x5be0cd19};
    union block M;//messageblocks
    uint64_t numbits = 0;
    enum flag status = READ;
    //nextblock is organising all of the preprocessing
    while(nextblock(&M, infile, &numbits, &status))
    {
      nexthash(&M, H);
    }
    //print H as the caluculation of hash at the end
    for(int i = 0; i< 8; i++)
    {
      printf("%02" PRIX32 "", H[i]);
    }

    printf("\n");
    
  }
  //close the file
  fclose(infile);
  return 0;
