#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int AllSize = nums1Size + nums2Size;
    int Even = 0, i=0, iMed=0;
    int Med=0, Med1=0;
    double ret;

    if (AllSize % 2 == 0)
    {
        Even = 1;
        iMed = AllSize / 2 - 1;  //Need to get the number in index iMed, iMed+1
    }
    else
    {
        iMed = AllSize / 2;      //Need to get the number in index iMed,   

    }

    if (nums1Size == 0)   //All numbers are in nums2
    {
        if (Even)
        {
            ret = (nums2[iMed] + nums2[iMed + 1])/2.0;
        }
        else  // odd
        {
            ret = nums2[iMed];
        }
        return ret;
    }

    if (nums2Size == 0)   //All numbers are in nums1
    {
        if (Even)
        {
            ret = (nums1[iMed] + nums1[iMed + 1])/2.0;
        }
        else  // odd
        {
            ret = nums1[iMed];
        }
        return ret;
    }

    int j1 = 0, j2 = 0;
    for (i = 0; i <= iMed ; i++)
    {
        
        if (j1 == nums1Size)
        {
            if (i == iMed)   Med = nums2[j2];
            j2++;
        }
        else if (j2 == nums2Size)
        {
            if (i == iMed)   Med = nums1[j1];
            j1++;
        }
        else if ((nums1[j1] < nums2[j2]))
        {
            if (i == iMed)   Med = nums1[j1];
            j1++;
        }
        else
        {
            if (i == iMed)   Med = nums2[j2];
            j2++;
        }
    }

    if (Even == 1)  //Even
    {   //Find Med1
        if (j1 == nums1Size) {
            Med1 = nums2[j2];
        }
        else if (j2 == nums2Size) {
            Med1 = nums1[j1];
        }
        else {

            if (nums1[j1] < nums2[j2]) {
                Med1 = nums1[j1];
            }
            else{
                Med1 = nums2[j2];
            }
        }

        ret = (Med + Med1) / 2.0;
    }
    else
    {
        ret = Med;
    }
    return ret;
}

void main(void)
{
//    int nums1[] = {1,3};
//    int nums2[] = { 2 };
    int nums1[] = { 100001 };
    int nums2[] = { 100000 };

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