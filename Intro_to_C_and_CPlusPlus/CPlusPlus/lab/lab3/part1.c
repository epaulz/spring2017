/* Eric Paulz
 * CPSC 1021-004
 * Lab 3 - Debugging
 * TA: Nick Glyder
 */

#include "functions.h"


int main(int argc, char *argv[])
{
  FILE* input = fopen(argv[1], "r");
  FILE* output = fopen(argv[2], "w");
  int i = 0;
  if(argc < 3)
  {
    fprintf(stderr, "Usage: ./executable inputfile outputfile\n");
    exit(1);
  }

  if(input == NULL)
  {
    printf("file %s did not open\n", argv[1]);
  }

  if(output == NULL)
  {
    printf("file %s did not open\n", argv[2]);
  }
  header_t hdr;
  readHeader(input, &hdr);
  createHeader(output, &hdr);

    pixel_t **image = (pixel_t **)malloc(hdr.height * sizeof(pixel_t *));
    for (i = 0; i < hdr.height; i++)
        image[i] = (pixel_t*)malloc(hdr.width * sizeof(pixel_t));

  readPixels(input, &hdr,image); //added ampersand
  writePixels(output, &hdr,image);

  return 0;
}
