#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int i, j;

void Ascii()
{
    cout << "**************************************************************************\n ___          _   _               _   _              _ _   _ " << endl;
    cout << "/ __| ___ _ _| |_(_)_ _  __ _    /_\\ | |__ _ ___ _ _(_) |_| |_  _ __  ___" << endl;
    cout << "\\__ \\/ _ \\ '_|  _| | ' \\/ _` |  / _ \\| / _` / _ \\ '_| |  _| ' \\| '  \\(_-<" << endl;
    cout << "|___/\\___/_|  \\__|_|_||_\\__, | /_/ \\_\\_\\__, \\___/_| |_|\\__|_||_|_|_|_/__/" << endl;
    cout << "                        |___/          |___/by Dominic                   \n\n**************************************************************************" << endl;
}

///USED FUNCTIONS IN SORTS AND MAIN
int* getradomarray(int a[], int arraySize)
{
	srand(time(nullptr));

	for (int i = 0; i < arraySize; i++)
	{
		a[i] = 0 + rand() % 100000;
	}
	return a;
}

void printArray(int a[], int arraySize)
{
    for(i = 0; i < arraySize; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl;
}

void arrayNullifier(int a[], int b[], int arraySize)
{
    for(i = 0; i < arraySize; i++)
    {
        a[i] = b[i];
    }
}

void sortComparison(double data[], int x)
{
    for(i = 0; i < x + 1; i++)  {   cout << i + 1 << "/10. Sort took: " << data[i] << " seconds" << endl;  }
    cout << endl;
}

void swapValues(int *frst, int *scnd)
{
    int tmp = *frst;
    *frst = *scnd;
    *scnd = tmp;
}

int getMax(int a[], int n)
{
    int maxi = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > maxi)
            maxi = a[i];
    return maxi;
}

int binarySearch(int a[], int item, int mini, int maxi)
{
    int mid = (mini + maxi)/2;

    if (maxi <= mini)   {   return (item > a[mini])?  (mini + 1): mini; }

    if(item == a[mid])  {   return mid+1;   }

    if(item > a[mid])   {   return binarySearch(a, item, mid+1, maxi);  }

    return binarySearch(a, item, mini, mid-1);
}

void countSort(int a[], int arraySize, int exp)
{
    int output[arraySize];
    int i, count[10] = {0};

    for (i = 0; i < arraySize; i++)
        count[ (a[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = arraySize - 1; i >= 0; i--)
    {
        output[count[ (a[i]/exp)%10 ] - 1] = a[i];
        count[ (a[i]/exp)%10 ]--;
    }

    for (i = 0; i < arraySize; i++)
        a[i] = output[i];
}

int partitioner1(int a[], int mini, int maxi)
{
    int pivot = a[mini];
    i = mini - 1;
    j = maxi + 1;

    for(;;)
    {
        do  {   i = i + 1;    } while(a[i] < pivot);

        do  {   j = j - 1;    } while(a[j] > pivot);

        if(i >= j)
            return j;

         swapValues(&a[i], &a[j]);
    }
}

int partitioner2(int a[], int mini, int maxi)
{
    int pivot = a[(mini + maxi) / 2];
    i = mini - 1;
    j = maxi + 1;

    while(true)
    {
        do  {   i = i + 1;    } while(a[i] < pivot);

        do  {   j = j - 1;    } while(a[j] > pivot);

        if(i >= j)
            return j;

         swapValues(&a[i], &a[j]);
    }
}

int partitioner3(int a[], int mini, int maxi)
{
    int pivot = a[maxi];
    int i = (mini - 1);

    for (j = mini; j <= maxi- 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swapValues(&a[i], &a[j]);
        }
    }
    swapValues(&a[i + 1], &a[maxi]);
    return (i + 1);
}

int partitioner4(int a[], int mini, int maxi)
{
	int pivot = a[maxi];
    int i = mini - 1;

    for (j = mini; j <= maxi - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swapValues(&a[i], &a[j]);
        }
    }
    swapValues(&a[i + 1], &a[maxi]);
    return (i + 1);
}

