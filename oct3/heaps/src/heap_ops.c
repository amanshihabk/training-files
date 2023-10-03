#include "heap_ops.h"
#include <stdint.h>
#include <stdio.h>

int32_t heap_idx = -1;

void heapify(Work *heap)
{
    int32_t i;

    for (i = (heap_idx / 2); i >= 0; i--)
    {
        #if defined(MIN_HEAP)
        _min_heapify(heap, i);
        #else
        _max_heapify(heap, i);
        #endif
    }
}

#if defined(MIN_HEAP)

void _min_heapify(Work *_heap, int32_t _i)
{
    uint32_t left_child = LEFT(_i);
    uint32_t right_child = RIGHT(_i);

    uint32_t smallest = _i;
    Work temp;

    if (left_child <= heap_idx && _heap[left_child].customer_urgency < _heap[_i].customer_urgency)
    {
        smallest = left_child;
    }
    else
    {
        smallest = _i;
    }

    if (right_child <= heap_idx && _heap[right_child].customer_urgency < _heap[smallest].customer_urgency)
    {
        smallest = right_child;
    }
    else
    {
        // Do nothing
    }

    if (smallest != _i)
    {
        temp = _heap[_i];
        _heap[_i] = _heap[smallest];
        _heap[smallest] = temp;

        _min_heapify(_heap, smallest);
    }
    else
    {
        // Do nothing
    }
}

#else

void _max_heapify(Work *_heap, int32_t _i)
{
    uint32_t left_child = LEFT(_i);
    uint32_t right_child = RIGHT(_i);

    uint32_t largest = _i;
    Work temp;

    if (left_child <= heap_idx && _heap[left_child].customer_urgency > _heap[_i].customer_urgency)
    {
        largest = left_child;
    }
    else
    {
        largest = _i;
    }

    if (right_child <= heap_idx && _heap[right_child].customer_urgency > _heap[largest].customer_urgency)
    {
        largest = right_child;
    }
    else
    {
        // Do nothing
    }

    if (largest != _i)
    {
        temp = _heap[_i];
        _heap[_i] = _heap[largest];
        _heap[largest] = temp;

        _max_heapify(_heap, largest);
    }
    else
    {
        // Do nothing
    }
}

#endif

void heappush(Work *heap, Work *element)
{
    if (heap_idx + 1 >= MAX_HEAP_SIZE)
    {
        printf("\nHeap is at memory capacity. Cannot add more.\n");
    }
    else
    {
        heap[++heap_idx] = *element;

        heapify(heap);
    }
}

Work heappop(Work *heap)
{
    Work to_return, temp;

    if (heap_idx > 0)
    {
        to_return = heap[0];
        temp = heap[0];
        heap[0] = heap[heap_idx];
        heap[heap_idx] = temp;
        heap_idx -= 1;

        heapify(heap);

        _age_work(heap);

        return to_return;
    }
    else if (heap_idx == 0)
    {
        heap_idx -= 1;
        return heap[0];
    }
    else
    {
        printf("\nHeap is empty.\n");
        to_return.customer_urgency = -1;

        return to_return;
    }

}

void print_heap(Work *heap)
{
    uint32_t i;

    if (heap_idx < 0)
    {
        printf("\nNo works.\n");
    }
    else
    {
        printf("\nThe heap now is : ");
        for (i = 0; i <= heap_idx; i++)
        {
            _print_individual_work(heap[i]);
        }
    }
}

void _print_individual_work(Work temp)
{
    printf("\n\nVehicle Make : %s", temp.vehicle_make);
    printf("\nVehicle Model : %s", temp.vehicle_model);
    printf("\nOwner Name : %s", temp.owner_name);
    printf("\nOwner Phone : %s", temp.owner_phno);
    printf("\nUrgency : %d", temp.customer_urgency);
}

void _age_work(Work *heap)
{
    uint32_t i;
    
    for (i = 0; i <= heap_idx; i++)
    {
        #if defined(MIN_HEAP)
        heap[heap_idx].customer_urgency -= 1;
        #else
        heap[heap_idx].customer_urgency += 1;
        #endif
    }
}