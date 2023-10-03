#include <stdint.h>

#ifndef _HEAPS_H
#define _HEAPS_H

#define PARENT(i) i / 2
#define LEFT(i) 2 * i + 1
#define RIGHT(i) 2 * i + 2

#define MAX_HEAP_SIZE 50
#define MAX_STR_SIZE 50
#define MAX_PHNO_SIZE 10

typedef struct 
{
    int8_t *vehicle_make;
    int8_t *vehicle_model;
    int8_t *owner_name;
    int8_t *owner_phno;
    int32_t customer_urgency;
} Work;

void heapify(Work*);
void heappush(Work*, Work*);
Work heappop(Work*);

void print_heap(Work*);
void _print_individual_work(Work);

void _age_work();

#if defined(MIN_HEAP)
void _min_heapify(Work*, int32_t);
#else
void _max_heapify(Work*, int32_t);
#endif

#endif