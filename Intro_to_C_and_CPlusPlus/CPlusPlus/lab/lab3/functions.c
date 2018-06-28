/* Eric Paulz
 * CPSC 1021-004
 * Lab 3 - Debugging
 * TA: Nick Glyder
 */

#include "functions.h"

void readHeader(FILE* ptr, header_t *hdr)
{
  fscanf(ptr, "%s %d %d %d ", hdr->magic, &hdr->width, &hdr->height,
                                &hdr->maxval);
}

void createHeader(FILE* ptr, header_t *hdr)
{
  fprintf(ptr, "%s %d %d %d\n", hdr->magic, hdr->width, hdr->height,
                                 hdr->maxval);
}

void readPixels(FILE* ptr, header_t *hdr, pixel_t **pix)
{
  int i, j;

  for(i = 0; i < hdr->height; i++)
  {
    for(j = 0; j < hdr->width; j++)
    {
       fscanf(ptr, "%c%c%c", &pix[i][j].r, &pix[i][j].g, &pix[i][j].b); //added ampersands for input
    }
  }
}

void writePixels(FILE* ptr, header_t *hdr, pixel_t **pix)
{
  int i;
  int j;
  for(i = 0; i < hdr->height; i++)
  {
    for(j = 0; j < hdr->width; j++)
    {
       fprintf(ptr, "%c%c%c", pix[i][j].r, pix[i][j].g, pix[i][j].b);
    }

  }
}
