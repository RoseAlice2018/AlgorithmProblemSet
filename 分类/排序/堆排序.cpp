int len;
int buildMaxHeap(vector<int>& arr)
{
    len = arr.size();
    int parent = (len-1)/2;
    for(int i = parent;i>=0;i--)
    {
        heapify(arr,i);
    }
}
void heapify(vector<int>& arr,int i)
{
    int left = 2*i +1;
    int right = 2*i + 2;
    int largest = i;
    if(left<len && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right<len && arr[right] > arr[largest])
    {
        largest = right;
    }
    if(largest!=i)
    {
        swap(arr,i,largest);
        heapify(arr,largest);
    }
}
void swap(vector<int>& arr,int i,int largest)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapSort(vector<int>& arr)
{
    buildMaxHeap(arr);
    for(int i=arr.size()-1;i>0;i--)
    {
        swap(arr,0,i);
        len--;
        heapify(arr,0);
    }
    return arr;
}