int partition4_r(int a[], int mini, int maxi)
{
    srand(time(nullptr));
	int random = mini + rand() % (maxi - mini);
	swapValues(&a[random], &a[maxi]);
	return partitioner4(a, mini, maxi);
}

void heapify(int a[], int arraySize, int x)
{
    int largest = x;
    int left = 2*x + 1;
    int right = 2*x + 2;

    if (left < arraySize && a[left] > a[largest])
        largest = left;

    if (right < arraySize && a[right] > a[largest])
        largest = right;

    if (largest != x)
    {
        swapValues(&a[x], &a[largest]);

        heapify(a, arraySize, largest);
    }
}

void merge(int a[], int left, int mid, int right)
{
    int k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = a[left + i];
    for(j = 0; j < n2; j++)
        R[j] = a[mid + 1+ j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

int sortSelection() //TODO return value, all descriptions.
{
    int choice;
    Ascii();
    for(;;){
    cout << endl << "Choose the sort for your array:" << endl;
    cout << "1  - Quick Sort v1 (pivot = first);" << endl << "2  - Quick Sort v2 (pivot = middle)" << endl << "3  - Quick Sort v3 (pivot = last);" << endl << "4  - Quick Sort v4 (random pivot);" << endl << "5  - Bubble Sort v1 (for loop);" << endl;
    cout << "6  - Bubble Sort v2 (Last Check);" << endl << "7  - Bubble Sort v3 (Swap Check);" << endl << "8  - Insertion Sort v1 (simple);" << endl << "9  - Insertion Sort v2 (recursive);" << endl;
    cout << "10 - Insertion Sort v3 (binary search);" << endl << "11 - Selection Sort;" << endl << "12 - Shell Sort;" << endl << "13 - Radix Sort;" << endl << "14 - Heap Sort;" << endl << "15 - Merge Sort" << endl;
    cin >> choice;
    system("cls");
    if(choice < 1 || choice > 15)
    {
        Ascii(); cout << endl;
        cout << "!!!Invalid input, try again!!!" << endl;
    }
    else
        break;
    }

    switch(choice)
    {
    case 1:
        cout << "Quick Sort v1. Usually the most efficient sort." << endl << "Best case scenario the number of operation is O(n log n), worst case O(n^2)" << endl;
        break;
    case 2:
        cout << "Quick Sort v2. Usually the most efficient sort." << endl << "Best case scenario the number of operation is O(n log n), worst case O(n^2)" << endl;
        break;
    case 3:
        cout << "Quick Sort v3. Usually the most efficient sort." << endl << "Best case scenario the number of operation is O(n log n), worst case O(n^2)" << endl;
        break;
    case 4:
        cout << "Quick Sort v4. Usually the most efficient sort." << endl << "Best case scenario the number of operation is O(n log n), worst case O(n^2)" << endl;
        break;
    case 5:
        cout << "Bubble Sort v1. One of the most inefficient sort." << endl << "Its running time totally depends on how initially the array is sorted. Operations of average: O(n^2)"<< endl;
        break;
    case 6:
        cout << "Bubble Sort v2. One of the most inefficient sort." << endl << "Its running time totally depends on how initially the array is sorted. Operations of average: O(n^2)"<< endl;
        break;
    case 7:
        cout << "Bubble Sort v3. One of the most inefficient sort." << endl << "Its running time totally depends on how initially the array is sorted. Operations of average: O(n^2)"<< endl;
        break;
    case 8:
        cout << "Insertion Sort v1. The most straight forward sort." << endl << "On large arrays Insertion Sort performs relatively bad. Operations of average: O(n^2)" << endl;
        break;
    case 9:
        cout << "Insertion Sort v2. The most straight forward sort." << endl << "On large arrays Insertion Sort performs relatively bad. Operations of average: O(n^2)" << endl;
        break;
    case 10:
        cout << "Insertion Sort v3. The most straight forward sort." << endl << "On large arrays Insertion Sort performs relatively bad. Operations of average: O(n^2)" << endl;
        break;
    case 11:
        cout << "Selection Sort. " << endl << "It has O(n2) time complexity, making it inefficient on large lists," << endl << "and generally performs worse than the similar insertion sort." << endl;
        break;
    case 12:
        cout << "Shell Sort." << endl << "The running time of Shellsort is heavily dependent on the gap sequence it uses. For many practical variants, " << endl << "determining their time complexity remains an open problem." << endl;
        break;
    case 13:
        cout << "Radix Sort. One of my favorites by cleverness." << endl << "Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by " << endl << "the individual digits which share the same significant position and value." << endl;
        break;
    case 14:
        cout << "Heap Sort." << endl << "Although somewhat slower in practice on most machines than a well-implemented quicksort, it has the advantage of a more favorable worst-case O(n log n) runtime." << endl;
        break;
    case 15:
        cout << "Merge Sort." << endl << "Most implementations produce a stable sort, which means that " << endl << "the order of equal elements is the same in the input and output." << endl;
        break;
    default:
        cout << "I will not be noticed by senpai :c";
    }
    return choice;
}
///FUNCTIONS OF THE SORTS
void quickSort1(int a[], int mini, int maxi)
{
    if (mini < maxi)
    {
        int pi = partitioner1(a, mini, maxi);
        quickSort1(a, mini, pi);
        quickSort1(a, pi + 1, maxi);
    }
}

void quickSort2(int a[], int mini, int maxi)
{
    if (mini < maxi)
    {
        int pi = partitioner2(a, mini, maxi);
        quickSort2(a, mini, pi);
        quickSort2(a, pi + 1, maxi);
    }
}

void quickSort3(int a[], int mini, int maxi)
{
    if (mini < maxi)
    {
        int pi = partitioner3(a, mini, maxi);
        quickSort3(a, mini, pi - 1);
        quickSort3(a, pi + 1, maxi);
    }
}

void quickSort4(int a[], int mini, int maxi)
{
    if (mini < maxi)
    {
        int pi = partition4_r(a, mini, maxi);
        quickSort4(a, mini, pi - 1);
        quickSort4(a, pi + 1, maxi);
    }
}

void bubbleSort1(int a[], int arraySize)
{
    for (i = 0; i < arraySize; i++)
    {
        for (j = 0; j < arraySize; j++)
        {
            if (a[j] > a[j+1]){ swapValues(&a[j], &a[j+1]); }
        }
    }
}

void bubbleSort2(int a[], int arraySize)
{
    for (i = 0; i < arraySize; i++)
    {
        for (j = 0; j < arraySize-i; j++)
        {
            if (a[j] > a[j+1]){ swapValues(&a[j], &a[j+1]); }
        }
    }
}

void bubbleSort3(int a[], int arraySize)
{
    bool swapped;
    do
    {
        swapped = false;
        for(i = 0; i < arraySize; i++)
        {
            if(a[i-1] > a[i])
            {
                swapValues(&a[i-1], &a[i]);
                swapped = true;
            }
        }
        arraySize = arraySize - 1;
    }while(swapped != 0);
}

void insertionSort1(int a[], int arraySize)
{
    int tmp;
    for (i = 1; i < arraySize; i++)
    {
        tmp = a[i];
        j = i-1;
        while (j >= 0 && a[j] > tmp)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = tmp;
    }
}

void insertionSort2(int a[], int arraySize)
{
    int tmp;
    if(arraySize > 0)
    {
        insertionSort2(a, arraySize-1);
        tmp = a[arraySize];
        j = arraySize-1;
        while(j >= 0 && a[j] > tmp)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = tmp;
    }
}

void insertionSort3(int a[], int arraySize)
{
    int loc, k, selected;

    for (i = 1; i < arraySize; ++i)
    {
        j = i - 1;
        selected = a[i];
        loc = binarySearch(a, selected, 0, j);

        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}

void selectionSort(int a[], int arraySize)
{
    int mini;
    for (i = 0; i < arraySize-1; i++)
    {
        mini = i;
        for (j = i+1; j < arraySize; j++)
            if (a[j] < a[mini]) {  mini = j; }

            swapValues(&a[mini], &a[i]);
    }
}

void shellSort(int a[], int arraySize)
{
    for (int dist = arraySize/2; dist > 0; dist /= 2)
    {
        for (int i = dist; i < arraySize; i += 1)
        {
            int tmp = a[i];
            int j;
            for (j = i; j >= dist && a[j - dist] > tmp; j -= dist)
                a[j] = a[j - dist];
            a[j] = tmp;
        }
    }
}

void radixSort(int a[], int arraySize)
{
    int m = getMax(a, arraySize);

    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(a, arraySize, exp);
}

void heapSort(int a[], int arraySize)
{
    if(arraySize == 2)
    {
        if(a[0] > a[1])
            swapValues(&a[0], &a[1]);
    }
    else
    {
        for (i = arraySize / 2 - 1; i >= 0; i--)
            heapify(a, arraySize, i);

        for (i = arraySize-1; i >= 0; i--)
        {
            swapValues(&a[0], &a[i]);
            heapify(a, i, 0);
        }
    }
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left+(right-left)/2;

        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);

        merge(a, left, mid, right);
    }
}

void arraySort(int a[], int arraySize, int choice)
{
    switch(choice)
    {
    case 1:
        quickSort1(a, 0, arraySize - 1);
        break;
    case 2:
        quickSort2(a, 0, arraySize - 1);
        break;
    case 3:
        quickSort3(a, 0, arraySize - 1);
        break;
    case 4:
        quickSort4(a, 0, arraySize - 1);
        break;
    case 5:
        bubbleSort1(a, arraySize);
        break;
    case 6:
        bubbleSort2(a, arraySize);
        break;
    case 7:
        bubbleSort3(a, arraySize);
        break;
    case 8:
        insertionSort1(a, arraySize);
        break;
    case 9:
        insertionSort2(a, arraySize);
        break;
    case 10:
        insertionSort3(a, arraySize);
        break;
    case 11:
        selectionSort(a, arraySize);
        break;
    case 12:
        shellSort(a, arraySize);
        break;
    case 13:
        radixSort(a, arraySize);
        break;
    case 14:
        heapSort(a, arraySize);
        break;
    case 15:
        mergeSort(a, 0, arraySize - 1);
        break;
    }
}

int main()
{
    int arraySize, choice, choice2 = 1, x = 0;
    Ascii();
    cout << "\n\nHello User." << endl << "This is a sorting program." << endl << "Here you can input your array and the algorithm of sorting it." << endl;
    cout << "First insert the length of array: ";
    cin >> arraySize;

    int *a = new int[arraySize];
    int *b = new int[arraySize];
    double data[10];
    /*
    cout << "\n";
    for(i = 0; i < arraySize; i++)
    {
        cout << i + 1 << "# element: ";
        cin >> a[i];
        cout << endl;
    }
    */

    getradomarray(a, arraySize);

    for(i = 0; i < arraySize; i++)  {   b[i] = a[i];    }

    for(;;){
    system("cls");

    //cout << "This is the array before the sort: " << endl;
    //printArray(b, arraySize);

    arrayNullifier(a, b, arraySize);
    choice = sortSelection();

    auto start = high_resolution_clock::now();
    arraySort(a, arraySize, choice);
    auto finish = high_resolution_clock::now();

    duration<double> elapsed = finish - start;

    data[x] = elapsed.count();

    cout << "Time of sort: " << data[x] << " s" << endl << endl;

    sortComparison(data, x);

    x = x+1;
    //cout << endl << endl << "This is the array after the chosen sort: " << endl;
    //printArray(a, arraySize);

    if(x == 10)
    {
        cout << endl << "You reached the limit of sort experiments." << endl << endl;
        break;
    }

    do{
    cout << "You can do up to 10 sorts.\nSelect a new sorting algorithm?" << endl << "Make sure your input is correct." << endl << "\n1 - Yes, 2 - No" << endl;
    cin >> choice2;
    }while(choice2 < 1 || choice2 > 2);
    if(choice2 == 2)
        break;
    }

    delete []b;
    delete []a;

    return 0;
}
