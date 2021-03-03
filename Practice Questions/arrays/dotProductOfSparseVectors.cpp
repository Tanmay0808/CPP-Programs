/*
  Impliment a class SparseVector that efficiently stores a sparse vector and computes dot product of two sparse vectors.

  Sparse Vector : A vector with most of its elements as zero, e.g - [0,1,0,0,0] or [1,0,0,0,0,2]
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class SparseVector{
    private:
        unordered_map<int, int> Arr;
    public:
        SparseVector(int *nums, int len);
        int dotProduct(SparseVector vec);
};

SparseVector::SparseVector(int *nums, int len){
    for (int i=0;i<len;i++)
    {
        if (nums[i] != 0)
        {
            Arr[i] = nums[i];
        }
    }
}

int SparseVector::dotProduct(SparseVector vec)
{
    int dot_val = 0;
    for (auto itr:Arr)
    {
        if (vec.Arr[itr.first])
        {
            dot_val += (vec.Arr[itr.first] * itr.second);
        }
    }
    return dot_val;
}

int main(int argc, char const *argv[])
{
    int nums1[] = {0,1,0,0,2,0,0}, nums2[] = {1,0,0,0,3,0,4};
    SparseVector V1(nums1,7);
    SparseVector V2(nums2,7);
    //Dot Product
    cout<<V1.dotProduct(V2)<<endl;
    return 0;
}
