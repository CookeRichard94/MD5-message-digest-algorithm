//Richard Cooke
//Theory Of Algorithms

#include <stdio.h>
#include <inttypes.h>

uint64_t nozerosbyts(uint64_t nobits)
{
    //calculation of how many zeros for correct padding
    uint64_t result = 512ULL - (nobits % 512ULL);
    if (result < 65){
    result += 512;
    }
    result -= 72;
    return (result/8ULL);
}
int main(int argc, char *argv[])
{
  if (argc != 2 )
  {
    printf("Error, need single argument for file \n");
    return 1;
  }
  FILE *infile = fopen(argv[1], "rb");
  if(!infile)
  {
    printf("error opening file");
    return 1;
  }
  else
  {
    //read the file
    uint8_t b;
    uint64_t nobits;
    //one byte at a time
    for(nobits=0;fread(&b,1,1,infile) == 1;nobits+=8)
    {
      //print all the bits
      printf("%02"PRIx8, b);
    }
    //add the one byte to the end
    printf("%02"PRIx8, 0x80);
    for(uint64_t i=nozerosbyts(nobits); i>0 ;i--)
    {
      //print the correct amount of zeros as returned from function to padd the input to
      //algorithm correctly
      printf("%02"PRIx8,0x00);
    }
    //finaly print the size of file in 16 bit format at the end
    printf("%016"PRIx64"\n",nobits);
  }
  //end loop, close file
  fclose(infile);
  return 0;
}