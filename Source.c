#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    double median, prev;
    int midSize = (nums1Size + nums2Size) / 2;
    int Even = 0;
    if ((nums1Size + nums2Size) % 2 == 0) Even = 1;

    for (int i = 0, j = 0; ;) {
        if (j == nums2Size) {
            median = nums1[i++];
        }
        else if (i == nums1Size) {
            median = nums2[j++];
        }
        else if (nums1[i] < nums2[j]) {
            median = nums1[i++];
        }
        else {
            median = nums2[j++];
        }

        if (Even == 0) //Odd
        {
            if (i + j == midSize + 1)
                return median;
        }
        else     //Even
        {
            if (i + j == midSize + 1)
                return ((prev + median) / 2.0);
            prev = median;
        }
    }
}

void main(void)
{
    int nums1[] = {1,3};
    int nums2[] = { 2 };
//    int nums1[] = { 100001 };
//    int nums2[] = { 100000 };

    double median=0.0;
    median = findMedianSortedArrays(
             nums1, 
             sizeof(nums1)/sizeof(int), 
             nums2, 
             sizeof(nums2)/sizeof(int)
             );

    printf("%f\n", median);

    median = findMedianSortedArrays(
             NULL,
             0,
             nums2,
             sizeof(nums2) / sizeof(int)
             );
    
    printf("%f\n", median);
}