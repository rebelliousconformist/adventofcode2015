#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <limits.h>
#include <inttypes.h>

int main()
{
  unsigned char hashedMD5digest[MD5_DIGEST_LENGTH];
  const char *data = "yzbqklnj";
  uint64_t maxcounter = UINT64_MAX;
  char stringtobegenerated[200];
  uint16_t comparatorZero = 0;
  char stringtobeusedforcomparison[200];

  	  printf("program start \n");

  for (uint64_t numberUpCounter = 0; numberUpCounter < maxcounter; numberUpCounter++)
  {
    sprintf(stringtobegenerated,"%s%u",data,numberUpCounter);
//    printf("stringtobegenerated is %s and ", stringtobegenerated);
    MD5((unsigned char *)stringtobegenerated,strlen(stringtobegenerated),hashedMD5digest);

//    printf("hashed function is ");
//    for(int hashIterator = 0; hashIterator < MD5_DIGEST_LENGTH; hashIterator++){
//      printf("%02x", hashedMD5string[hashIterator]);
//    }
//
//    fflush(stdout);
//    printf("\n");

    sprintf(stringtobeusedforcomparison,"%02x%02x%02x%02x%02x",hashedMD5digest[0],hashedMD5digest[1],hashedMD5digest[2],hashedMD5digest[3],hashedMD5digest[4]);

    if(!strncmp(stringtobeusedforcomparison,"000000",6)){
    	printf("found at %llu \n",numberUpCounter);
    	break;
    }

    memset(stringtobegenerated,0x00,sizeof(stringtobegenerated));
    memset(hashedMD5digest,0x00,MD5_DIGEST_LENGTH);
  }


  return EXIT_SUCCESS;
}

